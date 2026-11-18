// Event ESP scans over the 1024-slot table (live, not killed, not held).
extern char D_0061B7C0[];
extern char D_0071B7C0[], D_0071B840[], D_0071B8C0[];
extern "C" void func_002FBE50(void *);

// FUNCTION: GAME 0x2FB4C0
void KillEventEsp(void)
{
    for (int i = 0; i < 0x400; i++) {
        unsigned m = 0x80000000u >> (i & 0x1F);
        if ((((unsigned *)D_0071B7C0)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_0071B840)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_0071B8C0)[(unsigned)i >> 5] & m)) {
            char *p = D_0061B7C0 + i * 0x400;
            if ((*(int *)(p + 0x104) & 2) && *(short *)(p + 0x23A) != 0xD7)
                func_002FBE50(p);
        }
    }
}

// FUNCTION: GAME 0x2FB898
extern "C" void func_002FB898(int a, int b)
{
    for (int i = 0; i < 0x400; i++) {
        unsigned m = 0x80000000u >> (i & 0x1F);
        if ((((unsigned *)D_0071B7C0)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_0071B840)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_0071B8C0)[(unsigned)i >> 5] & m)) {
            char *p = D_0061B7C0 + i * 0x400;
            if (*(short *)(p + 0x23A) == a && *(unsigned short *)(p + 0x23C) == b)
                func_002FBE50(p);
        }
    }
}
