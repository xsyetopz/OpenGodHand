extern "C" void func_002D42E0(char *);
extern int D_00747A84[];

static inline bool used(char *b, int o) { return *(int *)(b + o) != 0; }

extern char *Message;
extern "C" int func_002AEDC0(char *, unsigned char);
extern "C" int func_002B2638(char *);
extern "C" void func_002B4768(void *, int *, int *);

extern char Snd[];
extern char D_0044B1E0[];
extern "C" int SearchData__FPUiPCcUi(void *, const char *, unsigned);
extern "C" void func_002CB7E8(char *, int);
extern "C" int func_002CB6E0(char *, int);

extern "C" char *getMessageAddr__C8cMessageUs(char *, unsigned short);
extern "C" int getCodeSize__11cMessCommonUs(unsigned short);
extern "C" int func_002A4B20(void *, unsigned short);
extern void *Font;

extern "C" void sceSifInitRpc(int);
extern "C" int func_00399008(int);
extern "C" int func_003B6290(const char *);
extern "C" int func_003B6240();
extern "C" void func_003B41E8();
extern "C" void func_00399BD8(int);
extern "C" void func_003B5C10();
extern "C" int func_003B58E0();
extern "C" void func_0031DB70(int) __attribute__((noreturn));
extern "C" int printf(const char *, ...);
extern const char D_0044C008[], D_0044C028[];

// FUNCTION: GAME 0x2BE028
extern "C" void func_002BE028()
{
    sceSifInitRpc(0);
    while (!func_00399008(0)) {
    }
    while (!func_003B6290(D_0044C008)) {
    }
    while (!func_003B6240()) {
    }
    sceSifInitRpc(0);
    while (!func_00399008(0)) {
    }
    func_003B41E8();
    func_00399BD8(2);
    func_003B5C10();
    if (func_003B58E0()) {
        printf(D_0044C028);
        func_0031DB70(-1);
    }
}

struct RoomEnt {
    unsigned short id, room;
    char pad[0x10];
};
struct RoomBuf {
    char d[0x1650];
};
extern RoomEnt SceRoomTable[];
extern RoomBuf D_005E9CB8[];
extern unsigned D_00747A24;
extern "C" void *memset(void *, int, unsigned);

// FUNCTION: GAME 0x2BEBC8
extern "C" void func_002BEBC8(char *self, unsigned short id)
{
    RoomEnt *e = SceRoomTable;
    if (e->id != 0xFFFF && e->id != id) {
        do {
            e++;
        } while (e->id != 0xFFFF && e->id != id);
    }
    if (e->room == 0xFFFF) {
        char *s0 = self + 8;
        memset(s0, 0, 0x1650);
        *(char **)self = s0;
    } else
        *(RoomBuf **)self = &D_005E9CB8[e->room];
    int r = e->room;
    *(int *)(self + 0x1658) = r;
    if (r == 0 && !(D_00747A24 & 0x4000000))
        memset(*(char **)self, 0, 0x1650);
}

extern char Sys[], Dvd[], Movie[], Mc[];
extern const char D_0044C048[], D_0044C068[];
extern "C" void func_002BE458(char *);
extern "C" int func_002BE240(char *, const char *, int, int);
extern "C" void func_00397128(int);
extern "C" void func_0030ABD8();
extern "C" void func_00395058();
extern "C" void func_003951F8(int, int, int, int);
extern "C" void func_00395398(int);
extern "C" void func_00200AC0(char *);
extern "C" void func_002C9D20(char *);
extern "C" void func_002B4960(char *);
extern "C" void func_002AE3F0(char *);
extern "C" void func_0031A718(char *);
extern "C" void func_002BE4E8(char *);


extern "C" void func_002B6080(float *, char *);
extern "C" void func_002B60D0(float *, char *);
extern "C" void func_002B6160(float *, char *);
extern "C" void func_002B5EC0(char *);
extern "C" int func_002B5E50(char *);
extern "C" void setLocalScale__5cNodeRC4cVec(char *, float *);
extern "C" void func_002B6230(char *, float *);
extern "C" void setLocalTranslation__5cNodeRC4cVec(char *, float *);

// FUNCTION: GAME 0x2B5D58
extern "C" void func_002B5D58(char *self, char *parent)
{
    if (!parent) {
        float s[4], r[4], t[4];
        func_002B6080(s, self);
        func_002B60D0(r, self);
        func_002B6160(t, self);
        func_002B5EC0(self);
        *(char **)(self + 4) = 0;
        setLocalScale__5cNodeRC4cVec(self, s);
        func_002B6230(self, r);
        setLocalTranslation__5cNodeRC4cVec(self, t);
    } else if (!func_002B5E50(self)) {
        *(char **)(self + 4) = parent;
        char *first = *(char **)(parent + 8);
        if (!first)
            *(char **)(parent + 8) = self;
        else {
            char *n = first;
            while (*(char **)(n + 0x10))
                n = *(char **)(n + 0x10);
            *(char **)(self + 0xC) = n;
            *(char **)(n + 0x10) = self;
        }
    }
}

extern "C" float capVu0LengthSq__FPCf(const float *);
extern "C" void MtxInitRotVec__FR7cMatrixRC4cVecUc(char *, const float *, unsigned char);
extern "C" void func_00147C40(char *, float *);

#ifdef NONMATCHING
// DRAFT: GAME 0x2B4DA8
// loop with two 0xAC-stride induction regs and the bool via andi 0xFF is not reproduced (7 variants incl. bool/unsigned char temps and != 0; gcc folds them all to the same 28-word output)
extern "C" void func_002B4DA8(char **self)
{
    int a = 0, c = 0;
    for (int i = 2; i >= 0; i--) {
        char *b = *self;
        if (used(b, a))
            func_002D42E0(b + c);
        c += 0xAC;
        a += 0xAC;
    }
    D_00747A84[0] &= ~0x2000;
}


// DRAFT: GAME 0x2B2588
// branch layout of the r<2 guard and shared return-0 block differs (3 variants)
extern "C" int func_002B2588(char *self)
{
    int ret;
    if (func_002AEDC0(Message, self[0x2C]) < 2) {
        while (1) {
            if (!(**(unsigned short **)(self + 0x8C) >> 15)) {
                ret = 1;
                break;
            }
            int r = func_002B2638(self);
            if (r == 1) {
                ret = 0;
                break;
            }
            if (r < 2) {
                if (r == 0)
                    func_002B4768(self, (int *)(self + 0x90), (int *)(self + 0x8C));
            } else if (r == 2) {
                ret = 1;
                break;
            }
        }
    } else
        ret = 0;
    return ret;
}


// DRAFT: GAME 0x2B2E80
// 25 words differ: the original has a dead lw 0x18 before the 0xFFFF store and a different delay-slot fill (7 variants; without volatile, empty-if, unused local and reordered tail loads all stay 25 words)
extern "C" void func_002B2E80(char *self)
{
    int s1;
    if (!*(int *)(self + 0x18))
        s1 = 0;
    else
        s1 = SearchData__FPUiPCcUi(*(void **)(*(int *)(self + 0x18) + 0x304), D_0044B1E0, 0);
    if (s1 != *(int *)(self + 0x1C)) {
        if (*(int *)(self + 0x18))
            func_002CB7E8(Snd, *(int *)(self + 0x20));
        if (s1)
            *(int *)(self + 0x20) = func_002CB6E0(Snd, s1);
        *(int *)(self + 0x1C) = s1;
    }
    (void)*(volatile int *)(self + 0x18);
    *(unsigned short *)(self + 0x88) = 0xFFFF;
    self[0x30]++;
    *(int *)(self + 0x84) = *(int *)(self + 0x90);
    *(int *)(self + 0x7C) = *(int *)(self + 0x8C);
}


// DRAFT: GAME 0x2B1090
// 17 words: body unconditional (no inner if); f2/f3 swap on (float)w, bnel vs bne loop tail; tried for(;;)+break, goto-check tail, temps t/k/a
extern "C" float func_002B1090(float *self, unsigned short no, float *p)
{
    unsigned short *s0 = (unsigned short *)getMessageAddr__C8cMessageUs(Message, no);
    float sum = 0.0f;
    float t, k, a;
    unsigned c;
    goto chk;
    for (;;) {
        t = (float)func_002A4B20(Font, *s0);
        k = *p * self[0x3C / 4] * self[0x44 / 4];
        a = self[0x2C / 4] * self[0x44 / 4];
        sum += t * k + a;
        s0 += getCodeSize__11cMessCommonUs(*s0);
    chk:
        c = *s0;
        if ((c >> 15) && (c & 0xFF00) == 0x8000)
            break;
    }
    return sum - self[0x2C / 4] * self[0x44 / 4];
}


#endif

// FUNCTION: GAME 0x2BE0F0
extern "C" void func_002BE0F0(char *self)
{
    func_002BE458(self);
    while (func_002BE240(self, D_0044C048, 0, 0) < 0) {
    }
    while (func_002BE240(self, D_0044C068, 0, 0) < 0) {
    }
    func_00397128(1);
    func_0030ABD8();
    func_00395058();
    char *sy = Sys;
    if ((*(unsigned *)(sy + 0x578) ^ 1) == 0)
        func_003951F8(0, 1, 3, 0);
    else
        func_003951F8(0, 1, 2, 0);
    func_00395398(0);
    func_00200AC0(Dvd);
    func_002C9D20(Snd);
    func_002B4960(Movie);
    func_002AE3F0(Mc);
    func_0031A718(self);
    func_002BE4E8(self);
}

#ifdef NONMATCHING

// DRAFT: GAME 0x2BB2D8
// flag test uses dsra in the original; ours uses srl, register assignment differs (3 variants)
extern "C" void func_002BB2D8(char *self)
{
    char *m;
    float *v = (float *)(self + 0x60);
    unsigned char *fl = (unsigned char *)(self + 4);
    if (capVu0LengthSq__FPCf((float *)(self + 0x50)) != 0.0f || capVu0LengthSq__FPCf(v) != 0.0f) {
        *fl |= 1;
        if (((*fl >> 1) & 1) == 1) {
            *(char **)(self + 0x70) = self + 0x80;
            *(char **)(self + 0xC0) = self + 0xB0;
            m = self + 0x10;
        } else {
            m = self + 0x10;
            *(char **)(self + 0xC0) = self + 0x40;
            *(char **)(self + 0x70) = m;
        }
    } else {
        *fl &= 0xFE;
        char *p = *(char **)(self + 8);
        m = self + 0x10;
        *(char **)(self + 0xC0) = p + 0x30;
        *(char **)(self + 0x70) = p;
    }
    MtxInitRotVec__FR7cMatrixRC4cVecUc(m, v, 0);
    func_00147C40(m, (float *)(self + 0x50));
}

#endif
