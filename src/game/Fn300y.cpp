// Event emitter scans over the 256-slot emitter table (live, not killed, not held).
extern char D_0071B940[], D_00741940[], D_00741960[], D_00741980[];
extern "C" void func_00302918(void *);

// FUNCTION: GAME 0x300900
void KillEventEmitter(void)
{
    for (int i = 0; i < 0x100; i++) {
        unsigned m = 0x80000000u >> (i & 0x1F);
        if ((((unsigned *)D_00741940)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_00741960)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_00741980)[(unsigned)i >> 5] & m)) {
            char *p = D_0071B940 + i * 0x260;
            if ((*(int *)(p + 0x118) & 2) && *(short *)(p + 0x18C) != 0xD7)
                func_00302918(p);
        }
    }
}

// FUNCTION: GAME 0x300AE8
extern "C" void func_00300AE8(int a, int b)
{
    for (int i = 0; i < 0x100; i++) {
        unsigned m = 0x80000000u >> (i & 0x1F);
        if ((((unsigned *)D_00741940)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_00741960)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_00741980)[(unsigned)i >> 5] & m)) {
            char *p = D_0071B940 + i * 0x260;
            if ((b == 0 && *(short *)(p + 0x18C) == a) || (b == 1 && *(short *)(p + 0x18C) != a))
                func_00302918(p);
        }
    }
}

// FUNCTION: GAME 0x300C00
extern "C" void func_00300C00(int a, int b)
{
    for (int i = 0; i < 0x100; i++) {
        unsigned m = 0x80000000u >> (i & 0x1F);
        if ((((unsigned *)D_00741940)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_00741960)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_00741980)[(unsigned)i >> 5] & m)) {
            char *p = D_0071B940 + i * 0x260;
            if ((b == 1 && (*(int *)(p + 0x118) & a)) || (b == 0 && !(*(int *)(p + 0x118) & a)))
                func_00302918(p);
        }
    }
}

// FUNCTION: GAME 0x300D20
extern "C" void func_00300D20(int a, int b)
{
    for (int i = 0; i < 0x100; i++) {
        unsigned m = 0x80000000u >> (i & 0x1F);
        if ((((unsigned *)D_00741940)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_00741960)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_00741980)[(unsigned)i >> 5] & m)) {
            char *p = D_0071B940 + i * 0x260;
            if (*(short *)(p + 0x18C) == a && *(unsigned short *)(p + 0x18E) == b)
                func_00302918(p);
        }
    }
}
