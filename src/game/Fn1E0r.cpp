// Small units in 0x1E0000-0x1F0000 (continued from Fn1E0q.cpp).

struct sIdIn1E {
    char pad[0xA8];
    int a, b;
};
struct sIdSys1E {
    sIdIn1E *m;
};
extern sIdSys1E *IDSys;

class cSlot1E {
public:
    int m_pad[2];
    int m_st;
};
typedef void (cSlot1E::*SlotFn1E)();

extern "C" void func_001E8DF0(char *, int *, int *, int);

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
    void ResetMoveOffsetPos();
    void Main();
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
    void move();
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

extern "C" void func_001E7470(char *, int, int);
extern "C" void func_001E7538(char *, int, int);

// FUNCTION: GAME 0x1E7600
extern "C" void func_001E7600(char *self)
{
    func_001E7470(self, 0xA, 0);
    func_001E7538(self, 2, 0);
    func_001E7470(self, 0, 1);
    func_001E7470(self, 9, 1);
}

extern "C" void func_002D6838(char *, int, int);

// FUNCTION: GAME 0x1ED4E8
extern "C" void func_001ED4E8(char *self, int on)
{
    if (on) {
        func_002D6838(self + 0x10D8, -3, 0x10);
        func_002D6838(self + 0x1154, 3, 0x10);
    } else {
        ((CustomIDWork *)(self + 0x10D8))->ResetMoveOffsetPos();
        ((CustomIDWork *)(self + 0x1154))->ResetMoveOffsetPos();
    }
}

extern "C" void func_001ED848(char *);

// FUNCTION: GAME 0x1ED680
extern "C" void func_001ED680(char *self)
{
    char *p;
    int i = 5;
    func_001ED848(self);
    p = self + 0x60;
    do {
        ((CustomIDWork *)p)->Main();
        p += 0x7C;
    } while (--i >= 0);
    ((cIDBase *)(self + 0x10))->move();
}

void KeyStop(void);
extern unsigned int D_00747A78;

class ColiseumBattle {
public:
    void PlCtrlOff(bool);
    int m_pad[0x15];
    int m_flags;
};

// FUNCTION: GAME 0x1EFE70
void ColiseumBattle::PlCtrlOff(bool on)
{
    int v;
    if (on) {
        KeyStop();
        v = m_flags | 4;
    } else {
        int mk = -5;
        D_00747A78 &= 0xFDFFFFFF;
        v = m_flags & mk;
    }
    m_flags = v;
}
