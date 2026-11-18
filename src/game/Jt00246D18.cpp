// God Hand: 0x246D18, a jump-table state machine.
extern "C" unsigned func_00276468(void *);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void func_002744E0(void *);

struct Ee {
    char _pad0[0x2F6];
    unsigned char m_2F6;
    char _pad1[0x304 - 0x2F7];
    char *m_304;
    char _pad2[0x3AC - 0x308];
    unsigned short m_3AC;
    char _pad3[0x5F0 - 0x3AE];
    int m_5F0;
    char _pad4[0x16D0 - 0x5F4];
    unsigned m_16D0;
    char _pad5[0x1864 - 0x16D4];
    unsigned char m_1864;
};

// FUNCTION: GAME 0x246D18
extern "C" void func_00246D18(Ee *self)
{
    switch (self->m_2F6) {
    case 0: {
        self->m_1864 = 0;
        unsigned t = func_00276468(self) & 0xFFFF;
        char *p = self->m_304;
        func_002A8578(self, *(int *)(p + 0x98) + (int)p, *(int *)(p + 0x9C) + (int)p, 10, t, 0, 0.0f);
        self->m_16D0 &= 0xDFFFFFFF;
        self->m_2F6++;
    }
    case 1:
        moveMotion__FP8cObjBase(self);
        if (self->m_16D0 & 0x20000000)
            self->m_2F6++;
        break;
    case 2: {
        self->m_1864 = 0;
        unsigned t = func_00276468(self) & 0xFFFF;
        char *p = self->m_304;
        func_002A8578(self, *(int *)(p + 0x3CC) + (int)p, *(int *)(p + 0x3D0) + (int)p, 6, t, 0, 0.0f);
        self->m_2F6++;
    }
    case 3:
        if (moveMotion__FP8cObjBase(self))
            self->m_2F6++;
        break;
    case 4: {
        self->m_1864 = 0;
        unsigned t = func_00276468(self) & 0xFFFF;
        char *p = self->m_304;
        func_002A8578(self, *(int *)(p + 0x98) + (int)p, *(int *)(p + 0x9C) + (int)p, 10, t, 0, 0.0f);
        self->m_16D0 &= 0xDFFFFFFF;
        self->m_2F6++;
    }
    case 5:
        moveMotion__FP8cObjBase(self);
        if (self->m_16D0 & 0x20000000)
            self->m_2F6++;
        break;
    case 6: {
        self->m_1864 = 0;
        unsigned t = func_00276468(self) & 0xFFFF;
        char *p = self->m_304;
        func_002A8578(self, *(int *)(p + 0x3E4) + (int)p, *(int *)(p + 0x3E8) + (int)p, 6, t, 0, 0.0f);
        self->m_2F6++;
    }
    case 7:
        if (moveMotion__FP8cObjBase(self))
            self->m_2F6 = 4;
        break;
    }
    if (self->m_3AC & 3) {
        if (self->m_5F0) {
            self->m_5F0 = 0;
            func_002744E0(self);
        }
    }
}
