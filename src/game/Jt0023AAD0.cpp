// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" void *Getplayer__Fv();
extern "C" int func_00276468(void *);
extern "C" void func_002A8578(void *, int, int, int, float, int, int);
extern "C" void func_002705D8(void *);
extern "C" void func_002A74E0(void *, void *, int);
extern "C" int func_002A7CA0(void *, void *);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern int D_007476B0;

#define B(o) (*(unsigned char *)(self + (o)))
#define H(o) (*(short *)(self + (o)))
#define UH(o) (*(unsigned short *)(self + (o)))
#define W(o) (*(unsigned *)(self + (o)))

// FUNCTION: GAME 0x23AAD0
extern "C" void func_0023AAD0(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0xC08) + (int)o, *(int *)(o + 0xC0C) + (int)o, 0xA, 0.0f, r, 0);
        W(0x16D0) = (W(0x16D0) | 0x8000) & ~2u;
        B(0x2F6)++;
    }
    case 1:
        W(0x16D0) |= 0x400000;
        if (moveMotion__FP8cObjBase(self)) {
            B(0x2F6)++;
            break;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    case 2: {
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0xC08) + (int)o, *(int *)(o + 0xC0C) + (int)o, 0xA, 0.0f, r, 0);
        *(int *)(self + 0x5F0) = 1;
        B(0x2F6)++;
    }
    case 3: {
        int n = H(0x54A);
        int m = H(0x548);
        W(0x16D0) |= 0x400000;
        n++;
        if (m < n) n = m;
        if (n >= m)
            UH(0x54A) = UH(0x548);
        else
            H(0x54A) = n;
        if ((D_007476B0 & 7) == (W(0x17D0) & 7)) {
            W(0x16D4) &= ~0x8000000u;
            char *pl = (char *)Getplayer__Fv();
            func_002A74E0(self, *(char **)(pl + 0xF0), 1);
            if (func_002A7CA0(self, self + 0x16A0))
                W(0x16D4) |= 0x8000000;
            if (*(float *)(self + 0x510) < 8.0f) {
                *(int *)(self + 0x5F0) = 0;
                W(0x16D0) = (W(0x16D0) & ~0x8000u) | 2;
            }
        }
        if (W(0x16EC))
            B(0x2F6) = 4;
        if (moveMotion__FP8cObjBase(self)) {
            if (!*(int *)(self + 0x5F0))
                B(0x2F6) = 4;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    }
    case 4: {
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0xC10) + (int)o, *(int *)(o + 0xC14) + (int)o, 0xA, 0.0f, r, 0);
        B(0x2F6)++;
    }
    case 5:
        W(0x16D0) |= 0x400000;
        if (moveMotion__FP8cObjBase(self)) {
            func_002705D8(self);
            break;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    }
}
