// Constructor-style initializer at 0x1495A0.
extern char D_0041EA90[];
extern "C" void func_0014FF80(void *);
extern "C" void *__12cBoundingBox(void *);

// FUNCTION: GAME 0x1495A0
extern "C" unsigned char *func_001495A0(unsigned char *s)
{
    func_0014FF80(s);
    *(char **)(s + 0x214) = D_0041EA90;
    float *q = (float *)(s + 0x240);
    *(float *)(s + 0x240) = 1.0f;
    q[1] = 1.0f;
    q[2] = 1.0f;
    q[3] = 1.0f;
    *(int *)(s + 0x250) = 0;
    *(int *)(s + 0x25C) = 0;
    __12cBoundingBox(s + 0x260);
    int c10 = 10;
    int c3 = 3;
    *(int *)(s + 0x2C0) = c10;
    *(int *)(s + 0x2C4) = c3;
    s[0x2B1] = 0;
    s[0x2B4] = 0;
    s[0x2B5] = 0;
    unsigned char *p1 = s + 0x28C;
    unsigned char *p2 = s + 0x290;
    unsigned char *p3 = s + 0x29C;
    unsigned char *p4 = s + 0x2A0;
    unsigned char i = 2;
    *(int *)(s + 0x254) = 0;
    *(int *)(s + 0x258) = 0;
    *(int *)(s + 0x220) = 0;
    *(int *)(s + 0x224) = 0;
    *(int *)(s + 0x228) = 0;
    *(int *)(s + 0x22C) = 0;
    *(int *)(s + 0x230) = 0;
    *(int *)(s + 0x234) = 0;
    *(int *)(s + 0x238) = 0;
    *(int *)(s + 0x2C8) = 0;
    *(int *)(s + 0x288) = 0;
    do {
        int t = i - 1;
        i = t;
        *(int *)((int)p1 + (t << 3)) = 0;
        *(int *)((int)p2 + (t << 3)) = 0;
        *(int *)((int)p3 + (t << 3)) = 0;
        *(int *)((int)p4 + (t << 3)) = 0;
    } while (i != 0);
    *(short *)(s + 0x2AE) = 0x3E8;
    s[0x2B6] = 0xFF;
    s[0x2BC] = 0xFF;
    s[0x2B7] = 0xFF;
    s[0x2B0] = 0xC8;
    *(short *)(s + 0x2B2) = 0xB4;
    s[0x2BE] = 0xFE;
    s[0x2BD] = 0;
    return s;
}
