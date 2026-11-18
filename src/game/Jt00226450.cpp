// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" void func_00262A10(void *);
extern "C" unsigned func_00276468(void *);
extern "C" void func_002609A8(void *, int, int, int, int, int);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" void func_00260B30(void *);
extern "C" void func_002705D8(void *);
extern "C" void func_0026EE40(void *, int, int);
extern "C" int func_00273960(void *, float);
extern "C" int func_00262AA8(void *);
extern "C" int getGameLevel__9cCoreSave(void *);
extern "C" void *Getplayer__Fv();
extern "C" void SetTgtTurn__8cGameObjRC4cVecf(void *, void *, float);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern char CoreSave[];

struct Ef {
    char _pad0[0x2F6];
    unsigned char m_2F6;
    char _pad1[0x304 - 0x2F7];
    char *m_304;
    char _pad2[0x3AC - 0x308];
    unsigned short m_3AC;
    char _pad3[0x5A8 - 0x3AE];
    float m_5A8;
    char _pad4[0x5F0 - 0x5AC];
    int m_5F0;
    int m_5F4;
    int m_5FC;
    char _pad6[0x16D0 - 0x600];
    unsigned m_16D0;
    unsigned m_16D4;
    char _pad7[0x1864 - 0x16D8];
    unsigned char m_1864;
    char _pad8[0x186A - 0x1865];
    unsigned char m_186A;
};

// FUNCTION: GAME 0x226450
extern "C" void func_00226450(Ef *self)
{
    self->m_186A = 2;
    self->m_16D4 |= 0x400;
    switch (self->m_2F6) {
    case 0: {
        self->m_1864 = 0;
        unsigned t = func_00276468(self) & 0xFFFF;
        func_002609A8(self, 0, 0x10, 0x4B, -1, 0);
        char *p = self->m_304;
        int o1 = *(int *)(p + 0x19B4);
        int o2 = *(int *)(p + 0x19B8);
        self->m_5F0 = 15;
        func_002A8578(self, o1 + (int)p, o2 + (int)p, 10, t, 0, 0.0f);
        switch (getGameLevel__9cCoreSave(CoreSave)) {
        case 1:
        default:
            self->m_5F0 = (int)((float)self->m_5F0 * 0.75f);
            break;
        case 2:
            self->m_5F0 = (int)((float)self->m_5F0 * 0.8f);
            break;
        case 3:
        case 4:
            self->m_5F0 = (int)((float)self->m_5F0 * 0.9f);
            break;
        case 5:
            break;
        }
        self->m_5FC = 0;
        self->m_5F4 = 100;
        func_0026EE40(self, 0, 0);
        self->m_2F6++;
    }
    case 1:
        if (self->m_5F0 != 0) {
            self->m_5F0 = self->m_5F0 - 1;
            void *pl = Getplayer__Fv();
            SetTgtTurn__8cGameObjRC4cVecf(self, *(void **)((char *)pl + 0xF0), self->m_5A8 * 0.19634955f);
        }
        if (self->m_3AC & 1) {
            if (self->m_5F4 > 10)
                self->m_5F4 = 10;
        }
        if (self->m_5F4) {
            self->m_16D0 |= 0x800000;
            self->m_5F4 = self->m_5F4 - 1;
        }
        if (moveMotion__FP8cObjBase(self))
            func_002705D8(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        func_002609A8(self, 0, 0x10, 0x4B, -1, 0);
        break;
    }
    func_00260B30(self);
    if ((self->m_3AC & 0x10) && func_00262AA8(self))
        return;
    if (self->m_3AC & 3)
        self->m_5FC = 1;
    if (self->m_5FC)
        self->m_16D4 &= 0xFFFFFBFF;
}
