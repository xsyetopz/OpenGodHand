// Small enemy state helpers in 0x280000-0x290000.
extern "C" void func_002A8578(void *, int, int, int, float, int, int);
extern "C" int func_00157C18(void *);

struct Es {
    char _p0[0x2F4];
    unsigned char m_2F4, m_2F5, m_2F6, m_2F7;
    char _p1[0x304 - 0x2F8];
    char *m_304;
    char _p2[0x15B0 - 0x308];
    unsigned char m_15B0;
};

class cEsP;
typedef void (cEsP::*cEsPmf)();
class cEsP {
public:
    virtual void v();
    char pad[0x2F4];
    unsigned char type;
    unsigned char type2;
};
extern "C" void func_002A87E8(cEsP *self, int a);
extern cEsPmf D_003C0480[];
extern cEsPmf D_003C03F8[];

// FUNCTION: GAME 0x28A4A0
extern "C" void func_0028A4A0(cEsP *self)
{
    if (self->type2 != 0)
        self->type2 = 0;
    (self->*D_003C0480[self->type2])();
    func_002A87E8(self, 0);
}

// FUNCTION: GAME 0x285EB8
extern "C" void func_00285EB8(cEsP *self)
{
    if (self->type2 >= 0xD)
        self->type2 = 0;
    (self->*D_003C03F8[self->type2])();
    func_002A87E8(self, 0);
}

struct EtTab {
    int m_0;
    int m_cnt;
    char *m_ent;
};
extern "C" int func_001FF238(char *);

// FUNCTION: GAME 0x28FED8
extern "C" int func_0028FED8(EtTab *self, int n)
{
    int cnt = 0;
    char *e = self->m_ent;
    for (int i = 0; i < self->m_cnt; i++) {
        char *p = e + i * 0x5C;
        if (func_001FF238(p) == 1) {
            if (cnt == n)
                return *(int *)(p + 0x20);
            cnt++;
        }
    }
    return 0xFFFF;
}

// FUNCTION: GAME 0x282120
extern "C" void func_00282120(Es *self)
{
    switch (self->m_2F6) {
    case 0: {
        if (self->m_15B0) {
            char *o = self->m_304;
            func_002A8578(self, *(int *)(o + 0x8C) + (int)o, *(int *)(o + 0x90) + (int)o, 5, 0.0f, 0, 0);
        } else {
            char *o = self->m_304;
            func_002A8578(self, *(int *)(o + 0x84) + (int)o, *(int *)(o + 0x88) + (int)o, 5, 0.0f, 0, 0);
        }
        self->m_2F6++;
    }
    case 1:
        if (func_00157C18(self)) {
            self->m_2F4 = 0;
            self->m_2F5 = 0;
            self->m_2F6 = 0;
            self->m_2F7 = 0;
        }
        break;
    }
}

extern float func_001F7EB0(void *, void *);
struct HoObj { char _p[0xF0]; void *m_F0; char _q[0x200]; unsigned char m_2F4, m_2F5; char _r[8]; unsigned short m_2FE; };
struct HoNode { int _0; HoNode *m_4; HoObj *m_8; };
struct HoList { char _p[0x500]; HoNode *m_500; };
// DRAFT: GAME 0x2919F8 - 38 words differ: range check 0x2A0..0x2FF folds to addiu/sltiu; original keeps slti pair + andi
#ifdef NONMATCHING
extern "C" int func_002919F8(HoList *self, void *p, float r)
{
    for (HoNode *n = self->m_500; n; n = n->m_4) {
        HoObj *o = n->m_8;
        if (o) {
            unsigned short u = o->m_2FE;
            if (u >= 0x2A0 && u < 0x300) continue;
            if (o->m_2F4 == 1 || o->m_2F5 == 2) {
                if (func_001F7EB0(o->m_F0, p) < r * r) return 1;
            }
        }
    }
    return 0;
}
#endif
