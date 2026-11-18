// God Hand: small functions in 0x1F0000-0x200000
extern "C" void func_001F29C0(char *, int, int);
// FUNCTION: GAME 0x1F2CF0
extern "C" void func_001F2CF0(char *self)
{
    func_001F29C0(self, 0, 0);
    func_001F29C0(self, 1, 0);
    func_001F29C0(self, 0xB, 0);
    func_001F29C0(self, 0xC, 0);
    *(int *)(self + 0x918) = 0;
    *(int *)(self + 0x91C) = 0;
    *(int *)self |= 1;
}

extern "C" int func_00322AF8(int, int, int, void *);
extern "C" void func_00395398(int);
extern "C" int func_00323000(int);
extern char D_00580D80[];
// FUNCTION: GAME 0x1FFBF0
extern "C" void func_001FFBF0(char *self, int a1)
{
    if (!func_00322AF8(0, a1, 0, D_00580D80)) {
        self[0x18] = 1;
        while (func_00323000(0) != 3)
            func_00395398(0);
        self[0x18] = 0;
    }
}

extern "C" int func_001FCBA0(char *);
extern "C" void func_001FC7F8(char *);
// FUNCTION: GAME 0x1FD580
extern "C" int func_001FD580(char *self)
{
    char *n = *(char **)(self + 0x3C);
    if (n) do {
        if (!func_001FCBA0(*(char **)(self + 0x3C))) return 0;
        n = *(char **)(self + 0x3C);
        *(int *)(self + 0x3C) = *(int *)(n + 0x24);
        if (*(int *)(n + 0x20))
            *(int *)(*(char **)(n + 0x20) + 0x24) = *(int *)(n + 0x24);
        if (*(int *)(n + 0x24))
            *(int *)(*(char **)(n + 0x24) + 0x20) = *(int *)(n + 0x20);
        func_001FC7F8(n);
    } while (*(char **)(self + 0x3C));
    return 1;
}

struct cCoreSave;
extern "C" {
void clearKillEmNum__9cCoreSave(cCoreSave *);
void clearKillNpcNum__9cCoreSave(cCoreSave *);
void initContinueNum__9cCoreSave(cCoreSave *);
void func_001FAFA8(cCoreSave *);
void func_002D9D48(void *, int);
int getVitalMax__9cCoreSave(cCoreSave *);
void setVital__9cCoreSavei(cCoreSave *, int);
}
extern char WorldTime[];
extern unsigned short D_00747A50;

// FUNCTION: GAME 0x1F9B10
extern "C" void stageInit__9cCoreSave(cCoreSave *self)
{
    clearKillEmNum__9cCoreSave(self);
    clearKillNpcNum__9cCoreSave(self);
    initContinueNum__9cCoreSave(self);
    func_001FAFA8(self);
    func_002D9D48(WorldTime, 0);
    if (D_00747A50 != 0x20)
        setVital__9cCoreSavei(self, getVitalMax__9cCoreSave(self));
}

extern "C" void SetNumber__12CustomIDWorki(char *, int);
// FUNCTION: GAME 0x1F33F8
extern "C" void func_001F33F8(char *self, int a, int b)
{
    func_001F29C0(self, 0xD, a);
    func_001F29C0(self, 0xE, a);
    func_001F29C0(self, 0xF, a);
    func_001F29C0(self, 0x10, a);
    func_001F29C0(self, 0x11, a);
    SetNumber__12CustomIDWorki(self + 0x728, b);
}

extern unsigned char D_00747A51;
// FUNCTION: GAME 0x1FB2D8
extern "C" void func_001FB2D8(char **self, unsigned short id)
{
    if (D_00747A51 && *self) {
        char *p = *self + 0x28A;
        unsigned i = 0;
        unsigned short ff = 0xFFFF;
        char *q = p;
        do {
            if (*(unsigned short *)(p + 6) == id) { *(unsigned short *)q = ff; return; }
            i++; q += 0x10; p += 0x10;
        } while (i < 0x80);
    }
}

extern long D_00747640;
// FUNCTION: GAME 0x1F6FA8
extern "C" int func_001F6FA8(char *self)
{
    long l = D_00747640 & (0xEFE0L << 27);
    if ((l & (0x8000L << 20)) && *(int *)(self + 0x20) == 0) return 1;
    if ((l & (0x8000L << 17)) && *(int *)(self + 0x20) == 1) return 1;
    if ((l & (0x8000L << 18)) && *(int *)(self + 0x20) == 2) return 1;
    if ((l & (0x8000L << 19)) && *(int *)(self + 0x20) == 3) return 1;
    return 0;
}
