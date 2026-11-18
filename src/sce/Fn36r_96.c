// COMPILER: ee-gcc2.96
extern int D_003EE330;
extern int D_003EE338[];
extern int D_003EE800[];
void func_0035FF98(int);
extern void *memset(void *, int, unsigned);
int *func_0035FF48(void);
void func_0035FC18(int);
int func_00360CA0();

// FUNCTION: GAME 0x35FEF0
int *func_0035FEF0(void)
{
    int *p = func_0035FF48();
    if (p) {
        func_0035FF98((int)p);
        D_003EE800[0] = D_003EE800[0] + 1;
        *p = 1;
        return p;
    }
    return p;
}

// FUNCTION: GAME 0x35F8B8
int func_0035F8B8(void)
{
    memset(D_003EE338, 0, 0x4C8);
    D_003EE338[1] = 8;
    func_0035FC18(1);
    return func_00360CA0();
}

extern int D_003EE340[];

// FUNCTION: GAME 0x35FBD8
void func_0035FBD8(int a, int b, int c)
{
    void (*fn)() = (void (*)())D_003EE340[0];
    int n = D_003EE340[2] + 1;
    int arg = D_003EE340[1];
    D_003EE340[2] = n;
    if (fn) fn(arg, c);
}

extern volatile int D_003EEA78;
extern int D_003EEA7C;
extern int D_003EEA80;
extern int *D_0045A260[];

// DRAFT: GAME 0x360AA8
// 13 words: register allocation (orig a1/a2/a3 vs mine a3/t0), andi/xori order
#ifdef NONMATCHING
void func_00360AA8(void)
{
    D_003EEA78--;
    if (D_003EEA78 == 0) {
        int idx = D_003EEA7C;
        if (idx != -1) {
            int v = D_003EEA80;
            int x = v ^ 0xC00;
            if ((v & 0xC7) != 0x82) *D_0045A260[idx] = x;
        }
    }
    if (D_003EEA78 < 0) D_003EEA78 = 0;
}
#endif

extern int D_00766CA0;
extern int D_003EE334;
int func_0035F8A8(void);
void func_0035FE60(void);
void func_0035FE90(void);
void func_0036CA50(void);

// DRAFT: GAME 0x35F838
// 18 words: original keeps explicit addiu for &D_00766CA0 before the sw in the call delay slot
#ifdef NONMATCHING
void func_0035F838(void)
{
    if (D_003EE330 <= 0) {
        D_00766CA0 = func_0035F8A8();
        func_0035F8B8();
        func_0035FE60();
        func_0035FE90();
        func_0036CA50();
        D_003EE334 = 0;
        D_003EE330++;
    }
}
#endif

int func_00365EB0();
int func_00365D90();

// DRAFT: GAME 0x365D18
// 25 words: original loads/copies the two sub-structs in a different order and keeps *c in t1/t3
#ifdef NONMATCHING
int func_00365D18(int *a, int *b, int *c)
{
    int l[12];
    int t;
    l[0] = a[1];
    l[1] = a[4];
    l[2] = a[3];
    l[4] = b[1];
    l[5] = b[2];
    l[6] = b[3];
    l[7] = b[4];
    t = *c;
    if (t == 0) t = func_00365EB0();
    return func_00365D90(l, l + 4, t);
}
#endif

int func_00369370();
int func_003691D8(unsigned char *);

// DRAFT: GAME 0x3691D8
// 19 words differ: register allocation (v in a3 vs v1, const in a2 vs a3), structure matches
#ifdef NONMATCHING
int func_003691D8(unsigned char *p)
{
    unsigned v;
    int r = 0;
    v = (((p[0] << 8 | p[1]) << 8 | p[2]) << 8 | p[3]);
    if (v == 0x100) r = 4;
    else if (v == 0x101) r = 3;
    else if (v - 0x102 < 0xAE) r = 1;
    else if (v == 0x1B2) r = 0x20;
    else if (v == 0x1B3) r = 0x40;
    else if (v == 0x1B5) r = 0x10;
    else if (v == 0x1B7) r = 0x80;
    else if (v == 0x1B8) r = 8;
    return r;
}

#endif

// DRAFT: GAME 0x36A708
// 38 words differ: prologue/s0 order and tail (original 164 B vs 152 B)
#ifdef NONMATCHING
int func_0036A708(int *a, int *b)
{
    int v = a[0xD7];
    if (v == 0) {
        int p = func_00369370(b[0], b[1], 0x40);
        if (p) {
            int q;
            p += 4;
            q = func_00369370(p, b[1] - (p - b[0]), -1);
            if (q) {
                int r = func_003691D8((unsigned char *)q);
                if (r & 0x10) a[0xD7] = 2;
                else if (r) a[0xD7] = 1;
            }
        }
        v = a[0xD7];
    }
    return v;
}
#endif

int func_0036C5F8();
void func_00369F20();
extern char D_003F1AA0[];

// FUNCTION: GAME 0x369E98
int func_00369E98(char *a, int b, int c)
{
    int *p;
    if (a == 0) {
        p = (int *)D_003F1AA0;
    } else {
        if (func_0036C5F8()) {
            func_00369F20(0, 0xFF030203);
            return;
        }
        p = (int *)(a + 0x250);
    }
    p[0] = b;
    p[1] = c;
    return 0;
}
