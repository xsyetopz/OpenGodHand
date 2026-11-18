extern "C" int ReleaseDamageGive__13cDamageManageP11cDamageGive(char *, char *);
extern "C" void func_001FE278(char *, char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x1FE370
// 36 words differ: self kept in s2 not s1, no branch-likely delay-slot fill; tried do-while, for loops, end-pointer hoist, lbu cast
extern "C" void func_001FE370(char *self, int id)
{
    char *p = self;
    unsigned i;
    char *q = self + 0x3C00;
    do {
        if (*(unsigned char *)(p + 0x4A) && *(int *)(p + 0x30) == id)
            ReleaseDamageGive__13cDamageManageP11cDamageGive(self, p);
        p += 0x60;
    } while (p < q);
    i = 0;
    p = self + 0x3C00;
    do {
        if (*(unsigned char *)(p + 0x4A) && *(int *)(p + 0x30) == id)
            func_001FE278(self, p);
        i++;
        p += 0x70;
    } while (i < 0x100);
}
#endif
