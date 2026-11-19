// Unnamed units in 0x156000-0x162000 (free small units, slice S02).

#ifdef NONMATCHING
// DRAFT: GAME 0x156508
// 16 differing words: draft lacks the leading daddu copy of a0 into v0; t lands in a0 not a3; lui/or order differs.
// Tried: asm barriers on t, m, v in all combinations, int/unsigned/long params, union return. 8 attempts.
extern "C" float func_00156508(int a0)
{
    unsigned t = (unsigned)a0 << 14;
    __asm__("" : "+r"(t));
    unsigned ex = (t & 0x1F800000u) + 0x28000000u;
    unsigned m = 0x7FFF0000u;
    __asm__("" : "+r"(m));
    unsigned lo = (m >> 8) & t;
    unsigned sg = (t << 2) & 0x80000000u;
    unsigned r = (lo | ex) | sg;
    return *(float *)&r;
}

// SKIP: GAME 0x156550 (MMI 128-bit psllw/pand/paddw/por with lq/sq; no ee-gcc 2.95 C form, no draft written)

// DRAFT: GAME 0x161668
// 15 differing words: the sb/nop/sltu run on v0 precedes the frame setup at 0x161688, so the unit likely starts mid-function.
extern "C" void func_001614D0(char *p);

extern "C" void func_00161668(char *p, int a1, int a2, int a3)
{
    p[0x5C] = (char)a3;
    func_001614D0(p);
}
#endif
