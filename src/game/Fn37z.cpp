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

// FUNCTION: GAME 0x37D728
extern "C" void func_0037D728(char *o)
{
    unsigned short *p = (unsigned short *)o;
    p[0x25] = p[0x23] + p[0x24];
    if (o[5] & 1)
        return;
    p[0x25] += p[0x17];
}

// FUNCTION: GAME 0x37E488
extern "C" void func_0037E488(char *o)
{
    if (func_0037E8D8((int *)o))
        o[2] = 0xC;
    else
        o[2] = 1;
}

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
// diff: 8 words; s0/s1 swapped (o in s0, r in s1 vs original o in s1, r in s0); 10 source forms tried; also void* copy, int callee, cast, if-return, long r (none fix)
extern "C" int func_00373F38(void *o)
{
    int r = func_00373D90(o);
    func_00373FC8(o);
    return r;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x374508
// diff: 8 words; s0/s1 swapped (o in s0, r in s1 vs original o in s1, r in s0); 10 source forms tried; also void* copy, int callee, cast, if-return, long r (none fix)
extern "C" int func_00374508(void *o)
{
    int r = func_00374360(o);
    func_00374598((int **)o);
    return r;
}
#endif

