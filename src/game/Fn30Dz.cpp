// FLAGS: -O0
// Unoptimised wrapper beside classFADE at 0x3077E8: forwards to the 0x307878 table lookup.
#ifdef NONMATCHING
extern unsigned D_00747A80[];
extern "C" unsigned char func_00307878(unsigned *, unsigned);

// DRAFT: GAME 0x3077E8 (12 words off: the compiled body ends with an extra b/nop pair before the epilogue)
extern "C" unsigned char func_003077E8(register unsigned i)
{
    return func_00307878(D_00747A80, i);
}
#endif
