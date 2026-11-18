// Small helpers in 0x2B0000-0x2C0000.

extern char Snd[];
extern "C" int func_002CB778(void *, int);
extern "C" void func_002BDC00(void *);

// FUNCTION: GAME 0x2B31F8
extern "C" int func_002B31F8(int *o)
{
    if (o[7])
        return func_002CB778(Snd, o[8]);
    return 1;
}

// FUNCTION: GAME 0x2BDBD0
extern "C" void func_002BDBD0(char *o)
{
    if ((o[0x10] ^ 1) & 1) {
    } else
        func_002BDC00(o);
}
