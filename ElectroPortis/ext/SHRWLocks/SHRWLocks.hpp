/*
Copyright (c) 2009 Valery Grebnev.
CPOL (Code Project Open License) Licensed http://www.codeproject.com/info/cpol10.aspx

This code is a part of the article “Reader/writer lock with a helper” which
describes a heuristic approach when developing reader/writer spin-locks for Windows XP/Vista.
The code has some additional comments which might be considered when porting 
the SHRW/SHRW2 lock objects.
*/

#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <intrin.h>

#pragma intrinsic(_InterlockedCompareExchange, _InterlockedDecrement, \
			_InterlockedXor, _InterlockedOr)

#define acquire_interlocked_compare_exchange _InterlockedCompareExchange
#define interlocked_decrement_release  _InterlockedDecrement
#define interlocked_Xor_release _InterlockedXor
#define interlocked_Or_release _InterlockedOr
/*
	#define acquire_interlocked_compare_exchange _InterlockedCompareExchange
	#define interlocked_decrement_release  _InterlockedDecrement
	#define interlocked_Xor_release _InterlockedXor
	#define interlocked_Or_release _InterlockedOr

	On Windows running on x86, the InterlockedXxx functions are all full-memory
	barriers when compiling with Microsoft compilers, see the article 
	“Lockless Programming Considerations for Xbox 360 and Microsoft Windows”
	(http://msdn.microsoft.com/en-us/library/bb310595(VS.85).aspx).
	Microsoft compilers insert the LOCK prefix when generating code for these
	intrinsics for x86, for example:

		;interlocked_Xor_release(&m_rw_status, 0x1+0xFFFF);
		...
		lock  xor DWORD PTR [edx], ecx
		...
		; while( acquire_interlocked_compare_exchange(&m_rw_status,0x1+0xFFFF,0x0) != 0x0)
		...
		lock cmpxchg DWORD PTR [esi], edx

	The LOCK semantic effectively locks a system bus when executing these instructions, see  the manual
	“Intel® 64 and IA-32 Architectures Software Developer’s Manual Volume 3A: System Programming Guide, Part 1”,
	#7.1.2.2 Software Controlled Bus Locking (http://download.intel.com/design/processor/manuals/253668.pdf).
	The InterlockedXxx operations are platform specific. They may not contain CPU memory barriers
	on a platform other than x86. Consider using explicit memory hardware/compiler barriers
	when porting the code to a different platform and/or when using different compilers.
*/


#define CACHE_LINE 64
/*
	#define CACHE_LINE 64
	On modern x86 processors, the line size is 64 bytes or 128 bytes
	(sub-divided or “sectored” into two 64-byte pieces).
*/


#define CACHE_ALIGN __declspec(align(CACHE_LINE))
/*
	#define CACHE_ALIGN __declspec(align(CACHE_LINE))
	In order to prevent “false sharing”, data structures should be aligned
	on the cache boundary as described in the articles “Align Data Structures on Cache Boundaries”
	(http://software.intel.com/en-us/articles/align-data-structures-on-cache-boundaries/),
	and “Developing Multithreaded Applications: A Platform Consistent Approach ”
	(http://software.intel.com/en-us/articles/developing-multithreaded-applications-a-platform-consistent-approach/).
*/


#define CACHE_PADDING(num_padding) char _cache_padding_##num_padding[CACHE_LINE*2];
/*
	#define CACHE_PADDING(num_padding) char _cache_padding_##num_padding[CACHE_LINE*2];
	For a Pentium 4 processor, which has the cache line size 128 bytes
	(sub-divided or “sectored” into two 64-byte pieces), the optimal organization 
	is to have a synchronization variable alone on a 128-byte line,
	see  the article “AP949 Using Spin Loops on Intel® Pentium® 4 Processor and Intel Xeonr Processor”
	(“http://software.intel.com/en-us/articles/ap949-using-spin-loops-on-intel-pentiumr-4-processor-and-intel-xeonr-processor/”).

	If adjacent sector prefetch is enabled, a request for one cache line will bring
	the other cache line in the pair. From this prospective, a sectored 2*64 cache line
	acts like a 128-byte cache line. We follow the recommendations in the articles 
	“AP949 Using Spin Loops on Intel® Pentium® 4 Processor and Intel Xeonr Processor”,
	and “Developing Multithreaded Applications: A Platform Consistent Approach ”
	to pad the data structure to twice the size of a cache line, 2*CACHE_LINE bytes.
*/


#define  pause YieldProcessor();
/*
	#define  pause __asm {pause}
	Intel strongly recommends using the PAUSE instruction in spin-wait loops,
	see  the article “AP949 Using Spin Loops on Intel® Pentium® 4 Processor and Intel Xeonr Processor”.
	Without a PAUSE instruction, a processor may suffer a severe penalty
	when exiting the loop because the processor detects a possible memory order violation.
	Inserting the PAUSE instruction significantly reduces the likelihood of a memory order violation,
	improving performance, and minimizing power consumption, see the article
	“Intel® Pentium® 4 Processor Optimization Reference Manual”,
	http://software.intel.com/en-us/articles/intel-pentiumr-4-processor-optimization-reference-manual/.
*/


#define _read_barrier_	_ReadBarrier()
#define _write_barrier_	_WriteBarrier()
/*
	#define _read_barrier_	_ReadBarrier()
	#define _write_barrier_	_WriteBarrier()
	When compiling the code with the Microsoft VC++8.0/9.0, it is possible to omit _ReadBarrier(),
	_WriteBarrier() functions.  The reason is that the read/write operations have release/acquire
	semantics when reading/writing the volatile m_rw_status  variable of the SHRW/SRW2 lock objects.
	This is specific to the latest Microsoft compilers. It might be necessary to use explicit fences
	like __memory_barrier() for the compilers other than those when porting the code.
*/


__forceinline LONG _acquire_read_(LONG volatile const& val) 
{
/*
	An x86 load acts as an implicit acquire barrier. 
	The SSE streaming instructions or fast string operations are not used in this code; and thus
	we do not need an explicit hardware fence, like the lfence instruction for the x86 platform.
	Consider using a hardware fence when poring the code to another platform with weaker ordering than x86. 
	In this case, a first candidate to employ might be MemoryBarrier when compiling with Microsoft compilers.
*/	
	LONG rc = val;

	// Compiler & hardware fences if needed, see the comment above and the comments	for the _read_barrier_ macro. 
	_read_barrier_;
	return rc;
}
__forceinline void _write_release_(volatile  LONG& target, LONG value)
{
	// Compiler & hardware fences if needed, see the comment below and the comments for the _write_barrier_ macro.
	_write_barrier_;
/*
	An x86 store acts as an implicit release barrier. 
	The SSE streaming instructions or fast string operations are not used in this code; and thus
	we do not need an explicit hardware fence, like the sfence instruction for the x86 platform.
	Consider using a hardware fence when poring the code to another platform with weaker ordering than x86.
	In this case, a first candidate to employ might be MemoryBarrier when compiling with Microsoft compilers.
*/
	target = value;
}


#define acquire_read(val) _acquire_read_(val)
#define write_release(target, val) _write_release_(target, val)
/*
	It is also possible to use the following definitions when accessing the volatile m_rw_status
	lock status value using Microsoft compilers VC++8.0/9.0 for x86 platforms: 

		#define acquire_read(val) val
		#define write_release(target, val) target = val
	
	But we will use acquire_read(val) and write_release(target, val) definitions as
		
		#define acquire_read(val) _acquire_read_(val)
		#define write_release(target, val) _write_release_(target, val)

	for the code portability purposes, and in order to make our intent more obvious and
	to make it easier to get the memory barrier instructions in the correct place when porting the code.
	
	For the x86 chips with strong instruction ordering, it is possible
	to get benefit when compiling with Microsoft compilers VC++ 8.0/9.0 which can provide
	acquire/release semantic for volatile variable access. As it is shown in the article
	“Lockless Programming Considerations for Xbox 360 and Microsoft Windows”
	(http://msdn.microsoft.com/en-us/library/bb310595(VS.85).aspx), Visual C++ 2005 goes beyond
	standard C++ to define multi-threading-friendly semantics for volatile variable access.
	Starting with Visual C++ 2005, reads from volatile variables are defined to have read-acquire semantics,
	and writes to volatile variables are defined to have write-release semantics.
	
	This means that the compiler will not rearrange any reads and writes past them, and on Windows it will
	ensure that the CPU does not do so either on  hardware architectures with strong operation ordering.
	Practically this means that the new optimized Microsoft compilers will generate the same code
	in the same order for both acquire_read(val)/write_release(target, val) versions, see the pseudo-code:

	; j = acquire_read(m_rw_status); compiled using  #define acquire_read(val) _acquire_read_(val)
	mov	eax, DWORD PTR [edx+128]

	;j = acquire_read(m_rw_status); compiled using  #define acquire_read(val) val
	mov	eax, DWORD PTR [edx+128]

	...
	; write_release(m_helper_flag, HELPER_SIGNAL_SLOWDOWN);
	; compiled using #define write_release(target, val) _write_release_(target, val)
	mov	DWORD PTR [ebx+384], 1

	; write_release(m_helper_flag, HELPER_SIGNAL_SLOWDOWN);
	; compiled using #define write_release(target, val) target = val
	mov	DWORD PTR [ebx+384], 1
*/

#pragma warning(disable:4324)

class CACHE_ALIGN SHRW2
{
public:
	void acquireLockShared()
	{
		while( !try_interlocked_increment_reader())
		{
			wait_conditionally(m_rw_status, 0xFFFF, m_writer_release_event);
		}
	}

	void acquireLockExclusive()
	{
		::EnterCriticalSection(&m_cswriters);
		int spin_count = 0;
		while( acquire_interlocked_compare_exchange(&m_rw_status,0x1+0xFFFF,0x0) != 0x0)
		{
			if (++spin_count == MAX_WRITER_SPIN)
			{
				::ResetEvent(m_writer_release_event);

				interlocked_Or_release(&m_rw_status,0x1+0xFFFF);

				wait_conditionally(m_rw_status, 0x1+0xFFFF, m_reader_release_event);

				return;
			}
			else
			{
				pause
			}
		}
		::ResetEvent(m_writer_release_event);
	}

	void releaseLockShared()
	{
		if(interlocked_decrement_release(&m_rw_status) == 0x1+0xFFFF )
		{
			::SetEvent(m_reader_release_event);
		}
		else
		{
		}
	}

	void releaseLockExclusive()
	{
		interlocked_Xor_release(&m_rw_status, 0x1+0xFFFF);
		::SetEvent(m_writer_release_event);
		::LeaveCriticalSection(&m_cswriters);
	}

	SHRW2()
	{
		::InitializeCriticalSection(&m_cswriters);

		m_writer_release_event = ::CreateEvent(NULL, TRUE, FALSE, NULL);
		m_reader_release_event = ::CreateEvent(NULL, FALSE, FALSE, NULL);
		m_rw_status = 0; 
	}
	
	~SHRW2()
	{
		::DeleteCriticalSection(&m_cswriters);
		::CloseHandle(m_writer_release_event);
		::CloseHandle(m_reader_release_event);
	}

private:

	bool try_interlocked_increment_reader(void)
	{
		LONG i;
		LONG j;

		j = acquire_read(m_rw_status);
		int spin_count = 0;

		do {
			if (spin_count == MAX_READER_SPIN)
			{
				return false;
			}
			else
			{
				i = j & 0xFFFF;
				j = acquire_interlocked_compare_exchange(&m_rw_status,
											i + 1,
											i);
				spin_count ++;
			}
			
		} while (i != j);
		return true;
	}
	
	inline void wait_conditionally(volatile LONG& cond_variable, int cond_min, HANDLE wait_event)
	{
		while( acquire_read(cond_variable) > cond_min)
		{
			::WaitForSingleObject(wait_event, INFINITE);
		}
	}

	// should be set to 1 on a Uniprocessor PC
	enum { MAX_WRITER_SPIN = 1000 ,MAX_READER_SPIN = 1000 };

	CACHE_PADDING(1)

	volatile LONG m_rw_status;

	CACHE_PADDING(2) CACHE_ALIGN

	CRITICAL_SECTION m_cswriters;
	HANDLE m_writer_release_event;
	HANDLE m_reader_release_event;

};

#pragma warning(default:4324)
