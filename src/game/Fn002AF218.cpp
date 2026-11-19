// God Hand: 0x2AF218 command cost
extern "C" int func_002AF348(int);
extern "C" int func_002AF380(unsigned short);
extern unsigned short D_003C23A8;
extern char *Message;

#ifdef NONMATCHING
// DRAFT: GAME 0x2AF218
// 67 words off: gcc builds a different compare tree than the original; tried plain switch with and without explicit 0xA000/0xA100/0xA500 returns.
extern "C" int func_002AF218(unsigned short *p)
{
    unsigned short op = p[0];
    if (!(op >> 15))
        return 0x1E;
    switch (op & 0xFF00) {
    case 0x8700:
        D_003C23A8 = p[1];
        return 0;
    case 0x9300:
        return (func_002AF348(*(int *)(Message + p[1] * 4 + 0xBDC)) * 0x1E) & 0xFFFE;
    case 0x9400:
        return (func_002AF380(*(unsigned short *)(Message + 0xBEE)) * 0x1E) & 0xFFFE;
    case 0xA000:
    case 0xA100:
    case 0xA500:
        return 0;
    case 0xA400:
        return (p[1] * 0x384) & 0xFFFC;
    case 0xA900:
        return (D_003C23A8 * 0x384) & 0xFFFC;
    default:
        return 0;
    }
}
#endif
