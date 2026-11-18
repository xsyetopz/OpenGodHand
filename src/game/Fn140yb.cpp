extern char D_0041EAF0[];
extern char g_EmdManager[];
extern char g_DataManager[];
extern "C" int func_001FE9B8(char *, int);
extern "C" void func_001FED78(char *, int, int);
extern "C" void func_001496C0(char *, int);
// FUNCTION: GAME 0x14E5D0
extern "C" void _$_4cObj(char *s, int f)
{
    *(char **)(s + 0x214) = D_0041EAF0;
    unsigned short id = *(unsigned short *)(s + 0x2FE);
    if (id) {
        if (func_001FE9B8(g_EmdManager, id) == 1)
            func_001FED78(g_EmdManager, *(unsigned short *)(s + 0x2FE), 0);
        else if (func_001FE9B8(g_DataManager, *(unsigned short *)(s + 0x2FE)) == 1)
            func_001FED78(g_DataManager, *(unsigned short *)(s + 0x2FE), 0);
    }
    func_001496C0(s, f);
}

struct Pt { char p[0x38]; float f38; };
struct Ck { char p[0x90]; Pt *p90; char q[0x5C]; unsigned short h0F0[4]; unsigned short h0F8[4]; short h100; char q2[2]; unsigned char b104; };
// FUNCTION: GAME 0x146978
extern "C" void OnScroll__11cCockScrollUsUs(Ck *s, unsigned short a, unsigned short b)
{
    if (s->h100 < 4) {
        switch (b) {
        case 0: s->h0F0[s->h100] = a + 0x30D1; break;
        case 1: s->h0F0[s->h100] = a + 0x304E; break;
        }
        if (s->b104 & 2) s->p90->f38 += 50.0f;
        s->b104 &= 0xFD;
        s->h0F8[s->h100] = b;
        s->h100++;
    }
}
