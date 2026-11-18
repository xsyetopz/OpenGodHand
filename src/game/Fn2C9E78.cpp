struct SdeVol {
    short s0;
    unsigned short s2;
    short s4, s6;
    unsigned short s8, sA;
    short sC, sE;
};
extern "C" void SdeSystemOutModeSet(int);
extern "C" void SdeSystemVolSet(SdeVol *);
extern "C" void SdePlayVolReset(int);
extern "C" void func_00375380(short, short);
extern "C" void func_00375500();

// DRAFT: GAME 0x2C9E78
// 37 words differ: sh store order, call-arg regs (a2/a3 + moves vs a0/a1 direct), swc1 order; tried store permutations, short[8] vs mixed s16/u16 struct, hoisted locals
#ifdef NONMATCHING
extern "C" void func_002C9E78(float *arg0)
{
    SdeVol v;
    SdeSystemOutModeSet(1);
    v.s8 = 0x5A;
    v.sE = 0x7F;
    v.s0 = 0x7F;
    v.s2 = 0x7F;
    v.s6 = 0x5A;
    v.sA = 0x7F;
    v.sC = 0x7F;
    v.s4 = 0;
    SdeSystemVolSet(&v);
    SdePlayVolReset(7);
    short x = v.s2;
    short y = v.s0;
    short z = v.s8;
    short w = v.sA;
    float f2 = y;
    float f3 = z;
    arg0[2] = f2;
    arg0[5] = f3;
    arg0[1] = x;
    arg0[4] = w;
    arg0[0] = f2;
    arg0[3] = f3;
    func_00375380(x, y);
    func_00375500();
}
#endif
