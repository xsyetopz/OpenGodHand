// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" unsigned func_00276468(void *);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" void func_002705D8(void *);
extern "C" int getGameLevel__9cCoreSave(void *);
extern "C" void *Getplayer__Fv();
extern "C" float Turn_dest__FPCffT0f(const float *, float, const float *, float);
extern "C" float Adjust_theta__Ff(float);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern "C" char *getMeshPtr__6cModelPCc(void *, const char *);
extern char CoreSave[];
extern const char D_004365A8[];
extern const char D_004365B0[];

struct Ei {
    char _pad0[0xF0];
    float *m_F0;
    char _pad1[0x104 - 0xF4];
    float m_104;
    char _pad2[0x2F6 - 0x108];
    unsigned char m_2F6;
    char _pad3[0x304 - 0x2F7];
    char *m_304;
    char _pad4[0x3AC - 0x308];
    unsigned short m_3AC;
    char _pad5[0x5A8 - 0x3AE];
    float m_5A8;
    char _pad6[0x5F0 - 0x5AC];
    int m_5F0;
    char _pad7[0x600 - 0x5F4];
    float m_600;
    char _pad8[0x16D4 - 0x604];
    unsigned m_16D4;
};

// FUNCTION: GAME 0x217310
extern "C" void func_00217310(Ei *self)
{
    switch (self->m_2F6) {
    case 0: {
        unsigned t = func_00276468(self) & 0xFFFF;
        char *p = self->m_304;
        func_002A8578(self, *(int *)(p + 0x1D4) + (int)p, *(int *)(p + 0x1D8) + (int)p, 3, t, 0, 0.0f);
        self->m_5F0 = 30;
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
        self->m_600 = self->m_104;
        self->m_2F6++;
    }
    case 1:
        if (self->m_5F0 != 0) {
            self->m_5F0 = self->m_5F0 - 1;
            float *a = self->m_F0;
            void *pl = Getplayer__Fv();
            float d = Turn_dest__FPCffT0f(a, self->m_600, *(float **)((char *)pl + 0xF0), self->m_5A8 * 0.39269909f);
            self->m_600 += d;
            self->m_600 = Adjust_theta__Ff(self->m_600);
            self->m_104 += d;
            self->m_104 = Adjust_theta__Ff(self->m_104);
        }
        if (moveMotion__FP8cObjBase(self))
            func_002705D8(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
    }
    if (self->m_3AC & 1) {
        self->m_16D4 &= 0xFFFFFFF7;
        char *m = getMeshPtr__6cModelPCc(self, D_004365A8);
        if (m)
            *(unsigned *)(m + 0x380) &= 0xFFFFFFFE;
        m = getMeshPtr__6cModelPCc(self, D_004365B0);
        if (m)
            *(unsigned *)(m + 0x380) &= 0xFFFFFFFE;
    }
}
