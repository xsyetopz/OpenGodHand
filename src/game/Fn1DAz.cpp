extern unsigned long Sys[];
extern char Snd[];
extern "C" void SetBgmState__4cSnd9eBgmState(char *, int);
extern "C" void func_001DEF48(char *, int);
extern "C" void func_001DF048(char *, int);
extern "C" void func_001DEFC8(char *, int);
extern "C" void func_001DF0F0(char *, int);
extern "C" void SeCall__4cSnd6eSeBlksssUii(char *, int, int, int, int, int, int);
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

// FUNCTION: GAME 0x1DA910
extern "C" void func_001DA910(char *self)
{
    switch (*(unsigned char *)(self + 0x3025)) {
    case 0: {
        char *s;
        SetBgmState__4cSnd9eBgmState(Snd, 3);
        s = self + 0x25B0;
        *(unsigned char *)(self + 0x3044) = 1;
        *(int *)(self + 0x3040) = 0;
        func_001DEF48(s, 1);
        func_001DF048(s, 1);
        func_001DEFC8(s, 0);
        func_001DF0F0(s, 0);
        *(unsigned char *)(self + 0x3025) += 1;
        break;
    }
    case 1:
        if (Sys[0x36] & 0xCC0000C000000UL) {
            char *s = self + 0x25B0;
            if (*(int *)(self + 0x3040) == 0) {
                *(int *)(self + 0x3040) = 1;
                *(unsigned char *)(self + 0x3044) = 0;
                __asm__ volatile("" : : : "memory");
                func_001DEF48(s, 0);
                func_001DF048(s, 0);
                func_001DEFC8(s, 1);
                func_001DF0F0(s, 1);
            } else {
                *(unsigned char *)(self + 0x3044) = 1;
                *(int *)(self + 0x3040) = 0;
                __asm__ volatile("" : : : "memory");
                func_001DEF48(s, 1);
                func_001DF048(s, 1);
                func_001DEFC8(s, 0);
                func_001DF0F0(s, 0);
            }
            SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15F, -1, -1, 0, 0);
        } else if (Sys[0x34] & 0x10000000UL) {
            char *s;
            SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15E, -1, -1, 0, 0);
            s = self + 0x25B0;
            func_001DF048(s, 0);
            func_001DF0F0(s, 0);
            *(unsigned char *)(self + 0x3025) += 1;
        }
        break;
    case 2:
        *(unsigned char *)(self + 0x3025) = 0;
        *(unsigned char *)(self + 0x3024) = 0xF;
        break;
    }
}
