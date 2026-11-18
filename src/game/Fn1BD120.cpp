#ifdef NONMATCHING
// DRAFT: GAME 0x1BD120
// 21 differing words: original lwu then andi/dsra, and a bne-free beq; tried long/unsigned/unsigned long flags and casts.
extern "C" void setClose__7cOmDoorb(char *self)
{
    long flags = *(unsigned *)(self + 0x620);
    if (((flags & 1) & 0xFFFFFFFF) && (((long)flags >> 1) & 1) != 1 && (unsigned char)self[0x2F4] < 2) {
        self[0x2F5] = 2;
        *(int *)(self + 0x620) &= ~1;
        self[0x2F4] = 0;
        self[0x2F6] = 0;
        self[0x2F7] = 0;
    }
}
#endif
