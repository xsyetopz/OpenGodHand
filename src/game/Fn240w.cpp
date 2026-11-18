// Small units in 0x240000-0x250000.

extern "C" void func_002A8578(float, void *, char *, char *, int, int, int);
extern "C" int func_00276468(void *);
extern "C" int func_00157C18(void *);
extern "C" void func_002705D8(void *);
extern "C" void func_0014F9F0(void *, float);
extern "C" void func_0014F928(void *, float);
extern "C" char *func_002DB6B0(void);
extern "C" void func_002A7498(float, void *, void *);

// FUNCTION: GAME 0x247218
extern "C" void func_00247218(char *self)
{
    *(unsigned char *)(self + 0x617) = 1;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        int r = func_00276468(self) & 0xFFFF;
        char *a, *b;
        if (*(int *)(self + 0x564) == 0x24F) {
            char *p = *(char **)(self + 0x304);
            a = (char *)(*(int *)(p + 0x1F70) + (int)p);
            b = (char *)(*(int *)(p + 0x1F74) + (int)p);
        } else {
            char *p = *(char **)(self + 0x304);
            a = (char *)(*(int *)(p + 0x1F78) + (int)p);
            b = (char *)(*(int *)(p + 0x1F7C) + (int)p);
        }
        func_002A8578(0.0f, self, a, b, 10, r, 0);
        *(short *)(self + 0x568) = 10;
        *(unsigned char *)(self + 0x623) = 1;
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (func_00157C18(self))
            func_002705D8(self);
        func_0014F9F0(self, 1.0f);
        func_0014F928(self, 1.0f);
        if (*(short *)(self + 0x568) > 0)
            (*(unsigned short *)(self + 0x568))--;
        else
            *(unsigned char *)(self + 0x623) = 0;
    }
}

// FUNCTION: GAME 0x2461F0
extern "C" void func_002461F0(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *a, *b;
        *(unsigned char *)(self + 0x1864) = 0;
        if (*(int *)(self + 0x564) == 0x256) {
            char *p = *(char **)(self + 0x304);
            a = (char *)(*(int *)(p + 0x2B7C) + (int)p);
            b = (char *)(*(int *)(p + 0x2B80) + (int)p);
            *(float *)(self + 0x600) = 45.0f;
        } else {
            char *p = *(char **)(self + 0x304);
            a = (char *)(*(int *)(p + 0x2C30) + (int)p);
            b = (char *)(*(int *)(p + 0x2C34) + (int)p);
            *(float *)(self + 0x600) = 60.0f;
        }
        func_002A8578(0.0f, self, a, b, 10, func_00276468(self) & 0xFFFF, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (*(float *)(self + 0x600) > 0.0f) {
            *(unsigned *)(self + 0x16D0) |= 0x800000;
            *(float *)(self + 0x600) -= *(float *)(self + 0x5A8);
        }
        char *o = func_002DB6B0();
        func_002A7498(*(float *)(self + 0x5A8) * 0.19634954f, self, *(void **)(o + 0xF0));
        if (func_00157C18(self) || (*(unsigned short *)(self + 0x3AC) & 0x10))
            func_002705D8(self);
        func_0014F9F0(self, 1.0f);
        func_0014F928(self, 1.0f);
    }
}

// FUNCTION: GAME 0x246370
extern "C" void func_00246370(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *a, *b;
        *(unsigned char *)(self + 0x1864) = 0;
        if (*(int *)(self + 0x564) == 0x256) {
            char *p = *(char **)(self + 0x304);
            a = (char *)(*(int *)(p + 0x2B84) + (int)p);
            b = (char *)(*(int *)(p + 0x2B88) + (int)p);
        } else {
            char *p = *(char **)(self + 0x304);
            a = (char *)(*(int *)(p + 0x2C38) + (int)p);
            b = (char *)(*(int *)(p + 0x2C3C) + (int)p);
        }
        func_002A8578(0.0f, self, a, b, 10, func_00276468(self) & 0xFFFF, 0);
        *(float *)(self + 0x600) = 30.0f;
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (*(float *)(self + 0x600) > 0.0f) {
            *(unsigned *)(self + 0x16D0) |= 0x800000;
            *(float *)(self + 0x600) -= *(float *)(self + 0x5A8);
        }
        char *o = func_002DB6B0();
        func_002A7498(*(float *)(self + 0x5A8) * 0.19634954f, self, *(void **)(o + 0xF0));
        if (func_00157C18(self) || (*(unsigned short *)(self + 0x3AC) & 0x10))
            func_002705D8(self);
        func_0014F9F0(self, 1.0f);
        func_0014F928(self, 1.0f);
    }
}
