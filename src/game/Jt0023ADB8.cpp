// God Hand: 0x23ADB8, a jump-table state machine.
extern "C" unsigned func_00276468(void *);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern char g_CollSolidManage[];

struct Ed {
    char _pad0[0x2F6];
    unsigned char m_2F6;
    char _pad1[0x304 - 0x2F7];
    char *m_304;
    char _pad2[0x54A - 0x308];
    short m_54A;
    char _pad3[0x54C - 0x54C + 0];
    float m_54C;
    char _pad4[0x617 - 0x550];
    unsigned char m_617;
    char _pad5[0x16D0 - 0x618];
    unsigned m_16D0;
    char _pad6[0x1864 - 0x16D4];
    unsigned char m_1864;
};

// FUNCTION: GAME 0x23ADB8
extern "C" void func_0023ADB8(Ed *self)
{
    self->m_54C = 5.0f;
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    self->m_16D0 |= 0x20000;
    self->m_617 = 1;
    switch (self->m_2F6) {
    case 0: {
        self->m_1864 = 0;
        unsigned t = func_00276468(self) & 0xFFFF;
        char *p = self->m_304;
        func_002A8578(self, *(int *)(p + 0xBE8) + (int)p, *(int *)(p + 0xBEC) + (int)p, 10, t, 0, 0.0f);
        self->m_16D0 &= 0xFFFF7FFF;
        self->m_16D0 &= 0xFFFFFFFD;
        self->m_2F6++;
        self->m_54A = 0;
    }
    case 1:
        self->m_16D0 |= 0x400000;
        moveMotion__FP8cObjBase(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        if (self->m_16D0 & 0x20000000)
            self->m_2F6 = 2;
        break;
    case 2: {
        unsigned t = func_00276468(self) & 0xFFFF;
        char *p = self->m_304;
        func_002A8578(self, *(int *)(p + 0xBF0) + (int)p, *(int *)(p + 0xBF4) + (int)p, 3, t, 0, 0.0f);
        self->m_2F6++;
    }
    case 3:
        moveMotion__FP8cObjBase(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    case 4: {
        unsigned t = func_00276468(self) & 0xFFFF;
        char *p = self->m_304;
        func_002A8578(self, *(int *)(p + 0xBF0) + (int)p, *(int *)(p + 0xBF4) + (int)p, 0, t, 0, 64.0f);
        self->m_2F6++;
    }
    case 5:
        moveMotion__FP8cObjBase(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    }
}
