// Unnamed unit at 0x2B6930.
extern "C" void ScrollTexture__6cModelf(char *, float);
extern "C" void calcParts__6cModel(char *);
extern "C" void KageDraw__8cObjBase(char *);
extern "C" void EmClothMove__F6eObjIdP4cObjP8PEN_INFOP10CLOTH_INFO(int, char *, char *, char *);
extern "C" void func_002B6A40(char *);
extern "C" void func_002B6DA0(char *);
extern "C" void func_002B6FE8(char *);
extern "C" void func_002B79E0(char *);

struct Fn2B69Vt { char _p[0x58]; short m_58; short _5a; void (*m_5C)(char *); };

// FUNCTION: GAME 0x2B6930
extern "C" void func_002B6930(char *self)
{
    unsigned char st = *(unsigned char *)(self + 0x2F4);
    switch (st) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4: {
        Fn2B69Vt *vt = *(Fn2B69Vt **)(self + 0x214);
        vt->m_5C(self + vt->m_58);
        break;
    }
    }
    ScrollTexture__6cModelf(self, 1.0f);
    if (*(unsigned char *)(self + 0x4E0)) func_002B6FE8(self);
    calcParts__6cModel(self);
    if (*(int *)(self + 0x4DC)) KageDraw__8cObjBase(self);
    if (*(unsigned char *)(self + 0x1390))
        EmClothMove__F6eObjIdP4cObjP8PEN_INFOP10CLOTH_INFO(*(int *)(self + 0x1394), self, self + 0x13A0, self + 0x2F20);
    if (*(unsigned char *)(self + 0x2FA0)) func_002B6A40(self);
    if (*(unsigned char *)(self + 0x2FF0)) func_002B79E0(self);
    if (*(unsigned char *)(self + 0x4D8)) func_002B6DA0(self);
    float *s = *(float **)(self + 0xF0);
    float *d = (float *)(self + 0x490);
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}
