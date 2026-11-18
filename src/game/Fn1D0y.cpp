// FUNCTION: GAME 0x1B1E30
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void SetMotionRun__5cOm71(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern "C" void func_001B1E30(char *self)
{
    *(int *)(self + 0x600) &= -0x101;
    if (moveMotion__FP8cObjBase(self)) {
        long f = *(unsigned *)(self + 0x600);
        long b = (f >> 3) & 1;
        if (b) {
            *(int *)(self + 0x600) &= -9;
            SetMotionRun__5cOm71(self);
        }
        *(int *)(self + 0x600) |= 0x100;
    }
    float one = 1.0f;
    addNullSpeed_Rotation__8cObjBasef(self, one);
    long g = *(unsigned *)(self + 0x600);
    long c = (g >> 7) & 1;
    if (c == 0)
        addNullSpeed__8cObjBasef(self, one);
}

// FUNCTION: GAME 0x1E2EB8
extern "C" void func_001E4520(char *, int);
extern "C" void func_001E4200(char *, unsigned, int, int);
extern "C" void func_001E4438(char *, int, int);
extern "C" void func_001E2EB8(char *self)
{
    switch (*(int *)(self + 0xC)) {
    case 0: {
        *(short *)(self + 0x4C2) = 10;
        long f = *(unsigned *)(self + 0x54);
        long b = (f >> 8) & 1;
        if (b == 0) {
            func_001E4520(self, 1);
            *(int *)(self + 0x54) |= 0x100;
        }
        *(int *)(self + 0xC) += 1;
        break;
    }
    case 1:
        func_001E4200(self, *(unsigned short *)(self + 0x494), 1, 1);
        func_001E4438(self, 0, 1);
        *(int *)(self + 0x10) = 0x78;
        *(int *)(self + 0xC) += 1;
        break;
    case 2: {
        int t = *(int *)(self + 0x10);
        int done;
        if (t) {
            *(int *)(self + 0x10) = t - 1;
            done = 0;
        } else
            done = 1;
        if (done & 0xFF) {
            func_001E4200(self, *(unsigned short *)(self + 0x494), 0, 0);
            *(int *)(self + 0xC) += 1;
        }
        break;
    }
    case 3:
        *(int *)(self + 4) = 0;
        *(int *)(self + 8) = 0;
        *(int *)(self + 0xC) = 0;
        break;
    }
}

// FUNCTION: GAME 0x1E4610
extern "C" void displayScrollLayer__FUib(unsigned, int);
extern "C" void func_001E4610(char *self)
{
    char *a = *(char **)(self + 0x4B0);
    if (a == 0) return;
    if (*(char **)(self + 0x4B4) == 0) return;
    long f = *(unsigned *)(self + 0x54);
    long b = (f >> 9) & 1;
    if (b == 0) return;
    a = *(char **)(a + 0xF0);
    *(float *)a = *(float *)a - 1.0f;
    a = *(char **)(*(char **)(self + 0x4B4) + 0xF0);
    *(float *)a = *(float *)a - 1.0f;
    float *q = *(float **)(*(char **)(self + 0x4B0) + 0xF0);
    if (*q < -130.0f) {
        *(int *)q = 0;
        **(int **)(*(char **)(self + 0x4B4) + 0xF0) = 0;
    }
    float x = **(float **)(*(char **)(self + 0x4B0) + 0xF0);
    if (x < -50.0f && -60.0f < x) {
        displayScrollLayer__FUib(*(unsigned *)(self + 0x458), 1);
        displayScrollLayer__FUib(*(unsigned *)(self + 0x488), 1);
    } else {
        displayScrollLayer__FUib(*(unsigned *)(self + 0x458), 0);
        displayScrollLayer__FUib(*(unsigned *)(self + 0x488), 0);
    }
}
