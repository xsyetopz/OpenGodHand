extern char Snd[];
extern "C" int func_002CB830(void *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x1FF638
// 10 words differ: movn r placed after jal in original (delay slot), compiled before call; tried ternary/if forms, temp for call result
extern "C" int func_001FF638(char *self)
{
    int *q = (int *)(self + 0x24);
    int i = 9;
    int r = 1;
    do {
        int id = *q;
        if (id >= 0) {
            r = r != 0 ? 0 : r;
            if (func_002CB830(Snd, id) != 0) {
                *q = -1;
                r = 1;
                *(int *)(self + 8) &= ~4;
            }
        }
        i--;
        q++;
    } while (i >= 0);
    return r;
}
#endif
