// COMPILER: ee-gcc2.96
extern int D_00758400, D_003E8DCC, D_003E9944;
extern char D_004551B8[];
extern void func_00336330();
extern void *memset(void *, int, unsigned);
extern char D_003E9D60[];
extern void func_00338990(), func_003389F8(), func_00338AC0(), func_00338A10(), func_00338B40(), func_003389C8();
extern void func_003394D0(), func_00339550(), func_0033A0C0(), func_0033A140(), func_00332670();
extern void func_0033F9D8(), func_0033FA10(), func_0033F9B0(), func_0033FA00(), func_0033FB48();
extern void func_003325F8(), func_0033BDD8(), func_0033F888(), func_0033C520(), func_0033C708();

// FUNCTION: GAME 0x33AF28
void func_0033AF28(int a)
{
    D_00758400 = a;
    func_00332670(0x23, &D_00758400, 1, 0, 0);
}

// FUNCTION: GAME 0x33CFB8
void func_0033CFB8(char *p)
{
    func_0033F9D8(*(int *)(p + 8), p + 0xAC, p + 0xB0);
    func_0033FA10(*(int *)(p + 8), p + 0xA6, p + 0xA8, p + 0xAA);
}

// FUNCTION: GAME 0x33CFF8
void func_0033CFF8(char *p)
{
    func_0033F9B0(*(int *)(p + 8), p + 0xAC, p + 0xB0);
    func_0033FA00(*(int *)(p + 8), *(short *)(p + 0xA6), *(short *)(p + 0xA8), *(short *)(p + 0xAA));
}

// FUNCTION: GAME 0x33D278
void func_0033D278(int *p)
{
    if (p[1] == 3) {
        func_0033FB48(p[2]);
        p[35] = 0;
        p[1] = 0;
    }
}

// FUNCTION: GAME 0x33B010
void func_0033B010(void)
{
    if (--D_003E8DCC == 0)
        func_003325F8();
}

#ifdef NONMATCHING
// DRAFT: GAME 0x33BE80 (4 words off: original tests the first load in $v1 and schedules ld $ra before the add)
void func_0033BE80(void)
{
    int *s = &D_003E9944;
    int v;
    v = *s;
    if (v == 0)
        func_0033BDD8();
    (*s)++;
}
#endif

// FUNCTION: GAME 0x33C728
void func_0033C728(void)
{
    func_0033F888();
    func_0033C520();
    memset(D_003E9D60, 0, 0x1040);
    func_0033C708(0);
}

// FUNCTION: GAME 0x336AC0
int func_00336AC0(int *p)
{
    if (p == 0) {
        func_00336330((int *)p, D_004551B8);
        return 0;
    }
    return p[5];
}
