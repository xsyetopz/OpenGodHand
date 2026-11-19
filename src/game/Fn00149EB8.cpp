// Units in slice F150: 0x149EB8, 0x26A3D8, 0x2D8C60, 0x376B80.

struct Src2D8 { float a0; float a4; float a8; char _c[4]; float a10; float a14; float a18; char _1c[4]; float a20; float a24; float a28; char _2c[4]; unsigned char b30; unsigned char b31; unsigned char b32; };
struct Lt2D8 { unsigned char b0, b1, b2; char _3[0x2D]; float f30; float f34; float f38; char _3c[4]; float f40; float f44; float f48; char _4c[4]; float f50; float f54; float f58; };
extern Lt2D8 World_light_work;
extern char D_0061A400[];

extern "C" void MtxInitCoord__FR7cMatrixRC4cVecN21Uc(void *, int, void *, void *, unsigned char);
extern "C" void Adjust_theta_vec__FPf(void *);
extern "C" void func_00150138(void *);
extern "C" void func_001501D0(void *, unsigned);
extern "C" void func_00156D70(void *, void *, void *, float);

// FUNCTION: GAME 0x149EB8
extern "C" void calcParts__6cModel(char *self)
{
    if (!(*(unsigned *)(self + 0x250) & 0x800)) {
        char *s = self + 0x110;
        MtxInitCoord__FR7cMatrixRC4cVecN21Uc(self + 0x80, *(int *)(self + 0xF0), self + 0x100, s, *(unsigned char *)(self + 0x140));
        char *v = self + 0x120;
        if (v != s) {
            *(float *)(self + 0x120) = *(float *)(self + 0x110);
            *(float *)(v + 4) = *(float *)(s + 4);
            *(float *)(v + 8) = *(float *)(s + 8);
        }
    }
    if (*(float *)(self + 0x27C) > 0.0f) { *(unsigned *)(self + 0x250) |= 4; }
    else { *(unsigned *)(self + 0x250) &= ~4u; }
    int i = 0;
    char *p = *(char **)(self + 0x144);
    if (*(unsigned char *)(self + 0x2B4) != 0) {
        do {
            Adjust_theta_vec__FPf(p + 0x100);
            unsigned long b3x = *(unsigned *)(p + 0x154);
            if (((b3x >> 3) % 2) != 0) { } else func_00150138(p);
            float f12 = *(float *)(self + 0x27C);
            if (f12 > 0.0f) {
                if (!(*(unsigned *)(p + 0x154) & 0x100000) && !(*(unsigned *)(self + 0x250) & 0x20))
                    func_00156D70(p, p, p + 0x40, f12);
            }
            unsigned long b4 = *(unsigned *)(p + 0x154);
            if (((b4 >> 4) % 2) != 0) { } else func_001501D0(p, *(unsigned *)(self + 0x250));
            i += 1;
            p = *(char **)(p + 0x144);
        } while (i < (int)*(unsigned char *)(self + 0x2B4));
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2D8C60 - 91 differing words (376 vs 376 bytes); asm computes two indexed table addresses (a0 and a1 shifted by 7), reg allocation differs
extern "C" void func_002D8C60(float t, int idx)
{
    Src2D8 *s = (Src2D8 *)(D_0061A400 + (idx << 7));
    World_light_work.f30 = World_light_work.f30 + ((s->a0 - World_light_work.f30) * t);
    World_light_work.f34 = World_light_work.f34 + ((s->a4 - World_light_work.f34) * t);
    World_light_work.f38 = World_light_work.f38 + ((s->a8 - World_light_work.f38) * t);
    World_light_work.f40 = World_light_work.f40 + ((s->a10 - World_light_work.f40) * t);
    World_light_work.f44 = World_light_work.f44 + ((s->a14 - World_light_work.f44) * t);
    World_light_work.f48 = World_light_work.f48 + ((s->a18 - World_light_work.f48) * t);
    World_light_work.f50 = World_light_work.f50 + ((s->a20 - World_light_work.f50) * t);
    World_light_work.f54 = World_light_work.f54 + ((s->a24 - World_light_work.f54) * t);
    World_light_work.f58 = World_light_work.f58 + ((s->a28 - World_light_work.f58) * t);
    World_light_work.b0 = (unsigned char)(World_light_work.b0 + (int)((float)(s->b30 - World_light_work.b0) * t));
    World_light_work.b1 = (unsigned char)(World_light_work.b1 + (int)((float)(s->b31 - World_light_work.b1) * t));
    World_light_work.b2 = (unsigned char)(World_light_work.b2 + (int)((float)(s->b32 - World_light_work.b2) * t));
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x26A3D8 - 76 differing words (356 vs 380 bytes), best of 9 variants; volatile n spill and n re-read before 2nd test help, asm branch-likely shapes not reproduced
extern "C" void func_0026A3D8(char *self)
{
    volatile int n = *(unsigned char *)(self + 0x2B4);
    char *c = 0;
    if (n > 1)
        c = *(char **)(*(char **)(self + 0x278) + 4);
    if (c != 0) {
        unsigned f = *(unsigned *)(c + 0x154);
        if (*(float *)(self + 0x16FC) != 0.0f) {
            *(unsigned *)(c + 0x154) = f | 0x800;
            *(float *)(c + 0x150) = *(float *)(self + 0x16FC);
        } else {
            *(float *)(c + 0x150) = 0.0f;
            *(unsigned *)(c + 0x154) = f & ~0x800u;
        }
    }
    c = 0;
    n = *(unsigned char *)(self + 0x2B4);
    if (n > 2)
        c = *(char **)(*(char **)(self + 0x278) + 8);
    if (c != 0) {
        unsigned f = *(unsigned *)(c + 0x154);
        if (*(float *)(self + 0x16FC) != 0.0f) {
            *(unsigned *)(c + 0x154) = f | 0x800;
            *(float *)(c + 0x150) = *(float *)(self + 0x16FC);
        } else {
            *(float *)(c + 0x150) = 0.0f;
            *(unsigned *)(c + 0x154) = f & ~0x800u;
        }
    }
    int t = *(int *)(self + 0x564);
    float k;
    if (t != 0x223 && (t < 0x223 || t >= 0x277 || t < 0x275))
        k = 0.6f;
    else
        k = -0.6f;
    *(float *)(self + 0x16FC) = *(float *)(self + 0x16FC) * k;
    float a = *(float *)(self + 0x16FC);
    if (a < 0.0f)
        a = -a;
    if (a <= 0.017453292f)
        *(float *)(self + 0x16FC) = 0.0f;
}
#endif

struct Ca376 { char _0[2]; unsigned short h2; int w4; short h8; char _a[2]; unsigned char bC; unsigned char bD; unsigned char bE; unsigned char bF; char _10[4]; unsigned short h14; };
struct Cb376 { char _0[2]; unsigned short h2; int w4; unsigned short h8; short hA; unsigned short hC; unsigned short hE; unsigned short h10; unsigned char b12; unsigned char b13; };
struct E376 { char _0[4]; char *base; char _8[0x18]; };
struct S376 { char _0[4]; unsigned short h4; char _6[8]; unsigned short hE; char _10[8]; unsigned short h18; unsigned short h1A; };
struct R376 {
    short h0; short h2; int w4; int w8;
    unsigned char bC; unsigned char bD; short hE; short h10; short h12; short h14;
    char _16[0xA];
    short h20; short h22; short h24;
    signed char b26; unsigned char b27; unsigned char b28; unsigned char b29;
    short h2A; short h2C; short h2E; short h30; short h32; short h34; short h36; short h38; short h3A; short h3C;
    unsigned char b3E; char _3F; unsigned char b40; unsigned char b41; unsigned char b42; unsigned char b43;
};
extern E376 D_0076EA50[];
extern "C" void func_00376CF8(void *, void *, int);
extern "C" R376 *func_0037D170(int, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x376B80 - hoisted m1/c17 constants; 90 differing words (376 vs 376 bytes); frame -0x60 vs asm -0x70 (asm saves s0-s5 and ra)
extern "C" void func_00376B80(void *arg0, void *arg1)
{
    Ca376 *a = (Ca376 *)arg0;
    Cb376 *b = (Cb376 *)arg1;
    int t = (short)b->hA * 0x30;
    S376 *s5 = (S376 *)(D_0076EA50[a->h8].base + t);
    if (!(s5->hE & 0x8000)) {
        short m1 = -1;
        short c17 = 0x17;
        R376 *v = func_0037D170(t, 0x30);
        if (v != 0) {
            v->h0 = 3;
            v->w4 = b->w4;
            v->w8 = a->w4;
            v->bD = 4;
            v->bC = a->bE;
            v->hE = m1;
            v->h10 = 0;
            v->h12 = a->h2;
            v->h14 = b->h2;
            func_00376CF8(arg0, v, 4);
            v->h20 = b->h8;
            v->h22 = b->hA;
            v->h24 = s5->h4;
            v->b28 = 0x7F;
            v->b27 = 0;
            v->b26 = a->bF + (unsigned char)b->h2;
            v->b29 = 0;
            v->h2A = 0;
            v->h2E = c17;
            v->h2C = a->h14;
            v->h30 = b->hC;
            v->h32 = b->hC;
            v->h36 = 0;
            v->h34 = b->hE;
            v->h38 = s5->h18;
            v->h3A = s5->h1A;
            v->b3E = m1;
            v->h3C = b->h10;
            v->b41 = 0;
            v->b40 = 0;
            v->b43 = 0;
            v->b42 = 0;
        }
    }
}
#endif
