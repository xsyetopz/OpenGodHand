extern char Snd[];
extern "C" void SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(int, int, void *, void *, float, int);
extern "C" void SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(char *, int, int, void *, int, int, int, int);
struct W { char _p[0x60]; unsigned f; };
static inline int Lt(const int &v, int n) { return n < v; }

// FUNCTION: GAME 0x27BDD8
extern "C" void func_0027BDD8(char *self)
{
    if (*(int *)(self + 0x564) != 0x263 && *(short *)(self + 0x54A) > 0) {
        W *w = *(W **)(self + 0x670);
        long fl;
        if (w && (fl = w->f, ((fl >> 0) & 1) == 1) && !(0.0f < *(float *)(self + 0x54C))) {
            SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 0, 10, self, 0, 0, 0, 0);
            char *p = Lt(*(unsigned char *)(self + 0x2B4), 4) ? *(char **)(*(char **)(self + 0x278) + 0x10) : 0;
            if (p)
                SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(0x58, 0x10, 0, *(void **)(p + 0xF0), 1.0f, -1);
            *(float *)(self + 0x54C) = 3.0f;
            if (*(short *)(self + 0x548) <= 0)
                *(short *)(self + 0x54A) = *(unsigned short *)(self + 0x548);
            else
                *(short *)(self + 0x54A) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F4) = 2;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}

// FUNCTION: GAME 0x27E228
extern "C" void func_0027E228(char *self)
{
    if (*(int *)(self + 0x564) != 0x266 && *(short *)(self + 0x54A) > 0) {
        W *w = *(W **)(self + 0x670);
        long fl;
        if (w && (fl = w->f, ((fl >> 0) & 1) == 1) && !(0.0f < *(float *)(self + 0x54C))) {
            SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 0, 10, self, 0, 0, 0, 0);
            char *p = Lt(*(unsigned char *)(self + 0x2B4), 4) ? *(char **)(*(char **)(self + 0x278) + 0x10) : 0;
            if (p)
                SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(0x58, 0x10, 0, *(void **)(p + 0xF0), 1.0f, -1);
            *(float *)(self + 0x54C) = 3.0f;
            if (*(short *)(self + 0x548) <= 0)
                *(short *)(self + 0x54A) = *(unsigned short *)(self + 0x548);
            else
                *(short *)(self + 0x54A) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F4) = 2;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}

// FUNCTION: GAME 0x27F3A0
extern "C" void func_0027F3A0(char *self)
{
    if (*(int *)(self + 0x564) != 0x26B && *(short *)(self + 0x54A) > 0) {
        W *w = *(W **)(self + 0x670);
        long fl;
        if (w && (fl = w->f, ((fl >> 0) & 1) == 1) && !(0.0f < *(float *)(self + 0x54C))) {
            SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 0, 10, self, 0, 0, 0, 0);
            char *p = Lt(*(unsigned char *)(self + 0x2B4), 4) ? *(char **)(*(char **)(self + 0x278) + 0x10) : 0;
            if (p)
                SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(0x58, 0x10, 0, *(void **)(p + 0xF0), 1.0f, -1);
            *(float *)(self + 0x54C) = 3.0f;
            if (*(short *)(self + 0x548) <= 0)
                *(short *)(self + 0x54A) = *(unsigned short *)(self + 0x548);
            else
                *(short *)(self + 0x54A) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F4) = 2;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}

// FUNCTION: GAME 0x281B40
extern "C" void func_00281B40(char *self)
{
    if (*(int *)(self + 0x564) != 0x26C && *(short *)(self + 0x54A) > 0) {
        W *w = *(W **)(self + 0x670);
        long fl;
        if (w && (fl = w->f, ((fl >> 0) & 1) == 1) && !(0.0f < *(float *)(self + 0x54C))) {
            SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 0, 10, self, 0, 0, 0, 0);
            char *p = Lt(*(unsigned char *)(self + 0x2B4), 4) ? *(char **)(*(char **)(self + 0x278) + 0x10) : 0;
            if (p)
                SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(0x58, 0x10, 0, *(void **)(p + 0xF0), 1.0f, -1);
            *(float *)(self + 0x54C) = 3.0f;
            if (*(short *)(self + 0x548) <= 0)
                *(short *)(self + 0x54A) = *(unsigned short *)(self + 0x548);
            else
                *(short *)(self + 0x54A) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F4) = 2;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}
