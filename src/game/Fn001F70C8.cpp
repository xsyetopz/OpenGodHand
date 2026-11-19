// Slice F141: units 0x1F70C8, 0x1FF858, 0x28E420.
extern "C" int func_001451E0(char *);
extern "C" int func_001F6FA0(void *);
extern "C" void func_00144FD8(char *self, void *a, void *b, void *c, short n, unsigned short k);
extern char *Cockpit;
extern "C" void func_001FFBF0(char *self, void *a1);
extern "C" void *func_001FFC60(void *a, void *b);
extern "C" void *memcpy(void *d, const void *s, unsigned int n);
extern "C" void *memset(void *d, int c, unsigned int n);
extern unsigned char D_0042C6B0;
extern unsigned char D_0042C6B8;
extern unsigned char D_0042C6C8;
extern unsigned char D_0045F039;

// FUNCTION: GAME 0x1F70C8
extern "C" int func_001F70C8(unsigned char *p)
{
    if (p[0x36] == 1)
        return 0;
    *(int *)(p + 0x2C) = 0x1F;
    if (*(short *)(p + 0x32) <= 0) {
        if (func_001F6FA0(p) == 0) {
            if (p[0x35] == 1)
                *(unsigned *)((char *)Cockpit + 0xF30) |= 0x20000000;
            p[0x35] = 0;
            return 0;
        }
    } else
        *(short *)(p + 0x32) -= 1;
    int r = func_001451E0(Cockpit + 0xEA0);
    if (r >= 0) {
        if (p[0x35] == 1)
            *(unsigned *)((char *)Cockpit + 0xF30) |= 0x20000000;
        *(int *)(p + 0x2C) = r;
        p[0x36] = 1;
        *(short *)(p + 0x32) = 2;
        return 1;
    }
    switch (p[0x35]) {
    case 0:
        if (r != -2)
            return 1;
        func_00144FD8(Cockpit + 0xEA0, *(void **)(p + 0x38), *(void **)(p + 0x3C), *(void **)(p + 0x40), p[0x34], *(unsigned short *)(p + 0x30));
        *(short *)(p + 0x32) = 0x2D;
        p[0x35] = p[0x35] + 1;
        /* fallthrough */
    case 1:
        *(unsigned short *)(p + 0x30) = *(unsigned short *)((char *)Cockpit + 0x12C2) + 1;
        break;
    default:
        break;
    }
    return 1;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1FF858
// 60 differing words: prologue swaps self (s0 vs s1) and s, and the 8-byte copy emits 16 bytes; loop address loads differ.
struct __attribute__((packed)) U64Unaligned { unsigned long long v; };

extern "C" int func_001FF858(char *self)
{
    char *s = self + 0x19;
    memset(s, 0, 0x20);
    *(U64Unaligned *)s = *(U64Unaligned *)&D_0042C6B0;
    if (self[0x19] != 0) {
        int i = 0;
        do {
            signed char c = s[i];
            i++;
            s[i - 1] = ((&D_0045F039)[c] & 1) ? (char)(c + 0x20) : c;
        } while (s[i] != 0);
    }
    func_001FFBF0(self, &D_0042C6B8);
    void *base = func_001FFC60(self, &D_0042C6C8);
    *(int *)(self + 0x10) = (int)base;
    int buf[4];
    memcpy(buf, base, 0x10);
    int b = *(int *)(self + 0x10);
    *(int *)self = b + buf[3];
    *(int *)(self + 0x10) = b + buf[2];
    if (*(int *)(self + 0xC) > 0) {
        char *e = (char *)*(int *)self;
        int i = 0;
        do {
            if (*(unsigned char *)e == 1 && *(int *)(e + 8) != 0)
                *(int *)(e + 8) += *(int *)self;
            i++;
            *(int *)(e + 4) += *(int *)(self + 0x10);
            e += 12;
        } while (i < *(int *)(self + 0xC));
    }
    return 1;
}
#endif

extern "C" void *Getplayer__Fv();
extern "C" void func_0028E580(void *);
extern "C" void func_002A8578(void *, int, int, int, float, int, int);
extern "C" void func_002A87E8(void *, int);
extern "C" void SetSeqEffect__8cObjBase(void *);
extern "C" void SetTgtTurn__8cGameObjRC4cVecf(void *, void *, float);
extern "C" void calcParts__6cModel(void *);
extern "C" void calcWorldParts__6cModel(void *);
extern "C" void InverseKinematics__2IKP8cObjBase(void *, void *);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *snd, int a, int b, void *obj, int c, int d, int e, int f);
extern "C" int SeEndCk__4cSnd6eSndId(void *snd, int id);
extern char Snd;
extern int D_00747A78;

// FUNCTION: GAME 0x28E420
extern "C" void func_0028E420(unsigned char *self)
{
    if (!(D_00747A78 & 0x40000000)) {
        func_0028E580(self);
        switch (self[0x2F6]) {
        case 0:
            {
                char *t = *(char **)(self + 0x304);
                func_002A8578(self, *(int *)(t + 0xC) + (int)t, 0, 0, 0.0f, 0, 0);
                self[0x2F6] = self[0x2F6] + 1;
            }
            /* fallthrough */
        case 1:
            SetTgtTurn__8cGameObjRC4cVecf(self, *(void **)((char *)Getplayer__Fv() + 0xF0), *(float *)(self + 0x5A8) * 0.09817477f);
            moveMotion__FP8cObjBase(self);
            break;
        }
        SetSeqEffect__8cObjBase(self);
        calcParts__6cModel(self);
        InverseKinematics__2IKP8cObjBase(self + 0x448, self);
        calcWorldParts__6cModel(self);
        func_002A87E8(self, 0);
        if (SeEndCk__4cSnd6eSndId(&Snd, *(int *)(self + 0x1550)) != 0)
            *(int *)(self + 0x1550) = SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(&Snd, 1, 0x12, self, 0, 0, 0, 0);
        unsigned char *v = *(unsigned char **)(self + 0xF0);
        unsigned char *d = self + 0x490;
        if (d != v) {
            *(float *)d = *(float *)v;
            *(float *)(d + 4) = *(float *)(v + 4);
            *(float *)(d + 8) = *(float *)(v + 8);
        }
    }
}
