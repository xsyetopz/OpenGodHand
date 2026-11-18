extern char Sys[];
#define F(o) (*(unsigned short *)(self + (o)))
#ifdef NONMATCHING
// DRAFT: GAME 0x13D200
// diff: clamp tail; original reloads lhu into v1 and stores it on the in-range path (beql), 12 words
extern "C" void func_0013D200(char *self)
{
    char *s = Sys;
    if (*(unsigned short *)(s + 0x5B0) == 0x20)
        return;
    if (*(unsigned char *)(self + 0x93))
        return;
    if (*(unsigned *)(s + 0x5E4) & 0x40000000)
        F(0x90) = F(0x90) - 1;
    else if (*(unsigned char *)(self + 0x92))
        F(0x90) = F(0x90) - 1;
    else
        F(0x90) = F(0x90) + 1;
    if ((short)F(0x90) < 0)
        F(0x90) = 0;
    else if ((short)F(0x90) >= 7)
        F(0x90) = 6;
    else
        F(0x90) = F(0x90);
}
#endif
