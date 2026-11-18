// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" unsigned func_00276468(void *);
extern "C" void func_002609A8(void *, int, int, int, int, int);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" void func_0026EE40(void *, int, int);
extern "C" void func_0026BEF0(void *, int, int);
extern "C" void func_00260B30(void *);
extern "C" void func_002705D8(void *);
extern "C" int getGameLevel__9cCoreSave(void *);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern char CoreSave[];

struct Eg {
    char _pad0[0x2F6];
    unsigned char m_2F6;
    char _pad1[0x304 - 0x2F7];
    char *m_304;
    char _pad2[0x3AC - 0x308];
    unsigned short m_3AC;
    char _pad3[0x568 - 0x3AE];
    unsigned short m_568;
    char _pad4[0x5F0 - 0x56A];
    int m_5F0;
    int m_5F4;
    int m_5F8;
    int m_5FC;
    char _pad5[0x16D0 - 0x600];
    unsigned m_16D0;
    unsigned m_16D4;
    char _pad6[0x1864 - 0x16D8];
    unsigned char m_1864;
    char _pad7[0x186A - 0x1865];
    unsigned char m_186A;
};

// FUNCTION: GAME 0x2274A0
extern "C" void func_002274A0(Eg *self)
{
    self->m_186A = 2;
    self->m_16D4 |= 0x400;
    switch (self->m_2F6) {
    case 0: {
        self->m_1864 = 0;
        unsigned t = func_00276468(self) & 0xFFFF;
        func_002609A8(self, 0x32, 0x21, 0x3E, -1, 0);
        char *p = self->m_304;
        int x = *(int *)(p + 0x2E0C);
        int y = *(int *)(p + 0x2E10);
        self->m_5F0 = 0;
        func_002A8578(self, x + (int)p, y + (int)p, 10, t, 0, 0.0f);
        switch (getGameLevel__9cCoreSave(CoreSave)) {
        case 1:
        default:
            self->m_5F0 = 70;
            break;
        case 2:
            self->m_5F0 = 80;
            break;
        case 3:
        case 4:
            self->m_5F0 = 90;
            break;
        case 5:
            break;
        }
        self->m_5FC = 0;
        self->m_568 = 0;
        self->m_5F4 = 100;
        self->m_5F8 = 1;
        func_0026EE40(self, 0, 0);
        self->m_2F6++;
    }
    case 1:
        self->m_16D0 |= 0x800000;
        if (moveMotion__FP8cObjBase(self))
            func_002705D8(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
    }
    if (self->m_3AC & 1) {
        if (self->m_5F4 != 0) {
            self->m_5F4 = 0;
            func_0026BEF0(self, 0x15, (short)self->m_568);
            self->m_568 = self->m_568 + 1;
        }
    } else {
        self->m_5F4 = 1;
    }
    if (self->m_3AC & 2)
        func_00260B30(self);
    if (self->m_3AC & 3)
        self->m_5FC = 1;
    if (self->m_5FC)
        self->m_16D4 &= 0xFFFFFBFF;
}
