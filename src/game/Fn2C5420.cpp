extern "C" {
extern char *scrArray;
extern int D_00747A84[];
extern char _gp[];
void func_002D5AD8();
}

#ifdef NONMATCHING
// DRAFT: GAME 0x002C5420
// 3 words: end pointer kept in a2 then moved to a3 in original; for/do-while tried
extern "C" void *SearchScroll__9cScrArrayUl(void *self, unsigned long id) {
    char **end = *(char ***)(scrArray + 8);
    char **p = *(char ***)(scrArray + 4);
    for (; p < end; p++) {
        char *o = *p;
        if (*(unsigned long *)(*(char **)(o + 0x320) + 8) == id)
            return o;
    }
    return 0;
}

#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x002CB198
// 9 words: dsrl 3 becomes sra, 0x1000000 test folds to lb; long/int/unsigned/ull variants tried
extern "C" int func_002CB198() {
    int a = D_00747A84[0];
    if (a & 0x800) return 1;
    if (a & 0x20000000) return 1;
    if (((unsigned long)a >> 7) & 1) return 1;
    int b = D_00747A84[-24];
    if (((unsigned long)b >> 3) & 1) return 1;
    int c = D_00747A84[-22];
    return (c & 0x1000000) != 0;
}

#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x002D5918
// 8 words: const-reg allocation and sw 0x34 hoisted; local/struct/order variants tried; sw 0x34 moved before 0x2C (11 words), fn/two decl swap (8), g/two/fn decl order (13)
extern "C" void func_002D5918(char *p) {
    int a = *(int *)(p + 0x10);
    int b = *(int *)(p + 8);
    void *fn = (void *)func_002D5AD8;
    void *g = _gp;
    short two = 2;
    *(void **)(p + 0x30) = g;
    *(short *)(p + 0xC) = two;
    *(void **)(p + 0x24) = fn;
    *(int *)(p + 0x28) = a;
    *(int *)(p + 0x2C) = b;
    *(int *)(p + 0x34) = *(unsigned short *)(p + 0x1C);
}
#endif
