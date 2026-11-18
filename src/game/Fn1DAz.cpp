extern "C" void func_001DE7C8(char *, int);
extern "C" void func_001DE088(char *, int);
extern "C" void func_001DE170(char *, int);
extern "C" void func_001DE258(char *, int);
extern "C" void func_001DE340(char *, int);
extern "C" void func_001DE428(char *, int);
extern "C" void func_001DE4F8(char *, int);
extern "C" void func_001DF358(char *, int);
extern "C" void func_001DF198(char *, int);
extern "C" void func_001DF278(char *, int);
extern "C" void func_001DEE40(char *, int);
extern "C" void func_001DF428(char *, int);
static inline unsigned char Tick(int *p)
{
    if (*p == 0)
        return 1;
    *p -= 1;
    return 0;
}
// FUNCTION: GAME 0x1DA4E8
extern "C" void func_001DA4E8(char *self)
{
    unsigned char r;
    switch (*(unsigned char *)(self + 0x3025)) {
    case 0:
        *(int *)(self + 0x3028) = 0x1E;
        *(unsigned char *)(self + 0x3045) = 0;
        *(unsigned char *)(self + 0x3025) += 1;
        break;
    case 1:
        r = Tick((int *)(self + 0x3028));
        if (r) {
            func_001DE7C8(self, 3);
            func_001DE088(self, 3);
            func_001DE170(self, 3);
            func_001DE258(self, 3);
            func_001DE340(self, 3);
            func_001DE428(self, 3);
            func_001DE4F8(self, 3);
            *(int *)(self + 0x3028) = 0x1E;
            *(unsigned char *)(self + 0x3025) += 1;
        }
        break;
    case 2:
        r = Tick((int *)(self + 0x3028));
        if (r) {
            char *p = self + 0x25B0;
            func_001DF358(p, 2);
            func_001DF198(p, 2);
            func_001DF278(p, 2);
            *(int *)(self + 0x3034) = *(int *)(self + 0x3038);
            func_001DEE40(p, *(int *)(self + 0x3038));
            func_001DF428(p, 2);
            *(unsigned char *)(self + 0x3025) = 0;
            *(unsigned char *)(self + 0x3024) = 0xD;
        }
        break;
    }
}
