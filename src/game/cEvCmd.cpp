// Event script command handlers (.text 0x2B0000 range).

struct cEvCmdData {
    unsigned short m_op;
    unsigned short m_arg;
    short m_s4;
};

struct cEvNode {
    unsigned short m_h0;
    short m_h2;
    cEvNode *m_prev;
    cEvNode *m_next;
};

struct cEvCmd {
    char _pad0[0xC];
    unsigned char m_c;
    unsigned char m_d;
    unsigned char m_e;
    unsigned char m_f;
    int m_10;
    int m_flags;
    int m_18;
    int m_1c;
    int m_20;
    unsigned short m_24[2];
    unsigned short m_28;
    char _pad2A[2];
    unsigned char m_2c;
    unsigned char m_2d;
    unsigned short m_2e;
    signed char m_30;
    unsigned char m_31;
    char _pad32[2];
    int m_34;
    unsigned short m_38;
    char _pad3A[2];
    unsigned char m_3c;
    char _pad3D[0x44 - 0x3D];
    unsigned char m_44;
    char _pad45[0x4C - 0x45];
    unsigned char m_4c;
    char _pad4D[3];
    int m_50;
    char _pad54[0x70 - 0x54];
    unsigned char m_70;
    char _pad71[0x8C - 0x71];
    cEvCmdData *m_data;
    char _pad90[0x94 - 0x90];
    unsigned short m_94;
    short m_96;
    float m_98;
    float m_9c;
    float m_a0;
    unsigned char m_a4;
    char _padA5;
    unsigned short m_a6;
    unsigned short m_a8;
    unsigned short m_aa;
    unsigned short m_ac;
    unsigned short m_ae;
    unsigned short m_b0;
    unsigned char m_b2;
    char _padB3;
    int m_b4;
    int m_b8;
};

extern "C" {
int func_002B1C80(cEvCmd *self);
void func_002B1F80(float, float, float, float);
void func_002B21F0(cEvCmd *self, unsigned short v);
void func_002B2A88(cEvCmd *self);
void func_002B22E0(cEvCmd *self, int v);
void func_002B4528(cEvCmd *self, const char *name);
void func_002B4428(cEvCmd *self, int a, void *b);
int func_002B4228(cEvCmd *self);
void func_002B42F0(cEvCmd *self);
void func_002B45C8(cEvCmd *self);
void func_002B45E0(cEvCmd *self, unsigned short v);
void func_002B45F0(cEvCmd *self);
int func_002B45F8(cEvCmd *self, cEvCmdData *d, unsigned int m);
}
void *SearchCameraData(const char *);

// FUNCTION: GAME 0x2B22E0
extern "C" void func_002B22E0(cEvCmd *self, int v)
{
    self->m_18 = v;
}

// FUNCTION: GAME 0x2B2400
extern "C" void func_002B2400(cEvCmd *self)
{
    self->m_flags |= 0x40;
    if ((unsigned char)(self->m_c - 6) >= 2) {
        self->m_c = 6;
        self->m_d = 0;
        self->m_e = 0;
        self->m_f = 0;
    }
}

// FUNCTION: GAME 0x2B22E8
extern "C" void func_002B22E8(cEvNode *n, cEvNode *prev, cEvNode *next, short s, unsigned short t)
{
    if (prev)
        prev->m_next = n;
    if (next)
        next->m_prev = n;
    n->m_prev = prev;
    n->m_next = next;
    n->m_h2 = s;
    n->m_h0 = t;
}

// FUNCTION: GAME 0x2B2318
extern "C" cEvNode *func_002B2318(cEvNode *n)
{
    if (n->m_prev)
        n->m_prev->m_next = n->m_next;
    if (n->m_next)
        n->m_next->m_prev = n->m_prev;
    return n->m_next;
}

// FUNCTION: GAME 0x2B4F78
extern "C" int func_002B4F78(cEvCmd *self)
{
    if (++self->m_10 == 0)
        self->m_10 = 1;
    return self->m_10;
}

// FUNCTION: GAME 0x2B2D08
extern "C" int func_002B2D08(cEvCmd *self)
{
    self->m_34 = 1;
    return 0;
}

// FUNCTION: GAME 0x2B2D18
extern "C" int func_002B2D18(cEvCmd *self)
{
    self->m_34 = 2;
    return 0;
}

// FUNCTION: GAME 0x2B2FB0
extern "C" int func_002B2FB0(cEvCmd *self)
{
    self->m_31 = self->m_data->m_arg;
    self->m_flags |= 0x200;
    return 0;
}

// FUNCTION: GAME 0x2B2FD8
extern "C" int func_002B2FD8(cEvCmd *self)
{
    self->m_38 = self->m_data->m_arg;
    return 0;
}

// FUNCTION: GAME 0x2B3008
extern "C" int func_002B3008(cEvCmd *self)
{
    self->m_3c = self->m_data->m_arg;
    return 0;
}

// FUNCTION: GAME 0x2B3020
extern "C" int func_002B3020(cEvCmd *self)
{
    self->m_flags |= 0x4000;
    return 0;
}

// FUNCTION: GAME 0x2B3038
extern "C" int func_002B3038(cEvCmd *self)
{
    self->m_flags |= 4;
    return 0;
}

// FUNCTION: GAME 0x2B3230
extern "C" void func_002B3230(cEvCmd *self)
{
    self->m_flags |= 0x10;
}

// FUNCTION: GAME 0x2B4518
extern "C" int func_002B4518(cEvCmd *self, int v)
{
    return self->m_b4 == v;
}

// FUNCTION: GAME 0x2B4598
extern "C" void func_002B4598(cEvCmd *self)
{
    if (self->m_b8 != 1)
        self->m_b8 = 1;
}

// FUNCTION: GAME 0x2B45B0
extern "C" void func_002B45B0(cEvCmd *self)
{
    if (self->m_b8 == 1)
        self->m_b8 = 0;
}

// FUNCTION: GAME 0x2B2F68
extern "C" int func_002B2F68() { return 0; }
// FUNCTION: GAME 0x2B2F70
extern "C" int func_002B2F70() { return 0; }
// FUNCTION: GAME 0x2B2F78
extern "C" int func_002B2F78() { return 0; }
// FUNCTION: GAME 0x2B2FA8
extern "C" int func_002B2FA8() { return 0; }
// FUNCTION: GAME 0x2B2FD0
extern "C" int func_002B2FD0() { return 0; }
// FUNCTION: GAME 0x2B2FF0
extern "C" int func_002B2FF0() { return 0; }
// FUNCTION: GAME 0x2B2FF8
extern "C" int func_002B2FF8() { return 0; }
// FUNCTION: GAME 0x2B3000
extern "C" int func_002B3000() { return 0; }
// FUNCTION: GAME 0x2B2580
extern "C" void func_002B2580() { }


// FUNCTION: GAME 0x2B2A30
extern "C" int func_002B2A30(cEvCmd *self)
{
    self->m_70 = 0;
    self->m_a4 = 0;
    func_002B2A88(self);
    return 0;
}

// FUNCTION: GAME 0x2B2A58
extern "C" int func_002B2A58(cEvCmd *self)
{
    self->m_70 = 1;
    self->m_a4 = 0;
    func_002B2A88(self);
    return 0;
}

// FUNCTION: GAME 0x2B2B78
extern "C" int func_002B2B78(cEvCmd *self)
{
    self->m_70 = 2;
    self->m_a4 = 4;
    self->m_18 = 0;
    self->m_94 = self->m_data->m_arg;
    self->m_96 = 0;
    self->m_3c = 0;
    return 0;
}

// FUNCTION: GAME 0x2B2BA8
extern "C" int func_002B2BA8(cEvCmd *self)
{
    self->m_70 = 2;
    self->m_a4 = 5;
    self->m_18 = 0;
    self->m_94 = self->m_data->m_arg;
    self->m_96 = 0;
    self->m_3c = 0;
    return 0;
}

// FUNCTION: GAME 0x2B2F80
extern "C" int func_002B2F80(cEvCmd *self)
{
    func_002B45E0(self, self->m_data->m_arg);
    return 0;
}

// FUNCTION: GAME 0x2B3050
extern "C" int func_002B3050(cEvCmd *self)
{
    func_002B4528(self, (const char *)self->m_data + 2);
    return 0;
}

// FUNCTION: GAME 0x2B4528
extern "C" void func_002B4528(cEvCmd *self, const char *name)
{
    func_002B4428(self, 1, SearchCameraData(name));
}

// FUNCTION: GAME 0x2B41F0
extern "C" void func_002B41F0(cEvCmd *self)
{
    func_002B45F0(self);
    self->m_10 = 0;
    self->m_flags &= ~0x10;
}

// FUNCTION: GAME 0x2B4560
extern "C" void func_002B4560(cEvCmd *self)
{
    if (func_002B4518(self, 1))
        func_002B4598(self);
}

// FUNCTION: GAME 0x2B17A8
extern "C" int func_002B17A8(cEvCmd *self)
{
    self->m_aa = 0x1E0;
    self->m_ac = 0x88;
    self->m_a6 = 0x100;
    self->m_ae = 0x100;
    self->m_a8 = 0x182;
    self->m_b0 = 0x182;
    return func_002B1C80(self);
}

// FUNCTION: GAME 0x2B1BE8
extern "C" int func_002B1BE8(cEvCmd *self)
{
    self->m_aa = 0x1E0;
    self->m_ac = 0x78;
    self->m_a6 = 0x100;
    self->m_ae = 0x100;
    self->m_a8 = 0x170;
    self->m_b0 = 0x170;
    return func_002B1C80(self);
}

// FUNCTION: GAME 0x2B1C30
extern "C" int func_002B1C30(cEvCmd *self)
{
    self->m_aa = 0x1E0;
    self->m_ac = 0x78;
    self->m_a6 = 0x100;
    self->m_ae = 0x100;
    self->m_a8 = 0x144;
    self->m_b0 = 0x144;
    return func_002B1C80(self);
}

// FUNCTION: GAME 0x2B2058
extern "C" void func_002B2058(float a, float b, float c, float d)
{
    func_002B1F80(a, b, a + c, b + d);
}

// FUNCTION: GAME 0x2B43B0
extern "C" void func_002B43B0(cEvCmd *self)
{
    if (func_002B45F8(self, self->m_data, 0xD200))
        return;
    if (func_002B45F8(self, self->m_data, 0xD900))
        return;
    if (func_002B45F8(self, self->m_data, 0xDA00))
        return;
    func_002B4428(self, 0, 0);
}

// FUNCTION: GAME 0x2B3158
extern "C" void func_002B3158(cEvCmd *self)
{
    self->m_10 = 0;
    self->m_98 = 0;
    self->m_flags |= 8;
    self->m_9c = 0;
    self->m_a0 = 0;
    func_002B45C8(self);
}

// FUNCTION: GAME 0x2B4188
extern "C" void func_002B4188(cEvCmd *self)
{
    switch (self->m_d) {
    case 0:
        func_002B41F0(self);
        self->m_d = self->m_d + 1;
    case 1:
        if (func_002B4228(self))
            func_002B42F0(self);
    }
}

// FUNCTION: GAME 0x2B2158
extern "C" void func_002B2158(cEvCmd *self, unsigned short a, unsigned char b, int c)
{
    self->m_flags |= 0x1000;
    func_002B22E0(self, c);
    self->m_2c = b;
    self->m_1c = 0;
    self->m_2d = 0;
    self->m_b2 = 0;
    self->m_2e = 0;
    self->m_44 = 0;
    self->m_4c = 0;
    self->m_50 = 0;
    self->m_20 = -1;
    self->m_30 = -1;
    func_002B21F0(self, a);
    self->m_c = 0;
    self->m_d = 0;
    self->m_e = 0;
    self->m_f = 0;
}

struct cEvView {
    char _pad0[0x1C];
    int m_1c;
    char _pad20[0x6C - 0x20];
    int m_6c;
    char _pad70[0x88 - 0x70];
    float m_88;
    float m_8c;
};

extern "C" {
unsigned short func_002B1290();
void func_002AFED0(cEvView *self, int a, int b, int c, float d, float e);
}

// FUNCTION: GAME 0x2B0420
extern "C" void func_002B0420(cEvView *self, int a)
{
    int d = self->m_1c - self->m_6c;
    func_002AFED0(self, func_002B1290(), a, d, self->m_88, self->m_8c);
}

struct cEvSlot {
    int m_first;
    char _pad4[0xAC - 4];
};

struct cEvSlotList {
    cEvSlot *m_slots;
};

static inline unsigned char isSlotUsed(cEvSlot *p)
{
    if (p->m_first)
        return 1;
    return 0;
}

extern "C" void func_002B4A50(cEvSlotList *l);

// FUNCTION: GAME 0x2B4E48
extern "C" int func_002B4E48(cEvSlotList *l)
{
    func_002B4A50(l);
    cEvSlot *p = l->m_slots;
    for (int i = 0; i < 3; i++, p++) {
        if (isSlotUsed(p) == 1)
            return 0;
    }
    return 1;
}

// FUNCTION: GAME 0x2B4F38
extern "C" int func_002B4F38(cEvSlotList *l)
{
    cEvSlot *p = l->m_slots;
    for (int i = 0; i < 3; i++, p++) {
        if (isSlotUsed(p) == 0)
            return i;
    }
    return -1;
}

struct cEvLink {
    char _pad0[4];
    struct cEvLinkList *m_list;
    cEvLink *m_head;
    cEvLink *m_prev;
    cEvLink *m_next;
};

struct cEvLinkList {
    char _pad0[8];
    cEvLink *m_first;
};

// FUNCTION: GAME 0x2B5E58
extern "C" int func_002B5E58(cEvLinkList *l)
{
    cEvLink *p = l->m_first;
    int n = 0;
    if (p) {
        n = 1;
        p = p->m_next;
        while (p) {
            p = p->m_next;
            n++;
        }
    }
    return n;
}

// FUNCTION: GAME 0x2B5E90
extern "C" cEvLink *func_002B5E90(cEvLinkList *l, int n)
{
    cEvLink *p = l->m_first;
    while (n-- != 0)
        p = p->m_next;
    return p;
}

// FUNCTION: GAME 0x2B5EC0
extern "C" void func_002B5EC0(cEvLink *self)
{
    if (self->m_list) {
        if (self->m_next)
            self->m_next->m_prev = self->m_prev;
        if (self->m_prev)
            self->m_prev->m_next = self->m_next;
        else
            self->m_list->m_first = self->m_next;
        self->m_next = 0;
        self->m_prev = 0;
        self->m_list = 0;
    }
}

// FUNCTION: GAME 0x2B5E50
extern "C" int func_002B5E50(cEvLinkList *l)
{
    return *(int *)((char *)l + 4);
}

extern unsigned char D_003C2554;
extern unsigned char D_003C2555;

// FUNCTION: GAME 0x2B6598
extern "C" void func_002B6598()
{
    D_003C2555 = 0;
    D_003C2554 = 0;
}

extern unsigned int D_00747A80;

// FUNCTION: GAME 0x2B8978
extern "C" int func_002B8978()
{
    unsigned t = D_00747A80 & 0x10000000;
    return t != 0;
}

extern "C" {
void func_002B4850(int a, unsigned short b);
void func_002B5028(int a, unsigned short b);
void func_002B5AF8(void *movie, int a, int b);
void func_002B5BB8(void *movie, int a, int b);
}
extern int Movie;

// FUNCTION: GAME 0x2B4880
extern "C" void func_002B4880()
{
    func_002B4850(1, 0xFFFF);
}

// FUNCTION: GAME 0x2B5C00
extern "C" void func_002B5C00()
{
    func_002B5028(1, 0xFFFF);
}

// 0x2B48A0 near-miss: only the scheduling of `lui v0` vs `daddu a1,a0` differs
// (original moves a0 to a1 first); same shape as 0x2B48C8, which matches.
#ifdef NONMATCHING
extern "C" void func_002B48A0(int a, int b)
{
    func_002B5AF8(&Movie, a, b);
}
#endif

// FUNCTION: GAME 0x2B48C8
extern "C" void func_002B48C8(int a, int b)
{
    func_002B5BB8(&Movie, a, b);
}

// FUNCTION: GAME 0x2B45C8
extern "C" void func_002B45C8(cEvCmd *) { }

// FUNCTION: GAME 0x2B45D0
extern "C" void func_002B45D0() { }

// FUNCTION: GAME 0x2B45E8
extern "C" void func_002B45E8() { }

// FUNCTION: GAME 0x2B45F0
extern "C" void func_002B45F0(cEvCmd *) { }

// FUNCTION: GAME 0x2B5F18
extern "C" void func_002B5F18() { }

struct cMsgView {
    char _pad[0xBEE];
    unsigned short m_bee;
};
extern cMsgView *Message;

// FUNCTION: GAME 0x2B1290
extern "C" unsigned short func_002B1290()
{
    return Message->m_bee;
}

extern int D_00747A0C;

// FUNCTION: GAME 0x2B12D8
extern "C" float func_002B12D8()
{
    float r = 26.0f;
    if (D_00747A0C != 0)
        r = 32.0f;
    return r;
}

extern "C" void func_003466A8();

// FUNCTION: GAME 0x2B4BC0
extern "C" void func_002B4BC0(cEvCmd *self)
{
    if (*(unsigned char *)((char *)self + 0x14))
        func_003466A8();
}

// FUNCTION: GAME 0x2B65F0
extern "C" void exitTask__11cNowLoading()
{
    D_003C2555 = 1;
}

// FUNCTION: GAME 0x2B3B40
extern "C" int func_002B3B40(cEvCmd *self)
{
    short v = self->m_data->m_arg + 1;
    if (self->m_96 < v)
        self->m_96 = v;
    return 0;
}
