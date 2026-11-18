// Jump-table unit; this file holds no other .rodata.
extern unsigned char D_005CB010;
extern char CoreSave[];
extern "C" int getComboMax__9cCoreSaveUi(void *, unsigned);

#ifdef NONMATCHING
// 36-word near-miss: original duplicates the lhu 0x5E2 / constant compare per case (212 B vs 176 B)
// DRAFT: GAME 0x12C000
extern "C" int func_0012C000(char *self, unsigned idx)
{
    unsigned v, k, cur;
    switch (idx) {
    case 0:
    default:
        if (D_005CB010)
            return 0;
        v = *(unsigned short *)(self + 0x5E2);
        if (v)
            return 0;
        cur = *(unsigned short *)(self + 0x5E0);
        goto tail;
    case 1: k = 1; break;
    case 2: k = 2; break;
    case 3: k = 3; break;
    case 4: k = 4; break;
    case 5: k = 5; break;
    }
    v = *(unsigned short *)(self + 0x5E2);
    if (v != k)
        return 0;
    cur = *(unsigned short *)(self + 0x5E0);
tail:
    return !((int)cur < getComboMax__9cCoreSaveUi(CoreSave, v));
}
#endif
