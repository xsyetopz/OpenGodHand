// Fn00160E78: save-point open state machine.
#ifdef NONMATCHING
extern int D_00747A2C[];
extern unsigned D_00747A24;
extern unsigned D_00747A88;
extern char *SaveLoad;
extern "C" void openSave__9cSaveLoad10eSavePoint(char *, int);

// DRAFT: GAME 0x00160E78
// 23 words differ: sra instead of dsrl on flag word, mask -3 not hoisted, v0=1 return layout; tried long/unsigned/ull casts, -3 literal, goto form
extern "C" int func_00160E78(char *p) {
    int r;
    if ((D_00747A2C[2] & 0x800) || D_00747A2C[3] < 0) return 1;
    if (((unsigned long)D_00747A2C[3] >> 6) & 1) return 1;
    switch (*(short *)(p + 0x52)) {
    case 0:
        openSave__9cSaveLoad10eSavePoint(SaveLoad, 0);
        *(unsigned short *)(p + 0x52) += 1;
    case 1:
        r = 0;
        if (!(D_00747A88 & 0x40000000)) {
    default:
            r = 1;
            D_00747A24 &= ~2;
            *(short *)(p + 0x52) = 0;
        }
    }
    return r;
}
#endif
