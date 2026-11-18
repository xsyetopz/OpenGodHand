#ifdef NONMATCHING
// DRAFT: GAME 0x2ACF30
// 21 differing words: return-0 block layout (bnel vs beqz), mult/addu operand order; tried nested ifs, offset-int and struct forms.
extern "C" int func_002ACF30(char *p, char *q, int k) {
    int n = *(int *)(p + 0x1B544);
    if (n == 0)
        return 0;
    int i = *(int *)(p + 0x740) - 1;
    char *e = p + (i << 4);
    if (*(int *)(e + 0x100) != k)
        return 0;
    if (p + (n - *(signed char *)(e + 0x10C)) * 0xAC + 0x744 == q) {
        *(int *)(p + 0x740) = i;
        *(int *)(p + 0x1B544) = *(int *)(p + 0x1B544) - *(signed char *)(e + 0x10C);
        return 1;
    }
    return 0;
}
#endif
