// God Hand: 0x25A920, a jump-table state machine.
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void func_002705D8(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern "C" int GetSeqSEBase__FP8cObjBase(void *);
extern "C" void SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern char g_CollSolidManage[];
extern char Snd[];

struct Eb {
    char _pad0[0x2F6];
    unsigned char m_2F6;
    char _pad1[0x304 - 0x2F7];
    char *m_304;
    char _pad2[0x3AC - 0x308];
    unsigned short m_3AC;
    char _pad3[0x54C - 0x3AE];
    float m_54C;
    char _pad4[0x5A8 - 0x550];
    float m_5A8;
    char _pad5[0x600 - 0x5AC];
    float m_600;
    char _pad6[0x1866 - 0x604];
    unsigned char m_1866;
};

// DRAFT: GAME 0x25A920
// diff: 6 words, v0/v1 swapped for the m_1866/m_2F6 increments in case 0.
#ifdef NONMATCHING
extern "C" void func_0025A920(Eb *self)
{
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    switch (self->m_2F6) {
    case 0: {
        char *p = self->m_304;
        func_002A8578(self, *(int *)(p + 0x1084) + (int)p, *(int *)(p + 0x1088) + (int)p, 3, 0, 0, 0.0f);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 1, (short)GetSeqSEBase__FP8cObjBase(self), self, 0, 0, 0, 0);
        self->m_1866++;
        self->m_2F6++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self))
            self->m_2F6++;
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    case 2: {
        char *p = self->m_304;
        func_002A8578(self, *(int *)(p + 0x107C) + (int)p, *(int *)(p + 0x1080) + (int)p, 3, 0, 0, 0.0f);
        self->m_600 = 150.0f;
        self->m_2F6++;
    }
    case 3:
        moveMotion__FP8cObjBase(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        self->m_600 = self->m_600 - self->m_5A8;
        if (self->m_600 <= 0.0f)
            self->m_2F6++;
        break;
    case 4: {
        char *p = self->m_304;
        func_002A8578(self, *(int *)(p + 0x1094) + (int)p, *(int *)(p + 0x1098) + (int)p, 3, 0, 0, 0.0f);
        self->m_54C = 5.0f;
        self->m_2F6++;
    }
    case 5:
        if (moveMotion__FP8cObjBase(self))
            func_002705D8(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    }
    self->m_3AC |= 0x400;
}
#endif
