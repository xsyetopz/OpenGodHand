extern "C" void Main__12CustomIDWork(void *);
extern "C" void move__7cIDBase(void *);

// FUNCTION: GAME 0x1E73C0
extern "C" void func_001E73C0(char *self)
{
    char *p = self + 0x580;
    int i;
    for (i = 1; i >= 0; i--, p += 0x7C)
        Main__12CustomIDWork(p);
    move__7cIDBase(self + 0x530);
    p = self + 0x50;
    for (i = 9; i >= 0; i--, p += 0x7C)
        Main__12CustomIDWork(p);
    move__7cIDBase(self);
}

extern unsigned D_00747A2C[];
extern char CoreSave;
extern "C" void addGold__9cCoreSaveib(void *, int, int);
extern "C" int getGold__9cCoreSave(void *);
extern "C" void func_001ED490(void *, int);

// FUNCTION: GAME 0x1EC8A8
extern "C" void func_001EC8A8(char *self)
{
    if (D_00747A2C[0] & 0x200) {
        if (*(unsigned long *)((char *)D_00747A2C - 0x3DC) & (0xCC00UL << 26)) {
            addGold__9cCoreSaveib(&CoreSave, 1000, 0);
            func_001ED490(self + 0x210, getGold__9cCoreSave(&CoreSave));
        }
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1F6AF8 - 12 words: second loop keeps shared exit; reg roles v1/a1 swapped
extern "C" void func_001F6AF8(int *self)
{
    int i;
    for (i = self[3] + 1; i < 4; i++) {
        if (self[4 + i] != 0) {
            self[3] = i;
            return;
        }
    }
    for (i = 0; i < self[3]; i++) {
        if (self[4 + i] != 0) {
            self[3] = i;
            return;
        }
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1F8550 - 12 words: f1/f2 allocation of p[1]/c[2] swapped, return-0 tail shared
extern "C" int func_001F8550(float *c, float *p)
{
    float y = c[1];
    float h = c[2];
    float py = p[1];
    if (!(py < y) && !(y + h < py)) {
        float dx = p[0] - c[4];
        float dz = p[2] - c[5];
        float l = dx * dx + dz * dz;
        __asm__ volatile("nop\n\tnop\n\tsqrt.s %0,%0" : "+f"(l));
        if (l < c[3])
            return 1;
    }
    return 0;
}
#endif

extern char Snd[];
extern "C" void func_002CB340(void *, int);

// FUNCTION: GAME 0x1FF5B8
extern "C" void func_001FF5B8(char *self)
{
    int *p = (int *)(self + 0x24);
    int i;
    for (i = 9; i >= 0; i--, p++) {
        if (*p >= 0) {
            *(int *)(self + 8) |= 4;
            func_002CB340(Snd, *p);
            *p = -1;
        }
    }
}

extern "C" char *func_001EC388(void *, int);
extern "C" int SeCall__4cSnd6eSeBlksPfUii(void *, int, int, void *, int, int);

// FUNCTION: GAME 0x1EC820
extern "C" void func_001EC820(char *self)
{
    unsigned long f = *(unsigned int *)(self + 0x54);
    f = (long)f >> 11;
    if ((f & 1) == 0) {
        char *e = func_001EC388(self, 0);
        if (e != 0) {
            long g = *(unsigned int *)(e + 0x30);
            long b = (g >> 2) & 1;
            if (b != 0) {
                *(int *)(self + 0x2A08) = SeCall__4cSnd6eSeBlksPfUii(Snd, 2, 3, *(char **)(self + 0x200) + 0x210, 0, 0);
                *(int *)(self + 0x54) |= 0x800;
            }
        }
    }
}
