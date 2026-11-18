// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void func_002705D8(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);

struct El {
    char _p0[0x250];
    unsigned m_250;
    char _p1[0x2F6 - 0x254];
    unsigned char m_2F6;
    char _p2[0x304 - 0x2F7];
    char *m_304;
    char _p3[0x54C - 0x308];
    float m_54C;
    char _p4[0x564 - 0x550];
    int m_564;
    char _p5[0x16D4 - 0x568];
    unsigned m_16D4;
    char _p6[0x17A8 - 0x16D8];
    int m_17A8;
    char _p7[0x17BE - 0x17AC];
    unsigned char m_17BE;
    char _p8[0x1869 - 0x17BF];
    unsigned char m_1869;
};

#define CALLAB(o1, o2, k)                                                  \
    do {                                                                   \
        char *p = self->m_304;                                             \
        int a = *(int *)(p + o1), b = *(int *)(p + o2);                    \
        func_002A8578(self, a + (int)p, b + (int)p, k, 0, 0, 0.0f);        \
    } while (0)
#define TAIL()                                                             \
    addNullSpeed_Rotation__8cObjBasef(self, 1.0f);                         \
    addNullSpeed__8cObjBasef(self, 1.0f)

#ifdef NONMATCHING
// DRAFT: GAME 0x2457D0 - m_54C store not in moveMotion delay slot; case 2 divu/flag register allocation (v0/v1, a1/a2) differs
extern "C" void func_002457D0(El *self)
{
    float f;
    self->m_250 |= 0x10000;
    switch (self->m_2F6) {
    case 0:
        CALLAB(0x23D8, 0x23DC, 3);
        self->m_2F6++;
    case 1:
        f = 3.0f;
        goto mm;
    case 2: {
        CALLAB(0x23E0, 0x23E4, 0);
        unsigned char m = self->m_17BE + 1;
        self->m_17BE = m;
        unsigned fl = self->m_16D4 & 0xFFFEFC7F;
        self->m_16D4 = fl;
        unsigned char r = m % 3;
        self->m_17BE = r;
        if (r == 1) {
            self->m_16D4 = fl | 0x80;
            if (self->m_564 == 0x276)
                self->m_16D4 = fl | 0x280;
        } else if (r == 2) {
            self->m_16D4 = fl | 0x100;
            if (self->m_564 == 0x276)
                self->m_16D4 = fl | 0x300;
        }
        self->m_1869 = 4;
        self->m_17A8 = 0;
        self->m_2F6++;
    }
    case 3:
        f = 2.0f;
    mm:
        self->m_54C = f;
        if (moveMotion__FP8cObjBase(self))
            self->m_2F6++;
        TAIL();
        break;
    case 4:
        CALLAB(0x2388, 0x238C, 0);
        self->m_2F6++;
    case 5:
        if (moveMotion__FP8cObjBase(self))
            func_002705D8(self);
        TAIL();
        break;
    }
}
#endif
