#pragma once
#include <GL/gl.h>

#include "saver.hpp"

typedef union EPANOS_REG {
    uint8_t u8;
    int32_t i32;
    uint32_t u32;
    int64_t i64;
    uint64_t u64;
    float s;
    double d;
} EPANOS_REG;

typedef struct EPANOS_ARGS {
    EPANOS_REG v0;
    EPANOS_REG v1;
    EPANOS_REG a0;
    EPANOS_REG a1;
    EPANOS_REG a2;
    EPANOS_REG a3;
    EPANOS_REG a4;
    EPANOS_REG a5;
    EPANOS_REG a6;
    EPANOS_REG a7;
    EPANOS_REG f0;
    EPANOS_REG f2;
    EPANOS_REG f12;
    EPANOS_REG f13;
    EPANOS_REG f14;
    EPANOS_REG f15;
    EPANOS_REG f16;
    EPANOS_REG f17;
    EPANOS_REG f18;
    EPANOS_REG f19;
} EPANOS_ARGS;

#ifdef __cplusplus
extern "C" {
#endif
extern char oflag, bflag;

void init_ep(void);
void reshape__GiT1(const GLuint width, const GLuint height);
void createActTable__Gv(EPANOS_ARGS *ARGS);
void display__Gv(EPANOS_ARGS *ARGS, wincount_t wincount);
#ifdef __cplusplus
}
#endif
