// FUNCTION: GAME 0x318540
struct W {
    char pad0[0x250];
    unsigned f250;
    char pad1[0x2F4 - 0x254];
    char b[4];
    char pad2[0x4D0 - 0x2F8];
    int g0;
    int g1;
};
extern "C" int func_00318540(W *p)
{
    p->b[0] = 0;
    p->b[1] = 0;
    p->b[2] = 0;
    p->b[3] = 0;
    p->f250 |= 0x80000;
    p->g0 = 0;
    p->g1 = 0;
    return 1;
}
