extern char Snd[];
extern "C" void free__5cHeapPv(void *, void *);
extern "C" void func_002CB340(void *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x1FF3A0
// 4 words differ: lui Snd/li -1/addiu s0/s2 setup order in loop prologue; tried decl order, hoisted Snd local
extern "C" void func_001FF3A0(char *self)
{
    *(int *)(self + 4) = 0;
    char *p = *(char **)(self + 0x10);
    *(int *)(self + 8) = 0;
    if (p)
        free__5cHeapPv(*(char **)(p - 0x20), p);
    *(char **)(self + 0x10) = 0;
    *(int *)(self + 0xC) = -1;
    *(int *)(self + 0x1C) = 0;
    *(int *)(self + 0x18) = 0;
    int *q = (int *)(self + 0x24);
    int i = 9;
    do {
        i--;
        func_002CB340(Snd, *q);
        *q = -1;
        q++;
    } while (i >= 0);
    *(int *)self = 8;
}
#endif
