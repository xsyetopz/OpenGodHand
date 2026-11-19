struct S375380 {
    char pad0[0x10];
    int f10;
    char pad14[0x70];
    int f84;
    char pad88[4];
    unsigned f8C;
    unsigned f90;
};
extern S375380 D_0076A790;
extern char D_0076A600[];
extern "C" {
void func_00372CB0(char *);
void func_00374B00(void);
void func_003754A8(S375380 *);
void func_003754F0(S375380 *);
void func_00375500(void);
void func_00375F68(void);
void func_00376E00(void);
void func_003777C0(void);
void func_003778D8(void);
void func_00377FA0(void);
void func_0037C930(void);
void func_0037CA98(void);
void func_0037CAE0(void);
void func_0037CE20(void);
void func_00386D48(void);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x375380
// 2 words off: lw s3 (timer) vs addiu f10 swapped before jal; tried c temp, ++f10 before/after timer read, f10 = f10 + 1, ++f10, volatile ptr var, s2 temp
extern "C" void func_00375380(void)
{
    S375380 *g = &D_0076A790;
    unsigned s;
    if (g->f84 != 0) {
        func_00375500();
        g->f84 = 0;
    }
    s = *(volatile unsigned *)0x10000800;
    g->f10++;
    func_00377FA0();
    func_003777C0();
    func_0037C930();
    func_003754A8(g);
    func_0037CA98();
    func_00386D48();
    func_00376E00();
    func_00375F68();
    func_0037CAE0();
    func_00374B00();
    func_003778D8();
    func_0037CE20();
    func_003754F0(g);
    char *p = D_0076A600;
    do {
        func_00372CB0(p);
        p += 0x84;
    } while ((int)p < (int)(D_0076A600 + 0x18C));
    unsigned e = *(volatile unsigned *)0x10000800;
    if (e < s)
        g->f8C = 0;
    else
        g->f8C = e - s;
    unsigned m = g->f8C;
    if (g->f90 < m)
        g->f90 = m;
}
#endif
