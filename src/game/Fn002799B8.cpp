extern "C" {
extern char *D_00586A7C;
extern int D_00747A0C;
extern int IDManager;
void Gp_draw_polyFT4__FPA3_CfUiUiPUiUiUiPC7GP_INFO7eOtTypeUi(float *, unsigned int, int, int, int);
int func_002ACE28(int, int);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2799B8 81 words: float constant-load order and global-load order differ in the a/b setup; tried unsigned char temp (84), b[3] moved to end (82), kept b[3]/a[3] at top (81).
extern "C" void func_002799B8(char *self)
{
    float a[4];
    float b[4];
    volatile int dead;
    char *cur;
    char *v;
    char *d;
    char *e;
    char *p;
    int n;

    b[3] = 1.0f;
    a[3] = 1.0f;
    a[0] = -0.04f;
    a[1] = 0.08f;
    *(int *)&a[2] = 0;
    *(int *)&b[0] = 0;
    b[1] = -0.2f;
    b[2] = -0.2f;

    cur = D_00586A7C;
    dead = *(unsigned char *)(cur + 0x2B4);
    if (*(unsigned char *)(cur + 0x2B4) > 6)
        n = *(int *)(*(char **)(cur + 0x278) + 0x18);
    else
        n = 0;
    if (!n)
        return;

    v = 0;
    dead = *(unsigned char *)(self + 0x2B4);
    if (dead)
        v = *(char **)(*(char **)(self + 0x278));
    if (!v)
        return;

    d = *(char **)(v + 0xD0);
    *(int *)(v + 0x148) = n;
    *(int *)(v + 0x100) = 0;
    *(int *)(v + 0x104) = 0;
    *(int *)(v + 0x108) = 0;
    if (d != (char *)a) {
        *(float *)d = a[0];
        *(float *)(d + 4) = a[1];
        *(float *)(d + 8) = a[2];
    }
    e = v + 0x100;
    if (e != (char *)b) {
        *(float *)e = b[0];
        *(float *)(e + 4) = b[1];
        *(float *)(e + 8) = b[2];
    }

    *(char **)(self + 0x1580) = cur;
    *(int *)(self + 0x1584) = 6;
    p = self + 0x1590;
    if (p != (char *)a) {
        *(float *)p = a[0];
        *(float *)(p + 4) = a[1];
        *(float *)(p + 8) = a[2];
    }
    p = self + 0x15A0;
    if (p != (char *)b) {
        *(float *)p = b[0];
        *(float *)(p + 4) = b[1];
        *(float *)(p + 8) = b[2];
    }
    *(unsigned char *)(self + 0x2F7) = 0;
    *(unsigned char *)(self + 0x2F5) = 3;
    *(unsigned char *)(self + 0x2F4) = 0;
    *(unsigned char *)(self + 0x2F6) = 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2B00A0 89 words: frame 0xC0 vs compiled 0x50 (needs larger locals), original loads $f6 before $f3; m2c first draft in byte-offset form.
extern "C" void func_002B00A0(char *self)
{
    float poly[16];
    float var_f0;
    float var_f3;
    float t0;
    float t3;
    float t5;
    float t6;

    if ((unsigned short)*(short *)(*(char **)(self + 0x64) + 2) != *(short *)(self + 0x54))
        return;
    var_f3 = *(float *)(self + 0x8C);
    if (*(int *)self & 1)
        var_f3 += (*(float *)(self + 0x38) + 12.0f) * *(float *)(self + 0x48);
    var_f0 = 8.0f;
    if (D_00747A0C != 0) {
        var_f0 = 4.0f;
        var_f3 += 4.0f;
    }
    t6 = *(float *)(self + 0x88) + var_f0;
    t0 = var_f3 + 13.0f;
    t5 = t0 - 17.0f;
    t3 = t6 + 34.0f;
    t0 = t0 + 17.0f;
    poly[0] = t6;
    poly[1] = t0;
    poly[2] = 65535.0f;
    poly[3] = 1.0f;
    poly[4] = t3;
    poly[5] = t0;
    poly[6] = 65535.0f;
    poly[7] = 1.0f;
    poly[8] = t6;
    poly[9] = t5;
    poly[10] = 65535.0f;
    poly[11] = 1.0f;
    poly[12] = t3;
    poly[13] = t5;
    poly[14] = 65535.0f;
    poly[15] = 1.0f;
    Gp_draw_polyFT4__FPA3_CfUiUiPUiUiUiPC7GP_INFO7eOtTypeUi(poly, 0x80808080u, 1, func_002ACE28(IDManager, 0x2F), 2);
}
#endif
