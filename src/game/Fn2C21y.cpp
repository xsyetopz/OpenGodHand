extern unsigned D_00747A8C[];
extern unsigned short D_00747A50;
extern char *CoreSave;
extern char *g_Sce;
extern "C" unsigned short *func_002C5028(char *, unsigned short);

// DRAFT: GAME 0x2C21A0 (25 words differ: register allocation of id and CoreSave base)
#ifdef NONMATCHING
extern "C" int func_002C21A0(char *self)
{
    char *s = self + 0x5C;
    switch (*(unsigned char *)s) {
    case 1:
        break;
    case 0:
        if (*(unsigned char *)(s + 1) == 1) {
            int id = *(unsigned short *)(s + 2);
            if (id < 0x40)
                D_00747A8C[(unsigned)id >> 5] |= 0x80000000u >> (id & 0x1F);
        } else {
            int id = *(unsigned short *)(s + 2);
            if (id < 0x40)
                D_00747A8C[(unsigned)id >> 5] &= ~(0x80000000u >> (id & 0x1F));
        }
        break;
    case 2: {
        unsigned short *r = func_002C5028(g_Sce, D_00747A50);
        if (r && r[1] != 0xFFFF) {
            if (*(unsigned char *)(s + 1) == 1) {
                int id = *(unsigned short *)(s + 2);
                if (id < 0x40) {
                    char *b = (char *)CoreSave + 0x14;
                    __asm__("" : "+r"(b));
                    ((unsigned *)b)[(unsigned)id >> 5] |= 0x80000000u >> (id & 0x1F);
                }
            } else {
                int id = *(unsigned short *)(s + 2);
                if (id < 0x40) {
                    char *b = (char *)CoreSave + 0x14;
                    __asm__("" : "+r"(b));
                    ((unsigned *)b)[(unsigned)id >> 5] &= ~(0x80000000u >> (id & 0x1F));
                }
            }
        }
        break;
    }
    }
    return 0;
}
#endif
