// COMPILER: ee-gcc2.9-991111
// Small unnamed functions in 0x310000-0x31D000.

// FUNCTION: GAME 0x319960
void func_00319960(void)
{
}

// FUNCTION: GAME 0x319968
void func_00319968(void)
{
}

// FUNCTION: GAME 0x31AF70
int func_0031AF70(int x)
{
    int a = ((x << 24) + (1 << 31)) >> 24;
    if (a < 0) {
        if (a >= -0x3F)
            a = 0;
    } else if (a <= 0x3F) {
        a = 0;
    }
    return a;
}

// FUNCTION: GAME 0x318540
int func_00318540(char *p)
{
    *(int *)(p + 0x250) |= 0x80000;
    p[0x2F4] = 0;
    p[0x2F5] = 0;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
    *(int *)(p + 0x4D0) = 0;
    *(int *)(p + 0x4D4) = 0;
    return 1;
}

// FUNCTION: GAME 0x31A0B8
void func_0031A0B8(char *p, unsigned n)
{
    p += 0x350;
    ((unsigned *)p)[n >> 5] &= ~(0x80000000u >> (n & 0x1F));
}

// FUNCTION: GAME 0x31AF40
int func_0031AF40(char *p, int k)
{
    switch (k) {
    case 1:
        return *(int *)(p + 0x154) != 0;
    case 2:
        return *(int *)(p + 0x4AC) != 0;
    }
    return 0;
}
