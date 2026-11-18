extern char *CoreSave[];
extern unsigned D_00747A2C;
extern "C" int getClearNum__9cCoreSave(void *);
extern "C" int ckClearStage__9cCoreSaveUs(void *, unsigned short);

#ifdef NONMATCHING
// DRAFT: GAME 0x1F4530
// 30 words differ: 0x200 test branch polarity/layout and CoreSave addr regs (s1/s2); tried early returns, single-exit nesting, bool results
extern "C" int func_001F4530(void *, int a, int b)
{
    int r;
    if (D_00747A2C & 0x200)
        return 1;
    if (getClearNum__9cCoreSave(CoreSave) != 0) {
        if (a != 0x33)
            return 1;
        r = *(unsigned *)(CoreSave[0] + 0x14) & 0x800000;
    } else {
        if (a >= 0x29)
            return 0;
        r = ckClearStage__9cCoreSaveUs(CoreSave, b);
    }
    return r != 0;
}
#endif
