// Medium units in 0x200000-0x280000.

extern char Snd[];
extern "C" void func_002CBA48(void *, int, int, void *, int, int, int, int);
extern "C" void func_002A8578(float, void *, char *, char *, int, int, int);
extern "C" int func_00157C18(void *);

// FUNCTION: GAME 0x27C790
extern "C" void func_0027C790(char *self)
{
    unsigned char st = *(unsigned char *)(self + 0x2F6);
    switch (st) {
    case 0: {
        func_002CBA48(Snd, 1, 12, self, 0, 0, 0, 0);
        st = *(unsigned char *)(self + 0x2F7);
        if (st) {
            char *p = *(char **)(self + 0x304);
            func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x40) + (int)p), (char *)(*(int *)(p + 0x44) + (int)p), 0, 0, 0);
        } else {
            char *p = *(char **)(self + 0x304);
            func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x38) + (int)p), (char *)(*(int *)(p + 0x3C) + (int)p), 0, 0, 0);
        }
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (func_00157C18(self)) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}
