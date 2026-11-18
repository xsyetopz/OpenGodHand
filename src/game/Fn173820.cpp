extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x00173820 -- ~25 words differ: orig hoists li 1 and uses beq, stores float after 2F7; tried char/int/bool arg, long vs int flag, 5B8 temp

extern "C" void setFake__5cOl0eb(char *self, bool v)
{
    long fl = *(unsigned *)(self + 0x5B0);
    if (((fl >> 1) & 1L) != 1L) {
        int w;
        self[0xD9B] = v;
        if (v == 1) {
            void *u = *(void **)(self + 0x600);
            if (u)
                SetDamageCollActive__11cDamageUnitb(u, 0);
            char *p = *(char **)(self + 0xDA8);
            if (p)
                *(int *)(p + 8) &= ~1;
            self[0x2F4] = v;
            w = *(int *)(self + 0x5B8) & ~0x100;
        } else {
            void *u = *(void **)(self + 0x600);
            if (u)
                SetDamageCollActive__11cDamageUnitb(u, 1);
            char *p = *(char **)(self + 0xDA8);
            if (p)
                *(int *)(p + 8) |= 1;
            self[0x2F4] = 0;
            w = *(int *)(self + 0x5B8) | 0x100;
        }
        self[0x2F5] = 0;
        *(int *)(self + 0x5B8) = w;
        self[0x2F6] = 0;
        self[0x2F7] = 0;
        *(float *)(self + 0x24C) = 1.0f;
    }
}
#endif
