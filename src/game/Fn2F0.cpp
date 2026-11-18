// Small free functions in 0x2F0000-0x30A2AF.

extern "C" {

struct S2F_A { char _p0[4]; int m_04; int m_08; int m_0C; int m_10[1]; };
struct S2F_Obj420 { char _p0[0x420]; float m_420; int m_424; };
struct S2F_Obj400 { int m_400pad; };

extern char D_00450080[];
extern char D_0044FCF8[];
struct S2F_E { int m_0; int m_4; int m_8; int m_C; };
void func_0030F5A0(char *a);
void func_002FB7B0(int a);
void func_00300C00(int a, int b);
void func_003028E8(char *a);

int func_003069A8(void *a, unsigned b, void **c);
int func_002F7110(int a);
int func_002F7CD8(int a);
int func_002FBCC8(int a);
int func_002E3480(int a);
int func_002E81D8(int a);
int func_002FBE88(int a, int b, int c, int d);
int func_00306AA8(int a, int b, int c, int d);

// FUNCTION: GAME 0x003069E8
int func_003069E8(char *a, int b, int *c, int *d) {
    *c = (int)(a + *(int *)(a + 4));
    *d = (int)(a + *(int *)(a + 8));
    return 1;
}

// FUNCTION: GAME 0x00306A48
int func_00306A48(char *a, unsigned b, int *c) {
    *c = 0;
    if (b >= *(unsigned *)(a + 4))
        return 0;
    int *t = (int *)(a + 0x10);
    int o = t[b];
    if (o == 0)
        return 0;
    *c = (int)(a + o);
    return 1;
}

// FUNCTION: GAME 0x00306A08
int func_00306A08(char *a, unsigned b, void **c) {
    *c = 0;
    char *p = a + *(int *)(a + 0xC);
    if (b >= *(unsigned *)(p + 4))
        return 0;
    return func_003069A8(p, b, c);
}

// FUNCTION: GAME 0x00306A88
int func_00306A88(int a, int b, int c, int d) { return func_00306AA8(a, b, c, d); }

// FUNCTION: GAME 0x003052E8
int func_003052E8(int a, int b, int c, int d) { return func_002FBE88(a, b, c, d); }

// FUNCTION: GAME 0x00305A18
char *func_00305A18(char *a) {
    *(char **)(a + 0x424) = D_00450080;
    *(float *)(a + 0x420) = 1.0f;
    return a;
}

// FUNCTION: GAME 0x00305BC0
void func_00305BC0(unsigned *a) {
    a[0x414 / 4] = 0;
    a[0x400 / 4] = 0;
    a[0x404 / 4] = 0;
    a[0x408 / 4] = 0xFFFFFFFFu;
    a[0x40C / 4] = 0xFFFFFFFFu;
}

// FUNCTION: GAME 0x00300060
int func_00300060(int a) { int r = a; if (a) r = func_002F7110(a); return r; }

// FUNCTION: GAME 0x00300088
int func_00300088(int a) { int r = a; if (a) r = func_002F7CD8(a); return r; }

// FUNCTION: GAME 0x002FFA68
int func_002FFA68(int a) { int r = a; if (a) r = func_002FBCC8(a); return r; }

// FUNCTION: GAME 0x002FFB10
int func_002FFB10(int a) { int r = a; if (a) r = func_002E3480(a); return r; }

// FUNCTION: GAME 0x002FFBD0
int func_002FFBD0(int a) { int r = a; if (a) r = func_002E81D8(a); return r; }

// FUNCTION: GAME 0x003057A0
void func_003057A0(S2F_E *e) {
    for (unsigned i = 0; i < 0x40; i++) {
        e->m_0 = 5;
        e->m_4 = 0;
        e->m_8 = 0;
        e->m_C = 0;
        e++;
    }
}

// FUNCTION: GAME 0x003058D8
S2F_E *func_003058D8(S2F_E *e, int k) {
    for (unsigned i = 0; i < 0x40; i++) {
        if (e->m_0 == k)
            return e;
        e++;
    }
    return 0;
}

// FUNCTION: GAME 0x00305A38
void func_00305A38(char *a, int b) {
    *(char **)(a + 0x424) = D_00450080;
    if (b & 1)
        func_0030F5A0(a);
}

// FUNCTION: GAME 0x00306140
void func_00306140(void) {
    func_002FB7B0(0x20);
    func_00300C00(0x20, 1);
}

// FUNCTION: GAME 0x00304F58
void func_00304F58(char *a) {
    *(char **)(a + 0xF0) = D_0044FCF8;
    func_003028E8(a);
}

}
