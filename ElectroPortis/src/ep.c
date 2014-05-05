/*
 * This is a decompilation of ElectroPaint, a work by David Tristram,
 * distributed with permission.  ElectroPaint is a US trademark owned by
 * Tristram Visual, a sole proprietorship operating in California.  Inquiries
 * may be directed to info@tristram.com and www.tristram.com.
 */
#include "stdafx.h"
#include "ep.h"
#include "replay_draw.hpp"
#include "saver.hpp"

#ifdef _MSC_VER
#if _MSC_VER < 1800
#include "vs2012_math/vs2012_math.h"
#endif

#include "rand48.h"
#pragma warning (disable:4101 4102 4700)
#else /* !_MSC_VER */
#include <math.h>
#include <stdlib.h>
#endif /* !_MSC_VER */

static float flt_100092A0 = 180.000000f;
static float flt_100092A4 = 240.000000f;
static float flt_100092A8 = 1.00000000f;
static float flt_1000929C = 60.0000000f;
static double dbl_100092E8 = 120.00000000000000;
static double dbl_100092E0 = 360.00000000000000;
static float flt_100092B8 = 0.500000000f;
static double dbl_10009300 = 1.0000000000000000;
static double dbl_10009320 = 10000.000000000000;
static float flt_100092B0 = 300.000000f;
static double dbl_10009308 = 2.0000000000000000;
static double dbl_100092F0 = -120.00000000000000;
static double dbl_100092D0 = 60.000000000000000;
static float flt_100092BC = -0.500000000f;
static double dbl_100092D8 = 0.50000000000000000;
static double dbl_10009318 = 0.010000000000000000;
static double dbl_10009310 = 300.00000000000000;
static float flt_100092B4 = -1.00000000f;
static float flt_100092AC = 2.00000000f;
static float flt_100092C8 = -4.00000000f;
static float flt_10009290 = 360.000000f;
static float flt_100092C4 = 52.0000000f;
static float flt_10009294 = -360.000000f;
static float flt_100092C0 = 0.600000024f;
static const char *aDoneReadingAni = "# done reading animation\n";
static const char *aDuration = "duration:";
static const char *asc_10009340 = " \t\n";
static const char *aVariance = "variance:";
static const char *aSeqloop = "seqloop:";
static const char *aActstop = "actstop:";
static const char *aGlxExtensionMi = "GLX extension missing";
static const char *asc_10009390 = "%[^\n]\n";
static const char *asc_10009388 = "#";
static const char *aS_0 = "%s\n";
static const char *aActset = "actset:";
static const char *aAtom = "ATOM";
static const char *aSeqkillall = "seqkillall:";
static const char *aD = "%d";
static const char *aM0_0 = "m > 0.0";
static const char *aF = "%f";
static const char *a_motif_wm_hint = "_MOTIF_WM_HINTS";
static const char *aEp_c = "ep.c++";
static const char *aSeqstop = "seqstop:";
static const char *aActresetall = "actresetall:";
static const char *aWarningSNotImp = "warning: %s not implemented\n";
static const char *aAbsframe = "absframe:";
static const char *aFatalErrorS = "fatal error: %s\n";
static const char *aSeqDAt_2f = "seq %d at %.2f\n";
static const char *aActlim1 = "actlim1:";
static const char *aSeqrepeat = "seqrepeat:";
static const char *aSDF = "%s %d, %f";
static const char *aActlim2 = "actlim2:";
static const char *aProcCurrentfra = "proc: currentFrame %.2f, seq %d,\tseqFrame %f, cmdtype %d, cmdFrame %f\n";
static const char *aCouldNotFindVa = "Could not find valid X visual";
static const char *aRanddelay = "randdelay:";
static const char *aElectropaint = "ElectroPaint";
static const char *aFrame = "frame:";
static const char *asc_10009338 = "\n";
static const char *aActstopall = "actstopall:";
static const char *aSF = "%s %f";
static const char *aSD = "%s %d";
static const char *aCouldNotFindAn = "Could not find any FBConfigs";
static const char *aWm_protocols = "WM_PROTOCOLS";
static const char *aReadingAnimati = "# reading animation...";
static const char *aRelframe = "relframe:";
static const char *aSeqdo = "seqdo:";
static const char *aBadCommandS = "bad command: %s";
static const char *aOnlyGlx1_2Supp = "Only GLX 1.2+ supported";
static const char *aS = "%s";
static const char *aActreset = "actreset:";
static const char *aDF = "%d, %f";
static const char *aCmdDDF = "  cmd %d,\t%d\t%f\n";
static const char *aSeqkill = "seqkill:";
static const char *aSeqname = "seqname:";
static const char *aWm_delete_wind = "WM_DELETE_WINDOW";
static const char *aWarningBadComm = "warning: bad command type (%d) in sequence cmd->seq\n";
static const char *aCouldNotFindXV = "Could not find X visual";
static const char *aCouldNotMakeGl = "Could not make GLX context current";

/* swapBuffers__Q2_10GLXWrapper6windowGv: no regmap info, emitting empty stmt at .text:100061FC */
/* sginap: no regmap info, emitting empty stmt at .text:10006208 */
/* __nw__GUi: no regmap info, emitting empty stmt at .text:1000631C */
/* __ct__Q2_10GLXWrapper6windowGPciN32: no regmap info, emitting empty stmt at .text:1000634C */
/* setRedraw__Q2_10GLXWrapper6windowGPGv_v: no regmap info, emitting empty stmt at .text:100063A8 */
/* setReshape__Q2_10GLXWrapper6windowGPGiT1_v: no regmap info, emitting empty stmt at .text:100063B8 */
/* setIdle__Q2_10GLXWrapper6windowGPGv_v: no regmap info, emitting empty stmt at .text:100063C8 */
/* setKeyboard__Q2_10GLXWrapper6windowGPGi_v: no regmap info, emitting empty stmt at .text:100063D8 */
/* mainLoop__Q2_10GLXWrapper6windowGv: no regmap info, emitting empty stmt at .text:100063E4 */
/* __process_needed_destructions__Gv: no regmap info, emitting empty stmt at .text:10006408 */
/* __assert: no regmap info, emitting empty stmt at .text:1000389C */
char oflag;
char bflag = 1;

static char aflag = 1;
static float square[8] = {-0.100000001f, -0.100000001f, 0.100000001f, -0.100000001f, 0.100000001f, 0.100000001f, -0.100000001f, 0.100000001f};
static float outlinecolRGBA[4] = {0.00000000f, 0.00000000f, 1.00000000f, 1.00000000f};
static float colRGBA[4] = {1.00000000f, 0.00000000f, 0.00000000f, 1.00000000f};
static char *defaultScript = "# created by mkmaster \n#\n# mello script\n#\n#\tDave Tristram\n#\n#\tthis script moves gently on the screen, and uses wheel to maintain\n#\ta 3D look.\n#\n#\n# constants\n#\nactset: 29, 1.0\t\t# \"full\"\nactset: 17, 0.0\t\t# \"auto\"\nactset: 18, 1.0\t\t# \"outline\"\n# actset: 73, 0.107258\t# \"whl\"\nactset: 31, 0.06\t# \"zoom\"\nactset: 38, 60.0\t# \"twst\"\n#actset: 80, 0.23\t# \"spn\" slow\nactset: 108, 1.2\t# \"size\"\nactset: 52, 40.0\t# \"n\"\n#\nseqdo: 1\t# wrist\nseqdo: 2\t# color\nseqdo: 3\t# wheel\nseqdo: 4\t# spin\nseqdo: 5\t# flip\nseqdo: 6\t# arm\nseqdo: 7\t# twist\nseqdo: 8\t# outline\n#\n# \n#\n# wrst anim: gentle radius modulation\n#\nseqname: 1\n#\nduration: 160\nactlim1: 101, -1.5\t\t# wrst\nactlim2: 101,  1.5\t\t# wrst\n#\n#\n#\n# color anim: hue and lightness motion\n#\n#\tthe hues chosen attempt to minimize \"green-out\"\n#\nseqname: 2\n#\nduration: 60\nactset: 127, 0.0\t\t# hue rate chan 0\n#\nactlim1: 123, 0.544053\t\t# hue chan 0 (just near cyan)\nactlim2: 123, 1.295\t\t# hue chan 0 (deep green)\n#\n#\nduration: 80\n#\nactlim1: 130, 0.0\t\t# lightness chan 0 (black)\nactlim2: 130, 1.0\t\t# lightness chan 0 (white)\n#\n#\n#\n# wheel anim: very slow, gentle rocking\n#\nseqname: 3\n#\nduration: 120\n#\nactlim1: 73, 0.137\t\t# wheel, real slow\nactlim2: 73, -0.137\t\t# wheel, real slow\n#\n#\n#\n# spin anim: somewhat fast occasionally\n#\nseqname: 4\n#\nduration: 100\n#\nactlim1: 80,  0.23\t\t# spn slow\nactlim2: 80, -0.23\t\t# spn slow\n#\nranddelay: 1000\n#\n#\nduration: 40\n#\nactlim1: 80,  5.23\t\t# spn fast\nactlim2: 80, -5.23\t\t# spn fast\n#\n#randdelay: 100\nranddelay: 200\n#\nseqloop:\n#\n#\n#\n# flip anim: somewhat fast occasionally\n#\nseqname: 5\n#\nduration: 50\n#\nactlim1: 87,  2.0\t\t# flip slow\nactlim2: 87, -2.0\t\t# flip slow\n#\n#randdelay: 500\nranddelay: 1200\n#\n#\nactlim1: 87,  10.0\t\t# flip fast\nactlim2: 87, -10.0\t\t# flip fast\n#\n#randdelay: 80\nranddelay: 220\n#\n#\nseqloop:\n#\n#\n#\n# arm anim: gentle radius modulation\n#\nseqname: 6\n#\nduration: 90\nactlim1: 94, -2.0\t\t# arm\nactlim2: 94,  2.0\t\t# arm\n#\n#\n#\n# twist anim:\n#\nseqname: 7\n#\n#duration: 1750\nduration: 2250\nactlim1: 38, 200.0\t\t# twst\nactlim2: 38, -200.0\t\t# twst\n#\n#\n#\n# outline anim: on and off infrequently, mostly on\n#\n#\nseqname: 8\n#\nduration: 5000\n#\nactlim1: 18, 0.2\t\t# outline\nactlim2: 18, 1.0\t\t# outline\n#\n#\n#\n# end of generated script";
static uintptr_t acttable[1024];
static uintptr_t *acttable_ptr = acttable;
static char sflag;
static float currentFrame;
static float relFrame;
static float baseFrame;
static float absFrame;
static float wheel;
static float dwheel;
static float x[128];
static float y[128];
static float dzoom[128];
static float arm[128];
static float wrist[128];
static float dtwist[128];
static float flip[128];
static float spin[128];
static float hue[128];
static float light[128];
static float alpha[128];
static float alphaout[128];
static float size[128];
static char outline[128];
static char fill[128];
static float gflip;
static float dflip;
static float gspin;
static float dspin;
static int n;
static int nlimit;
static float t;
static uintptr_t *seqList;
static uintptr_t *editSeq;
static int theWindow;
static int __Argv;
static int __Argc;

static void drawit__Gv(EPANOS_ARGS *ARGS, wincount_t wincount);
static void addToSeq__GP7animSeqP11animCommand(EPANOS_ARGS *ARGS);
static void animateacts__Gv(EPANOS_ARGS *ARGS);
static void stopAnimation__Gv(EPANOS_ARGS *ARGS);
static void readAnimation__Gv(EPANOS_ARGS *ARGS);
static void foldtwixt__GiPffT3(EPANOS_ARGS *ARGS);
static void drawshape__GiT1(EPANOS_ARGS *ARGS, wincount_t wincount);
static void tasteQueue__Gv(EPANOS_ARGS *ARGS);
static void hls_to_rgb__GfN21PfN24(EPANOS_ARGS *ARGS);
static void killSeq__GP7animSeq(EPANOS_ARGS *ARGS);
static void createBlankActAnim__Gv(EPANOS_ARGS *ARGS);
static void value__GfN21(EPANOS_ARGS *ARGS);
static void processCommand__GP11animCommand(EPANOS_ARGS *ARGS);
static void setacttargets__Gv(EPANOS_ARGS *ARGS);
static void twixt__GiPff(EPANOS_ARGS *ARGS);
static void exprand__Gf(EPANOS_ARGS *ARGS);

#if _MSC_VER < 1800
static double
trunc(double d)
{
    return (d > 0) ? floor(d) : ceil(d);
}
#endif // _MSC_VER

static int32_t
trunc_w_d(double x)
{
    double r = trunc(x);
    if (r > INT32_MAX || r < INT32_MIN)
        return INT32_MAX;
    else
        return (int32_t)r;
}

void
init_ep(void)
{
    EPANOS_ARGS ARGS;

    memset(acttable, 0, sizeof(acttable));
    createActTable__Gv(&ARGS);
    memset(outline, 1, sizeof(outline));
    memset(fill, 1, sizeof(fill));

    if (aflag == 1)
        readAnimation__Gv(&ARGS);

    srand48(0);
    srand48(time(NULL));
    nlimit = 52;
    wheel = 0.0f;
}

static void drawit__Gv(EPANOS_ARGS *ARGS, wincount_t wincount)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  double var_110;
  uint64_t var_90;
  double var_108;
  double var_50;
  uint64_t var_10;
  double var_100;
  double var_F8;
  uint64_t var_78;
  uint64_t var_18;
  double var_F0;
  double var_60;
  double var_E8;
  uint64_t var_20;
  double var_E0;
  uint64_t var_88;
  double var_D8;
  uint64_t var_28;
  double var_D0;
  double var_70;
  double var_C8;
  uint64_t var_30;
  uint64_t var_C0;
  double var_58;
  uint64_t var_B8;
  uint64_t var_38;
  uint64_t var_B0;
  uint64_t var_80;
  uint64_t var_A8;
  uint64_t var_40;
  uint64_t var_A0;
  double var_68;
  uint64_t var_98;
  uint64_t var_48;
  drawit__Gv:
  sp.u64 = (int32_t) (sp.u32 + -272);

  memcpy(&var_F8, &f22, 8);
  at.u64 = (int32_t) (1 << 16);
  var_C0 = s0.u64;
  at.u64 = 48152;
  var_B0 = gp.u64;
  gp.u64 = (int32_t) (t9.u32 + at.u32);
  memcpy(&f22, &flt_100092A8, 4);
  s0.u64 = (uint64_t) glColor3f;
  ARGS->f12.s = f22.s;
  t9.u64 = s0.u64;
  var_10 = s1.u64;
  ARGS->f13.s = f22.s;
  var_B8 = ra.u64;
  {
    ARGS->f14.s = f22.s;
    wrap_glColor3f((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  s1.u64 = (uint64_t) glPushMatrix;
  t9.u64 = s1.u64;
  memcpy(&var_70, &f20, 8);
  {
    var_30 = fp.u64;
    wrap_glPushMatrix(wincount);
  }
  f20.u32 = 0;
  fp.u64 = (uint64_t) glRotatef;
  memcpy(&var_58, &f24, 8);
  ARGS->f13.s = f22.s;
  ARGS->v0.u64 = (uint64_t) (&wheel);
  t9.u64 = fp.u64;
  var_40 = s3.u64;
  ARGS->f14.s = f20.s;
  memcpy(&ARGS->f12, &wheel, 4);
  {
    ARGS->f15.s = f20.s;
    wrap_glRotatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, (float) ARGS->f15.s, wincount);
  }
  memcpy(&f24, &flt_100092BC, 4);
  memcpy(&var_68, &f26, 8);
  memcpy(&var_60, &f30, 8);
  memcpy(&var_50, &f28, 8);
  var_38 = s6.u64;
  var_18 = s7.u64;
  var_20 = s5.u64;
  ARGS->a3.u64 = (uint64_t) (&nlimit);
  ARGS->a1.u64 = (uint64_t) (&n);
  ARGS->v1.u64 = nlimit;
  var_28 = s4.u64;
  ARGS->a4.u64 = n;
  if (((signed) 0) < ((signed) ARGS->v1.i64))
    ARGS->v1.u64 = 1;
  else
    ARGS->v1.u64 = 0;

  var_48 = s2.u64;
  var_A8 = ARGS->v1.u64;
  if (ARGS->v1.u64 == 0)
  {
    s3.u64 = ARGS->a4.u64;
    goto loc_100054E4;
  }
  else
    s3.u64 = ARGS->a4.u64;

  s2.u64 = (uint64_t) twixt__GiPff;
  s4.u64 = (uint64_t) glTranslatef;
  s5.u64 = (uint64_t) dzoom;
  {
    s1.u64 = (uint64_t) (&t);
    goto loc_100054B8;
  }
  loc_1000545C:
  if (((signed) s0.i64) < ((signed) 128))
    ARGS->a0.u64 = 1;
  else
    ARGS->a0.u64 = 0;


  if (ARGS->a0.u64 != 0)
  {
    t9.u64 = s2.u64;
    goto loc_10005470;
  }
  else
    t9.u64 = s2.u64;

  s0.u64 = (int32_t) (s0.u32 + -128);
  t9.u64 = s2.u64;
  loc_10005470:
  ARGS->a0.u64 = s0.u64;

  ARGS->a1.u64 = s5.u64;
  {
    memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
    twixt__GiPff(ARGS);
  }
  ARGS->f12.s = f20.s;
  t9.u64 = s4.u64;
  ARGS->f13.s = f20.s;
  {
    ARGS->f14.s = ARGS->f0.s * f24.s;
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->a3.u64 = (uint64_t) (&nlimit);
  ARGS->a1.u64 = (uint64_t) (&n);
  ARGS->a0.u64 = nlimit;
  ARGS->a4.u64 = n;
  s3.u64 = (int32_t) (s3.u32 + -1);
  ARGS->a0.u64 = (int32_t) (ARGS->a4.u32 - ARGS->a0.u32);
  if (((signed) ARGS->a0.i64) < ((signed) s3.i64))
    ARGS->a2.u64 = 1;
  else
    ARGS->a2.u64 = 0;

  if (ARGS->a2.u64 == 0)
  {
    if (((signed) ARGS->a0.i64) < ((signed) ARGS->a4.i64))
      ARGS->a2.u64 = 1;
    else
      ARGS->a2.u64 = 0;

    goto loc_100054E0;
  }
  else
    if (((signed) ARGS->a0.i64) < ((signed) ARGS->a4.i64))
    ARGS->a2.u64 = 1;
  else
    ARGS->a2.u64 = 0;


  loc_100054B8:
  ARGS->a2.u64 = (int32_t) (s3.i32 >> 31);

  ARGS->a0.u64 = s3.u64 ^ ARGS->a2.u64;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a2.u32);
  ARGS->a0.u64 = ARGS->a0.u64 & 127;
  ARGS->a0.u64 = ARGS->a0.u64 ^ ARGS->a2.u64;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a2.u32);
  if (ARGS->a0.i64 >= 0)
  {
    s0.u64 = ARGS->a0.u64;
    goto loc_1000545C;
  }
  else
    s0.u64 = ARGS->a0.u64;

  {
    s0.u64 = (int32_t) (ARGS->a0.u32 + 128);
    goto loc_1000545C;
  }
  loc_100054E0:
  var_A8 = ARGS->a2.u64;

  loc_100054E4:
  s5.u64 = (uint64_t) foldtwixt__GiPffT3;

  s1.u64 = (uint64_t) (&t);
  s4.u64 = (uint64_t) glTranslatef;
  at.u64 = var_A8;
  s2.u64 = (uint64_t) twixt__GiPff;
  s7.u64 = (uint64_t) colRGBA;
  s6.u64 = (uint64_t) outlinecolRGBA;
  if (at.u64 == 0)
  {
    s3.u64 = ARGS->a4.u64;
    goto loc_10005858;
  }
  else
    s3.u64 = ARGS->a4.u64;

  ARGS->a4.u64 = (uint64_t) (&colRGBA[2]);
  var_98 = ARGS->a4.u64;
  ARGS->a2.u64 = (uint64_t) (&colRGBA[1]);
  var_80 = ARGS->a2.u64;
  ARGS->v1.u64 = (uint64_t) (&outlinecolRGBA[2]);
  var_88 = ARGS->v1.u64;
  ARGS->v0.u64 = (uint64_t) (&outlinecolRGBA[1]);
  {
    var_90 = ARGS->v0.u64;
    goto loc_10005C10;
  }
  loc_1000552C:
  if (((signed) s0.i64) < ((signed) 128))
    ARGS->a5.u64 = 1;
  else
    ARGS->a5.u64 = 0;


  if (ARGS->a5.u64 != 0)
  {
    t9.u64 = s2.u64;
    goto loc_10005540;
  }
  else
    t9.u64 = s2.u64;

  s0.u64 = (int32_t) (s0.u32 + -128);
  t9.u64 = s2.u64;
  loc_10005540:
  ARGS->a1.u64 = (uint64_t) x;

  ARGS->a0.u64 = s0.u64;
  {
    memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
    twixt__GiPff(ARGS);
  }
  t9.u64 = s2.u64;
  ARGS->a1.u64 = (uint64_t) y;
  f30.s = ARGS->f0.s;
  ARGS->a0.u64 = s0.u64;
  {
    memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
    twixt__GiPff(ARGS);
  }
  memcpy(&var_D0, &ARGS->f0, 8);
  t9.u64 = s2.u64;
  ARGS->a1.u64 = (uint64_t) dzoom;
  ARGS->a0.u64 = s0.u64;
  {
    memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
    twixt__GiPff(ARGS);
  }
  t9.u64 = s2.u64;
  ARGS->a1.u64 = (uint64_t) arm;
  f24.s = ARGS->f0.s;
  ARGS->a0.u64 = s0.u64;
  {
    memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
    twixt__GiPff(ARGS);
  }
  memcpy(&var_C8, &ARGS->f0, 8);
  ARGS->a1.u64 = (uint64_t) wrist;
  t9.u64 = s2.u64;
  memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
  ARGS->a0.u64 = s0.u64;
  {
    memcpy(&var_100, &f24, 8);
    twixt__GiPff(ARGS);
  }
  t9.u64 = s2.u64;
  ARGS->a1.u64 = (uint64_t) size;
  f28.s = ARGS->f0.s;
  ARGS->a0.u64 = s0.u64;
  {
    memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
    twixt__GiPff(ARGS);
  }
  memcpy(&f24, &flt_10009290, 4);
  t9.u64 = s5.u64;
  f26.s = ARGS->f0.s;
  ARGS->a1.u64 = (uint64_t) spin;
  ARGS->a0.u64 = s0.u64;
  memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
  {
    ARGS->f15.s = f24.s;
    foldtwixt__GiPffT3(ARGS);
  }
  memcpy(&var_E0, &ARGS->f0, 8);
  ARGS->a1.u64 = (uint64_t) flip;
  t9.u64 = s5.u64;
  memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
  ARGS->a0.u64 = s0.u64;
  ARGS->f15.s = f24.s;
  {
    memcpy(&var_108, &f26, 8);
    foldtwixt__GiPffT3(ARGS);
  }
  memcpy(&var_D8, &ARGS->f0, 8);
  t9.u64 = s2.u64;
  ARGS->a1.u64 = (uint64_t) dtwist;
  ARGS->a0.u64 = s0.u64;
  {
    memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
    twixt__GiPff(ARGS);
  }
  t9.u64 = s5.u64;
  f24.s = ARGS->f0.s;
  ARGS->a1.u64 = (uint64_t) hue;
  ARGS->a0.u64 = s0.u64;
  memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
  {
    ARGS->f15.s = f22.s;
    foldtwixt__GiPffT3(ARGS);
  }
  ARGS->a1.u64 = (uint64_t) alpha;
  t9.u64 = s2.u64;
  memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
  f26.s = ARGS->f0.s;
  ARGS->a0.u64 = s0.u64;
  {
    memcpy(&var_110, &f24, 8);
    twixt__GiPff(ARGS);
  }
  memcpy(&var_E8, &ARGS->f0, 8);
  t9.u64 = s5.u64;
  ARGS->a1.u64 = (uint64_t) light;
  ARGS->a0.u64 = s0.u64;
  memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
  {
    ARGS->f15.s = f22.s;
    foldtwixt__GiPffT3(ARGS);
  }
  t9.u64 = s2.u64;
  ARGS->a1.u64 = (uint64_t) alphaout;
  f24.s = ARGS->f0.s;
  ARGS->a0.u64 = s0.u64;
  {
    memcpy(&ARGS->f14, (char *) (s1.u32 + 0), 4);
    twixt__GiPff(ARGS);
  }
  t9.u64 = (uint64_t) hls_to_rgb__GfN21PfN24;
  memcpy(&var_F0, &ARGS->f0, 8);
  ARGS->f12.s = f26.s;
  ARGS->f13.s = f24.s;
  ARGS->a4.u64 = var_80;
  ARGS->f14.s = f22.s;
  ARGS->a3.u64 = s7.u64;
  {
    ARGS->a5.u64 = var_98;
    hls_to_rgb__GfN21PfN24(ARGS);
  }
  memcpy(&f7, &flt_100092B8, 4);
  f5.s = f26.s + f7.s;
  memcpy(&f6, &dbl_10009300, 8);
  ARGS->f2.d = f5.s;
  memcpy(&f1, &var_F0, 8);
  if (f6.d < ARGS->f2.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  memcpy(&ARGS->f0, &var_E8, 8);
  memcpy((char *) (s6.u32 + 12), &f1, 4);
  memcpy((char *) (s7.u32 + 12), &ARGS->f0, 4);
  if (!EPANOS_fp_cond)
  {
    ARGS->f12.s = f5.s;
    goto loc_100056E8;
  }
  else
    ARGS->f12.s = f5.s;

  memcpy(&ARGS->f12, &flt_100092B4, 4);
  ARGS->f12.s = f5.s + ARGS->f12.s;
  loc_100056E8:
  t9.u64 = (uint64_t) hls_to_rgb__GfN21PfN24;

  ARGS->f13.s = f22.s - f24.s;
  ARGS->a4.u64 = var_90;
  ARGS->f14.s = f22.s;
  ARGS->a3.u64 = s6.u64;
  {
    ARGS->a5.u64 = var_88;
    hls_to_rgb__GfN21PfN24(ARGS);
  }
  t9.u64 = (uint64_t) glPushMatrix;
  {
    ;
    wrap_glPushMatrix(wincount);
  }
  t9.u64 = s4.u64;
  ARGS->f12.s = f30.s;
  memcpy(&ARGS->f13, &var_D0, 8);
  {
    ARGS->f14.s = f20.s;
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->f13.s = f20.s;
  t9.u64 = fp.u64;
  ARGS->f14.s = f20.s;
  memcpy(&ARGS->f12, &var_E0, 8);
  {
    ARGS->f15.s = f22.s;
    wrap_glRotatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, (float) ARGS->f15.s, wincount);
  }
  t9.u64 = s4.u64;
  ARGS->f12.s = f20.s;
  memcpy(&ARGS->f13, &var_C8, 8);
  {
    ARGS->f14.s = f20.s;
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->f13.s = f20.s;
  t9.u64 = fp.u64;
  ARGS->f14.s = f22.s;
  memcpy(&ARGS->f12, &var_D8, 8);
  {
    ARGS->f15.s = f20.s;
    wrap_glRotatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, (float) ARGS->f15.s, wincount);
  }
  ARGS->f12.s = f28.s;
  t9.u64 = s4.u64;
  ARGS->f13.s = f20.s;
  {
    ARGS->f14.s = f20.s;
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->a6.u64 = (uint64_t) fill;
  ARGS->a6.u64 = (int32_t) (s0.u32 + ARGS->a6.u32);
  var_78 = ARGS->a6.u64;
  ARGS->a6.u64 = *((int8_t *) (ARGS->a6.u32 + 0));
  if (ARGS->a6.u64 == 0)
  {
    ARGS->a7.u64 = (uint64_t) outline;
    goto loc_100057BC;
  }
  else
    ARGS->a7.u64 = (uint64_t) outline;

  t9.u64 = (uint64_t) glColor3f;
  memcpy(&ARGS->f12, (char *) (s7.u32 + 0), 4);
  memcpy(&ARGS->f13, (char *) (s7.u32 + 4), 4);
  {
    memcpy(&ARGS->f14, (char *) (s7.u32 + 8), 4);
    wrap_glColor3f((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  t9.u64 = (uint64_t) drawshape__GiT1;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = 1;
    drawshape__GiT1(ARGS, wincount);
  }
  ARGS->a7.u64 = (uint64_t) outline;
  loc_100057BC:
  ARGS->a7.u64 = (int32_t) (s0.u32 + ARGS->a7.u32);

  var_A0 = ARGS->a7.u64;
  ARGS->a7.u64 = *((int8_t *) (ARGS->a7.u32 + 0));
  if (ARGS->a7.u64 == 0)
  {
    t9.u64 = (uint64_t) glPopMatrix;
    goto loc_100057F8;
  }
  else
    t9.u64 = (uint64_t) glPopMatrix;

  t9.u64 = (uint64_t) glColor3f;
  memcpy(&ARGS->f12, (char *) (s6.u32 + 0), 4);
  memcpy(&ARGS->f13, (char *) (s6.u32 + 4), 4);
  {
    memcpy(&ARGS->f14, (char *) (s6.u32 + 8), 4);
    wrap_glColor3f((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  t9.u64 = (uint64_t) drawshape__GiT1;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = 0;
    drawshape__GiT1(ARGS, wincount);
  }
  t9.u64 = (uint64_t) glPopMatrix;
  loc_100057F8:
  {
    ;
    wrap_glPopMatrix(wincount);
  }

  ARGS->a1.u64 = (uint64_t) (&n);
  ARGS->a3.u64 = (uint64_t) (&nlimit);
  t4.u64 = (uint64_t) (&sflag);
  t4.u64 = sflag;
  if (t4.u64 == 0)
  {
    t9.u64 = (uint64_t) glScalef;
    goto loc_100058AC;
  }
  else
    t9.u64 = (uint64_t) glScalef;

  loc_10005818:
  t6.u64 = nlimit;

  s3.u64 = (int32_t) (s3.u32 + -1);
  t5.u64 = n;
  ARGS->a2.u64 = (int32_t) (s3.i32 >> 31);
  ARGS->a0.u64 = s3.u64 ^ ARGS->a2.u64;
  t5.u64 = (int32_t) (t5.u32 - t6.u32);
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a2.u32);
  if (((signed) t5.i64) < ((signed) s3.i64))
    t5.u64 = 1;
  else
    t5.u64 = 0;

  ARGS->a0.u64 = ARGS->a0.u64 & 127;
  ARGS->a0.u64 = ARGS->a0.u64 ^ ARGS->a2.u64;
  if (t5.u64 == 0)
  {
    ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a2.u32);
    goto loc_10005858;
  }
  else
    ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a2.u32);

  loc_10005848:
  if (ARGS->a0.i64 >= 0)
  {
    s0.u64 = ARGS->a0.u64;
    goto loc_1000552C;
  }
  else
    s0.u64 = ARGS->a0.u64;


  {
    s0.u64 = (int32_t) (ARGS->a0.u32 + 128);
    goto loc_1000552C;
  }
  loc_10005858:
  s2.u64 = var_48;

  s3.u64 = var_40;
  s6.u64 = var_38;
  fp.u64 = var_30;
  s4.u64 = var_28;
  s0.u64 = var_C0;
  s5.u64 = var_20;
  s7.u64 = var_18;
  s1.u64 = var_10;
  memcpy(&f20, &var_70, 8);
  memcpy(&f26, &var_68, 8);
  memcpy(&f30, &var_60, 8);
  t9.u64 = (uint64_t) glPopMatrix;
  memcpy(&f22, &var_F8, 8);
  memcpy(&f24, &var_58, 8);
  {
    memcpy(&f28, &var_50, 8);
    wrap_glPopMatrix(wincount);
  }
  ra.u64 = var_B8;
  gp.u64 = var_B0;
  {
    sp.u64 = (int32_t) (sp.u32 + 272);
    return;
  }
  loc_100058AC:
  ARGS->f12.s = f22.s;

  memcpy(&ARGS->f13, &flt_100092B4, 4);
  {
    ARGS->f14.s = f22.s;
    wrap_glScalef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  t9.u64 = (uint64_t) glPushMatrix;
  {
    ;
    wrap_glPushMatrix(wincount);
  }
  t9.u64 = s4.u64;
  ARGS->f12.s = f30.s;
  memcpy(&ARGS->f13, &var_D0, 8);
  {
    ARGS->f14.s = f20.s;
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->f13.s = f20.s;
  t9.u64 = fp.u64;
  ARGS->f14.s = f20.s;
  memcpy(&ARGS->f12, &var_E0, 8);
  {
    ARGS->f15.s = f22.s;
    wrap_glRotatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, (float) ARGS->f15.s, wincount);
  }
  t9.u64 = s4.u64;
  ARGS->f12.s = f20.s;
  memcpy(&ARGS->f13, &var_C8, 8);
  {
    ARGS->f14.s = f20.s;
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->f13.s = f20.s;
  t9.u64 = fp.u64;
  ARGS->f14.s = f22.s;
  memcpy(&ARGS->f12, &var_D8, 8);
  {
    ARGS->f15.s = f20.s;
    wrap_glRotatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, (float) ARGS->f15.s, wincount);
  }
  ARGS->f12.s = f28.s;
  t9.u64 = s4.u64;
  ARGS->f13.s = f20.s;
  {
    ARGS->f14.s = f20.s;
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  memcpy(&ARGS->f13, &var_108, 8);
  t9.u64 = (uint64_t) glScalef;
  ARGS->f14.s = f22.s;
  {
    ARGS->f12.s = ARGS->f13.s;
    wrap_glScalef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->a1.u64 = var_78;
  ARGS->a1.u64 = *((int8_t *) (ARGS->a1.u32 + 0));
  if (ARGS->a1.u64 == 0)
  {
    ARGS->a2.u64 = var_A0;
    goto loc_10005980;
  }
  else
    ARGS->a2.u64 = var_A0;

  t9.u64 = (uint64_t) glColor3f;
  memcpy(&ARGS->f12, (char *) (s7.u32 + 0), 4);
  memcpy(&ARGS->f13, (char *) (s7.u32 + 4), 4);
  {
    memcpy(&ARGS->f14, (char *) (s7.u32 + 8), 4);
    wrap_glColor3f((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  t9.u64 = (uint64_t) drawshape__GiT1;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = 1;
    drawshape__GiT1(ARGS, wincount);
  }
  ARGS->a2.u64 = var_A0;
  loc_10005980:
  ARGS->a2.u64 = *((int8_t *) (ARGS->a2.u32 + 0));

  if (ARGS->a2.u64 == 0)
  {
    t9.u64 = (uint64_t) glPopMatrix;
    goto loc_100059B4;
  }
  else
    t9.u64 = (uint64_t) glPopMatrix;

  t9.u64 = (uint64_t) glColor3f;
  memcpy(&ARGS->f12, (char *) (s6.u32 + 0), 4);
  memcpy(&ARGS->f13, (char *) (s6.u32 + 4), 4);
  {
    memcpy(&ARGS->f14, (char *) (s6.u32 + 8), 4);
    wrap_glColor3f((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  t9.u64 = (uint64_t) drawshape__GiT1;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = 0;
    drawshape__GiT1(ARGS, wincount);
  }
  t9.u64 = (uint64_t) glPopMatrix;
  loc_100059B4:
  {
    ;
    wrap_glPopMatrix(wincount);
  }

  ARGS->f13.s = f20.s;
  t9.u64 = fp.u64;
  ARGS->f14.s = f20.s;
  memcpy(&ARGS->f12, &flt_100092A0, 4);
  {
    ARGS->f15.s = f22.s;
    wrap_glRotatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, (float) ARGS->f15.s, wincount);
  }
  t9.u64 = (uint64_t) glPushMatrix;
  {
    ;
    wrap_glPushMatrix(wincount);
  }
  t9.u64 = s4.u64;
  ARGS->f12.s = f30.s;
  memcpy(&ARGS->f13, &var_D0, 8);
  {
    ARGS->f14.s = f20.s;
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->f13.s = f20.s;
  t9.u64 = fp.u64;
  ARGS->f14.s = f20.s;
  memcpy(&ARGS->f12, &var_E0, 8);
  {
    ARGS->f15.s = f22.s;
    wrap_glRotatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, (float) ARGS->f15.s, wincount);
  }
  t9.u64 = s4.u64;
  ARGS->f12.s = f20.s;
  memcpy(&ARGS->f13, &var_C8, 8);
  {
    ARGS->f14.s = f20.s;
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->f13.s = f20.s;
  t9.u64 = fp.u64;
  ARGS->f14.s = f22.s;
  memcpy(&ARGS->f12, &var_D8, 8);
  {
    ARGS->f15.s = f20.s;
    wrap_glRotatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, (float) ARGS->f15.s, wincount);
  }
  ARGS->f12.s = f28.s;
  t9.u64 = s4.u64;
  ARGS->f13.s = f20.s;
  {
    ARGS->f14.s = f20.s;
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  memcpy(&ARGS->f13, &var_108, 8);
  t9.u64 = (uint64_t) glScalef;
  ARGS->f14.s = f22.s;
  {
    ARGS->f12.s = ARGS->f13.s;
    wrap_glScalef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->a3.u64 = var_78;
  ARGS->a3.u64 = *((int8_t *) (ARGS->a3.u32 + 0));
  if (ARGS->a3.u64 == 0)
  {
    t9.u64 = (uint64_t) glColor3f;
    goto loc_10005A90;
  }
  else
    t9.u64 = (uint64_t) glColor3f;

  memcpy(&ARGS->f12, (char *) (s7.u32 + 0), 4);
  memcpy(&ARGS->f13, (char *) (s7.u32 + 4), 4);
  {
    memcpy(&ARGS->f14, (char *) (s7.u32 + 8), 4);
    wrap_glColor3f((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  t9.u64 = (uint64_t) drawshape__GiT1;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = 1;
    drawshape__GiT1(ARGS, wincount);
  }
  loc_10005A90:
  ARGS->a4.u64 = var_A0;

  ARGS->a4.u64 = *((int8_t *) (ARGS->a4.u32 + 0));
  if (ARGS->a4.u64 == 0)
  {
    t9.u64 = (uint64_t) glColor3f;
    goto loc_10005AC0;
  }
  else
    t9.u64 = (uint64_t) glColor3f;

  memcpy(&ARGS->f12, (char *) (s6.u32 + 0), 4);
  memcpy(&ARGS->f13, (char *) (s6.u32 + 4), 4);
  {
    memcpy(&ARGS->f14, (char *) (s6.u32 + 8), 4);
    wrap_glColor3f((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  t9.u64 = (uint64_t) drawshape__GiT1;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = 0;
    drawshape__GiT1(ARGS, wincount);
  }
  loc_10005AC0:
  t9.u64 = (uint64_t) glPopMatrix;

  {
    ;
    wrap_glPopMatrix(wincount);
  }
  t9.u64 = (uint64_t) glScalef;
  ARGS->f12.s = f22.s;
  memcpy(&ARGS->f13, &flt_100092B4, 4);
  {
    ARGS->f14.s = f22.s;
    wrap_glScalef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  t9.u64 = (uint64_t) glPushMatrix;
  {
    ;
    wrap_glPushMatrix(wincount);
  }
  t9.u64 = s4.u64;
  ARGS->f12.s = f30.s;
  memcpy(&ARGS->f13, &var_D0, 8);
  {
    ARGS->f14.s = f20.s;
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->f13.s = f20.s;
  t9.u64 = fp.u64;
  ARGS->f14.s = f20.s;
  memcpy(&ARGS->f12, &var_E0, 8);
  {
    ARGS->f15.s = f22.s;
    wrap_glRotatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, (float) ARGS->f15.s, wincount);
  }
  t9.u64 = s4.u64;
  ARGS->f12.s = f20.s;
  memcpy(&ARGS->f13, &var_C8, 8);
  {
    ARGS->f14.s = f20.s;
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->f13.s = f20.s;
  t9.u64 = fp.u64;
  ARGS->f14.s = f22.s;
  memcpy(&ARGS->f12, &var_D8, 8);
  {
    ARGS->f15.s = f20.s;
    wrap_glRotatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, (float) ARGS->f15.s, wincount);
  }
  ARGS->f12.s = f28.s;
  t9.u64 = s4.u64;
  ARGS->f13.s = f20.s;
  {
    ARGS->f14.s = f20.s;
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  memcpy(&ARGS->f13, &var_108, 8);
  t9.u64 = (uint64_t) glScalef;
  ARGS->f14.s = f22.s;
  {
    ARGS->f12.s = ARGS->f13.s;
    wrap_glScalef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->a5.u64 = var_78;
  ARGS->a5.u64 = *((int8_t *) (ARGS->a5.u32 + 0));
  if (ARGS->a5.u64 == 0)
  {
    t9.u64 = (uint64_t) glColor3f;
    goto loc_10005B9C;
  }
  else
    t9.u64 = (uint64_t) glColor3f;

  memcpy(&ARGS->f12, (char *) (s7.u32 + 0), 4);
  memcpy(&ARGS->f13, (char *) (s7.u32 + 4), 4);
  {
    memcpy(&ARGS->f14, (char *) (s7.u32 + 8), 4);
    wrap_glColor3f((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  t9.u64 = (uint64_t) drawshape__GiT1;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = 1;
    drawshape__GiT1(ARGS, wincount);
  }
  loc_10005B9C:
  ARGS->a6.u64 = var_A0;

  ARGS->a6.u64 = *((int8_t *) (ARGS->a6.u32 + 0));
  if (ARGS->a6.u64 == 0)
  {
    t9.u64 = (uint64_t) glColor3f;
    goto loc_10005BCC;
  }
  else
    t9.u64 = (uint64_t) glColor3f;

  memcpy(&ARGS->f12, (char *) (s6.u32 + 0), 4);
  memcpy(&ARGS->f13, (char *) (s6.u32 + 4), 4);
  {
    memcpy(&ARGS->f14, (char *) (s6.u32 + 8), 4);
    wrap_glColor3f((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  t9.u64 = (uint64_t) drawshape__GiT1;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = 0;
    drawshape__GiT1(ARGS, wincount);
  }
  loc_10005BCC:
  t9.u64 = (uint64_t) glPopMatrix;

  {
    ;
    wrap_glPopMatrix(wincount);
  }
  ARGS->f13.s = f20.s;
  t9.u64 = fp.u64;
  ARGS->f14.s = f20.s;
  memcpy(&ARGS->f12, &var_110, 8);
  {
    ARGS->f15.s = f22.s;
    wrap_glRotatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, (float) ARGS->f15.s, wincount);
  }
  t9.u64 = s4.u64;
  ARGS->f12.s = f20.s;
  ARGS->f13.s = f20.s;
  {
    memcpy(&ARGS->f14, &var_100, 8);
    wrap_glTranslatef((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  ARGS->a1.u64 = (uint64_t) (&n);
  {
    ARGS->a3.u64 = (uint64_t) (&nlimit);
    goto loc_10005818;
  }
  loc_10005C10:
  ARGS->a2.u64 = (int32_t) (s3.i32 >> 31);

  ARGS->a0.u64 = s3.u64 ^ ARGS->a2.u64;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a2.u32);
  ARGS->a0.u64 = ARGS->a0.u64 & 127;
  ARGS->a0.u64 = ARGS->a0.u64 ^ ARGS->a2.u64;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a2.u32);
  {
    ;
    goto loc_10005848;
  }
}

static void addToSeq__GP7animSeqP11animCommand(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  addToSeq__GP7animSeqP11animCommand:
  *((uint32_t *) (ARGS->a1.u32 + 16)) = ARGS->a0.u32;

  ARGS->a4.u64 = *((int32_t *) (ARGS->a0.u32 + 24));
  if (ARGS->a4.u64 == 0)
  {
    memcpy(&f4, (char *) (ARGS->a1.u32 + 8), 4);
    goto loc_10003994;
  }
  else
    memcpy(&f4, (char *) (ARGS->a1.u32 + 8), 4);

  memcpy(&ARGS->f0, (char *) (ARGS->a4.u32 + 8), 4);
  if (f4.s < ARGS->f0.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (EPANOS_fp_cond)
  {
    ARGS->a3.u64 = *((int32_t *) (ARGS->a4.u32 + 20));
    goto loc_10003988;
  }
  else
    ARGS->a3.u64 = *((int32_t *) (ARGS->a4.u32 + 20));

  if (ARGS->a3.u64 == 0)
  {
    ;
    goto loc_100039A0;
  }
  else
    ;

  loc_10003930:
  memcpy(&f1, (char *) (ARGS->a3.u32 + 8), 4);

  if (f4.s < f1.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (EPANOS_fp_cond)
  {
    ;
    goto loc_1000395C;
  }
  else
    ;

  ARGS->a4.u64 = ARGS->a3.u64;
  ARGS->a3.u64 = *((int32_t *) (ARGS->a3.u32 + 20));
  if (ARGS->a3.u64 != 0)
  {
    ;
    goto loc_10003930;
  }
  else
    ;

  {
    at.u64 = *((int32_t *) (ARGS->a1.u32 + 20));
    goto loc_10003968;
  }
  loc_1000395C:
  *((uint32_t *) (ARGS->a1.u32 + 20)) = ARGS->a3.u32;

  *((uint32_t *) (ARGS->a4.u32 + 20)) = ARGS->a1.u32;
  at.u64 = *((int32_t *) (ARGS->a1.u32 + 20));
  loc_10003968:
  if (at.u64 != 0)
  {
    ;
    goto locret_10003980;
  }
  else
    ;


  ARGS->v0.u64 = *((int32_t *) (ARGS->a0.u32 + 32));
  *((uint32_t *) (ARGS->v0.u32 + 20)) = ARGS->a1.u32;
  {
    *((uint32_t *) (ARGS->a0.u32 + 32)) = ARGS->a1.u32;
    return;
  }
  locret_10003980:
  {
    ;
    return;
  }

  loc_10003988:
  *((uint32_t *) (ARGS->a1.u32 + 20)) = ARGS->a4.u32;

  {
    *((uint32_t *) (ARGS->a0.u32 + 24)) = ARGS->a1.u32;
    return;
  }
  loc_10003994:
  *((uint32_t *) (ARGS->a0.u32 + 32)) = ARGS->a1.u32;

  {
    *((uint32_t *) (ARGS->a0.u32 + 24)) = ARGS->a1.u32;
    return;
  }
  loc_100039A0:
  *((uint32_t *) (ARGS->a4.u32 + 20)) = ARGS->a1.u32;

  {
    *((uint32_t *) (ARGS->a0.u32 + 32)) = ARGS->a1.u32;
    return;
  }
}

static void animateacts__Gv(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  animateacts__Gv:
  ARGS->v0.u64 = 45932;

  f9.u64 = 0;
  at.u64 = (int32_t) (t9.u32 + ARGS->v0.u32);
  ARGS->a3.u64 = 0;
  {
    ARGS->a4.u64 = acttable_ptr;
    goto loc_10005C54;
  }
  loc_10005C4C:
  memcpy((char *) (ARGS->a2.u32 + 24), &f5, 4);

  loc_10005C50:
  if (ARGS->a5.u64 == 0)
  {
    ARGS->a3.u64 = (int32_t) (ARGS->a3.u32 + 1);
    goto locret_10005CB8;
  }
  else
    loc_10005C54:
  ARGS->a3.u64 = (int32_t) (ARGS->a3.u32 + 1);



  ARGS->a2.u64 = *((int32_t *) (ARGS->a4.u32 + 0));
  ARGS->a4.u64 = (int32_t) (ARGS->a4.u32 + 4);
  if (ARGS->a2.u64 == 0)
  {
    if (((signed) ARGS->a3.i64) < ((signed) 1024))
      ARGS->a5.u64 = 1;
    else
      ARGS->a5.u64 = 0;

    goto loc_10005C50;
  }
  else
    if (((signed) ARGS->a3.i64) < ((signed) 1024))
    ARGS->a5.u64 = 1;
  else
    ARGS->a5.u64 = 0;


  memcpy(&f8, (char *) (ARGS->a2.u32 + 24), 4);
  memcpy(&f7, (char *) (ARGS->a2.u32 + 4), 4);
  ARGS->v1.u64 = *((int8_t *) (ARGS->a2.u32 + 0));
  memcpy(&f4, (char *) (ARGS->a2.u32 + 8), 4);
  ARGS->a6.u64 = *((int8_t *) (ARGS->a2.u32 + 1));
  if (ARGS->v1.u64 == 0)
  {
    memcpy(&f6, (char *) (ARGS->a2.u32 + 20), 4);
    goto loc_10005C50;
  }
  else
    memcpy(&f6, (char *) (ARGS->a2.u32 + 20), 4);

  if (ARGS->a6.u64 == 0)
  {
    ;
    goto loc_10005C50;
  }
  else
    ;

  f5.s = f6.s + f8.s;
  ARGS->f0.s = f4.s - f5.s;
  ARGS->f0.s = f7.s * ARGS->f0.s;
  ARGS->f0.d = ARGS->f0.s;
  if (ARGS->f0.d < f9.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    ;
    goto loc_10005C4C;
  }
  else
    ;

  f5.s = f4.s;
  {
    *((uint8_t *) (ARGS->a2.u32 + 1)) = 0;
    goto loc_10005C4C;
  }
  locret_10005CB8:
  {
    ;
    return;
  }

}

static void stopAnimation__Gv(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  stopAnimation__Gv:
  ARGS->v0.u64 = 51120;

  at.u64 = (int32_t) (t9.u32 + ARGS->v0.u32);
  ARGS->a3.u64 = 0;
  ARGS->a2.u64 = acttable_ptr;
  ARGS->a5.u64 = *((int32_t *) (ARGS->a2.u32 + 0));
  loc_10004804:
  ARGS->a2.u64 = (int32_t) (ARGS->a2.u32 + 4);

  ARGS->a3.u64 = (int32_t) (ARGS->a3.u32 + 1);
  if (ARGS->a5.u64 == 0)
  {
    if (((signed) ARGS->a3.i64) < ((signed) 1024))
      ARGS->a4.u64 = 1;
    else
      ARGS->a4.u64 = 0;

    goto loc_10004818;
  }
  else
    if (((signed) ARGS->a3.i64) < ((signed) 1024))
    ARGS->a4.u64 = 1;
  else
    ARGS->a4.u64 = 0;


  *((uint8_t *) (ARGS->a5.u32 + 0)) = 0;
  loc_10004818:
  if (ARGS->a4.u64 != 0)
  {
    ARGS->a5.u64 = *((int32_t *) (ARGS->a2.u32 + 0));
    goto loc_10004804;
    ARGS->a5.u64 = *((int32_t *) (ARGS->a2.u32 + 0));
  }


  {
    ;
    return;
  }
}

static void readAnimation__Gv(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  int var_2E0;
  uint64_t var_60;
  uint64_t var_D8;
  uint64_t var_58;
  uint64_t var_18;
  double var_50;
  uint64_t var_48;
  uint64_t var_C8;
  uint64_t var_20;
  uint64_t var_C0;
  uint64_t var_30;
  uint64_t var_B8;
  uint64_t var_B0;
  char var_2D8[256];
  uint64_t var_A8;
  uint64_t var_A0;
  uint64_t var_40;
  uint64_t var_98;
  uint64_t var_90;
  uint64_t var_28;
  uint64_t var_88;
  uint64_t var_80;
  uint64_t var_D0;
  uint64_t var_78;
  uint64_t var_8;
  uint64_t var_70;
  uint64_t var_38;
  uint64_t var_68;
  uint64_t var_10;
  char var_1D8[256];
  readAnimation__Gv:
  sp.u64 = (int32_t) (sp.u32 + -736);

  var_C0 = s3.u64;
  s3.u64 = 54768;
  var_D0 = gp.u64;
  gp.u64 = (int32_t) (t9.u32 + s3.u32);
  s3.u64 = (uint64_t) (&oflag);
  var_C8 = s0.u64;
  ARGS->a0.u64 = oflag;
  s0.u64 = (uint64_t) defaultScript;
  var_18 = ra.u64;
  if (ARGS->a0.u64 == 0)
  {
    s0.u64 = defaultScript;
    goto loc_100039F4;
  }
  else
    s0.u64 = defaultScript;

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) 268500992;
  {
    ARGS->a0.u64 = (uint64_t) (&aReadingAnimati[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64);
  }
  ARGS->a0.u64 = oflag;
  loc_100039F4:
  memcpy(&var_50, &f20, 8);

  var_8 = s5.u64;
  var_10 = s1.u64;
  if (ARGS->a0.u64 == 0)
  {
    var_20 = s6.u64;
    goto loc_10003A14;
  }
  else
    var_20 = s6.u64;

  t9.u64 = (uint64_t) printf;
  {
    ARGS->a0.u64 = (uint64_t) asc_10009338;
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64);
  }
  loc_10003A14:
  s5.u64 = (uint64_t) sscanf;

  s1.u64 = (uint64_t) strcmp;
  s6.u64 = (uint64_t) strcspn;
  var_30 = s7.u64;
  var_38 = s4.u64;
  var_40 = fp.u64;
  var_48 = s2.u64;
  f20.u32 = 0;
  ARGS->a1.u64 = var_2E0;
  {
    var_A8 = ARGS->a1.u64;
    goto loc_10003B54;
  }
  loc_10003A40:
  ARGS->a0.u64 = (uint64_t) asc_10009388;

  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a2.u64 = 1;
    ARGS->v0.u64 = (int) strncmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (unsigned int) ARGS->a2.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a0.u64 = *((int8_t *) (s3.u32 + 0));
    goto loc_100047C0;
  }
  else
    ARGS->a0.u64 = *((int8_t *) (s3.u32 + 0));

  if (ARGS->a0.u64 == 0)
  {
    t9.u64 = (uint64_t) free;
    goto loc_10003A78;
  }
  else
    t9.u64 = (uint64_t) free;

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) 268500992;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aBadCommandS[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64);
  }
  t9.u64 = (uint64_t) free;
  loc_10003A78:
  {
    ARGS->a0.u64 = s2.u64;
    free((void *) ARGS->a0.u64);
  }

  ARGS->a1.u64 = 1;
  var_58 = ARGS->a1.u64;
  ARGS->a2.u64 = var_58;
  loc_10003A8C:
  var_60 = ARGS->a2.u64;

  loc_10003A90:
  ARGS->a3.u64 = var_60;

  loc_10003A94:
  var_68 = ARGS->a3.u64;

  loc_10003A98:
  ARGS->a4.u64 = var_68;

  loc_10003A9C:
  var_70 = ARGS->a4.u64;

  ARGS->a5.u64 = var_70;
  loc_10003AA4:
  var_78 = ARGS->a5.u64;

  loc_10003AA8:
  ARGS->a6.u64 = var_78;

  loc_10003AAC:
  var_80 = ARGS->a6.u64;

  ARGS->a7.u64 = var_80;
  loc_10003AB4:
  var_88 = ARGS->a7.u64;

  loc_10003AB8:
  fp.u64 = var_88;

  loc_10003ABC:
  s7.u64 = fp.u64;

  loc_10003AC0:
  s4.u64 = s7.u64;

  loc_10003AC4:
  fp.u64 = s4.u64;

  loc_10003AC8:
  s7.u64 = fp.u64;

  loc_10003ACC:
  s4.u64 = s7.u64;

  loc_10003AD0:
  s7.u64 = s4.u64;

  loc_10003AD4:
  fp.u64 = s7.u64;

  loc_10003AD8:
  s7.u64 = fp.u64;

  loc_10003ADC:
  s4.u64 = s7.u64;

  loc_10003AE0:
  if (s4.u64 == 0)
  {
    t9.u64 = s5.u64;
    goto loc_10003DA4;
  }
  else
    loc_10003AE4:
  t9.u64 = s5.u64;



  loc_10003AE8:
  ARGS->a0.u64 = s0.u64;

  ARGS->a2.u64 = (uint64_t) (&var_1D8[0]);
  {
    ARGS->a1.u64 = (uint64_t) asc_10009390;
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (char *) ARGS->a2.u64);
  }
  t4.u64 = *((int8_t *) (s3.u32 + 0));
  if (t4.u64 == 0)
  {
    t5.u64 = (uint64_t) (&bflag);
    goto loc_10003B18;
  }
  else
    t5.u64 = (uint64_t) (&bflag);

  t9.u64 = (uint64_t) printf;
  ARGS->a1.u64 = (uint64_t) (&var_1D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) aS_0;
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64);
  }
  t5.u64 = (uint64_t) (&bflag);
  loc_10003B18:
  t5.u64 = bflag;

  s2.u64 = (uint64_t) strlen;
  if (t5.u64 == 0)
  {
    var_1D8[0] = 0;
    goto loc_10003DD8;
  }
  else
    var_1D8[0] = 0;

  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009338;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  t9.u64 = s2.u64;
  s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
  s0.u64 = (int32_t) (s0.u32 + 1);
  {
    ARGS->a0.u64 = s0.u64;
    ARGS->v0.u64 = (unsigned int) strlen((const char *) ARGS->a0.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a1.u64 = (uint64_t) seqList;
    goto loc_100041A4;
  }
  else
    ARGS->a1.u64 = (uint64_t) seqList;

  loc_10003B54:
  var_58 = 0;

  var_60 = 0;
  var_68 = 0;
  var_70 = 0;
  var_78 = 0;
  var_80 = 0;
  var_88 = 0;
  var_90 = 0;
  var_98 = 0;
  s2.u64 = 0;
  var_A0 = 0;
  fp.u64 = 0;
  s7.u64 = 0;
  var_B0 = 0;
  s4.u64 = 0;
  t9.u64 = s5.u64;
  var_B8 = 0;
  ARGS->a0.u64 = s0.u64;
  ARGS->a2.u64 = (uint64_t) (&var_2D8[0]);
  var_D8 = 0;
  {
    ARGS->a1.u64 = (uint64_t) aS;
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (char *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  ARGS->a1.u64 = (uint64_t) asc_10009340;
  {
    var_28 = s2.u64;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  t9.u64 = (uint64_t) malloc;
  ARGS->a0.u64 = 24;
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    ARGS->v0.u64 = (void *) malloc((unsigned int) ARGS->a0.u64);
    memset((void *)ARGS->v0.u32, 0, ARGS->a0.u32);
  }
  t8.u64 = (uint64_t) (&absFrame);
  t9.u64 = s1.u64;
  memcpy(&ARGS->f0, &absFrame, 4);
  s2.u64 = ARGS->v0.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  ARGS->a0.u64 = (uint64_t) aFrame;
  {
    memcpy((char *) (ARGS->v0.u32 + 8), &ARGS->f0, 4);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    t9.u64 = s5.u64;
    goto loc_10003D30;
  }
  else
    t9.u64 = s5.u64;

  ARGS->a0.u64 = (uint64_t) 268500992;
  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aRelframe[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    t9.u64 = s5.u64;
    goto loc_10003E58;
  }
  else
    t9.u64 = s5.u64;

  ARGS->a0.u64 = (uint64_t) 268500992;
  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  s4.u64 = var_D8;
  {
    ARGS->a0.u64 = (uint64_t) (&aAbsframe[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_10003ED0;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  s7.u64 = var_B8;
  {
    ARGS->a0.u64 = (uint64_t) (&aRanddelay[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_10003F48;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  fp.u64 = var_B0;
  {
    ARGS->a0.u64 = (uint64_t) (&aDuration[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_10004014;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aVariance[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_10004074;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  s4.u64 = var_A0;
  {
    ARGS->a0.u64 = (uint64_t) (&aActlim1[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_100040D0;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  s7.u64 = var_98;
  {
    ARGS->a0.u64 = (uint64_t) (&aActlim2[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    t9.u64 = s1.u64;
    goto loc_10004138;
  }
  else
    t9.u64 = s1.u64;

  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  fp.u64 = var_90;
  {
    ARGS->a0.u64 = (uint64_t) aActset;
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_100042C0;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aActreset[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_100043B4;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aActresetall[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 != 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_10003DFC;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  ARGS->a2.u64 = 6;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a2.u32;
  ARGS->a1.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a1.u64 == 0)
  {
    s7.u64 = fp.u64;
    goto loc_10003AC0;
  }
  else
    s7.u64 = fp.u64;

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) aS;
  {
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64);
  }
  {
    s7.u64 = fp.u64;
    goto loc_10003AC0;
  }
  loc_10003D30:
  ARGS->a2.u64 = (int32_t) (s2.u32 + 12);

  ARGS->a1.u64 = (uint64_t) aF;
  ARGS->a0.u64 = s0.u64;
  {
    *((uint32_t *) (s2.u32 + 0)) = 0;
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (float *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a3.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a3.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003D7C;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  memcpy(&f1, (char *) (s2.u32 + 12), 4);
  t9.u64 = (uint64_t) printf;
  f1.d = f1.s;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  ARGS->a2.u64 = f1.u64;
  {
    ARGS->a0.u64 = (uint64_t) aSF;
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (double) ARGS->a2.d);
  }
  loc_10003D7C:
  memcpy(&f4, (char *) (s2.u32 + 12), 4);

  ARGS->a5.u64 = (uint64_t) (&relFrame);
  ARGS->a6.u64 = (uint64_t) (&baseFrame);
  memcpy(&f3, &relFrame, 4);
  memcpy(&ARGS->f2, &baseFrame, 4);
  f3.s = f3.s + f4.s;
  ARGS->a4.u64 = (uint64_t) (&absFrame);
  memcpy(&relFrame, &f3, 4);
  ARGS->f2.s = ARGS->f2.s + f3.s;
  memcpy(&absFrame, &ARGS->f2, 4);
  loc_10003DA4:
  ARGS->a0.u64 = (uint64_t) editSeq;

  ARGS->a0.u64 = editSeq;
  if (ARGS->a0.u64 == 0)
  {
    s4.u64 = (uint64_t) addToSeq__GP7animSeqP11animCommand;
    goto loc_1000445C;
  }
  else
    loc_10003DB0:
  s4.u64 = (uint64_t) addToSeq__GP7animSeqP11animCommand;


  t9.u64 = s4.u64;
  {
    ARGS->a1.u64 = s2.u64;
    addToSeq__GP7animSeqP11animCommand(ARGS);
  }
  ARGS->a1.u64 = (uint64_t) editSeq;
  ARGS->a2.u64 = (uint64_t) (&relFrame);
  ARGS->a1.u64 = editSeq;
  memcpy(&f5, &relFrame, 4);
  {
    memcpy((char *) (ARGS->a1.u32 + 12), &f5, 4);
    goto loc_10003AE4;
  }
  loc_10003DD8:
  t9.u64 = (uint64_t) scanf;

  s0.u64 = -1;
  ARGS->a0.u64 = (uint64_t) asc_10009390;
  {
    ARGS->a1.u64 = var_A8;
    ARGS->v0.u64 = (int) scanf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == s0.u64)
  {
    ARGS->a1.u64 = (uint64_t) seqList;
    goto loc_100041A4;
  }
  else
    ARGS->a1.u64 = (uint64_t) seqList;

  {
    s0.u64 = var_A8;
    goto loc_10003B54;
  }
  loc_10003DFC:
  t9.u64 = s1.u64;

  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aActstop[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_10004408;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aActstopall[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 != 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_10003FA4;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  ARGS->a2.u64 = 8;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a2.u32;
  ARGS->a1.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a1.u64 == 0)
  {
    ARGS->a7.u64 = var_80;
    goto loc_10003AB4;
  }
  else
    ARGS->a7.u64 = var_80;

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) aS;
  {
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64);
  }
  {
    ARGS->a7.u64 = var_80;
    goto loc_10003AB4;
  }
  loc_10003E58:
  ARGS->a2.u64 = (int32_t) (s2.u32 + 12);

  ARGS->a1.u64 = (uint64_t) aF;
  ARGS->a0.u64 = s0.u64;
  {
    *((uint32_t *) (s2.u32 + 0)) = 0;
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (float *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a3.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a3.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003EA4;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  memcpy(&f6, (char *) (s2.u32 + 12), 4);
  t9.u64 = (uint64_t) printf;
  f6.d = f6.s;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  ARGS->a2.u64 = f6.u64;
  {
    ARGS->a0.u64 = (uint64_t) aSF;
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (double) ARGS->a2.d);
  }
  loc_10003EA4:
  memcpy(&f9, (char *) (s2.u32 + 12), 4);

  ARGS->a5.u64 = (uint64_t) (&relFrame);
  ARGS->a6.u64 = (uint64_t) (&baseFrame);
  memcpy(&f8, &relFrame, 4);
  memcpy(&f7, &baseFrame, 4);
  f8.s = f8.s + f9.s;
  ARGS->a4.u64 = (uint64_t) (&absFrame);
  memcpy(&relFrame, &f8, 4);
  f7.s = f7.s + f8.s;
  {
    memcpy(&absFrame, &f7, 4);
    goto loc_10003AE0;
  }
  loc_10003ED0:
  ARGS->a2.u64 = (int32_t) (s2.u32 + 12);

  t9.u64 = s5.u64;
  ARGS->a1.u64 = (uint64_t) aF;
  ARGS->a0.u64 = s0.u64;
  s4.u64 = 1;
  {
    *((uint32_t *) (s2.u32 + 0)) = s4.u32;
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (float *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a7.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a7.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003F24;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  memcpy(&f10, (char *) (s2.u32 + 12), 4);
  t9.u64 = (uint64_t) printf;
  f10.d = f10.s;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  ARGS->a2.u64 = f10.u64;
  {
    ARGS->a0.u64 = (uint64_t) aSF;
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (double) ARGS->a2.d);
  }
  loc_10003F24:
  t6.u64 = (uint64_t) (&relFrame);

  t5.u64 = (uint64_t) (&baseFrame);
  memcpy(&relFrame, &f20, 4);
  memcpy(&ARGS->f12, (char *) (s2.u32 + 12), 4);
  t4.u64 = (uint64_t) (&absFrame);
  memcpy(&baseFrame, &ARGS->f12, 4);
  memcpy(&f11, (char *) (s2.u32 + 12), 4);
  {
    memcpy(&absFrame, &f11, 4);
    goto loc_10003ADC;
  }
  loc_10003F48:
  ARGS->a2.u64 = (int32_t) (s2.u32 + 12);

  t9.u64 = s5.u64;
  ARGS->a1.u64 = (uint64_t) aF;
  ARGS->a0.u64 = s0.u64;
  s4.u64 = 103;
  {
    *((uint32_t *) (s2.u32 + 0)) = s4.u32;
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (float *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  t7.u64 = *((int8_t *) (s3.u32 + 0));
  if (t7.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003AD8;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  memcpy(&ARGS->f13, (char *) (s2.u32 + 12), 4);
  t9.u64 = (uint64_t) printf;
  ARGS->f13.d = ARGS->f13.s;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  ARGS->a2.u64 = ARGS->f13.u64;
  {
    ARGS->a0.u64 = (uint64_t) aSF;
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (double) ARGS->a2.d);
  }
  {
    s7.u64 = fp.u64;
    goto loc_10003ADC;
  }
  loc_10003FA4:
  t9.u64 = s1.u64;

  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aSeqname[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    t9.u64 = s1.u64;
    goto loc_100044F8;
  }
  else
    t9.u64 = s1.u64;

  ARGS->a0.u64 = (uint64_t) aSeqdo;
  {
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_10004630;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aSeqloop[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 != 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_10004328;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  ARGS->a2.u64 = 12;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a2.u32;
  ARGS->a1.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a1.u64 == 0)
  {
    ARGS->a5.u64 = var_70;
    goto loc_10003AA4;
  }
  else
    ARGS->a5.u64 = var_70;

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) aS;
  {
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64);
  }
  {
    ARGS->a5.u64 = var_70;
    goto loc_10003AA4;
  }
  loc_10004014:
  ARGS->a0.u64 = s0.u64;

  t9.u64 = s5.u64;
  s7.u64 = var_28;
  ARGS->a1.u64 = (uint64_t) aF;
  s4.u64 = 101;
  *((uint32_t *) (s2.u32 + 0)) = s4.u32;
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 12);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (float *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a3.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a3.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003AD4;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  memcpy(&ARGS->f14, (char *) (s2.u32 + 12), 4);
  t9.u64 = (uint64_t) printf;
  ARGS->f14.d = ARGS->f14.s;
  ARGS->a0.u64 = (uint64_t) aSF;
  ARGS->a2.u64 = ARGS->f14.u64;
  {
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (double) ARGS->a2.d);
  }
  {
    fp.u64 = s7.u64;
    goto loc_10003AD8;
  }
  loc_10004074:
  ARGS->a0.u64 = s0.u64;

  t9.u64 = s5.u64;
  ARGS->a1.u64 = (uint64_t) aF;
  s7.u64 = 102;
  *((uint32_t *) (s2.u32 + 0)) = s7.u32;
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 12);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (float *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a4.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a4.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003AD0;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  memcpy(&ARGS->f15, (char *) (s2.u32 + 12), 4);
  t9.u64 = (uint64_t) printf;
  ARGS->f15.d = ARGS->f15.s;
  ARGS->a0.u64 = (uint64_t) aSF;
  ARGS->a2.u64 = ARGS->f15.u64;
  {
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (double) ARGS->a2.d);
  }
  {
    s7.u64 = s4.u64;
    goto loc_10003AD4;
  }
  loc_100040D0:
  ARGS->a0.u64 = s0.u64;

  ARGS->a1.u64 = (uint64_t) aDF;
  t9.u64 = s5.u64;
  ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
  s4.u64 = 2;
  *((uint32_t *) (s2.u32 + 0)) = s4.u32;
  {
    ARGS->a3.u64 = (int32_t) (s2.u32 + 12);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64, (float *) ARGS->a3.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a5.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a5.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003ACC;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  memcpy(&ARGS->f16, (char *) (s2.u32 + 12), 4);
  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) 268500992;
  ARGS->f16.d = ARGS->f16.s;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
  ARGS->a3.u64 = ARGS->f16.u64;
  {
    ARGS->a0.u64 = (uint64_t) (&aSDF[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64, (double) ARGS->a3.d);
  }
  {
    s4.u64 = s7.u64;
    goto loc_10003AD0;
  }
  loc_10004138:
  ARGS->a0.u64 = s0.u64;

  ARGS->a1.u64 = (uint64_t) aDF;
  t9.u64 = s5.u64;
  ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
  s4.u64 = 3;
  *((uint32_t *) (s2.u32 + 0)) = s4.u32;
  {
    ARGS->a3.u64 = (int32_t) (s2.u32 + 12);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64, (float *) ARGS->a3.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a1.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a1.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003AC8;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  memcpy(&ARGS->f17, (char *) (s2.u32 + 12), 4);
  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) 268500992;
  ARGS->f17.d = ARGS->f17.s;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
  ARGS->a3.u64 = ARGS->f17.u64;
  {
    ARGS->a0.u64 = (uint64_t) (&aSDF[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64, (double) ARGS->a3.d);
  }
  {
    s7.u64 = fp.u64;
    goto loc_10003ACC;
  }
  ARGS->a1.u64 = (uint64_t) seqList;
  loc_100041A4:
  ARGS->a1.u64 = seqList;

  if (ARGS->a1.u64 == 0)
  {
    s4.u64 = ARGS->a1.u64;
    goto loc_100041C4;
  }
  else
    s4.u64 = ARGS->a1.u64;

  loc_100041B0:
  ARGS->a2.u64 = *((int32_t *) (s4.u32 + 0));

  if (ARGS->a2.u64 == 0)
  {
    ;
    goto loc_10004624;
  }
  else
    ;

  s4.u64 = *((int32_t *) (s4.u32 + 36));
  if (s4.u64 != 0)
  {
    ARGS->a3.u64 = *((int8_t *) (s3.u32 + 0));
    goto loc_100041B0;
  }
  else
    loc_100041C4:
  ARGS->a3.u64 = *((int8_t *) (s3.u32 + 0));


  if (ARGS->a3.u64 == 0)
  {
    ARGS->a1.u64 = (uint64_t) seqList;
    goto loc_100041E4;
  }
  else
    ARGS->a1.u64 = (uint64_t) seqList;

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) 268500992;
  {
    ARGS->a0.u64 = (uint64_t) (&aDoneReadingAni[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64);
  }
  ARGS->a1.u64 = (uint64_t) seqList;
  loc_100041E4:
  ARGS->a1.u64 = seqList;

  s1.u64 = (uint64_t) printf;
  if (ARGS->a1.u64 == 0)
  {
    s4.u64 = ARGS->a1.u64;
    goto loc_10004288;
  }
  else
    s4.u64 = ARGS->a1.u64;

  {
    ARGS->a1.u64 = *((int8_t *) (s3.u32 + 0));
    goto loc_1000424C;
  }
  loc_100041FC:
  s0.u64 = *((int32_t *) (s0.u32 + 20));

  if (s0.u64 == 0)
  {
    ;
    goto loc_10004240;
  }
  else
    ;

  loc_10004208:
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_100041FC;
  }
  else
    ;


  memcpy(&ARGS->f18, (char *) (s0.u32 + 12), 4);
  ARGS->a0.u64 = (uint64_t) 268500992;
  t9.u64 = s1.u64;
  ARGS->f18.d = ARGS->f18.s;
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 0));
  ARGS->a2.u64 = *((int32_t *) (s0.u32 + 4));
  ARGS->a3.u64 = ARGS->f18.u64;
  {
    ARGS->a0.u64 = (uint64_t) (&aCmdDDF[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (int32_t) ARGS->a1.u64, (int32_t) ARGS->a2.u64, (double) ARGS->a3.d);
  }
  s0.u64 = *((int32_t *) (s0.u32 + 20));
  if (s0.u64 != 0)
  {
    ;
    goto loc_10004280;
  }
  else
    ;

  loc_10004240:
  s4.u64 = *((int32_t *) (s4.u32 + 36));

  if (s4.u64 == 0)
  {
    ARGS->a1.u64 = *((int8_t *) (s3.u32 + 0));
    goto loc_10004288;
  }
  else
    ARGS->a1.u64 = *((int8_t *) (s3.u32 + 0));

  loc_1000424C:
  if (ARGS->a1.u64 == 0)
  {
    ;
    goto loc_10004274;
  }
  else
    ;


  memcpy(&ARGS->f19, (char *) (s4.u32 + 8), 4);
  ARGS->a0.u64 = (uint64_t) 268500992;
  t9.u64 = s1.u64;
  ARGS->f19.d = ARGS->f19.s;
  ARGS->a1.u64 = *((int32_t *) (s4.u32 + 0));
  ARGS->a2.u64 = ARGS->f19.u64;
  {
    ARGS->a0.u64 = (uint64_t) (&aSeqDAt_2f[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (int32_t) ARGS->a1.u64, (double) ARGS->a2.d);
  }
  loc_10004274:
  s0.u64 = *((int32_t *) (s4.u32 + 24));

  if (s0.u64 == 0)
  {
    s1.u64 = (uint64_t) printf;
    goto loc_10004240;
  }
  else
    s1.u64 = (uint64_t) printf;

  loc_10004280:
  {
    ARGS->a0.u64 = *((int8_t *) (s3.u32 + 0));
    goto loc_10004208;
  }

  loc_10004288:
  s5.u64 = var_8;

  s1.u64 = var_10;
  s6.u64 = var_20;
  s7.u64 = var_30;
  s4.u64 = var_38;
  fp.u64 = var_40;
  s2.u64 = var_48;
  memcpy(&f20, &var_50, 8);
  ra.u64 = var_18;
  gp.u64 = var_D0;
  s0.u64 = var_C8;
  s3.u64 = var_C0;
  {
    sp.u64 = (int32_t) (sp.u32 + 736);
    return;
  }
  loc_100042C0:
  ARGS->a0.u64 = s0.u64;

  ARGS->a1.u64 = (uint64_t) aDF;
  t9.u64 = s5.u64;
  ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
  s7.u64 = 4;
  *((uint32_t *) (s2.u32 + 0)) = s7.u32;
  {
    ARGS->a3.u64 = (int32_t) (s2.u32 + 12);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64, (float *) ARGS->a3.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a1.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a1.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003AC4;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  memcpy(&f21, (char *) (s2.u32 + 12), 4);
  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) 268500992;
  f21.d = f21.s;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
  ARGS->a3.u64 = f21.u64;
  {
    ARGS->a0.u64 = (uint64_t) (&aSDF[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64, (double) ARGS->a3.d);
  }
  {
    fp.u64 = s4.u64;
    goto loc_10003AC8;
  }
  loc_10004328:
  t9.u64 = s1.u64;

  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aSeqstop[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_1000469C;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aSeqrepeat[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_100046F0;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aSeqkill[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 == 0)
  {
    ARGS->a0.u64 = (uint64_t) 268500992;
    goto loc_1000476C;
  }
  else
    ARGS->a0.u64 = (uint64_t) 268500992;

  t9.u64 = s1.u64;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aSeqkillall[0]);
    ARGS->v0.u64 = (int) strcmp((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  if (ARGS->v0.u64 != 0)
  {
    t9.u64 = (uint64_t) strncmp;
    goto loc_10003A40;
  }
  else
    t9.u64 = (uint64_t) strncmp;

  ARGS->a2.u64 = 15;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a2.u32;
  ARGS->a1.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a1.u64 == 0)
  {
    ARGS->a2.u64 = var_58;
    goto loc_10003A8C;
  }
  else
    ARGS->a2.u64 = var_58;

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) aS;
  {
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64);
  }
  {
    ARGS->a2.u64 = var_58;
    goto loc_10003A8C;
  }
  loc_100043B4:
  ARGS->a0.u64 = s0.u64;

  t9.u64 = s5.u64;
  ARGS->a1.u64 = (uint64_t) aD;
  ARGS->a3.u64 = 5;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a3.u32;
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a4.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a4.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003AC0;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) aSD;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
  }
  {
    s4.u64 = s7.u64;
    goto loc_10003AC4;
  }
  loc_10004408:
  ARGS->a0.u64 = s0.u64;

  t9.u64 = s5.u64;
  ARGS->a1.u64 = (uint64_t) aD;
  ARGS->a5.u64 = 7;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a5.u32;
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a6.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a6.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003AB8;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) aSD;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
  }
  {
    fp.u64 = var_88;
    goto loc_10003ABC;
  }
  loc_1000445C:
  t9.u64 = (uint64_t) malloc;

  {
    ARGS->a0.u64 = 40;
    ARGS->v0.u64 = (void *) malloc((unsigned int) ARGS->a0.u64);
    memset((void *)ARGS->v0.u32, 0, ARGS->a0.u32);
  }
  ARGS->a4.u64 = (uint64_t) editSeq;
  editSeq = ARGS->v0.u32;
  t8.u64 = 1;
  *((uint8_t *) (ARGS->v0.u32 + 4)) = t8.u8;
  t7.u64 = editSeq;
  *((uint32_t *) (t7.u32 + 0)) = 0;
  t6.u64 = editSeq;
  memcpy(&f25, &flt_100092B0, 4);
  memcpy((char *) (t6.u32 + 8), &f20, 4);
  t5.u64 = editSeq;
  memcpy(&f23, &flt_100092A8, 4);
  memcpy((char *) (t5.u32 + 16), &f25, 4);
  t4.u64 = editSeq;
  memcpy((char *) (t4.u32 + 20), &f23, 4);
  ARGS->a7.u64 = editSeq;
  memcpy((char *) (ARGS->a7.u32 + 16), &f25, 4);
  ARGS->a6.u64 = editSeq;
  memcpy((char *) (ARGS->a6.u32 + 20), &f23, 4);
  ARGS->a5.u64 = editSeq;
  *((uint32_t *) (ARGS->a5.u32 + 32)) = 0;
  ARGS->a3.u64 = editSeq;
  *((uint32_t *) (ARGS->a3.u32 + 28)) = 0;
  ARGS->a2.u64 = editSeq;
  *((uint32_t *) (ARGS->a2.u32 + 24)) = 0;
  ARGS->a1.u64 = editSeq;
  ARGS->a0.u64 = (uint64_t) seqList;
  *((uint32_t *) (ARGS->a1.u32 + 36)) = 0;
  ARGS->a0.u64 = seqList;
  t9.u64 = (uint64_t) seqList;
  if (ARGS->a0.u64 == 0)
  {
    ARGS->a4.u64 = editSeq;
    goto loc_100044E8;
  }
  else
    ARGS->a4.u64 = editSeq;

  *((uint32_t *) (ARGS->a4.u32 + 36)) = ARGS->a0.u32;
  loc_100044E8:
  ARGS->a0.u64 = (uint64_t) editSeq;

  ARGS->a0.u64 = editSeq;
  {
    seqList = ARGS->a0.u32;
    goto loc_10003DB0;
  }
  loc_100044F8:
  ARGS->a0.u64 = s0.u64;

  t9.u64 = s5.u64;
  ARGS->a1.u64 = 9;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a1.u32;
  ARGS->a1.u64 = (uint64_t) aD;
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a2.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a2.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10004544;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) aSD;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
  }
  loc_10004544:
  ARGS->a4.u64 = (uint64_t) (&relFrame);

  ARGS->a5.u64 = (uint64_t) (&absFrame);
  ARGS->a3.u64 = (uint64_t) seqList;
  ARGS->a6.u64 = (uint64_t) (&baseFrame);
  ARGS->a3.u64 = seqList;
  memcpy(&baseFrame, &f20, 4);
  memcpy(&absFrame, &f20, 4);
  memcpy(&relFrame, &f20, 4);
  if (ARGS->a3.u64 == 0)
  {
    s4.u64 = ARGS->a3.u64;
    goto loc_1000468C;
  }
  else
    s4.u64 = ARGS->a3.u64;

  ARGS->v0.u64 = *((int32_t *) (s2.u32 + 4));
  loc_10004570:
  ARGS->a7.u64 = *((int32_t *) (s4.u32 + 0));

  if (ARGS->a7.u64 == ARGS->v0.u64)
  {
    ;
    goto loc_10004684;
  }
  else
    ;

  s4.u64 = *((int32_t *) (s4.u32 + 36));
  if (s4.u64 != 0)
  {
    t9.u64 = (uint64_t) malloc;
    goto loc_10004570;
  }
  else
    t9.u64 = (uint64_t) malloc;

  loc_10004588:
  {
    ARGS->a0.u64 = 40;
    ARGS->v0.u64 = (void *) malloc((unsigned int) ARGS->a0.u64);
    memset((void *)ARGS->v0.u32, 0, ARGS->a0.u32);
  }

  ARGS->a4.u64 = (uint64_t) editSeq;
  editSeq = ARGS->v0.u32;
  t7.u64 = *((int32_t *) (s2.u32 + 4));
  *((uint32_t *) (ARGS->v0.u32 + 0)) = t7.u32;
  t6.u64 = editSeq;
  t5.u64 = 1;
  *((uint8_t *) (t6.u32 + 4)) = t5.u8;
  t4.u64 = editSeq;
  memcpy(&f29, &flt_100092B0, 4);
  memcpy((char *) (t4.u32 + 8), &f20, 4);
  ARGS->a7.u64 = editSeq;
  memcpy(&f27, &flt_100092A8, 4);
  memcpy((char *) (ARGS->a7.u32 + 16), &f29, 4);
  ARGS->a6.u64 = editSeq;
  memcpy((char *) (ARGS->a6.u32 + 20), &f27, 4);
  ARGS->a5.u64 = editSeq;
  *((uint32_t *) (ARGS->a5.u32 + 24)) = 0;
  ARGS->a3.u64 = editSeq;
  *((uint32_t *) (ARGS->a3.u32 + 28)) = 0;
  ARGS->a2.u64 = editSeq;
  *((uint32_t *) (ARGS->a2.u32 + 32)) = 0;
  ARGS->a1.u64 = editSeq;
  ARGS->a0.u64 = (uint64_t) seqList;
  *((uint32_t *) (ARGS->a1.u32 + 36)) = 0;
  ARGS->a0.u64 = seqList;
  t8.u64 = (uint64_t) editSeq;
  t9.u64 = (uint64_t) seqList;
  if (ARGS->a0.u64 == 0)
  {
    ARGS->a4.u64 = editSeq;
    goto loc_10004608;
  }
  else
    ARGS->a4.u64 = editSeq;

  *((uint32_t *) (ARGS->a4.u32 + 36)) = ARGS->a0.u32;
  loc_10004608:
  t8.u64 = editSeq;

  seqList = t8.u32;
  t9.u64 = (uint64_t) free;
  loc_10004614:
  {
    ARGS->a0.u64 = s2.u64;
    free((void *) ARGS->a0.u64);
  }

  {
    t9.u64 = s5.u64;
    goto loc_10003AE8;
  }
  loc_10004624:
  t9.u64 = *((int32_t *) (s4.u32 + 24));

  {
    *((uint32_t *) (s4.u32 + 28)) = t9.u32;
    goto loc_100041C4;
  }
  loc_10004630:
  ARGS->a0.u64 = s0.u64;

  t9.u64 = s5.u64;
  ARGS->a1.u64 = (uint64_t) aD;
  ra.u64 = 10;
  *((uint32_t *) (s2.u32 + 0)) = ra.u32;
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  at.u64 = *((int8_t *) (s3.u32 + 0));
  if (at.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003AA8;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) aSD;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
  }
  {
    ARGS->a6.u64 = var_78;
    goto loc_10003AAC;
  }
  loc_10004684:
  ARGS->v0.u64 = (uint64_t) editSeq;

  editSeq = s4.u32;
  loc_1000468C:
  if (s4.u64 != 0)
  {
    t9.u64 = (uint64_t) free;
    goto loc_10004614;
  }
  else
    t9.u64 = (uint64_t) free;


  {
    t9.u64 = (uint64_t) malloc;
    goto loc_10004588;
  }
  loc_1000469C:
  ARGS->a0.u64 = s0.u64;

  t9.u64 = s5.u64;
  ARGS->a1.u64 = (uint64_t) aD;
  ARGS->v1.u64 = 11;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->v1.u32;
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a0.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a0.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003A98;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) aSD;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
  }
  {
    ARGS->a4.u64 = var_68;
    goto loc_10003A9C;
  }
  loc_100046F0:
  ARGS->a0.u64 = s0.u64;

  t9.u64 = s5.u64;
  ARGS->a1.u64 = 13;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a1.u32;
  ARGS->a1.u64 = (uint64_t) aD;
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a2.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a2.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10004758;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) aSD;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
  }
  ARGS->a3.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a3.u64 == 0)
  {
    t9.u64 = (uint64_t) printf;
    goto loc_10004758;
  }
  else
    t9.u64 = (uint64_t) printf;

  ARGS->a0.u64 = (uint64_t) 268500992;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a0.u64 = (uint64_t) (&aWarningSNotImp[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64);
  }
  loc_10004758:
  t9.u64 = (uint64_t) free;

  {
    ARGS->a0.u64 = s2.u64;
    free((void *) ARGS->a0.u64);
  }
  {
    t9.u64 = s5.u64;
    goto loc_10003AE8;
  }
  loc_1000476C:
  ARGS->a0.u64 = s0.u64;

  t9.u64 = s5.u64;
  ARGS->a1.u64 = 14;
  *((uint32_t *) (s2.u32 + 0)) = ARGS->a1.u32;
  ARGS->a1.u64 = (uint64_t) aD;
  {
    ARGS->a2.u64 = (int32_t) (s2.u32 + 4);
    ARGS->v0.u64 = (int) sscanf((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64, (int32_t *) ARGS->a2.u64);
  }
  t9.u64 = s6.u64;
  ARGS->a0.u64 = s0.u64;
  {
    ARGS->a1.u64 = (uint64_t) asc_10009340;
    ARGS->v0.u64 = (unsigned int) strcspn((const char *) ARGS->a0.u64, (const char *) ARGS->a1.u64);
  }
  ARGS->a2.u64 = *((int8_t *) (s3.u32 + 0));
  if (ARGS->a2.u64 == 0)
  {
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);
    goto loc_10003A90;
  }
  else
    s0.u64 = (int32_t) (ARGS->v0.u32 + s0.u32);

  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) aSD;
  ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
  {
    ARGS->a2.u64 = *((int32_t *) (s2.u32 + 4));
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64, (int32_t) ARGS->a2.u64);
  }
  {
    ARGS->a3.u64 = var_60;
    goto loc_10003A94;
  }
  loc_100047C0:
  if (ARGS->a0.u64 == 0)
  {
    t9.u64 = (uint64_t) free;
    goto loc_100047DC;
  }
  else
    t9.u64 = (uint64_t) free;


  t9.u64 = (uint64_t) printf;
  ARGS->a0.u64 = (uint64_t) aS;
  {
    ARGS->a1.u64 = (uint64_t) (&var_2D8[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (char *) ARGS->a1.u64);
  }
  t9.u64 = (uint64_t) free;
  loc_100047DC:
  {
    ARGS->a0.u64 = s2.u64;
    free((void *) ARGS->a0.u64);
  }

  {
    t9.u64 = s5.u64;
    goto loc_10003AE8;
  }
}

static void foldtwixt__GiPffT3(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  foldtwixt__GiPffT3:
  ARGS->a4.u64 = (int32_t) (ARGS->a0.u32 + -1);

  ARGS->v0.u64 = (int32_t) (1 << 16);
  ARGS->a5.u64 = (int32_t) (ARGS->a0.u32 << 2);
  ARGS->v0.u64 = 48628;
  if (ARGS->a0.i64 <= 0)
  {
    at.u64 = (int32_t) (t9.u32 + ARGS->v0.u32);
    goto loc_10005238;
  }
  else
    at.u64 = (int32_t) (t9.u32 + ARGS->v0.u32);

  loc_100051C0:
  ARGS->a2.u64 = (int32_t) (ARGS->a5.u32 + ARGS->a1.u32);

  memcpy(&f5, (char *) (ARGS->a2.u32 + 0), 4);
  ARGS->v1.u64 = (int32_t) (ARGS->a4.u32 << 2);
  memcpy(&f8, &flt_100092B8, 4);
  ARGS->v1.u64 = (int32_t) (ARGS->v1.u32 + ARGS->a1.u32);
  memcpy(&f6, (char *) (ARGS->v1.u32 + 0), 4);
  f8.s = ARGS->f15.s * f8.s;
  f4.s = f5.s - f6.s;
  memcpy(&f7, &flt_100092A8, 4);
  if (f8.s < f4.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  memcpy(&f9, &flt_100092BC, 4);
  if (EPANOS_fp_cond)
  {
    f7.s = f7.s - ARGS->f14.s;
    goto loc_10005224;
  }
  else
    f7.s = f7.s - ARGS->f14.s;

  f10.s = ARGS->f15.s * f9.s;
  if (f4.s < f10.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    f8.s = f7.s * f6.s;
    goto loc_10005218;
  }
  else
    f8.s = f7.s * f6.s;

  ARGS->f0.s = f5.s + ARGS->f15.s;
  ARGS->f0.s = ARGS->f14.s * ARGS->f0.s;
  {
    ARGS->f0.s = f8.s + ARGS->f0.s;
    return;
  }
  loc_10005218:
  ARGS->f0.s = f5.s * ARGS->f14.s;

  {
    ARGS->f0.s = f8.s + ARGS->f0.s;
    return;
  }
  loc_10005224:
  ARGS->f0.s = f6.s + ARGS->f15.s;

  f1.s = f5.s * ARGS->f14.s;
  ARGS->f0.s = f7.s * ARGS->f0.s;
  {
    ARGS->f0.s = ARGS->f0.s + f1.s;
    return;
  }
  loc_10005238:
  {
    ARGS->a4.u64 = (int32_t) (ARGS->a4.u32 + 128);
    goto loc_100051C0;
  }

}

static void drawshape__GiT1(EPANOS_ARGS *ARGS, wincount_t wincount)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  uint64_t var_20;
  uint64_t var_18;
  uint64_t var_10;
  uint64_t var_8;
  drawshape__GiT1:
  sp.u64 = (int32_t) (sp.u32 + -32);

  var_18 = s0.u64;
  var_10 = s1.u64;
  at.u64 = (int32_t) (1 << 16);
  var_8 = ra.u64;
  at.u64 = 48476;
  var_20 = gp.u64;
  if (ARGS->a1.u64 == 0)
  {
    gp.u64 = (int32_t) (t9.u32 + at.u32);
    goto loc_100052DC;
  }
  else
    gp.u64 = (int32_t) (t9.u32 + at.u32);

  t9.u64 = (uint64_t) glBegin;
  {
    ARGS->a0.u64 = 9;
    wrap_glBegin((unsigned int) ARGS->a0.u64, wincount);
  }
  s0.u64 = (uint64_t) glVertex2f;
  s1.u64 = (uint64_t) square;
  t9.u64 = s0.u64;
  memcpy(&ARGS->f12, &square[0], 4);
  {
    memcpy(&ARGS->f13, &square[1], 4);
    wrap_glVertex2f((float) ARGS->f12.s, (float) ARGS->f13.s, wincount);
  }
  t9.u64 = s0.u64;
  memcpy(&ARGS->f12, &square[2], 4);
  {
    memcpy(&ARGS->f13, &square[3], 4);
    wrap_glVertex2f((float) ARGS->f12.s, (float) ARGS->f13.s, wincount);
  }
  t9.u64 = s0.u64;
  memcpy(&ARGS->f12, &square[4], 4);
  {
    memcpy(&ARGS->f13, &square[5], 4);
    wrap_glVertex2f((float) ARGS->f12.s, (float) ARGS->f13.s, wincount);
  }
  t9.u64 = s0.u64;
  memcpy(&ARGS->f12, &square[6], 4);
  {
    memcpy(&ARGS->f13, &square[7], 4);
    wrap_glVertex2f((float) ARGS->f12.s, (float) ARGS->f13.s, wincount);
  }
  t9.u64 = (uint64_t) glEnd;
  {
    ;
    wrap_glEnd(wincount);
  }
  ra.u64 = var_8;
  loc_100052C8:
  s0.u64 = var_18;

  s1.u64 = var_10;
  gp.u64 = var_20;
  {
    sp.u64 = (int32_t) (sp.u32 + 32);
    return;
  }
  loc_100052DC:
  t9.u64 = (uint64_t) glBegin;

  {
    ARGS->a0.u64 = 1;
    wrap_glBegin((unsigned int) ARGS->a0.u64, wincount);
  }
  s0.u64 = (uint64_t) glVertex2f;
  s1.u64 = (uint64_t) square;
  t9.u64 = s0.u64;
  memcpy(&ARGS->f12, &square[0], 4);
  {
    memcpy(&ARGS->f13, &square[1], 4);
    wrap_glVertex2f((float) ARGS->f12.s, (float) ARGS->f13.s, wincount);
  }
  t9.u64 = s0.u64;
  memcpy(&ARGS->f12, &square[2], 4);
  {
    memcpy(&ARGS->f13, &square[3], 4);
    wrap_glVertex2f((float) ARGS->f12.s, (float) ARGS->f13.s, wincount);
  }
  t9.u64 = s0.u64;
  memcpy(&ARGS->f12, &square[2], 4);
  {
    memcpy(&ARGS->f13, &square[3], 4);
    wrap_glVertex2f((float) ARGS->f12.s, (float) ARGS->f13.s, wincount);
  }
  t9.u64 = s0.u64;
  memcpy(&ARGS->f12, &square[4], 4);
  {
    memcpy(&ARGS->f13, &square[5], 4);
    wrap_glVertex2f((float) ARGS->f12.s, (float) ARGS->f13.s, wincount);
  }
  t9.u64 = s0.u64;
  memcpy(&ARGS->f12, &square[4], 4);
  {
    memcpy(&ARGS->f13, &square[5], 4);
    wrap_glVertex2f((float) ARGS->f12.s, (float) ARGS->f13.s, wincount);
  }
  t9.u64 = s0.u64;
  memcpy(&ARGS->f12, &square[6], 4);
  {
    memcpy(&ARGS->f13, &square[7], 4);
    wrap_glVertex2f((float) ARGS->f12.s, (float) ARGS->f13.s, wincount);
  }
  t9.u64 = s0.u64;
  memcpy(&ARGS->f12, &square[6], 4);
  {
    memcpy(&ARGS->f13, &square[7], 4);
    wrap_glVertex2f((float) ARGS->f12.s, (float) ARGS->f13.s, wincount);
  }
  t9.u64 = s0.u64;
  memcpy(&ARGS->f12, &square[0], 4);
  {
    memcpy(&ARGS->f13, &square[1], 4);
    wrap_glVertex2f((float) ARGS->f12.s, (float) ARGS->f13.s, wincount);
  }
  t9.u64 = (uint64_t) glEnd;
  {
    ;
    wrap_glEnd(wincount);
  }
  {
    ra.u64 = var_8;
    goto loc_100052C8;
  }
}

static void tasteQueue__Gv(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  double var_30;
  uint64_t var_10;
  uint64_t var_28;
  uint64_t var_20;
  uint64_t var_8;
  uint64_t var_18;
  tasteQueue__Gv:
  sp.u64 = (int32_t) (sp.u32 + -48);

  var_8 = ra.u64;
  var_18 = s0.u64;
  memcpy(&var_30, &f20, 8);
  var_10 = s2.u64;
  ARGS->v0.u64 = (int32_t) (1 << 16);
  var_20 = s1.u64;
  ARGS->v0.u64 = 49368;
  var_28 = gp.u64;
  gp.u64 = (int32_t) (t9.u32 + ARGS->v0.u32);
  memcpy(&f1, &flt_100092A8, 4);
  s1.u64 = (uint64_t) (&currentFrame);
  at.u64 = (uint64_t) seqList;
  memcpy(&ARGS->f0, &currentFrame, 4);
  at.u64 = seqList;
  s2.u64 = (uint64_t) processCommand__GP11animCommand;
  memcpy(&f20, &dbl_100092D8, 8);
  ARGS->f0.s = ARGS->f0.s + f1.s;
  s0.u64 = at.u64;
  if (at.u64 == 0)
  {
    memcpy(&currentFrame, &ARGS->f0, 4);
    goto loc_10004FCC;
  }
  else
    memcpy(&currentFrame, &ARGS->f0, 4);

  {
    memcpy(&f4, &currentFrame, 4);
    goto loc_10004F2C;
  }
  loc_10004F20:
  s0.u64 = *((int32_t *) (s0.u32 + 36));

  loc_10004F24:
  if (s0.u64 == 0)
  {
    memcpy(&f4, (char *) (s1.u32 + 0), 4);
    goto loc_10004FCC;
  }
  else
    memcpy(&f4, (char *) (s1.u32 + 0), 4);


  loc_10004F2C:
  memcpy(&f5, (char *) (s0.u32 + 8), 4);

  f4.d = f4.s;
  ARGS->f2.d = f5.s;
  f4.d = f4.d + f20.d;
  if (ARGS->f2.d < f4.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ARGS->a0.u64 = *((int32_t *) (s0.u32 + 28));
  if (!EPANOS_fp_cond)
  {
    ARGS->a2.u64 = *((int8_t *) (s0.u32 + 4));
    goto loc_10004F20;
  }
  else
    ARGS->a2.u64 = *((int8_t *) (s0.u32 + 4));

  if (ARGS->a2.u64 == 0)
  {
    ;
    goto loc_10004F20;
  }
  else
    ;

  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004F20;
  }
  else
    ;

  memcpy(&f6, (char *) (ARGS->a0.u32 + 8), 4);
  f6.s = f6.s + f5.s;
  f6.d = f6.s;
  if (f6.d < f4.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    ;
    goto loc_10004F20;
  }
  else
    ;

  t9.u64 = s2.u64;
  loc_10004F7C:
  {
    ;
    processCommand__GP11animCommand(ARGS);
  }

  ARGS->v1.u64 = *((int8_t *) (s0.u32 + 4));
  memcpy(&f9, (char *) (s0.u32 + 8), 4);
  memcpy(&f8, (char *) (s1.u32 + 0), 4);
  if (ARGS->v1.u64 == 0)
  {
    ARGS->a0.u64 = *((int32_t *) (s0.u32 + 28));
    goto loc_10004FC4;
  }
  else
    ARGS->a0.u64 = *((int32_t *) (s0.u32 + 28));

  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004FC4;
  }
  else
    ;

  memcpy(&f7, (char *) (ARGS->a0.u32 + 8), 4);
  f8.d = f8.s;
  f7.s = f7.s + f9.s;
  f8.d = f8.d + f20.d;
  f7.d = f7.s;
  if (f7.d < f8.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (EPANOS_fp_cond)
  {
    t9.u64 = s2.u64;
    goto loc_10004F7C;
  }
  else
    t9.u64 = s2.u64;

  loc_10004FC4:
  {
    s0.u64 = *((int32_t *) (s0.u32 + 36));
    goto loc_10004F24;
  }

  loc_10004FCC:
  gp.u64 = var_28;

  s0.u64 = var_18;
  ra.u64 = var_8;
  s1.u64 = var_20;
  s2.u64 = var_10;
  memcpy(&f20, &var_30, 8);
  {
    sp.u64 = (int32_t) (sp.u32 + 48);
    return;
  }
}

static void hls_to_rgb__GfN21PfN24(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  double var_50;
  uint64_t var_30;
  uint64_t var_20;
  double var_48;
  uint64_t var_10;
  double var_40;
  uint64_t var_28;
  double var_18;
  uint64_t var_38;
  hls_to_rgb__GfN21PfN24:
  at.u64 = (int32_t) (1 << 16);

  sp.u64 = (int32_t) (sp.u32 + -80);
  at.u64 = 55468;
  var_20 = gp.u64;
  gp.u64 = (int32_t) (t9.u32 + at.u32);
  memcpy(&f1, &dbl_100092D8, 8);
  ARGS->f0.d = ARGS->f13.s;
  memcpy(&var_18, &f20, 8);
  var_28 = s2.u64;
  if (ARGS->f0.d <= f1.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  f4.s = ARGS->f13.s;
  var_30 = s1.u64;
  f5.s = ARGS->f12.s;
  s1.u64 = ARGS->a5.u64;
  var_38 = s0.u64;
  s0.u64 = ARGS->a4.u64;
  s2.u64 = ARGS->a3.u64;
  if (!EPANOS_fp_cond)
  {
    memcpy(&f6, &flt_100092A8, 4);
    goto loc_10003748;
  }
  else
    memcpy(&f6, &flt_100092A8, 4);

  f20.s = ARGS->f14.s + f6.s;
  {
    f20.s = ARGS->f13.s * f20.s;
    goto loc_10003754;
  }
  loc_10003748:
  f21.s = ARGS->f13.s * ARGS->f14.s;

  f20.s = ARGS->f13.s + ARGS->f14.s;
  f20.s = f20.s - f21.s;
  loc_10003754:
  f23.u32 = 0;

  ;
  if (ARGS->f14.s == f23.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    var_10 = ra.u64;
    goto loc_10003794;
  }
  else
    var_10 = ra.u64;

  memcpy((char *) (s1.u32 + 0), &f4, 4);
  memcpy((char *) (s0.u32 + 0), &f4, 4);
  memcpy((char *) (s2.u32 + 0), &f4, 4);
  loc_10003778:
  s0.u64 = var_38;

  s1.u64 = var_30;
  s2.u64 = var_28;
  memcpy(&f20, &var_18, 8);
  gp.u64 = var_20;
  {
    sp.u64 = (int32_t) (sp.u32 + 80);
    return;
  }
  loc_10003794:
  memcpy(&ARGS->f15, &dbl_100092E0, 8);

  ARGS->f14.d = f5.s;
  ARGS->f14.d = ARGS->f14.d * ARGS->f15.d;
  memcpy(&ARGS->f12, &flt_100092AC, 4);
  ARGS->f14.s = ARGS->f14.d;
  memcpy(&ARGS->f15, &dbl_100092E8, 8);
  memcpy(&var_50, &ARGS->f14, 8);
  ARGS->f14.d = ARGS->f14.s;
  t9.u64 = (uint64_t) value__GfN21;
  ARGS->f12.s = f4.s * ARGS->f12.s;
  memcpy(&var_48, &ARGS->f14, 8);
  ARGS->f14.d = ARGS->f14.d + ARGS->f15.d;
  ARGS->f12.s = ARGS->f12.s - f20.s;
  ARGS->f13.s = f20.s;
  memcpy(&var_40, &ARGS->f12, 8);
  {
    ARGS->f14.s = ARGS->f14.d;
    value__GfN21(ARGS);
  }
  t9.u64 = (uint64_t) value__GfN21;
  memcpy((char *) (s2.u32 + 0), &ARGS->f0, 4);
  memcpy(&ARGS->f12, &var_40, 8);
  ARGS->f13.s = f20.s;
  {
    memcpy(&ARGS->f14, &var_50, 8);
    value__GfN21(ARGS);
  }
  memcpy(&ARGS->f15, &dbl_100092F0, 8);
  memcpy(&ARGS->f14, &var_48, 8);
  t9.u64 = (uint64_t) value__GfN21;
  ARGS->f14.d = ARGS->f14.d + ARGS->f15.d;
  memcpy(&ARGS->f12, &var_40, 8);
  memcpy((char *) (s0.u32 + 0), &ARGS->f0, 4);
  ARGS->f13.s = f20.s;
  {
    ARGS->f14.s = ARGS->f14.d;
    value__GfN21(ARGS);
  }
  ra.u64 = var_10;
  {
    memcpy((char *) (s1.u32 + 0), &ARGS->f0, 4);
    goto loc_10003778;
  }
}

static void killSeq__GP7animSeq(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  uint64_t var_30;
  uint64_t var_28;
  uint64_t var_10;
  uint64_t var_20;
  uint64_t var_18;
  killSeq__GP7animSeq:
  sp.u64 = (int32_t) (sp.u32 + -48);

  var_20 = s1.u64;
  var_18 = ra.u64;
  var_30 = s0.u64;
  at.u64 = (int32_t) (1 << 16);
  s0.u64 = ARGS->a0.u64;
  var_10 = s2.u64;
  at.u64 = 51060;
  var_28 = gp.u64;
  if (ARGS->a0.u64 == 0)
  {
    gp.u64 = (int32_t) (t9.u32 + at.u32);
    goto loc_10004904;
  }
  else
    gp.u64 = (int32_t) (t9.u32 + at.u32);

  s1.u64 = (uint64_t) seqList;
  *((uint8_t *) (ARGS->a0.u32 + 4)) = 0;
  ARGS->a3.u64 = seqList;
  if (ARGS->a0.u64 != ARGS->a3.u64)
  {
    s2.u64 = (uint64_t) free;
    goto loc_100048A4;
  }
  else
    s2.u64 = (uint64_t) free;

  ARGS->a0.u64 = *((int32_t *) (ARGS->a3.u32 + 36));
  seqList = ARGS->a0.u32;
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 24));
  if (ARGS->a0.u64 == 0)
  {
    t9.u64 = s2.u64;
    goto loc_10004894;
  }
  else
    t9.u64 = s2.u64;

  loc_1000487C:
  t9.u64 = s2.u64;

  {
    s1.u64 = *((int32_t *) (ARGS->a0.u32 + 20));
    free((void *) ARGS->a0.u64);
  }
  if (s1.u64 != 0)
  {
    ARGS->a0.u64 = s1.u64;
    goto loc_1000487C;
  }
  else
    ARGS->a0.u64 = s1.u64;

  t9.u64 = s2.u64;
  loc_10004894:
  s1.u64 = (uint64_t) seqList;

  {
    ARGS->a0.u64 = s0.u64;
    free((void *) ARGS->a0.u64);
  }
  ARGS->a3.u64 = seqList;
  loc_100048A4:
  ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 36));

  if (ARGS->a2.u64 == 0)
  {
    s2.u64 = (uint64_t) free;
    goto loc_10004904;
  }
  else
    s2.u64 = (uint64_t) free;

  loc_100048B0:
  if (ARGS->a2.u64 == s0.u64)
  {
    ;
    goto loc_100048D0;
  }
  else
    ;


  ARGS->a3.u64 = ARGS->a2.u64;
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 36));
  if (ARGS->a2.u64 != 0)
  {
    ;
    goto loc_100048B0;
  }
  else
    ;

  {
    s2.u64 = var_10;
    goto loc_10004908;
  }
  loc_100048D0:
  ARGS->a2.u64 = *((int32_t *) (s0.u32 + 36));

  *((uint32_t *) (ARGS->a3.u32 + 36)) = ARGS->a2.u32;
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 24));
  if (ARGS->a1.u64 == 0)
  {
    ARGS->a0.u64 = ARGS->a1.u64;
    goto loc_100048F8;
  }
  else
    ARGS->a0.u64 = ARGS->a1.u64;

  loc_100048E4:
  t9.u64 = s2.u64;

  {
    s1.u64 = *((int32_t *) (ARGS->a0.u32 + 20));
    free((void *) ARGS->a0.u64);
  }
  if (s1.u64 != 0)
  {
    ARGS->a0.u64 = s1.u64;
    goto loc_100048E4;
  }
  else
    ARGS->a0.u64 = s1.u64;

  loc_100048F8:
  t9.u64 = s2.u64;

  {
    ARGS->a0.u64 = s0.u64;
    free((void *) ARGS->a0.u64);
  }
  loc_10004904:
  s2.u64 = var_10;

  loc_10004908:
  ra.u64 = var_18;

  s0.u64 = var_30;
  s1.u64 = var_20;
  gp.u64 = var_28;
  {
    sp.u64 = (int32_t) (sp.u32 + 48);
    return;
  }
}

void createActTable__Gv(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  uint64_t var_20;
  uint64_t var_18;
  uint64_t var_10;
  uint64_t var_8;
  createActTable__Gv:
  sp.u64 = (int32_t) (sp.u32 + -32);

  at.u64 = (int32_t) (1 << 16);
  var_20 = s1.u64;
  at.u64 = 45688;
  var_10 = gp.u64;
  gp.u64 = (int32_t) (t9.u32 + at.u32);
  s1.u64 = (uint64_t) createBlankActAnim__Gv;
  t9.u64 = s1.u64;
  var_18 = ra.u64;
  {
    var_8 = s0.u64;
    createBlankActAnim__Gv(ARGS);
  }
  s0.u64 = (uint64_t) acttable;
  t9.u64 = s1.u64;
  {
    acttable[18] = ARGS->v0.u32;
    createBlankActAnim__Gv(ARGS);
  }
  t9.u64 = s1.u64;
  {
    acttable[73] = ARGS->v0.u32;
    createBlankActAnim__Gv(ARGS);
  }
  t9.u64 = s1.u64;
  {
    acttable[31] = ARGS->v0.u32;
    createBlankActAnim__Gv(ARGS);
  }
  t9.u64 = s1.u64;
  {
    acttable[38] = ARGS->v0.u32;
    createBlankActAnim__Gv(ARGS);
  }
  t9.u64 = s1.u64;
  {
    acttable[80] = ARGS->v0.u32;
    createBlankActAnim__Gv(ARGS);
  }
  t9.u64 = s1.u64;
  {
    acttable[108] = ARGS->v0.u32;
    createBlankActAnim__Gv(ARGS);
  }
  memcpy(&ARGS->f0, &flt_100092C4, 4);
  t9.u64 = s1.u64;
  memcpy((char *) (ARGS->v0.u32 + 24), &ARGS->f0, 4);
  {
    acttable[52] = ARGS->v0.u32;
    createBlankActAnim__Gv(ARGS);
  }
  t9.u64 = s1.u64;
  {
    acttable[101] = ARGS->v0.u32;
    createBlankActAnim__Gv(ARGS);
  }
  t9.u64 = s1.u64;
  {
    acttable[127] = ARGS->v0.u32;
    createBlankActAnim__Gv(ARGS);
  }
  t9.u64 = s1.u64;
  {
    acttable[123] = ARGS->v0.u32;
    createBlankActAnim__Gv(ARGS);
  }
  t9.u64 = s1.u64;
  {
    acttable[87] = ARGS->v0.u32;
    createBlankActAnim__Gv(ARGS);
  }
  t9.u64 = s1.u64;
  {
    acttable[94] = ARGS->v0.u32;
    createBlankActAnim__Gv(ARGS);
  }
  memcpy(&f1, &flt_100092A8, 4);
  t9.u64 = s1.u64;
  memcpy((char *) (ARGS->v0.u32 + 24), &f1, 4);
  {
    acttable[45] = ARGS->v0.u32;
    createBlankActAnim__Gv(ARGS);
  }
  s1.u64 = var_20;
  ra.u64 = var_18;
  gp.u64 = var_10;
  acttable[130] = ARGS->v0.u32;
  s0.u64 = var_8;
  {
    sp.u64 = (int32_t) (sp.u32 + 32);
    return;
  }
}

static void createBlankActAnim__Gv(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  uint64_t var_10;
  uint64_t var_8;
  createBlankActAnim__Gv:
  at.u64 = (int32_t) (1 << 16);

  sp.u64 = (int32_t) (sp.u32 + -16);
  at.u64 = 45788;
  var_8 = gp.u64;
  gp.u64 = (int32_t) (t9.u32 + at.u32);
  t9.u64 = (uint64_t) malloc;
  var_10 = ra.u64;
  {
    ARGS->a0.u64 = 40;
    ARGS->v0.u64 = (void *) malloc((unsigned int) ARGS->a0.u64);
    memset((void *)ARGS->v0.u32, 0, ARGS->a0.u32);
  }
  memcpy(&ARGS->f2, &flt_100092A8, 4);
  memcpy(&f1, &flt_100092C0, 4);
  gp.u64 = var_8;
  ARGS->f0.u32 = 0;
  memcpy((char *) (ARGS->v0.u32 + 4), &ARGS->f2, 4);
  memcpy((char *) (ARGS->v0.u32 + 8), &ARGS->f0, 4);
  memcpy((char *) (ARGS->v0.u32 + 12), &ARGS->f0, 4);
  memcpy((char *) (ARGS->v0.u32 + 16), &ARGS->f0, 4);
  memcpy((char *) (ARGS->v0.u32 + 20), &ARGS->f0, 4);
  memcpy((char *) (ARGS->v0.u32 + 24), &ARGS->f0, 4);
  ra.u64 = var_10;
  memcpy((char *) (ARGS->v0.u32 + 28), &ARGS->f0, 4);
  memcpy((char *) (ARGS->v0.u32 + 32), &f1, 4);
  sp.u64 = (int32_t) (sp.u32 + 16);
  {
    memcpy((char *) (ARGS->v0.u32 + 36), &ARGS->f0, 4);
    return;
  }
}

static void value__GfN21(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  value__GfN21:
  ARGS->v0.u64 = 55680;

  at.u64 = (int32_t) (t9.u32 + ARGS->v0.u32);
  memcpy(&f7, &flt_10009290, 4);
  if (f7.s < ARGS->f14.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  memcpy(&f3, &dbl_100092D0, 8);
  if (!EPANOS_fp_cond)
  {
    memcpy(&ARGS->f0, &flt_10009294, 4);
    goto loc_10003640;
  }
  else
    memcpy(&ARGS->f0, &flt_10009294, 4);

  ARGS->f14.s = ARGS->f14.s + ARGS->f0.s;
  loc_10003640:
  f1.u32 = 0;

  ;
  if (ARGS->f14.s < f1.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  memcpy(&ARGS->f0, &flt_1000929C, 4);
  memcpy(&f5, &flt_100092A4, 4);
  if (!EPANOS_fp_cond)
  {
    memcpy(&f6, &flt_100092A0, 4);
    goto loc_10003660;
  }
  else
    memcpy(&f6, &flt_100092A0, 4);

  ARGS->f14.s = ARGS->f14.s + f7.s;
  loc_10003660:
  if (ARGS->f14.s < ARGS->f0.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;


  ;
  if (EPANOS_fp_cond)
  {
    ARGS->f0.s = ARGS->f13.s;
    goto loc_100036C0;
  }
  else
    ARGS->f0.s = ARGS->f13.s;

  if (ARGS->f14.s < f6.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (EPANOS_fp_cond)
  {
    ;
    goto locret_100036E8;
  }
  else
    ;

  if (ARGS->f14.s < f5.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    ARGS->f0.s = ARGS->f12.s;
    goto locret_100036B8;
  }
  else
    ARGS->f0.s = ARGS->f12.s;

  ARGS->f2.s = f5.s - ARGS->f14.s;
  ARGS->f2.d = ARGS->f2.s;
  ARGS->f2.d = ARGS->f2.d / f3.d;
  f1.s = ARGS->f13.s - ARGS->f12.s;
  f1.d = f1.s;
  ARGS->f0.d = ARGS->f12.s;
  f1.d = f1.d * ARGS->f2.d;
  ARGS->f0.d = ARGS->f0.d + f1.d;
  {
    ARGS->f0.s = ARGS->f0.d;
    return;
  }
  locret_100036B8:
  {
    ;
    return;
  }

  loc_100036C0:
  memcpy(&f3, &dbl_100092D0, 8);

  ARGS->f2.d = ARGS->f14.s;
  ARGS->f2.d = ARGS->f2.d / f3.d;
  f1.s = ARGS->f13.s - ARGS->f12.s;
  f1.d = f1.s;
  ARGS->f0.d = ARGS->f12.s;
  f1.d = f1.d * ARGS->f2.d;
  ARGS->f0.d = ARGS->f0.d + f1.d;
  {
    ARGS->f0.s = ARGS->f0.d;
    return;
  }
  locret_100036E8:
  {
    ;
    return;
  }

}

static void processCommand__GP11animCommand(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  uint64_t var_20;
  uint64_t var_18;
  uint64_t var_10;
  processCommand__GP11animCommand:
  ARGS->v0.u64 = (int32_t) (1 << 16);

  sp.u64 = (int32_t) (sp.u32 + -32);
  ARGS->v0.u64 = 50812;
  var_18 = gp.u64;
  gp.u64 = (int32_t) (t9.u32 + ARGS->v0.u32);
  at.u64 = (uint64_t) (&oflag);
  at.u64 = oflag;
  var_20 = s0.u64;
  s0.u64 = ARGS->a0.u64;
  if (at.u64 == 0)
  {
    var_10 = ra.u64;
    goto loc_10004990;
  }
  else
    var_10 = ra.u64;

  memcpy(&ARGS->f2, (char *) (ARGS->a0.u32 + 8), 4);
  ARGS->a2.u64 = *((int32_t *) (ARGS->a0.u32 + 16));
  ARGS->a3.u64 = (uint64_t) (&currentFrame);
  memcpy(&f1, (char *) (ARGS->a2.u32 + 8), 4);
  memcpy(&ARGS->f0, &currentFrame, 4);
  ARGS->a4.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
  ARGS->f2.d = ARGS->f2.s;
  t9.u64 = (uint64_t) printf;
  f1.d = f1.s;
  ARGS->a0.u64 = (uint64_t) 268500992;
  ARGS->a5.u64 = ARGS->f2.u64;
  ARGS->f0.d = ARGS->f0.s;
  ARGS->a3.u64 = f1.u64;
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 0));
  ARGS->a1.u64 = ARGS->f0.u64;
  {
    ARGS->a0.u64 = (uint64_t) (&aProcCurrentfra[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (double) ARGS->a1.d, (int32_t) ARGS->a2.u64, (double) ARGS->a3.d, (int32_t) ARGS->a4.u64, (double) ARGS->a5.d);
  }
  loc_10004990:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 0));

  ARGS->a0.u64 = (uint64_t) 268500992;
  ;
  ;
//  ARGS->a0.u64 = (uint64_t) (&jpt_100049B4[0]);
  ARGS->a4.u64 = (uint64_t) (&currentFrame);
  ;
  ;
  ;
  {
    t9.u64 = (uint64_t) exprand__Gf;
    switch (ARGS->a1.u64)
    {
      case 0:
        goto loc_10004A00;

      case 1:
        goto loc_10004CF8;

      case 2:
        goto loc_10004CBC;

      case 3:
        goto loc_10004C70;

      case 4:
        goto loc_10004C38;

      case 101:
        goto loc_10004AA4;

      case 102:
        goto loc_10004A80;

      case 103:
        goto loc_10004A14;

      case 8:
        goto loc_10004B98;

      case 9:
        goto loc_10004B84;

      case 10:
        goto loc_10004B6C;

      case 11:
        goto loc_10004B54;

      case 12:
        goto loc_10004B30;

      case 13:
        goto loc_10004B1C;

      case 14:
        goto loc_10004B04;

      case 15:
        goto loc_10004AC8;

      case 7:
        goto loc_10004BB8;

      case 6:
        goto loc_10004BEC;

      case 5:
        goto loc_10004C00;

      default:
        goto def_100049B4;

    }

  }
  loc_100049BC:
  {
    ;
    killSeq__GP7animSeq(ARGS);
  }

  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 0));
  def_100049B4:
  t9.u64 = (uint64_t) printf;

  ARGS->a0.u64 = (uint64_t) 268500992;
  ARGS->a2.u64 = *((int32_t *) (s0.u32 + 16));
  {
    ARGS->a0.u64 = (uint64_t) (&aWarningBadComm[0]);
    ARGS->v0.u64 = (int) printf((const char *) ARGS->a0.u64, (int32_t) ARGS->a1.u64);
  }
  ARGS->a2.u64 = *((int32_t *) (s0.u32 + 16));
  ARGS->a1.u64 = *((int32_t *) (ARGS->a2.u32 + 28));
  ARGS->a1.u64 = *((int32_t *) (ARGS->a1.u32 + 20));
  *((uint32_t *) (ARGS->a2.u32 + 28)) = ARGS->a1.u32;
  loc_100049EC:
  ra.u64 = var_10;

  loc_100049F0:
  s0.u64 = var_20;

  gp.u64 = var_18;
  {
    sp.u64 = (int32_t) (sp.u32 + 32);
    return;
  }
  loc_10004A00:
  ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
  {
    *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
    goto loc_100049EC;
  }
  loc_10004A14:
  {
    memcpy(&ARGS->f12, &flt_100092A8, 4);
    exprand__Gf(ARGS);
  }

  memcpy(&f8, &flt_100092A8, 4);
  memcpy(&f4, (char *) (s0.u32 + 12), 4);
  ARGS->a4.u64 = *((int32_t *) (s0.u32 + 16));
  memcpy(&f9, &dbl_10009308, 8);
  f7.d = ARGS->f0.s;
  memcpy(&f5, (char *) (ARGS->a4.u32 + 20), 4);
  f7.d = f7.d * f9.d;
  f6.d = f4.s;
  f8.s = f8.s - f5.s;
  f6.d = f6.d * f7.d;
  memcpy(&f3, (char *) (ARGS->a4.u32 + 8), 4);
  f5.d = f5.s;
  f4.s = f4.s * f8.s;
  f5.d = f5.d * f6.d;
  f4.d = f4.s;
  f3.d = f3.s;
  f4.d = f4.d + f5.d;
  f3.d = f3.d + f4.d;
  f3.s = f3.d;
  memcpy((char *) (ARGS->a4.u32 + 8), &f3, 4);
  ARGS->a4.u64 = *((int32_t *) (s0.u32 + 16));
  ARGS->a3.u64 = *((int32_t *) (ARGS->a4.u32 + 28));
  ARGS->a3.u64 = *((int32_t *) (ARGS->a3.u32 + 20));
  {
    *((uint32_t *) (ARGS->a4.u32 + 28)) = ARGS->a3.u32;
    goto loc_100049EC;
  }
  loc_10004A80:
  memcpy(&f4, (char *) (s0.u32 + 12), 4);

  f6.u64 = 0;
  f4.d = f4.s;
  if (f4.d < f6.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    memcpy(&f5, &dbl_10009300, 8);
    goto loc_10004E0C;
  }
  else
    memcpy(&f5, &dbl_10009300, 8);

  {
    f4.d = f6.d;
    goto loc_10004E20;
  }
  loc_10004AA4:
  memcpy(&f4, (char *) (s0.u32 + 12), 4);

  memcpy(&f5, &dbl_10009300, 8);
  f4.d = f4.s;
  if (f4.d < f5.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    ;
    goto loc_10004DEC;
  }
  else
    ;

  {
    f4.d = f5.d;
    goto loc_10004DEC;
  }
  loc_10004AC8:
  ARGS->a5.u64 = (uint64_t) seqList;

  ARGS->a5.u64 = seqList;
  if (ARGS->a5.u64 == 0)
  {
    ARGS->a0.u64 = ARGS->a5.u64;
    goto def_100049B4;
  }
  else
    ARGS->a0.u64 = ARGS->a5.u64;

  loc_10004AD8:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 16));

  if (ARGS->a1.u64 != ARGS->a0.u64)
  {
    t9.u64 = (uint64_t) killSeq__GP7animSeq;
    goto loc_100049BC;
  }
  else
    t9.u64 = (uint64_t) killSeq__GP7animSeq;

  ARGS->a6.u64 = *((int32_t *) (ARGS->a1.u32 + 28));
  ARGS->a6.u64 = *((int32_t *) (ARGS->a6.u32 + 20));
  *((uint32_t *) (ARGS->a1.u32 + 28)) = ARGS->a6.u32;
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 36));
  if (ARGS->a0.u64 != 0)
  {
    ;
    goto loc_10004AD8;
  }
  else
    ;

  {
    ARGS->a1.u64 = *((int32_t *) (s0.u32 + 0));
    goto def_100049B4;
  }
  loc_10004B04:
  ARGS->a7.u64 = (uint64_t) seqList;

  ARGS->a7.u64 = seqList;
  if (ARGS->a7.u64 == 0)
  {
    ARGS->a0.u64 = ARGS->a7.u64;
    goto loc_10004D24;
  }
  else
    ARGS->a0.u64 = ARGS->a7.u64;

  {
    ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));
    goto loc_10004D18;
  }
  loc_10004B1C:
  t5.u64 = *((int32_t *) (s0.u32 + 16));

  t4.u64 = *((int32_t *) (t5.u32 + 28));
  t4.u64 = *((int32_t *) (t4.u32 + 20));
  {
    *((uint32_t *) (t5.u32 + 28)) = t4.u32;
    goto loc_100049EC;
  }
  loc_10004B30:
  t7.u64 = *((int32_t *) (s0.u32 + 16));

  t6.u64 = *((int32_t *) (t7.u32 + 24));
  *((uint32_t *) (t7.u32 + 28)) = t6.u32;
  t5.u64 = *((int32_t *) (s0.u32 + 16));
  memcpy(&f6, (char *) (t5.u32 + 12), 4);
  memcpy(&f5, (char *) (t5.u32 + 8), 4);
  f5.s = f5.s + f6.s;
  {
    memcpy((char *) (t5.u32 + 8), &f5, 4);
    goto loc_100049EC;
  }
  loc_10004B54:
  t8.u64 = (uint64_t) seqList;

  t8.u64 = seqList;
  if (t8.u64 == 0)
  {
    ARGS->a0.u64 = t8.u64;
    goto loc_10004D60;
  }
  else
    ARGS->a0.u64 = t8.u64;

  {
    ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));
    goto loc_10004D54;
  }
  loc_10004B6C:
  t9.u64 = (uint64_t) seqList;

  t9.u64 = seqList;
  if (t9.u64 == 0)
  {
    ARGS->a0.u64 = t9.u64;
    goto loc_10004DA0;
  }
  else
    ARGS->a0.u64 = t9.u64;

  {
    ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));
    goto loc_10004D94;
  }
  loc_10004B84:
  at.u64 = *((int32_t *) (s0.u32 + 16));

  ra.u64 = *((int32_t *) (at.u32 + 28));
  ra.u64 = *((int32_t *) (ra.u32 + 20));
  {
    *((uint32_t *) (at.u32 + 28)) = ra.u32;
    goto loc_100049EC;
  }
  loc_10004B98:
  t9.u64 = (uint64_t) stopAnimation__Gv;

  {
    ;
    stopAnimation__Gv(ARGS);
  }
  ARGS->v0.u64 = *((int32_t *) (s0.u32 + 16));
  at.u64 = *((int32_t *) (ARGS->v0.u32 + 28));
  at.u64 = *((int32_t *) (at.u32 + 20));
  {
    *((uint32_t *) (ARGS->v0.u32 + 28)) = at.u32;
    goto loc_100049EC;
  }
  loc_10004BB8:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

  ARGS->a0.u64 = (uint64_t) acttable;
  ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004BD8;
  }
  else
    ;

  *((uint8_t *) (ARGS->a0.u32 + 0)) = 0;
  loc_10004BD8:
  ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
  {
    *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
    goto loc_100049EC;
  }
  loc_10004BEC:
  ARGS->a4.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->a3.u64 = *((int32_t *) (ARGS->a4.u32 + 28));
  ARGS->a3.u64 = *((int32_t *) (ARGS->a3.u32 + 20));
  {
    *((uint32_t *) (ARGS->a4.u32 + 28)) = ARGS->a3.u32;
    goto loc_100049EC;
  }
  loc_10004C00:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

  ARGS->a0.u64 = (uint64_t) acttable;
  ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004C24;
  }
  else
    ;

  memcpy(&f7, (char *) (ARGS->a0.u32 + 36), 4);
  memcpy((char *) (ARGS->a0.u32 + 24), &f7, 4);
  loc_10004C24:
  ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
  {
    *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
    goto loc_100049EC;
  }
  loc_10004C38:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

  ARGS->a0.u64 = (uint64_t) acttable;
  ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004C5C;
  }
  else
    ;

  memcpy(&f8, (char *) (s0.u32 + 12), 4);
  memcpy((char *) (ARGS->a0.u32 + 24), &f8, 4);
  loc_10004C5C:
  ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
  {
    *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
    goto loc_100049EC;
  }
  loc_10004C70:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

  ARGS->a0.u64 = (uint64_t) acttable;
  ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004E6C;
  }
  else
    ;

  memcpy(&f5, (char *) (s0.u32 + 12), 4);
  memcpy(&f4, (char *) (ARGS->a0.u32 + 16), 4);
  if (f4.s < f5.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    memcpy(&f6, (char *) (ARGS->a0.u32 + 12), 4);
    goto loc_10004E80;
  }
  else
    memcpy(&f6, (char *) (ARGS->a0.u32 + 12), 4);

  if (f5.s < f6.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    ;
    goto loc_10004E40;
  }
  else
    ;

  {
    f5.s = f6.s;
    goto loc_10004E40;
  }
  loc_10004CBC:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 4));

  ARGS->a0.u64 = (uint64_t) acttable;
  ARGS->a1.u64 = (int32_t) (ARGS->a1.u32 << 2);
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + ARGS->a1.u32);
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 0));
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004DD8;
  }
  else
    ;

  memcpy(&f5, (char *) (s0.u32 + 12), 4);
  memcpy(&f4, (char *) (ARGS->a0.u32 + 16), 4);
  if (f4.s < f5.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    ;
    goto loc_10004DD4;
  }
  else
    ;

  {
    f5.s = f4.s;
    goto loc_10004DD4;
  }
  loc_10004CF8:
  ARGS->a3.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->a2.u64 = *((int32_t *) (ARGS->a3.u32 + 28));
  ARGS->a2.u64 = *((int32_t *) (ARGS->a2.u32 + 20));
  {
    *((uint32_t *) (ARGS->a3.u32 + 28)) = ARGS->a2.u32;
    goto loc_100049EC;
  }
  loc_10004D0C:
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 36));

  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004D24;
  }
  else
    ;

  loc_10004D18:
  ARGS->a3.u64 = *((int32_t *) (ARGS->a0.u32 + 0));

  if (ARGS->a3.u64 != ARGS->a1.u64)
  {
    ;
    goto loc_10004D0C;
  }
  else
    ;

  loc_10004D24:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 16));

  if (ARGS->a1.u64 != ARGS->a0.u64)
  {
    ra.u64 = var_10;
    goto loc_100049F0;
  }
  else
    ra.u64 = var_10;

  if (ARGS->a0.u64 == 0)
  {
    t9.u64 = (uint64_t) killSeq__GP7animSeq;
    goto loc_10004EB4;
  }
  else
    t9.u64 = (uint64_t) killSeq__GP7animSeq;

  {
    ;
    killSeq__GP7animSeq(ARGS);
  }
  {
    ra.u64 = var_10;
    goto loc_100049F0;
  }
  loc_10004D48:
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 36));

  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004D6C;
  }
  else
    ;

  loc_10004D54:
  ARGS->a4.u64 = *((int32_t *) (ARGS->a0.u32 + 0));

  if (ARGS->a4.u64 != ARGS->a1.u64)
  {
    ;
    goto loc_10004D48;
  }
  else
    ;

  loc_10004D60:
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004D6C;
  }
  else
    ;


  *((uint32_t *) (ARGS->a0.u32 + 28)) = 0;
  loc_10004D6C:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 16));

  if (ARGS->a1.u64 == ARGS->a0.u64)
  {
    ra.u64 = var_10;
    goto loc_100049F0;
  }
  else
    ra.u64 = var_10;

  ARGS->a5.u64 = *((int32_t *) (ARGS->a1.u32 + 28));
  ARGS->a5.u64 = *((int32_t *) (ARGS->a5.u32 + 20));
  {
    *((uint32_t *) (ARGS->a1.u32 + 28)) = ARGS->a5.u32;
    goto loc_100049EC;
  }
  loc_10004D88:
  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 36));

  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004DB8;
  }
  else
    ;

  loc_10004D94:
  ARGS->a6.u64 = *((int32_t *) (ARGS->a0.u32 + 0));

  if (ARGS->a6.u64 != ARGS->a1.u64)
  {
    ;
    goto loc_10004D88;
  }
  else
    ;

  loc_10004DA0:
  if (ARGS->a0.u64 == 0)
  {
    ;
    goto loc_10004DB8;
  }
  else
    ;


  ARGS->a7.u64 = *((int32_t *) (ARGS->a0.u32 + 24));
  *((uint32_t *) (ARGS->a0.u32 + 28)) = ARGS->a7.u32;
  memcpy(&f9, (char *) (ARGS->a4.u32 + 0), 4);
  memcpy((char *) (ARGS->a0.u32 + 8), &f9, 4);
  loc_10004DB8:
  ARGS->a1.u64 = *((int32_t *) (s0.u32 + 16));

  if (ARGS->a1.u64 == ARGS->a0.u64)
  {
    ra.u64 = var_10;
    goto loc_100049F0;
  }
  else
    ra.u64 = var_10;

  t4.u64 = *((int32_t *) (ARGS->a1.u32 + 28));
  t4.u64 = *((int32_t *) (t4.u32 + 20));
  {
    *((uint32_t *) (ARGS->a1.u32 + 28)) = t4.u32;
    goto loc_100049EC;
  }
  loc_10004DD4:
  memcpy((char *) (ARGS->a0.u32 + 16), &f5, 4);

  loc_10004DD8:
  t6.u64 = *((int32_t *) (s0.u32 + 16));

  t5.u64 = *((int32_t *) (t6.u32 + 28));
  t5.u64 = *((int32_t *) (t5.u32 + 20));
  {
    *((uint32_t *) (t6.u32 + 28)) = t5.u32;
    goto loc_100049EC;
  }
  loc_10004DEC:
  t7.u64 = *((int32_t *) (s0.u32 + 16));

  f10.s = f4.d;
  memcpy((char *) (t7.u32 + 16), &f10, 4);
  t7.u64 = *((int32_t *) (s0.u32 + 16));
  t6.u64 = *((int32_t *) (t7.u32 + 28));
  t6.u64 = *((int32_t *) (t6.u32 + 20));
  {
    *((uint32_t *) (t7.u32 + 28)) = t6.u32;
    goto loc_100049EC;
  }
  loc_10004E0C:
  if (f5.d < f4.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;


  ;
  if (!EPANOS_fp_cond)
  {
    ;
    goto loc_10004E20;
  }
  else
    ;

  f4.d = f5.d;
  loc_10004E20:
  t9.u64 = *((int32_t *) (s0.u32 + 16));

  f11.s = f4.d;
  memcpy((char *) (t9.u32 + 20), &f11, 4);
  t9.u64 = *((int32_t *) (s0.u32 + 16));
  t8.u64 = *((int32_t *) (t9.u32 + 28));
  t8.u64 = *((int32_t *) (t8.u32 + 20));
  {
    *((uint32_t *) (t9.u32 + 28)) = t8.u32;
    goto loc_100049EC;
  }
  loc_10004E40:
  {
    memcpy((char *) (ARGS->a0.u32 + 12), &f5, 4);
    goto loc_10004E4C;
  }

  loc_10004E48:
  memcpy((char *) (ARGS->a0.u32 + 16), &f5, 4);

  loc_10004E4C:
  ARGS->v0.u64 = *((int32_t *) (s0.u32 + 16));

  memcpy(&ARGS->f13, (char *) (ARGS->v0.u32 + 16), 4);
  memcpy((char *) (ARGS->a0.u32 + 28), &ARGS->f13, 4);
  at.u64 = *((int32_t *) (s0.u32 + 16));
  memcpy(&ARGS->f12, (char *) (at.u32 + 20), 4);
  ra.u64 = 1;
  *((uint8_t *) (ARGS->a0.u32 + 0)) = ra.u8;
  memcpy((char *) (ARGS->a0.u32 + 32), &ARGS->f12, 4);
  loc_10004E6C:
  ARGS->a0.u64 = *((int32_t *) (s0.u32 + 16));

  ARGS->v1.u64 = *((int32_t *) (ARGS->a0.u32 + 28));
  ARGS->v1.u64 = *((int32_t *) (ARGS->v1.u32 + 20));
  {
    *((uint32_t *) (ARGS->a0.u32 + 28)) = ARGS->v1.u32;
    goto loc_100049EC;
  }
  loc_10004E80:
  if (f4.s < f6.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;


  ;
  if (!EPANOS_fp_cond)
  {
    f5.s = f4.s;
    goto loc_10004E94;
  }
  else
    f5.s = f4.s;

  f5.s = f6.s;
  loc_10004E94:
  memcpy((char *) (ARGS->a0.u32 + 12), &f5, 4);

  memcpy(&f6, (char *) (s0.u32 + 12), 4);
  if (f4.s < f6.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    f5.s = f6.s;
    goto loc_10004E48;
  }
  else
    f5.s = f6.s;

  {
    f5.s = f4.s;
    goto loc_10004E48;
  }
  loc_10004EB4:
  ARGS->a0.u64 = *((int32_t *) (ARGS->a1.u32 + 28));

  ARGS->a0.u64 = *((int32_t *) (ARGS->a0.u32 + 20));
  {
    *((uint32_t *) (ARGS->a1.u32 + 28)) = ARGS->a0.u32;
    goto loc_100049EC;
  }
}

void display__Gv(EPANOS_ARGS *ARGS, wincount_t wincount)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  double var_50;
  uint64_t var_30;
  uint64_t var_20;
  double var_48;
  uint64_t var_10;
  double var_40;
  double var_28;
  uint64_t var_18;
  uint64_t var_38;
  uint64_t var_8;
  display__Gv:
  at.u64 = (int32_t) (1 << 16);

  sp.u64 = (int32_t) (sp.u32 + -80);
  at.u64 = 45256;
  var_30 = gp.u64;
  gp.u64 = (int32_t) (t9.u32 + at.u32);
  t9.u64 = (uint64_t) glClear;
  var_38 = ra.u64;
  ARGS->a0.u64 = 16384;
  {
    memcpy(&var_28, &f20, 8);
    wrap_glClear((unsigned int) ARGS->a0.u64, wincount);
  }
  memcpy(&f20, &flt_100092A8, 4);
  t9.u64 = (uint64_t) glColor3f;
  ARGS->f14.s = f20.s;
  ARGS->f13.s = f20.s;
  var_8 = s0.u64;
  {
    ARGS->f12.s = f20.s;
    wrap_glColor3f((float) ARGS->f12.s, (float) ARGS->f13.s, (float) ARGS->f14.s, wincount);
  }
  s0.u64 = (uint64_t) acttable;
  ARGS->v1.u64 = (uint64_t) (&t);
  ARGS->v0.u64 = acttable[45];
  memcpy(&f1, &t, 4);
  memcpy(&ARGS->f2, (char *) (ARGS->v0.u32 + 24), 4);
  var_20 = s1.u64;
  s1.u64 = (uint64_t) (&n);
  memcpy(&ARGS->f0, &dbl_10009300, 8);
  f1.s = f1.s + ARGS->f2.s;
  ARGS->a0.u64 = n;
  f1.d = f1.s;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 + 1);
  var_18 = s2.u64;
  ARGS->a3.u64 = (int32_t) (ARGS->a0.i32 >> 31);
  if (ARGS->f0.d <= f1.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ARGS->a2.u64 = (uint64_t) (&aflag);
  ARGS->a0.u64 = ARGS->a0.u64 ^ ARGS->a3.u64;
  var_10 = s3.u64;
  s3.u64 = 1;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a3.u32);
  ARGS->a1.u64 = aflag;
  ARGS->f0.u32 = 0;
  if (!EPANOS_fp_cond)
  {
    ARGS->a0.u64 = ARGS->a0.u64 & 127;
    goto loc_10005F8C;
  }
  else
    ARGS->a0.u64 = ARGS->a0.u64 & 127;

  memcpy(&t, &ARGS->f0, 4);
  ARGS->a0.u64 = ARGS->a0.u64 ^ ARGS->a3.u64;
  ARGS->a0.u64 = (int32_t) (ARGS->a0.u32 - ARGS->a3.u32);
  {
    n = ARGS->a0.u32;
    goto loc_10005F90;
  }
  loc_10005F8C:
  s3.u64 = 0;

  loc_10005F90:
  if (ARGS->a1.u64 == 0)
  {
    t9.u64 = (uint64_t) tasteQueue__Gv;
    goto loc_10005FB8;
  }
  else
    t9.u64 = (uint64_t) tasteQueue__Gv;


  {
    ;
    tasteQueue__Gv(ARGS);
  }
  t9.u64 = (uint64_t) setacttargets__Gv;
  {
    ;
    setacttargets__Gv(ARGS);
  }
  t9.u64 = (uint64_t) animateacts__Gv;
  {
    ;
    animateacts__Gv(ARGS);
  }
  loc_10005FB8:
  t9.u64 = (uint64_t) floor;

  ARGS->a2.u64 = (uint64_t) dtwist;
  ARGS->a4.u64 = (uint64_t) (&dwheel);
  ARGS->a6.u64 = (uint64_t) wrist;
  t4.u64 = (uint64_t) arm;
  s2.u64 = (uint64_t) (&n);
  t6.u64 = (uint64_t) dzoom;
  s2.u64 = n;
  ARGS->f18.u32 = 0;
  t8.u64 = (uint64_t) y;
  ra.u64 = (uint64_t) x;
  s1.u64 = (int32_t) (s2.u32 << 2);
  t7.u64 = acttable[31];
  t8.u64 = (int32_t) (s1.u32 + t8.u32);
  ra.u64 = (int32_t) (s1.u32 + ra.u32);
  memcpy((char *) (t8.u32 + 0), &ARGS->f18, 4);
  memcpy((char *) (ra.u32 + 0), &ARGS->f18, 4);
  memcpy(&ARGS->f17, (char *) (t7.u32 + 24), 4);
  t5.u64 = acttable[94];
  t6.u64 = (int32_t) (s1.u32 + t6.u32);
  memcpy((char *) (t6.u32 + 0), &ARGS->f17, 4);
  memcpy(&ARGS->f16, (char *) (t5.u32 + 24), 4);
  ARGS->a7.u64 = acttable[101];
  t4.u64 = (int32_t) (s1.u32 + t4.u32);
  memcpy((char *) (t4.u32 + 0), &ARGS->f16, 4);
  memcpy(&ARGS->f15, (char *) (ARGS->a7.u32 + 24), 4);
  ARGS->a5.u64 = acttable[73];
  ARGS->a6.u64 = (int32_t) (s1.u32 + ARGS->a6.u32);
  memcpy((char *) (ARGS->a6.u32 + 0), &ARGS->f15, 4);
  memcpy(&ARGS->f14, (char *) (ARGS->a5.u32 + 24), 4);
  ARGS->a3.u64 = acttable[38];
  memcpy(&dwheel, &ARGS->f14, 4);
  memcpy(&ARGS->f13, (char *) (ARGS->a3.u32 + 24), 4);
  ARGS->a1.u64 = acttable[52];
  ARGS->a2.u64 = (int32_t) (s1.u32 + ARGS->a2.u32);
  memcpy((char *) (ARGS->a2.u32 + 0), &ARGS->f13, 4);
  memcpy(&ARGS->f12, (char *) (ARGS->a1.u32 + 24), 4);
  memcpy(&var_50, &ARGS->f14, 8);
  {
    ARGS->f12.d = ARGS->f12.s;
    ARGS->f0.d = (double) floor((double) ARGS->f12.d);
  }
  ARGS->a6.u64 = (uint64_t) (&nlimit);
  f23.i32 = trunc_w_d(ARGS->f0.d);
  memcpy(&nlimit, &f23, 4);
  ARGS->a5.u64 = acttable[18];
  memcpy(&f21, (char *) (ARGS->a5.u32 + 24), 4);
  ARGS->f19.u64 = 0;
  f21.d = f21.s;
  ARGS->a4.u64 = (uint64_t) outline;
  if (ARGS->f19.d < f21.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ARGS->a3.u64 = 1;
  ARGS->a4.u64 = (int32_t) (s2.u32 + ARGS->a4.u32);
  ARGS->a2.u64 = acttable[123];
  if (EPANOS_fp_cond)
  {
    ;
    goto loc_10006094;
  }
  else
    ;

  ARGS->a3.u64 = 0;
  loc_10006094:
  *((uint8_t *) (ARGS->a4.u32 + 0)) = ARGS->a3.u8;

  memcpy(&f5, (char *) (ARGS->a2.u32 + 24), 4);
  memcpy(&f6, &flt_100092B4, 4);
  ARGS->a1.u64 = (uint64_t) hue;
  if (f20.s <= f5.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ARGS->a3.u64 = (uint64_t) light;
  ARGS->a1.u64 = (int32_t) (s1.u32 + ARGS->a1.u32);
  ARGS->a2.u64 = acttable[130];
  ARGS->a7.u64 = (int32_t) (s1.u32 + ARGS->a3.u32);
  if (!EPANOS_fp_cond)
  {
    memcpy((char *) (ARGS->a1.u32 + 0), &f5, 4);
    goto loc_100060C8;
  }
  else
    memcpy((char *) (ARGS->a1.u32 + 0), &f5, 4);

  f5.s = f5.s + f6.s;
  memcpy((char *) (ARGS->a1.u32 + 0), &f5, 4);
  loc_100060C8:
  if (f5.s <= f20.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;


  ;
  if (!EPANOS_fp_cond)
  {
    ;
    goto loc_100060E0;
  }
  else
    ;

  f25.s = f5.s + f20.s;
  memcpy((char *) (ARGS->a1.u32 + 0), &f25, 4);
  loc_100060E0:
  memcpy(&f27, (char *) (ARGS->a2.u32 + 24), 4);

  memcpy(&f20, &flt_10009290, 4);
  if (s3.u64 == 0)
  {
    memcpy((char *) (ARGS->a7.u32 + 0), &f27, 4);
    goto loc_10006194;
  }
  else
    memcpy((char *) (ARGS->a7.u32 + 0), &f27, 4);

  t5.u64 = *((int32_t *) (s0.u32 + 320));
  t6.u64 = (uint64_t) (&dflip);
  t7.u64 = *((int32_t *) (s0.u32 + 348));
  s3.u64 = (uint64_t) (&gflip);
  memcpy(&ARGS->f13, (char *) (t7.u32 + 24), 4);
  memcpy(&ARGS->f12, &gflip, 4);
//  s3.u64 = (uint64_t) fmodf;
  memcpy(&dflip, &ARGS->f13, 4);
  memcpy(&f29, (char *) (t5.u32 + 24), 4);
  t4.u64 = (uint64_t) (&dspin);
  t9.u64 = s3.u64;
  memcpy(&var_48, &f29, 8);
  ARGS->f12.s = ARGS->f12.s + ARGS->f13.s;
  ARGS->f13.s = f20.s;
  {
    memcpy(&dspin, &f29, 4);
    ARGS->f0.s = (float) fmodf((float) ARGS->f12.s, (float) ARGS->f13.s);
  }
  s1.u64 = (uint64_t) (&gspin);
  memcpy(&ARGS->f13, &var_48, 8);
  memcpy(&ARGS->f12, &gspin, 4);
  t9.u64 = s3.u64;
  t8.u64 = (uint64_t) (&gflip);
  memcpy(&var_40, &ARGS->f0, 8);
  memcpy(&gflip, &ARGS->f0, 4);
  ARGS->f12.s = ARGS->f12.s + ARGS->f13.s;
  {
    ARGS->f13.s = f20.s;
    ARGS->f0.s = (float) fmodf((float) ARGS->f12.s, (float) ARGS->f13.s);
  }
  ra.u64 = (int32_t) (s2.i32 >> 31);
  t9.u64 = s2.u64 ^ ra.u64;
  t9.u64 = (int32_t) (t9.u32 - ra.u32);
  t9.u64 = t9.u64 & 127;
  memcpy(&ARGS->f15, &var_40, 8);
  t9.u64 = t9.u64 ^ ra.u64;
  at.u64 = (uint64_t) flip;
  t9.u64 = (int32_t) (t9.u32 - ra.u32);
  ra.u64 = (uint64_t) spin;
  t9.u64 = (int32_t) (t9.u32 << 2);
  memcpy(&gspin, &ARGS->f0, 4);
  at.u64 = (int32_t) (t9.u32 + at.u32);
  t9.u64 = (int32_t) (t9.u32 + ra.u32);
  memcpy((char *) (at.u32 + 0), &ARGS->f15, 4);
  memcpy((char *) (t9.u32 + 0), &ARGS->f0, 4);
  loc_10006194:
//  t9.u64 = (uint64_t) fmodf;

  ra.u64 = (uint64_t) (&wheel);
  memcpy(&ARGS->f13, &var_50, 8);
  memcpy(&ARGS->f12, &wheel, 4);
  s1.u64 = var_20;
  s2.u64 = var_18;
  s3.u64 = var_10;
  ARGS->f12.s = ARGS->f12.s - ARGS->f13.s;
  {
    ARGS->f13.s = f20.s;
    ARGS->f0.s = (float) fmodf((float) ARGS->f12.s, (float) ARGS->f13.s);
  }
  t9.u64 = (uint64_t) drawit__Gv;
  at.u64 = (uint64_t) (&wheel);
  memcpy(&f20, &var_28, 8);
  {
    memcpy(&wheel, &ARGS->f0, 4);
    drawit__Gv(ARGS, wincount);
  }
  ARGS->v1.u64 = *((int32_t *) (s0.u32 + 180));
  ARGS->v0.u64 = (uint64_t) (&t);
  memcpy(&ARGS->f15, (char *) (ARGS->v1.u32 + 24), 4);
  memcpy(&ARGS->f14, &t, 4);
  t9.u64 = (uint64_t) glFinish;
  ARGS->f14.s = ARGS->f14.s + ARGS->f15.s;
  {
    memcpy(&t, &ARGS->f14, 4);
    wrap_glFinish(wincount);
  }
  //t9.u64 = (uint64_t) swapBuffers__Q2_10GLXWrapper6windowGv;
  ARGS->a0.u64 = (uint64_t) (&theWindow);
  s0.u64 = var_8;
  {
    ARGS->a0.u64 = theWindow;
    ;
  }
  //t9.u64 = (uint64_t) (&sginap);
  {
    ARGS->a0.u64 = 0;
    ;
  }
  ra.u64 = var_38;
  gp.u64 = var_30;
  {
    sp.u64 = (int32_t) (sp.u32 + 80);
    return;
  }
}

static void setacttargets__Gv(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  double var_30;
  uint64_t var_10;
  uint64_t var_28;
  uint64_t var_20;
  uint64_t var_8;
  uint64_t var_18;
  setacttargets__Gv:
  sp.u64 = (int32_t) (sp.u32 + -48);

  var_28 = s2.u64;
  var_18 = ra.u64;
  memcpy(&var_30, &f20, 8);
  var_20 = s1.u64;
  at.u64 = (int32_t) (1 << 16);
  var_10 = s0.u64;
  at.u64 = 49072;
  var_8 = gp.u64;
  gp.u64 = (int32_t) (t9.u32 + at.u32);
  s0.u64 = (uint64_t) acttable;
  s1.u64 = 0;
  {
    memcpy(&f20, &flt_100092A8, 4);
    goto loc_10005034;
  }
  loc_10005024:
  s1.u64 = (int32_t) (s1.u32 + 1);

  if (((signed) s1.i64) < ((signed) 1024))
    ARGS->v0.u64 = 1;
  else
    ARGS->v0.u64 = 0;

  if (ARGS->v0.u64 == 0)
  {
    s0.u64 = (int32_t) (s0.u32 + 4);
    goto loc_10005108;
  }
  else
    s0.u64 = (int32_t) (s0.u32 + 4);

  loc_10005034:
  s2.u64 = *((int32_t *) (s0.u32 + 0));

  if (s2.u64 == 0)
  {
    ;
    goto loc_10005024;
  }
  else
    ;

  ARGS->v1.u64 = *((int8_t *) (s2.u32 + 0));
  if (ARGS->v1.u64 == 0)
  {
    ARGS->a1.u64 = *((int8_t *) (s2.u32 + 1));
    goto loc_10005024;
  }
  else
    ARGS->a1.u64 = *((int8_t *) (s2.u32 + 1));

  if (ARGS->a1.u64 != 0)
  {
    t9.u64 = (uint64_t) drand48;
    goto loc_10005024;
  }
  else
    t9.u64 = (uint64_t) drand48;

  ARGS->a0.u64 = 1;
  {
    *((uint8_t *) (s2.u32 + 1)) = ARGS->a0.u8;
    ARGS->f0.d = (double) drand48();
  }
  memcpy(&f3, (char *) (s2.u32 + 12), 4);
  ARGS->f0.s = ARGS->f0.d;
  memcpy(&f1, (char *) (s2.u32 + 16), 4);
  ARGS->f2.s = f20.s - ARGS->f0.s;
  ARGS->f0.s = f3.s * ARGS->f0.s;
  t9.u64 = (uint64_t) exprand__Gf;
  f1.s = f1.s * ARGS->f2.s;
  ARGS->f0.s = ARGS->f0.s + f1.s;
  ARGS->f12.s = f20.s;
  {
    memcpy((char *) (s2.u32 + 8), &ARGS->f0, 4);
    exprand__Gf(ARGS);
  }
  memcpy(&f6, &flt_100092AC, 4);
  memcpy(&ARGS->f2, (char *) (s2.u32 + 32), 4);
  memcpy(&f1, (char *) (s2.u32 + 28), 4);
  f3.s = ARGS->f0.s * f6.s;
  f4.s = f20.s - ARGS->f2.s;
  f3.s = f1.s * f3.s;
  f1.s = f1.s * f4.s;
  ARGS->f2.s = ARGS->f2.s * f3.s;
  f1.s = f1.s + ARGS->f2.s;
  if (f1.s < f20.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  ;
  if (!EPANOS_fp_cond)
  {
    f5.s = f20.s;
    goto loc_10005128;
  }
  else
    f5.s = f20.s;

  loc_100050C0:
  memcpy(&f7, (char *) (s2.u32 + 20), 4);

  memcpy(&f4, (char *) (s2.u32 + 8), 4);
  f4.s = f4.s - f7.s;
  f4.s = f4.s / f5.s;
  f7.u32 = 0;
  ;
  if (f7.s < f4.s)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  s0.u64 = (int32_t) (s0.u32 + 4);
  ARGS->a2.u64 = (int32_t) (s1.u32 + 1);
  if (((signed) s1.i64) < ((signed) 1023))
    ARGS->a1.u64 = 1;
  else
    ARGS->a1.u64 = 0;

  s1.u64 = ARGS->a2.u64;
  if (!EPANOS_fp_cond)
  {
    memcpy((char *) (s2.u32 + 20), &f4, 4);
    goto loc_100050FC;
  }
  else
    memcpy((char *) (s2.u32 + 20), &f4, 4);

  {
    f4.s = f20.s;
    goto loc_10005100;
  }
  loc_100050FC:
  memcpy(&f4, &flt_100092B4, 4);

  loc_10005100:
  if (ARGS->a1.u64 != 0)
  {
    memcpy((char *) (s2.u32 + 4), &f4, 4);
    goto loc_10005034;
  }
  else
    memcpy((char *) (s2.u32 + 4), &f4, 4);


  loc_10005108:
  gp.u64 = var_8;

  s0.u64 = var_10;
  ra.u64 = var_18;
  s1.u64 = var_20;
  s2.u64 = var_28;
  memcpy(&f20, &var_30, 8);
  {
    sp.u64 = (int32_t) (sp.u32 + 48);
    return;
  }
  loc_10005128:
  t9.u64 = (uint64_t) exprand__Gf;

  {
    ARGS->f12.s = f20.s;
    exprand__Gf(ARGS);
  }
  memcpy(&f6, &flt_100092AC, 4);
  memcpy(&f7, (char *) (s2.u32 + 32), 4);
  memcpy(&f5, (char *) (s2.u32 + 28), 4);
  f8.s = ARGS->f0.s * f6.s;
  f9.s = f20.s - f7.s;
  f8.s = f5.s * f8.s;
  f5.s = f5.s * f9.s;
  f7.s = f7.s * f8.s;
  {
    f5.s = f5.s + f7.s;
    goto loc_100050C0;
  }
}

void reshape__GiT1(const GLuint width, const GLuint height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(300.0,
                   (GLdouble)((float)width / (float)height),
                   0.01,
                   10000.0);
    glTranslatef(0.0f, 0.0f, -4.0f);
    glMatrixMode(GL_MODELVIEW);
}

static void twixt__GiPff(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  twixt__GiPff:
  ARGS->a4.u64 = (int32_t) (ARGS->a0.u32 + -1);

  ARGS->a6.u64 = (int32_t) (ARGS->a0.u32 << 2);
  ARGS->v0.u64 = (int32_t) (1 << 16);
  ARGS->a5.u64 = (int32_t) (ARGS->a1.u32 + ARGS->a6.u32);
  ARGS->v0.u64 = 48704;
  if (ARGS->a0.i64 <= 0)
  {
    at.u64 = (int32_t) (t9.u32 + ARGS->v0.u32);
    goto loc_100051A0;
  }
  else
    at.u64 = (int32_t) (t9.u32 + ARGS->v0.u32);

  loc_10005178:
  memcpy(&ARGS->f2, &flt_100092A8, 4);

  ARGS->v1.u64 = (int32_t) (ARGS->a4.u32 << 2);
  memcpy(&ARGS->f0, (char *) (ARGS->a5.u32 + 0), 4);
  ARGS->v1.u64 = (int32_t) (ARGS->a1.u32 + ARGS->v1.u32);
  memcpy(&f1, (char *) (ARGS->v1.u32 + 0), 4);
  ARGS->f2.s = ARGS->f2.s - ARGS->f14.s;
  ARGS->f0.s = ARGS->f0.s * ARGS->f14.s;
  f1.s = f1.s * ARGS->f2.s;
  {
    ARGS->f0.s = ARGS->f0.s + f1.s;
    return;
  }
  loc_100051A0:
  {
    ARGS->a4.u64 = (int32_t) (ARGS->a4.u32 + 128);
    goto loc_10005178;
  }

}

static void exprand__Gf(EPANOS_ARGS *ARGS)
{
  EPANOS_REG t4;
  EPANOS_REG t5;
  EPANOS_REG t6;
  EPANOS_REG t7;
  EPANOS_REG s0;
  EPANOS_REG s1;
  EPANOS_REG s2;
  EPANOS_REG s3;
  EPANOS_REG s4;
  EPANOS_REG s5;
  EPANOS_REG s6;
  EPANOS_REG s7;
  EPANOS_REG at;
  EPANOS_REG t8;
  EPANOS_REG t9;
  EPANOS_REG gp;
  EPANOS_REG sp;
  EPANOS_REG ra;
  EPANOS_REG fp;
  EPANOS_REG f1;
  EPANOS_REG f3;
  EPANOS_REG f4;
  EPANOS_REG f5;
  EPANOS_REG f6;
  EPANOS_REG f7;
  EPANOS_REG f8;
  EPANOS_REG f9;
  EPANOS_REG f10;
  EPANOS_REG f11;
  EPANOS_REG f20;
  EPANOS_REG f21;
  EPANOS_REG f22;
  EPANOS_REG f23;
  EPANOS_REG f24;
  EPANOS_REG f25;
  EPANOS_REG f26;
  EPANOS_REG f27;
  EPANOS_REG f28;
  EPANOS_REG f29;
  EPANOS_REG f30;
  EPANOS_REG f31;
  int EPANOS_fp_cond;
  double var_20;
  uint64_t var_18;
  uint64_t var_10;
  exprand__Gf:
  ARGS->f0.u64 = 0;

  sp.u64 = (int32_t) (sp.u32 + -32);
  memcpy(&var_20, &f30, 8);
  f30.d = ARGS->f12.s;
  if (ARGS->f0.d < f30.d)
    EPANOS_fp_cond = 1;
  else
    EPANOS_fp_cond = 0;

  at.u64 = (int32_t) (1 << 16);
  var_10 = ra.u64;
  at.u64 = 55164;
  var_18 = gp.u64;
  if (!EPANOS_fp_cond)
  {
    gp.u64 = (int32_t) (t9.u32 + at.u32);
    goto loc_10003890;
  }
  else
    gp.u64 = (int32_t) (t9.u32 + at.u32);

  t9.u64 = (uint64_t) drand48;
  loc_10003850:
  {
    ;
    ARGS->f0.d = (double) drand48();
  }

  t9.u64 = (uint64_t) expm1;
  {
    ARGS->f12.d = ARGS->f0.d * f30.d;
    ARGS->f0.d = (double) expm1((double) ARGS->f12.d);
  }
  t9.u64 = (uint64_t) expm1;
  f30.d = ARGS->f0.d;
  {
    memcpy(&ARGS->f12, &dbl_10009300, 8);
    ARGS->f0.d = (double) expm1((double) ARGS->f12.d);
  }
  ARGS->f0.d = f30.d / ARGS->f0.d;
  ra.u64 = var_10;
  gp.u64 = var_18;
  memcpy(&f30, &var_20, 8);
  sp.u64 = (int32_t) (sp.u32 + 32);
  {
    ARGS->f0.s = ARGS->f0.d;
    return;
  }
  loc_10003890:
//  t9.u64 = (uint64_t) __assert;

  ARGS->a2.u64 = 264;
  ARGS->a1.u64 = (uint64_t) aEp_c;
  {
    ARGS->a0.u64 = (uint64_t) aM0_0;
    ;
  }
  {
    t9.u64 = (uint64_t) drand48;
    goto loc_10003850;
  }
}
