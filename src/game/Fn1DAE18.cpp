extern "C" void func_001DEF48(char *, int);
extern "C" void func_001DEFC8(char *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x1DAE18
// 13 words differ: gcc if-converts the flag test to movz where original branches; tried ternary, early returns, m2c shape, if/else mixes
extern "C" void func_001DAE18(char *self)
{
    char *s = self + 0x25B0;
    func_001DEF48(s, 0);
    func_001DEFC8(s, 0);
    int **pa = *(int ***)(self + 0x3004);
    int **pb = *(int ***)(self + 0x3008);
    int a = *(int *)((char *)*pa + 0x604);
    int b = *(int *)((char *)*pb + 0x604);
    if (a == 0)
        a = 0xD;
    if (b == 0)
        b = 0xD;
    int v;
    if (a < b) {
        v = 0x11;
        if (!*(unsigned char *)(self + 0x3044)) {
            v = 0x12;
        }
    } else {
        v = 0x13;
        if (b < a) {
            if (*(unsigned char *)(self + 0x3044))
                v = 0x12;
            else
                v = 0x11;
        }
    }
    self[0x3025] = 0;
    self[0x3024] = v;
}
#endif
