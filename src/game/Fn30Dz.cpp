// FLAGS: -O0
// Unoptimised wrapper beside classFADE at 0x3077E8: forwards to the 0x307878 table lookup.
#ifdef NONMATCHING
extern unsigned D_00747A80[];
extern "C" unsigned char func_00307878(unsigned *, unsigned);

// DRAFT: GAME 0x3077E8 (12 words off: the compiled body ends with an extra b/nop pair before the epilogue; tried int/char/uchar return+callee types, register, local temp, switch/for wrappers, no-return gives 2 words but drops the v1/v0 moves)
extern "C" unsigned char func_003077E8(register unsigned i)
{
    return func_00307878(D_00747A80, i);
}
#endif
