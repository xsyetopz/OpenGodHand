// FLAGS: -O0
// Unoptimised game functions at 0x300000-0x310000 (2.95.3-136 C++, register-declared parameters).

// FUNCTION: GAME 0x307840
extern "C" int *func_00307840(register int *p) { *p = 0; return p; }

#ifdef NONMATCHING
// DRAFT: GAME 0x307878 (11 words off: original schedules the shifts through different temporaries)
extern "C" unsigned char func_00307878(register unsigned *a, register unsigned i) {
    return (a[i >> 5] & (0x80000000u >> (i & 0x1F))) != 0;
}
#endif
