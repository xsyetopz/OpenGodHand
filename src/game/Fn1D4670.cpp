#ifdef NONMATCHING
// DRAFT: GAME 0x001D4670
// DRAFT: orig keeps arg copy in a2 and a1=a2+0x1638 loop pointer (p[-1] reloads); tried p[-1] ints, struct E/W array, pointer-increment, int arg cast
extern "C" void func_001D4670(int base) {
    int i;
    int *p = (int *)(base + 0x1638);
    for (i = 0x33; i >= 0; i--) {
        p[0] = 3;
        **(int **)((char *)p[-1] + 0xF0) = 0;
        (*(int **)((char *)p[-1] + 0xF0))[1] = 0;
        (*(int **)((char *)p[-1] + 0xF0))[2] = 0;
        *(int *)((char *)p[-1] + 0x104) = 0;
        char *q = (char *)p[-1];
        p += 2;
        *(int *)(q + 0x250) |= 2;
    }
    int *a = (int *)(base + 0x17E4);
    int *b = (int *)(base + 0x17E8);
    for (i = 4; i >= 0; i--) { *a = 0; a--; }
    b += 4;
    for (i = 4; i >= 0; i--) { *b = 0; b--; }
}
#endif
