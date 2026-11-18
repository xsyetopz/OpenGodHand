// FLAGS: -O0
// Unoptimised game functions at 0x300000-0x310000 (2.95.3-136 C++, register-declared parameters).

// FUNCTION: GAME 0x307840
extern "C" int *func_00307840(register int *p) { *p = 0; return p; }

#ifdef NONMATCHING
// DRAFT: GAME 0x3077B0 (3 words off: original moves a0 straight to v0 and branches twice)
extern "C" int func_003077B0(register int a) { register int r = a; return r; }

// DRAFT: GAME 0x307878 (11 words off: original schedules the shifts through different temporaries)
extern "C" unsigned char func_00307878(register unsigned *a, register unsigned i) {
    return (a[i >> 5] & (0x80000000u >> (i & 0x1F))) != 0;
}
#endif
