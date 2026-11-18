extern "C" int strcmp(const char *, const char *);
extern "C" char D_0044D100[];
extern "C" void func_00345EC8(int);
extern "C" void func_002D40F8(void *);
extern "C" void func_002D3200(void *);
extern "C" void func_002D0350(void *, int);

struct S3 { int w0; };

// FUNCTION: GAME 0x2D3710
extern "C" void func_002D3710(S3 *s) { if (s->w0) func_00345EC8(s->w0); func_002D40F8(s); }

// FUNCTION: GAME 0x2DA940
extern "C" float func_002DA940(float a, float b) { float d = a - b; if (d > 3.14159274f) return d - 6.28318548f; if (d < -3.14159274f) return d + 6.28318548f; return d; }

struct N { char name[4]; float f4, f8, fC; };
struct S2 { char pad[0x24]; N *n; };
// FUNCTION: GAME 0x2D2CF0
extern "C" float func_002D2CF0(S2 *s) {
    if (s->n && strcmp(s->n->name, D_0044D100) == 0 && s->n->f4 == 1.3f) return s->n->fC;
    return 0.018f;
}

// FUNCTION: GAME 0x2D2DC8
extern "C" char *func_002D2DC8(char *t) {
    *(int *)t = 0;
    char *p = t + 0x40;
    for (int i = 15; i != -1; i--) { func_002D3200(p); p += 0xC0; }
    *(int *)(t + 0xC40) = 1;
    return t;
}

struct Q { char pad[0x44]; float f44; };
struct P { char pad[4]; Q *w4; char pad2[0x54]; int w5C; int pad3; float f64, f68, f6C, f70; unsigned short h74, h76; };
// FUNCTION: GAME 0x2D69A8
extern "C" void func_002D69A8(P *a, unsigned short b, float x, float y) {
    Q *q = a->w4;
    if (q) {
        a->f64 = x; a->w5C = 3; a->f68 = y;
        a->f6C = q->f44; a->f70 = q->f44;
        a->h74 = b;
        if (!b) a->h74 = 1;
        a->h76 = 0;
    }
}

struct H { int w0, w4, w8; unsigned char b; };
struct K { char pad[0xC]; H *h; int w10; };
// FUNCTION: GAME 0x2D0360
extern "C" void func_002D0360(K *k) {
    if (!k->h->b) {
        k->h->w4 += (int)k->h;
        if (k->h->w8) k->h->w8 += (int)k->h;
        k->h->b = 1;
    }
    k->w10 = k->h->w4;
    func_002D0350(k, 2);
}

extern "C" int func_003B5968(int);
extern "C" void func_003B5A50(int);
extern "C" int func_002D3020(void *, int, int, int);
// FUNCTION: GAME 0x2D3050
extern "C" int func_002D3050(void *s, int a, int *o, int c) {
    *o = 0;
    int h = func_003B5968(c);
    if (h) {
        int r = func_002D3020(s, a, h, c);
        if (r) { *o = h; return r; }
        func_003B5A50(h);
    }
    return 0;
}

extern "C" int func_002D0C10(int, int);
// FUNCTION: GAME 0x2D0CD0
extern "C" int func_002D0CD0(int a) {
    int r = -2;
    if (func_002D0C10(a, 0x209)) r = 0x1B;
    else if (func_002D0C10(a, 0x223)) r = 0x2E;
    else if (func_002D0C10(a, 0x220) || func_002D0C10(a, 0x221) || func_002D0C10(a, 0x222)) r = 1;
    return r;
}

extern "C" char *func_002D2DB0(char *, int);
extern "C" int func_002CC568(char *);
extern "C" void func_002CC578(char *);
// FUNCTION: GAME 0x2D2228
extern "C" char *func_002D2228(char *s) {
    for (int i = 0; i < 16; i++) {
        if (func_002CC568(func_002D2DB0(s, i)) == 0) {
            func_002CC578(func_002D2DB0(s, i));
            return func_002D2DB0(s, i);
        }
    }
    return 0;
}

extern "C" int func_002D03D0(void *, int);
extern "C" int func_002CFF68(void *);
extern "C" int func_002D0318(void *);
extern "C" int func_002D03E8(void *);
extern "C" void func_002CFF90(void *);
extern "C" int func_00323000(int);
// FUNCTION: GAME 0x2D0068
extern "C" void func_002D0068(char *s) {
    if (func_002D03D0(s, 1)) {
        if (func_002CFF68(s) != 1) {
            if (!func_002D03D0(s, 2)) {
                if (func_002D0318(s) == 1) {
                    func_002D0360((K *)s);
                    if (!func_002D03E8(s)) func_002CFF90(s);
                }
            } else if (func_002D03D0(s, 4) == 1) {
                if (func_00323000(*(int *)(s + 0x18)) == 3) func_002D0350(s, 8);
            }
        }
    }
}
extern "C" void func_0030A4D0(float *, char *, int);
// FUNCTION: GAME 0x2D8008
extern "C" void func_002D8008(char *a, char *b, char *c, int d, int e) {
    float t[4];
    *(float *)(b + 0x3C) = 1.0f;
    func_0030A4D0(t, a + 0x30, e);
    float *dst = (float *)(c + 0x30);
    for (int i = 3; i != -1; i--) dst[3 - i] = t[3 - i];
}
extern "C" int func_002D3110(int *, int, int, int, int);
extern "C" int func_002D3190(int *);
extern "C" void func_002D3240(int, int, int, int, int, int);
// FUNCTION: GAME 0x2D2F78
extern "C" int func_002D2F78(int *s, int a, int b, int c, int d) {
    int h = func_002D3110(s, a, b, c, d);
    if (!h) return 0;
    int r = func_002D3190(s);
    func_002D3240(h, a, b, c, d, r);
    if (!*s) *s = h;
    return r;
}
struct SysT { char pad[0x5B0]; unsigned short m; };
extern "C" SysT Sys;
extern "C" int func_002D0D70(int, int);
extern "C" void func_002CD4A8(char *, float);
// FUNCTION: GAME 0x2D0850
extern "C" void func_002D0850(char *s) {
    int r = func_002D0D70((int)s, Sys.m);
    for (char *p = *(char **)(s + 0x18); p; p = *(char **)(p + 0x88)) {
        if (*(int *)(p + 0xB0) == 2) continue;
        if (*(int *)(p + 0x90) == r) continue;
        func_002CD4A8(p, 15.0f);
    }
    unsigned short m = Sys.m;
    if (m != 0x20 && m != 0x23) {
        *(int *)(s + 0x128) = -2;
        *(int *)(s + 0xB0) |= 0x200000;
        *(int *)(s + 0xAC) |= 0x200000;
    }
    *(int *)(s + 0x44) = 0;
    *(int *)(s + 0x138) = 3;
    *(int *)(s + 0x48) = 0;
}
struct VT5 { char pad[0x10]; short adj; short pad2; int (*fn)(char *, int); };
extern "C" void func_002D58E8(char *, int, int);
extern "C" void func_002D5440(char *, int);
// FUNCTION: GAME 0x2D5580
extern "C" int func_002D5580(char *s, int a, int b, int c) {
    VT5 *vt = *(VT5 **)(s + 0x30);
    int r = vt->fn(s + vt->adj, c);
    if (r != -1) func_002D58E8(*(char **)s + r * 0x58, a, b);
    func_002D5440(s, r);
    return r;
}
struct Q5 { char pad[0x28]; int w28; };
struct T5 { Q5 *w0; int w4; char pad[4]; unsigned short hC, hE; };
extern "C" int CreateThread(void *);
extern "C" void StartThread(int, void *);
extern "C" void func_003AFBD0(int);
extern "C" void WaitSema(int);
extern "C" void kill__9cTaskWork(void *);
// FUNCTION: GAME 0x2D57C8
extern "C" void func_002D57C8(T5 *s) {
    switch (s->hC) {
    case 2:
        s->w4 = CreateThread((char *)s + 0x20);
        StartThread(s->w4, s);
        goto L;
    case 1:
        if (--s->hE == 0) { func_003AFBD0(s->w4); goto L; }
        break;
    case 4:
    L: {
        Q5 *q = s->w0;
        s->hC = 0x7F;
        WaitSema(q->w28);
        break; }
    }
    if (s->hC == 0x7F) kill__9cTaskWork(s);
}
struct Hp;
extern "C" Hp D_00754200;
extern "C" char *_MemoryAlloc__FUiUiR5cHeap(unsigned, unsigned, Hp &);
extern "C" void *memset(void *, int, unsigned);
extern "C" void func_002D5768(char *, int, unsigned short, void *);
extern "C" int CreateSema(void *);
struct T2 { char *w0; int w4, w8; unsigned short hC, hE; char pad[4]; int w14, w18; char pad2[0xC]; int w28; };
// FUNCTION: GAME 0x2D50E8
extern "C" void func_002D50E8(T2 *s, int n, int a, int b) {
    s->hC = n;
    s->hE = b;
    s->w0 = _MemoryAlloc__FUiUiR5cHeap(n * 0x58, 0x10, D_00754200);
    memset(s->w0, 0, n * 0x58);
    for (unsigned i = 0; i < s->hC; i++)
        func_002D5768(s->w0 + i * 0x58, a, s->hE + i, s);
    s->w14 = 1;
    s->w18 = 0;
    s->w28 = CreateSema((char *)s + 0x10);
}
extern "C" void getEffTypeString__FPc12eEffDataType(char *, int);
extern "C" int sprintf(char *, const char *, ...);
extern "C" char D_0044D3B0[];
// FUNCTION: GAME 0x2D9F68
extern "C" void func_002D9F68(char *self, int a, ...) {
    char buf[0x100];
    char t[0x40];
    getEffTypeString__FPc12eEffDataType(t, *(short *)(self + 0x23A));
    sprintf(buf, D_0044D3B0, t, *(unsigned short *)(self + 0x23C) - 1, a);
}
extern "C" void func_002D34A8(char *);
extern "C" int func_002D3210(char *);
// FUNCTION: GAME 0x2D2E38
extern "C" void func_002D2E38(char **s) {
    int i;
    if (*s) {
    L:
        func_002D34A8(*s);
        if (!func_002D3210(*s)) {
            i = 1;
            char *end = (char *)s + 0xC40;
            char *base = (char *)s + 0x40;
            do {
                *s = *s + 0xC0;
                if (!(*s < end)) *s = base;
                if (func_002D3210(*s) == 1) { i++; goto L; }
                i++;
            } while (i < 16);
            *s = 0;
        }
    }
}