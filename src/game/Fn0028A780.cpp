// Units at 0x28A780, 0x2B04C0, 0x2B0908.
extern "C" float func_002B0D68(void *, int, float *);
extern "C" float func_002B1090(void *, int, float *);
extern "C" int func_002B1270(void *, unsigned short *);
extern "C" int func_002B1290(void *);
extern "C" int func_002B12A0(unsigned short *);
extern "C" float func_002B12D8();
extern "C" int func_002A4B20(void *, unsigned short);
extern void *Font;
extern "C" int Rnd__Fv(void);
extern "C" void func_002A8578(void *, float, int, int, int, int, int);
extern "C" void SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, void *, void *, unsigned, int);
extern "C" void SetTgtTurn__8cGameObjRC4cVecf(void *, void *, float);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void calcNullPart__6cModel(void *);
extern "C" void Add_nullspeed__FP8cObjBase(void *);
extern char Snd[];

// FUNCTION: GAME 0x2B0908
extern "C" float func_002B0908(char *self, unsigned short *p, float *f)
{
    unsigned short t = *p;
    if ((t >> 15) != 0) {
        switch (t & 0xFF00) {
        case 0xA800:
            return *f * *(float *)(self + 0x3C) * *(float *)(self + 0x44) * 40.0f;
        case 0x9300:
            return func_002B0D68(self, func_002B1270(self, p), f);
        case 0x9400:
            return func_002B1090(self, func_002B1290(self), f);
        default:
            return 0.0f;
        }
    }
    if (func_002B12A0(p) != 0)
        return func_002B12D8() * (*f * *(float *)(self + 0x3C) * *(float *)(self + 0x44));
    return (float)func_002A4B20(Font, *p) * (*f * *(float *)(self + 0x3C) * *(float *)(self + 0x44));
}

struct Row5 {
    int v[5];
};
extern Row5 D_003C23B0[];

// FUNCTION: GAME 0x2B04C0
extern "C" int func_002B04C0(char *self, unsigned short *p, char *out)
{
    unsigned short t = *p;
    if ((t >> 15) == 0)
        return 0;
    switch (t & 0xFF00) {
    case 0xB000:
        *(float *)out = (float)p[1] / 100.0f;
        return 1;
    case 0xB200:
        *(int *)(out + 4) = (p[1] << 16) | p[2];
        return 1;
    case 0xB300:
        *(int *)(out + 4) = D_003C23B0[*(int *)(self + 0x4C)].v[*(int *)(self + 0x50)];
        return 1;
    case 0xB600:
        *(int *)(out + 4) = D_003C23B0[*(int *)(self + 0x4C)].v[p[1]];
        return 1;
    case 0xB700:
        *(int *)(out + 8) |= 1;
        return 1;
    case 0xB800:
        *(int *)(out + 8) &= 0xFFFFFFFE;
        return 1;
    default:
        break;
    }
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x28A780 - 69 differing words; the reference has one extra andi between the two Rnd calls on the x==0x2AB and x-other paths. Tried: p reload after Rnd (79->69), discarded Rnd()&1 (no change), if/else x-check (no change).
extern "C" void func_0028A780(char *self)
{
    unsigned char st = *(unsigned char *)(self + 0x2F6);
    int timer;
    switch (st) {
    case 0: {
        int x = *(int *)(self + 0x564);
        char *p;
        int a;
        int b;
        if (x != 0x2A7 && x != 0x2AB)
            Rnd__Fv();
        int r = Rnd__Fv() & 1;
        p = *(char **)(self + 0x304);
        if (r) {
            a = *(int *)(p + 0x80);
            b = *(int *)(p + 0x84);
        } else {
            a = *(int *)(p + 0x88);
            b = *(int *)(p + 0x8C);
        }
        func_002A8578(self, 0.0f, a + (int)p, b + (int)p, 5, 0, 0);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 1, 0x5C, self, 0, 0, 0, 0);
        *(int *)(self + 0x5F0) = 10;
        *(unsigned char *)(self + 0x2F6) = *(unsigned char *)(self + 0x2F6) + 1;
    }
        /* fallthrough */
    case 1:
        timer = *(int *)(self + 0x5F0);
        if (timer != 0) {
            char *part;
            char *tgt;
            *(int *)(self + 0x5F0) = timer - 1;
            part = *(char **)(self + 0x670);
            tgt = *(char **)(part + 0x34);
            if (tgt != 0)
                SetTgtTurn__8cGameObjRC4cVecf(self, *(void **)(tgt + 0xF0), *(float *)(self + 0x5A8) * 0.3926991f);
        }
        if (moveMotion__FP8cObjBase(self) != 0) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
        calcNullPart__6cModel(self);
        Add_nullspeed__FP8cObjBase(self);
        return;
    }
}
#endif
