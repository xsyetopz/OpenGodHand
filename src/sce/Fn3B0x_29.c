// COMPILER: ee-gcc2.9-991111
// SCE helpers in 0x3B0000-0x3B1000.

extern int D_003FAE40;
extern int func_001F6E68(int);
extern int func_001F6ED8(int, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x3B02E8
// diff: 9 words, s0/s1 allocation and jal delay slot (3 variants tried)
int func_003B02E8(int fd, int a, int b)
{
    if (!fd) {
        if (!D_003FAE40) {
            if (!func_001F6E68(a))
                return -1;
            D_003FAE40 = 1;
        }
        return func_001F6ED8(a, b);
    }
    return -1;
}
#endif
