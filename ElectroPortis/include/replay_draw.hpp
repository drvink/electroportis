#pragma once
#include <GL/gl.h>

#include "saver.hpp"

typedef enum gl_cmd {
    GLCOLOR3F,
    GLPUSHMATRIX,
    GLROTATEF,
    GLTRANSLATEF,
    GLPOPMATRIX,
    GLSCALEF,
    GLBEGIN,
    GLVERTEX2F,
    GLEND,
    GLCLEAR,
    GLFINISH
} gl_cmd;

#ifdef __cplusplus
#include "SHRWLocks.hpp"

struct gl_arg_t {
    gl_arg_t() {}

    gl_arg_t(const unsigned int ui)
        : ui(ui)
    {}

    gl_arg_t(const float f)
        : f(f)
    {}

    inline operator unsigned int() const { return ui; }
    inline operator float() const { return f; }
    gl_arg_t operator=(gl_arg_t& x) const { return *this; }

    union {
        // GLbitfield, GLenum, ...
        unsigned int ui;
        // GLfloat, ...
        float f;
    };
};

typedef std::vector<gl_arg_t> gl_args_t;
typedef std::pair<gl_cmd, gl_args_t> gl_record_t;

extern SHRW2 g_replay_list_lock;
extern std::vector<gl_record_t> g_replay_list;
#endif

#ifdef __cplusplus
extern "C" {
#endif
void wrap_glColor3f(GLfloat r, GLfloat g, GLfloat b, const wincount_t wincount);
void wrap_glPushMatrix(const wincount_t wincount);
void wrap_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z, const wincount_t wincount);
void wrap_glTranslatef(GLfloat x, GLfloat y, GLfloat z, const wincount_t wincount);
void wrap_glPopMatrix(const wincount_t wincount);
void wrap_glScalef(GLfloat x, GLfloat y, GLfloat z, const wincount_t wincount);
void wrap_glBegin(GLenum mode, const wincount_t wincount);
void wrap_glVertex2f(GLfloat x, GLfloat y, const wincount_t wincount);
void wrap_glEnd(const wincount_t wincount);
void wrap_glClear(GLbitfield mask, const wincount_t wincount);
void wrap_glFinish(const wincount_t wincount);
#ifdef __cplusplus
}
#endif

void replay_draw(void);
void clear_replay_list(void);
