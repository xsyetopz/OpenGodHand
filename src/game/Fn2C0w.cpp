// Small units in 0x2C0000-0x2D0000.

extern "C" int func_002C3890(char *, void *, int);
extern "C" void func_002C41C8(void);
extern char Snd[];
extern "C" int func_002CB198(void *);
extern "C" void func_002CBC20(void *, void *, int);
extern "C" void func_002C8B68(char *);

// FUNCTION: GAME 0x2C4150
extern "C" void func_002C4150(char *self, short a, int b, int c, int d, int e)
{
    *(short *)(self + 0xD8) = a;
    *(int *)(self + 0xDC) = b;
    *(char *)(self + 0xE5) = d;
    *(char *)(self + 0xE4) = c;
    if (c == 1) {
        e = func_002C3890(self, (void *)func_002C41C8, e);
        if (e >= 0)
            *(unsigned char *)(*(char **)(self + 0x1C) + (e * 0x58) + 0x50) |= 1;
        e = 0;
    } else {
        func_002C41C8();
    }
}

// FUNCTION: GAME 0x2C8AD8
extern "C" void func_002C8AD8(char *self)
{
    if (!(*(unsigned char *)(self + 0xC) & 1) || func_002CB198(Snd) == 1) {
        void *p = *(void **)(self + 0x14);
        if (p) {
            *(unsigned char *)(self + 0x13) = 4;
            if (*(unsigned short *)(self + 0x2A) == 0)
                func_002CBC20(Snd, p, 10);
            *(void **)(self + 0x14) = 0;
        }
    } else if (*(unsigned char *)(self + 0x12) == 0) {
        func_002C8B68(self);
    }
}
