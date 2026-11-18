extern unsigned D_00747A2C[];
extern "C" void func_002B17A8(char *);
extern "C" void func_002B17F8(char *);
extern "C" void func_002B1830(char *);
extern "C" void func_002B1BE8(char *);
extern "C" void func_002B1C30(char *);

// FUNCTION: GAME 0x2B16F0
extern "C" void func_002B16F0(char *self)
{
    int *f = (int *)D_00747A2C;
    unsigned long l = f[1];
    unsigned long v = (l >> 1) & 1;
    if (v)
        return;
    if (f[22] & 0x8000000)
        return;
    switch (*(unsigned char *)(self + 0xA4)) {
    case 0: func_002B17A8(self); break;
    case 2: func_002B17F8(self); break;
    case 3: func_002B1830(self); break;
    case 4: func_002B1BE8(self); break;
    case 5: func_002B1C30(self); break;
    }
}
