// Slice F177 units: 0x2C4940, 0x2C4B78, 0x1BEA40, 0x2D4DC8, 0x17DB60.
#include "game/cScenario.h"
#include "game/cVec.h"

struct sSaveMgr;
extern unsigned int g_CasinoWork;
extern "C" void func_002C02E8(void *);
extern char *CoreSave;
extern char *g_Sce;
extern sSaveMgr *g_SaveManager;
extern unsigned int D_00747A24;
extern "C" char *Getplayer__Fv();
extern "C" void setCheckPoint__12cSaveManagerbPC4cVecT2(sSaveMgr *, int, int, int);
extern "C" void set__13cActionButton12eScePriority8eActType11eActBtnTypePvT48eActFunc(void *, int, int, int, void *, void *, void *);
extern "C" int getCasinoTicketNum__9cCoreSave(void *);
extern "C" float capVu0LengthSq__FPCf(const float *);
extern "C" void func_001BEB28(void);
extern char g_ActBtn;
extern char D_003C3560;
extern "C" void sceVu0ApplyMatrix(float *, void *, float *);
extern "C" float fRand0_1__Fv();
extern "C" int Rnd__Fv(void);

#define CP16(d, s) __asm__ volatile("lqc2 $vf4,0(%0)\n\tsqc2 $vf4,0(%1)" : : "r"(s), "r"(d) : "memory")
#define CP16B(d, s) __asm__ volatile("lqc2 $vf4,0(%0)\n\tsqc2 $vf4,%1" : : "r"(s), "m"(d) : "memory")

// FUNCTION: GAME 0x2C4940
extern "C" void beginCasinoBattle__9cScenario()
{
    sVec4 a;
    sVec4 b;
    char *v;
    char *vt;
    register void *(*f)(char *) asm("$5");
    *(unsigned int *)(CoreSave + 0x14) |= 0x04000000;
    v = Getplayer__Fv();
    vt = *(char **)(v + 0x214);
    f = *(void *(**)(char *))(vt + 0x84);
    CP16(&a, (char *)f(v + *(short *)(vt + 0x80)));
    v = Getplayer__Fv();
    vt = *(char **)(v + 0x214);
    f = *(void *(**)(char *))(vt + 0x8C);
    CP16B(b, (char *)f(v + *(short *)(vt + 0x88)));
    *(unsigned short *)(g_Sce + 0x16) = 0;
    *(cVec *)g_Sce = *(cVec *)&a;
    *(float *)(g_Sce + 0x10) = b.y;
    setCheckPoint__12cSaveManagerbPC4cVecT2(g_SaveManager, 0, 0, 0);
    D_00747A24 |= 0x08000000;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2C4B78
extern "C" void endKurohukuBattle__9cScenario(char *p)
{
    sVec4 pos;
    unsigned short room = *(unsigned short *)(p + 0x16);
    float ang;
    CP16(&pos, p);
    ang = *(float *)(p + 0x10);
    func_002C02E8(g_SaveManager);
    if ((((unsigned long)g_CasinoWork) >> 4) & 1) {
        ((cScenario *)g_Sce)->beginRoomJump(room, *(cVec *)&pos, ang, 0, 2, 1);
    } else {
        ((cScenario *)g_Sce)->beginRoomJump(room, *(cVec *)&pos, ang, 0, 0, 1);
    }
    g_CasinoWork = g_CasinoWork & ~8 & ~0x10;
    D_00747A24 &= 0xF7FFFFFF;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1BEA40
extern "C" void ChkTreasureBox__5cOmea(char *self)
{
    sVec4 e;
    sVec4 d;
    char *v;
    char *vt;
    char *pa;
    char *pb;
    register void *(*f)(char *) asm("$5");
    void *(*g)(char *);
    unsigned int fl = *(unsigned int *)(self + 0x600);
    if (fl & 1u) {
        return;
    }
    v = Getplayer__Fv();
    vt = *(char **)(v + 0x214);
    f = *(void *(**)(char *))(vt + 0x84);
    pa = (char *)f(v + *(short *)(vt + 0x80));
    vt = *(char **)(self + 0x214);
    g = *(void *(**)(char *))(vt + 0x84);
    pb = (char *)g(self + *(short *)(vt + 0x80));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(d));
    __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%2" : : "r"(pa), "r"(pb), "m"(d) : "memory");
    CP16(&e, &d);
    if (capVu0LengthSq__FPCf((float *)&e) < 1.0f && getCasinoTicketNum__9cCoreSave((void *)&CoreSave) != 0) {
        set__13cActionButton12eScePriority8eActType11eActBtnTypePvT48eActFunc((void *)&g_ActBtn, 4, 0, 0, (void *)func_001BEB28, self, 0);
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x17DB60
extern "C" void initMove__5cOl21RC4cVecT1f(char *self, float *a, float *b, float f)
{
    sVec4 d;
    sVec4 t;
    float *m;
    float *p;
    float r;
    float gx;
    float gz;
    m = (float *)(self + 0x610);
    p = *(float **)(self + 0xF0);
    if (p != m) {
        m[0] = p[0];
        m[1] = p[1];
        m[2] = p[2];
    }
    m = (float *)(self + 0x620);
    if (m != a) {
        m[0] = a[0];
        m[1] = a[1];
        m[2] = a[2];
    }
    m = (float *)(self + 0x630);
    if (m != b) {
        m[0] = b[0];
        m[1] = b[1];
        m[2] = b[2];
    }
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(t));
    __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%2" : : "r"(b), "r"(a), "m"(t) : "memory");
    CP16(&d, &t);
    r = f * fRand0_1__Fv();
    gx = d.x / f;
    *(float *)(self + 0x644) = 0.0f;
    gz = d.z / f;
    p = *(float **)(self + 0xF0);
    *(float *)(self + 0x640) = gx;
    *(float *)(self + 0x648) = gz;
    p[0] = a[0] + gx * r;
    p = *(float **)(self + 0xF0);
    p[2] = a[2] + *(float *)(self + 0x648) * r;
    if ((Rnd__Fv() ^ 1) & 1) {
        *(float *)(self + 0x640) = -*(float *)(self + 0x640);
        *(float *)(self + 0x648) = -*(float *)(self + 0x648);
    }
}
#endif

// FUNCTION: GAME 0x2D4DC8
extern "C" void setBasePoint__7cSplineP4cVec(char *self, float *src)
{
    float *d = (float *)self;
    sVec4 tv;
    float *t = &tv.x;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(tv));
    t[0] = src[0];
    t[1] = src[4];
    t[2] = src[8];
    t[3] = src[12];
    sceVu0ApplyMatrix(t, (void *)&D_003C3560, t);
    d[0] = t[0];
    d[4] = t[1];
    d[8] = t[2];
    d[12] = t[3];
    t[0] = src[1];
    t[1] = src[5];
    t[2] = src[9];
    t[3] = src[13];
    sceVu0ApplyMatrix(t, (void *)&D_003C3560, t);
    d[1] = t[0];
    d[5] = t[1];
    d[9] = t[2];
    d[13] = t[3];
    t[0] = src[2];
    t[1] = src[6];
    t[2] = src[10];
    t[3] = src[14];
    sceVu0ApplyMatrix(t, (void *)&D_003C3560, t);
    d[2] = t[0];
    d[6] = t[1];
    d[10] = t[2];
    d[14] = t[3];
}
