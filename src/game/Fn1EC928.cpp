extern float D_005681E0[4];
extern float D_005681F0[4];
extern float D_00568200[4];
extern float D_00568210[4];
extern float D_00568220[4];
extern float D_00568230[4];

#ifdef NONMATCHING
// DRAFT: GAME 0x001EC928
// 70 words: orig stores 0.0f via mtc1 $zero,$f0 + swc1 and schedules lui $at/mtc1 pairs interleaved; ours emits sw $zero; tried chained zero assignment (70)
extern "C" void func_001EC928(int arg0, int arg1) {
    if (arg1 == 0xFFFF && arg0 != 0) {
        D_00568220[0] = -25.84f;
        D_005681E0[0] = 0.45f;
        D_00568230[0] = -33.13f;
        D_00568230[3] = 1.0f;
        D_005681E0[1] = -0.21f;
        D_005681E0[2] = 0.95f;
        D_005681E0[3] = 1.0f;
        D_005681F0[0] = 0.0f;
        D_005681F0[1] = -0.20944f;
        D_005681F0[3] = 1.0f;
        D_00568200[0] = 0.0f;
        D_00568200[2] = 3.0f;
        D_00568200[3] = 1.0f;
        D_00568210[0] = 0.0f;
        D_00568210[2] = 0.0f;
        D_00568210[3] = 1.0f;
        D_00568220[1] = 1.59f;
        D_00568220[2] = -9.72f;
        D_00568220[3] = 1.0f;
        D_00568230[1] = 0.22f;
        D_00568230[2] = -5.92f;
        D_00568210[1] = D_00568200[1] = D_005681F0[2] = 0.0f;
    }
}
#endif
