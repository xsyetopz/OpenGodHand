// Divide-padded units; the DIVNOP tag restores the original nops before div.s.
extern "C" void func_002D65D0(char *, float *);
extern "C" void SetOffsetPosY__12CustomIDWorki(char *, int);
extern "C" void func_001855A8(char *, int);
extern "C" void func_00185690(char *, int);

// FUNCTION: GAME 0x1F55C0
// DIVNOP: 2
extern "C" void func_001F55C0(char *self, int a, int, int c)
{
    float v[2];
    func_002D65D0(self + 0x30D0, v);
    char *s = self + 0x31C8;
    func_002D65D0(s, v + 1);
    SetOffsetPosY__12CustomIDWorki(s, (int)(v[0] / (float)a * (float)c));
}

// FUNCTION: GAME 0x2B4228
// DIVNOP: 1 2
extern "C" int func_002B4228(int *self)
{
    int n = self[4] + 1;
    self[4] = n;
    unsigned a = 6 - n;
    float f1 = (float)a / 6.0f;
    float f2 = (float)(a * a);
    f1 = f1 + f1;
    float f0 = f2 / 36.0f;
    ((float *)self)[0x28] = f0;
    ((float *)self)[0x26] = f1 - f0;
    ((float *)self)[0x27] = f1 - f0;
    return self[4] == 6;
}

// FUNCTION: GAME 0x184B60
// DIVNOP: 2
extern "C" void func_00184B60(char *self)
{
    float r = (float)*(short *)(self + 0x620) / (float)*(short *)(self + 0x62E);
    switch (*(unsigned char *)(self + 0x656)) {
    case 0:
        if (r <= 0.95f) { func_001855A8(self, 1); (*(unsigned char *)(self + 0x656))++; }
        break;
    case 1:
        if (r <= 0.9f) { func_001855A8(self, 4); (*(unsigned char *)(self + 0x656))++; }
        break;
    case 2:
        if (r <= 0.75f) { func_00185690(self, 1); (*(unsigned char *)(self + 0x656))++; }
        break;
    case 3:
        if (r <= 0.5f) { func_00185690(self, 2); (*(unsigned char *)(self + 0x656))++; }
        break;
    case 4:
        if (r <= 0.25f) { func_00185690(self, 3); (*(unsigned char *)(self + 0x656))++; }
        break;
    case 5:
        if (r <= 0.0f) { func_00185690(self, 4); (*(unsigned char *)(self + 0x656))++; }
        break;
    case 6:
        *(unsigned char *)(self + 0x65D) = 1;
        break;
    }
}

#ifdef NONMATCHING
extern "C" void sceVu0CopyVector(float *, const float *);
extern "C" void sceVu0ApplyMatrix(float *, void *, const float *);
extern "C" void Gp_draw_poly3__FPA3_CfUiUi7eOtTypeUi(float *, int, int, int, int);
extern "C" void Gp_draw_poly4__FPA3_CfUiUiPC7GP_INFO7eOtTypeUi(float *, int, int, int, int, int);
extern void *pCamWork;
struct K { unsigned char v; unsigned char pad; unsigned short t; };
extern "C" K *func_002BDEE8(float);
extern "C" K *func_002BDF30(char *, int, int, float);
extern char CoreSave[];
extern float g_HeatSys;
extern "C" int func_001F4530(char *, int, int);
extern "C" int getVitalMax__9cCoreSave(char *);
extern "C" int getReelItem__9cCoreSave(char *);
extern "C" void func_001F5650(char *, int, int, int, int, int, int, int);

// DRAFT: GAME 0x2BDDE0
// diff: 8 words; prologue scheduling (mov.s f20,f12 goes into the jal delay slot in the original, swc1 f20 saved after s1); u=t copy temps and nested-if forms tried, copies get propagated
// needs DIVNOP: 2
extern "C" int func_002BDDE0(char *a, int b, int c, float t)
{
    K *p = func_002BDEE8(t);
    K *q = func_002BDF30(a, b, c, t);
    if (!p || !q) return 0;
    if (p == q) return p->v;
    float f = (t - (float)p->t) / (float)(q->t - p->t);
    return (int)((float)p->v * (1.0f - f) + (float)q->v * f);
}

// DRAFT: GAME 0x1F4248
// diff: 5 words; the u8 load at 0x37CA is hoisted above the bne/delay slot by the compiler
// needs DIVNOP: 2 2
extern "C" void func_001F4248(char *self)
{
    if (func_001F4530(self, *(short *)(self + 0x37A8), *(unsigned short *)(self + 0x37AC))) {
        short a, b, c, d;
        short t = *(short *)(self + 0x37BC);
        if (t != -1) {
            b = *(short *)(self + 0x37BE);
            a = t * 20 + 100;
        } else {
            a = getVitalMax__9cCoreSave(CoreSave);
            float f = (float)*(short *)(self + 0x37BE);
            if (100.0f < f) f = 100.0f;
            b = (int)(f / 100.0f * (float)a);
        }
        t = *(short *)(self + 0x37C0);
        if (t != -1) {
            float f = *(float *)(self + 0x37C4);
            c = t * 30 + 120;
            d = (int)f;
        } else {
            c = (int)g_HeatSys;
            float f = *(float *)(self + 0x37C4);
            if (100.0f < f) f = 100.0f;
            d = (int)(f / 100.0f * (float)c);
        }
        short r8 = *(short *)(self + 0x37C8);
        int r = r8;
        if (r8 == -1) r = getReelItem__9cCoreSave(CoreSave);
        func_001F5650(self + 0x60, 2, a, b, c, d, r, *(unsigned char *)(self + 0x37CA));
    } else {
        func_001F5650(self + 0x60, 1, 0, 0, 0, 0, 0, 0);
    }
}

// DRAFT: GAME 0x1334A8
// diff: 6 words; s4/s5 register assignment for a2 and the pCamWork address
// needs DIVNOP: 2 2
extern "C" void func_001334A8(float *p, int quad, int a2)
{
    float v[16];
    unsigned n, i;
    if (!quad) {
        sceVu0CopyVector(v, p);
        n = 3;
        sceVu0CopyVector(v + 4, p + 4);
        sceVu0CopyVector(v + 8, p + 8);
    } else {
        sceVu0CopyVector(v, p);
        n = 4;
        sceVu0CopyVector(v + 4, p + 4);
        sceVu0CopyVector(v + 8, p + 8);
        sceVu0CopyVector(v + 12, p + 12);
    }
    for (i = 0; i < n; i++) {
        float t[4];
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(char(*)[16])t));
        sceVu0ApplyMatrix(t, pCamWork, v + i * 4);
        if (t[3] == 0.0f) return;
        float x = t[0] / t[3];
        float y = t[1] / t[3];
        t[2] = t[3];
        t[0] = x;
        t[1] = y;
        if (t[3] < 0.0f) return;
        if (x < 0.0f) return;
        if (y < 0.0f) return;
        if (4096.0f < x) return;
        if (4096.0f < y) return;
    }
    if (!quad) Gp_draw_poly3__FPA3_CfUiUi7eOtTypeUi(v, a2, 0, 2, 2);
    else Gp_draw_poly4__FPA3_CfUiUiPC7GP_INFO7eOtTypeUi(v, a2, 0, 0, 2, 2);
}
#endif
