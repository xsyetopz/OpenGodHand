// Smallest unclaimed units in 0x1E0000-0x1F0000.

struct sIdIn1E {
    char pad[0xA8];
    int a, b;
};
struct sIdSys1E {
    sIdIn1E *m;
};
extern sIdSys1E *IDSys;

extern "C" void func_001F28C0(char *);

// FUNCTION: GAME 0x1EEC68
extern "C" void func_001EEC68(char *self)
{
    func_001F28C0(self + 0x60);
    sIdIn1E *p = IDSys->m;
    p->b = 0;
    p->a = 0;
}

extern "C" void func_001E8DF0(char *, int *, int *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x1E7E68 - 2 words: andi/sltiu use v0 instead of a3
extern "C" void func_001E7E68(void *a, void *b, void *c, unsigned int d)
{
    unsigned int e = d & 0xFFFF;
    d = e;
    if (b && c && d < 0x16)
        func_001E8DF0();
}
#endif

class cSlot1E {
public:
    void run();
    int m_pad[2];
    int m_st;
};
typedef void (cSlot1E::*SlotFn1E)();
extern "C" SlotFn1E D_003BE0D8[];

// FUNCTION: GAME 0x1E1CD0
extern "C" void func_001E1CD0(cSlot1E *self)
{
    (self->*D_003BE0D8[self->m_st])();
}

extern "C" void *memset(void *, int, unsigned int);

// FUNCTION: GAME 0x1E79A8
extern "C" void func_001E79A8(int *self, int v)
{
    memset(self, 0, 0x54);
    *self = v;
}

extern "C" SlotFn1E D_003BE168[];

// FUNCTION: GAME 0x1E58B8
extern "C" void func_001E58B8(cSlot1E *self)
{
    (self->*D_003BE168[self->m_st])();
}

enum eScePriority { ePri };
enum eActType { eAct };
enum eActBtnType { eBtn };
enum eActFunc { eFn };
class cActionButton {
public:
    void set(eScePriority, eActType, eActBtnType, void *, void *, eActFunc);
};
extern cActionButton g_ActBtn;
extern "C" void func_001E4920(void);
extern "C" void func_001E9F18(void);

class Slot2 {
public:
    void SetActBtn();
};

// FUNCTION: GAME 0x1E48E0
void Slot2::SetActBtn()
{
    g_ActBtn.set((eScePriority)4, (eActType)0x15, (eActBtnType)0, (void *)func_001E4920, this, (eActFunc)0);
}

class DogRace {
public:
    void SetActBtn();
};

// FUNCTION: GAME 0x1E9ED8
void DogRace::SetActBtn()
{
    g_ActBtn.set((eScePriority)4, (eActType)0x18, (eActBtnType)0, (void *)func_001E9F18, this, (eActFunc)0);
}

// FUNCTION: GAME 0x1E7960
extern "C" int *func_001E7960(int *self)
{
    memset(self, 0, 0x54);
    self[0x15] = 0;
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
    return self;
}

extern "C" int *func_001E8DA8(int *);
extern "C" void func_001E8E88(int *);
extern "C" void func_001E8EB8(int *);

// FUNCTION: GAME 0x1E8DA8
extern "C" int *func_001E8DA8(int *self)
{
    memset(self, 0, 0x54);
    func_001E8E88(self);
    func_001E8EB8(self);
    return self;
}

// FUNCTION: GAME 0x1E8798
extern "C" int *func_001E8798(int *self)
{
    func_001E8DA8(self);
    self[0x30] = 0;
    *(float *)(self + 0x2F) = 0.134256094f;
    return self;
}

// FUNCTION: GAME 0x1E7E18
extern "C" int *func_001E7E18(int *self)
{
    func_001E8DA8(self);
    self[0x30] = 0;
    *(float *)(self + 0x2F) = 0.134256094f;
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
    return self;
}

struct cVec1E {
    float x, y, z;
};
struct sVecSrc1E {
    char pad[0xF0];
};

// FUNCTION: GAME 0x1E8E48
extern "C" int func_001E8E48(cVec1E **self, cVec1E *out)
{
    cVec1E *p = *self;
    if (p)
        return 0;
    p = *(cVec1E **)((char *)p + 0xF0);
    if (out != p) {
        out->x = p->x;
        out->y = p->y;
        out->z = p->z;
    }
    return 1;
}

void displayScrollLayer(unsigned int, bool);

// FUNCTION: GAME 0x1E3298
extern "C" void func_001E3298(char *self)
{
    int *p = (int *)(self + 0x400);
    int i = 0x22;
    do {
        displayScrollLayer(*p++, false);
    } while (--i >= 0);
}

// FUNCTION: GAME 0x1E6820
extern "C" void func_001E6820(char *self)
{
    int *p = (int *)(self + 0x3A0);
    int i = 0xB;
    do {
        displayScrollLayer(*p++, false);
    } while (--i >= 0);
}

// FUNCTION: GAME 0x1E3240
extern "C" void func_001E3240(char *self, int on)
{
    func_001E3298(self);
    if (on)
        displayScrollLayer(*(unsigned *)(self + 0x400), true);
    else
        displayScrollLayer(*(unsigned *)(self + 0x404), true);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1E87E0 - 2 words: andi/sltiu use v0 instead of a3
extern "C" void func_001E87E0(int *self, void *a, void *b, unsigned short d)
{
    if (a && b && d <= 0x15) {
        func_001E8DF0();
        self[1] = 0;
        self[2] = 0;
        self[3] = 0;
    }
}
#endif

class classFADE {
public:
    void kill();
};
extern classFADE Fade;

#ifdef NONMATCHING
// DRAFT: GAME 0x1EFD00 - 2 words: target lwu+dsra, mine lw+srl
extern "C" void func_001EFD00(char *self)
{
    int *f = (int *)(self + 0x54);
    if ((*f >> 1) & 1) {
        Fade.kill();
        *f &= -3;
    }
}
#endif

// FUNCTION: GAME 0x1E66C0
extern "C" void func_001E66C0(int *self)
{
    switch (self[3]) {
    case 0:
        self[3] = 1;
        break;
    case 1:
        self[3] = 2;
        break;
    case 2:
        self[1] = 0;
        self[2] = 0;
        self[3] = 0;
        break;
    }
}

extern "C" SlotFn1E D_003BE528[];
extern "C" void func_001EC088(cSlot1E *);

// FUNCTION: GAME 0x1EA1A8
extern "C" void func_001EA1A8(cSlot1E *self)
{
    (self->*D_003BE528[self->m_pad[1]])();
    func_001EC088(self);
}

class CustomIDWork {
public:
    void SetMessNo(int);
};
extern "C" void func_001E7538(char *, int, int);

// FUNCTION: GAME 0x1E7908
extern "C" void func_001E7908(char *self, int m, int n)
{
    ((CustomIDWork *)(self + 0x5FC))->SetMessNo(m);
    func_001E7538(self, 0, n);
    func_001E7538(self, 1, n);
}

class cIDBase {
public:
    void release();
};
void free__5cHeapPv(void *, void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x1E7368 - 3 words: IDSys load uses v0/v1 swapped
extern "C" void func_001E7368(char *self)
{
    ((cIDBase *)(self + 0x530))->release();
    ((cIDBase *)self)->release();
    sIdSys1E *t = IDSys;
    int *p = (int *)t->m;
    p[0x23] = 0;
    p[0x22] = 0;
    char *q = *(char **)(self + 0x678);
    if (q)
        free__5cHeapPv(*(void **)(q - 0x20), q);
}
#endif

extern "C" void func_001E8F78(float);

// FUNCTION: GAME 0x1E9028
extern "C" void func_001E9028(char *self, float a, float b)
{
#define V (*(float *)(self + 0xB8))
    V += a;
    if (0.0f < b) {
        if (b < V)
            V = b;
    } else {
        if (V < b)
            V = b;
    }
    func_001E8F78(V);
#undef V
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1E8DF0 - 2 words: pointer init scheduled before the branch
extern "C" void func_001E8DF0(char *self, int *a, int *b, int n)
{
    n &= 0xFFFF;
    if (a && b && (unsigned)n < 0x16) {
        *(unsigned short *)(self + 0xB4) = n;
        *(int **)self = a;
        int *d;
        for (n = 0, d = (int *)(self + 0x54); n < *(unsigned short *)(self + 0xB4); n++)
            *d++ = *b++;
    }
}
#endif
