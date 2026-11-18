// God Hand: 0x2311A8, a jump-table switch.
extern "C" unsigned func_00276468(void *);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void func_002705D8(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern "C" int GetSeqSEBase__FP8cObjBase(void *);
extern "C" void SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern char Snd[];

struct Ej {
    char _pad0[0x2F6];
    unsigned char m_2F6;
    char _pad1[0x304 - 0x2F7];
    char *m_304;
    char _pad2[0x54C - 0x308];
    float m_54C;
    char _pad3[0x564 - 0x550];
    int m_564;
};

// DRAFT: GAME 0x2311A8
// diff: 12 words; the original loads the offset pair into v1/a0 then adds into a1/a2, and increments m_2F6 via v1
#ifdef NONMATCHING
extern "C" void func_002311A8(Ej *self)
{
    switch (self->m_2F6) {
    case 0: {
        unsigned t = func_00276468(self) & 0xFFFF;
        char *p;
        int a, b;
        switch (self->m_564) {
        default:
            p = self->m_304;
            a = *(int *)(p + 0x1C0);
            b = *(int *)(p + 0x1C4);
            break;
        case 0x20A ... 0x20E:
        case 0x218:
        case 0x245 ... 0x247:
        case 0x24F:
        case 0x278 ... 0x279:
            p = self->m_304;
            a = *(int *)(p + 0x948);
            b = *(int *)(p + 0x94C);
            break;
        case 0x21A ... 0x21E:
        case 0x225:
        case 0x22C ... 0x22F:
        case 0x248 ... 0x249:
        case 0x24C ... 0x24E:
        case 0x252:
        case 0x25A:
            p = self->m_304;
            a = *(int *)(p + 0x11A0);
            b = *(int *)(p + 0x11A4);
            break;
        }
        int x = a + (int)p;
        int y = b + (int)p;
        func_002A8578(self, x, y, 10, t, 0, 0.0f);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 1, (short)GetSeqSEBase__FP8cObjBase(self), self, 0, 0, 0, 0);
        self->m_54C = 2.0f;
        self->m_2F6++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self))
            func_002705D8(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
    }
}
#endif
