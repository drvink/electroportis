#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <tchar.h>
#include <mmsystem.h>
#include <ScrnSave.h>

#ifndef NDEBUG
#define _CRTDBG_MAP_ALLOC
#endif
#include <stdlib.h>

#ifndef NDEBUG
#include <crtdbg.h>
#endif

#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <assert.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include "wglext.h"
