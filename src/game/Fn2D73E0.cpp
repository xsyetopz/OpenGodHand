extern "C" void *memset(void *, int, unsigned long);
extern "C" void free__5cHeapPv(char *, void *);
extern char RoomHeap[];

#ifdef NONMATCHING
// DRAFT: GAME 0x002D73E0 -- 2 words differ: lui s4 (RoomHeap) and li s1,7 swapped in prologue; tried decl order, hoisted heap ptr, V1-V4 (for-scoped, heap local, p-before-q, for+heap), V5 sep counter (19), V6 store after loop (14), V8 p top (32), V9 i first (2, same as baseline)

extern "C" void func_002D73E0(char *self)
{
    int i;
    memset(self + 0x80, 0, 0x7000);
    for (i = 0xFF; i >= 0; i--)
        *(short *)(self + 0x7010 - (0xFF - i) * 0x70) = 0xFF;
    *(int *)(self + 0x78) = 0;
    int *q = (int *)(self + 0x16100);
    char *p = self + 0x10000;
    for (i = 7; i >= 0; i--) {
        if (*(void **)(p + 0x5D74)) {
            free__5cHeapPv(RoomHeap, *(void **)(p + 0x5D74));
            *(int *)(p + 0x5D74) = 0;
        }
        *q = 0;
        p += 0x80;
        q++;
    }
    *(int *)(self + 0x16130) = 0;
    *(int *)(self + 0x16120) = 0;
}
#endif
