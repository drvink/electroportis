SPECIAL THANKS TO
=================
* David Tristram, for permitting distribution of ElectroPaint

* Pete Plank, for providing me with a copy of dbx
* Joseph Greathouse, for amazing feats in MIPS virtual address to physical
  address translation in IRIX symmon<sup>1</sup> before I decided to "simply"
  write a decompiler instead of doing a manual reverse engineering
* Alex Marshall, for some tips in deciphering one weird MIPS assembly idiom
  discovered by a local mom
* Hector Martin, for some tips that put me on the right path while solving some
  early problems
* Gregg Tavares and Andrew Richards, for OpenGL advice
* Peter Kliem, for the Android port
* Everyone at Hex-Rays
* The Otaru crew
* Scotch 'n soda
* All Capcom staff
* **AND YOU...**

[1] IP32 symmon is, for whatever reason, missing a v2p command even though the
    kernel itself already has to be able to do it to function!

NO THANKS TO
============
* [Those responsible][herb] for Visual C++ missing math library
  functions standardized in C99 [fourteen years ago][c99].  Remember,
  just "pressure your standards committee representatives" more, since
  VC++ is [focusing][vc++] on C++.

[herb]: http://herbsutter.com/2012/05/03/reader-qa-what-about-vc-and-c99/
[c99]: http://en.wikipedia.org/wiki/C99
[vc++]: http://www.bfilipek.com/2013/12/c-status-at-end-of-2013.html
