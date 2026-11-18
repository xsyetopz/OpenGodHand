extern char Snd[];
extern "C" void func_002A8578(float, void *, char *, char *, int, int, int);
extern "C" void func_002A8608(void *, int, int, int, int, int);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, void *, void *, unsigned, int);
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" int func_0026F120(void *);
extern "C" void func_00270C78(void *);
extern char g_CollSolidManage[];
extern "C" unsigned func_00276468(void *);

// FUNCTION: GAME 0x0027C620
extern "C" void func_0027C620(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p = *(char **)(self + 0x304);
        func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x28) + (int)p), (char *)(*(int *)(p + 0x2C) + (int)p), 5, 0, 0);
        func_002A8608(self, 0xBC, 0x1C, 0, 2, *(int *)(self + 0x15B0));
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}

// FUNCTION: GAME 0x0027C6D0
extern "C" void func_0027C6D0(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 1, 0, self, 0, 0, 0, 0);
        char *p = *(char **)(self + 0x304);
        func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x30) + (int)p), (char *)(*(int *)(p + 0x34) + (int)p), 5, 0, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}

// FUNCTION: GAME 0x0027CF40
extern "C" void func_0027CF40(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p;
        if (*(unsigned char *)(self + 0x2F7) != 0) {
            p = *(char **)(self + 0x304);
            func_002A8578(0.0f, self, (char *)(*(int *)(p + 0xB0) + (int)p), (char *)(*(int *)(p + 0xB4) + (int)p), 3, 0, 0);
        } else {
            p = *(char **)(self + 0x304);
            func_002A8578(0.0f, self, (char *)(*(int *)(p + 0xB8) + (int)p), (char *)(*(int *)(p + 0xBC) + (int)p), 3, 0, 0);
        }
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        moveMotion__FP8cObjBase(self);
    }
}

// FUNCTION: GAME 0x0027E438
extern "C" void func_0027E438(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p = *(char **)(self + 0x304);
        func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x190) + (int)p), (char *)(*(int *)(p + 0x194) + (int)p), 0, 0, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1: {
        float one = 1.0f;
        moveMotion__FP8cObjBase(self);
        addNullSpeed_Rotation__8cObjBasef(self, one);
        addNullSpeed__8cObjBasef(self, one);
    }
    }
}

// FUNCTION: GAME 0x0027F6B0
extern "C" void func_0027F6B0(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p;
        if (*(unsigned char *)(self + 0x2F7) != 0) {
            p = *(char **)(self + 0x304);
            func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x3C) + (int)p), (char *)(*(int *)(p + 0x44) + (int)p), 5, 0, 0);
        } else {
            p = *(char **)(self + 0x304);
            func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x3C) + (int)p), (char *)(*(int *)(p + 0x40) + (int)p), 5, 0, 0);
        }
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}

// FUNCTION: GAME 0x0027FB48
extern "C" void func_0027FB48(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p = *(char **)(self + 0x304);
        func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x78) + (int)p), (char *)(*(int *)(p + 0x7C) + (int)p), 5, 0, 0);
        *(int *)(self + 0x5F0) = 1;
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}

// FUNCTION: GAME 0x0027FD00
extern "C" void func_0027FD00(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p;
        if (*(unsigned char *)(self + 0x2F7) != 0) {
            p = *(char **)(self + 0x304);
            func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x80) + (int)p), (char *)(*(int *)(p + 0x88) + (int)p), 5, 0, 0);
        } else {
            p = *(char **)(self + 0x304);
            func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x80) + (int)p), (char *)(*(int *)(p + 0x84) + (int)p), 5, 0, 0);
        }
        *(int *)(self + 0x5F0) = 1;
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}

// FUNCTION: GAME 0x0027FDD8
extern "C" void func_0027FDD8(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p;
        if (*(unsigned char *)(self + 0x2F7) != 0) {
            p = *(char **)(self + 0x304);
            func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x8C) + (int)p), (char *)(*(int *)(p + 0x94) + (int)p), 5, 0, 0);
        } else {
            p = *(char **)(self + 0x304);
            func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x8C) + (int)p), (char *)(*(int *)(p + 0x90) + (int)p), 5, 0, 0);
        }
        *(int *)(self + 0x5F0) = 1;
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}

// FUNCTION: GAME 0x00246F40
extern "C" void func_00246F40(char *self)
{
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    *(unsigned *)(self + 0x16D0) |= 0x20000;
    *(unsigned *)(self + 0x16D0) |= 0x10000;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        unsigned t = func_00276468(self) & 0xFFFF;
        char *p = *(char **)(self + 0x304);
        func_002A8578(80.0f, self, (char *)(*(int *)(p + 0xC34) + (int)p), (char *)(*(int *)(p + 0xC38) + (int)p), 10, t, 0);
        *(int *)(self + 0x5B4) = 99999;
        func_0026F120(self);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        *(unsigned *)(self + 0x16D0) |= 0x20000;
        if (moveMotion__FP8cObjBase(self))
            func_00270C78(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
    }
}

// FUNCTION: GAME 0x00278878
extern "C" void func_00278878(char *self)
{
    *(float *)(self + 0x54C) = 3.0f;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p = *(char **)(self + 0x304);
        func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x1C) + (int)p), (char *)(*(int *)(p + 0x20) + (int)p), 2, 0, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 2;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
        float one = 1.0f;
        addNullSpeed_Rotation__8cObjBasef(self, one);
        addNullSpeed__8cObjBasef(self, one);
    }
}
