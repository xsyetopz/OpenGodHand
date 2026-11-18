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
