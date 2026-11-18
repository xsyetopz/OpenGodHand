extern int D_0044B360;
extern int D_0044B378;
extern int D_0044B410;

// DRAFT: GAME 0x2B6688
// 39 words differ: arg kept in a0 originally (mine copies to a1, 0xFFFF const reg order); tried do/for loops, p hoisted, array vs scalar externs, ?: vs if tail
#ifdef NONMATCHING
extern "C" int func_002B6688(int a)
{
    if (a == 0x264)
        return 4;
    if ((unsigned)(a - 0x300) < 0x200)
        return 0;
    if (D_0044B360 != 0xFFFF) {
        int *p = &D_0044B360;
        do {
            if (a == *p++)
                return 0;
        } while (*p != 0xFFFF);
    }
    if (D_0044B378 != 0xFFFF) {
        int *p = &D_0044B378;
        do {
            if (a == *p++)
                return 3;
        } while (*p != 0xFFFF);
    }
    if (D_0044B410 != 0xFFFF) {
        int *p = &D_0044B410;
        do {
            if (a == *p++)
                return 2;
        } while (*p != 0xFFFF);
    }
    if ((unsigned)(a - 0x200) < 0x100)
        return 3;
    return 0;
}
#endif
