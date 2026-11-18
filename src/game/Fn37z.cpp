// More small functions in the ProDG game-code island 0x370000-0x387430.
extern "C" {
int func_00373A50(char *);
int func_0037E8D8(int *);
int func_0037FE78(char *, char *);
void func_00374598(int **);
int func_0037D0A8(int);
int func_00373D90(void *);
void func_00373FC8(void *);
int func_00374360(void *);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x37D728
// diff: addu operand order (1 word)
extern "C" void func_0037D728(char *o)
{
    int a = *(unsigned short *)(o + 0x46) + *(unsigned short *)(o + 0x48);
    *(unsigned short *)(o + 0x4A) = a;
    if (((unsigned char *)o)[5] & 1)
        return;
    *(unsigned short *)(o + 0x4A) = *(unsigned short *)(o + 0x2E) + a;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x37E488
// diff: result reg v1 vs v0, branch sense (3 words)
extern "C" void func_0037E488(char *o)
{
    o[2] = func_0037E8D8((int *)o) ? 0xC : 1;
}
#endif

// FUNCTION: GAME 0x37FE40
extern "C" void func_0037FE40(char *o)
{
    if (func_0037FE78(o, o + 0x370))
        o[2] = 1;
}

// FUNCTION: GAME 0x373A18
extern "C" void func_00373A18(char *o, int v)
{
    if (func_00373A50(o))
        *(int *)(o + 0x50) = v;
}

// FUNCTION: GAME 0x376400
extern "C" void func_00376400(int *o)
{
    if (!func_0037D0A8(o[1])) {
        *(short *)o = 0;
        o[1] = 0;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x373F38
// diff: s0/s1 swapped (saved-reg allocation)
extern "C" int func_00373F38(void *o)
{
    int r = func_00373D90(o);
    func_00373FC8(o);
    return r;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x374508
// diff: s0/s1 swapped (saved-reg allocation)
extern "C" int func_00374508(void *o)
{
    int r = func_00374360(o);
    func_00374598((int **)o);
    return r;
}
#endif
