extern "C" void func_002A8578(float, void *, char *, char *, int, int, int);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" void *func_002DDAB0(void *, float, int);
extern "C" void dieCommon__7cOmBase(void *);
extern char g_CollSolidManage[];

extern "C" void func_00277A48(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p = *(char **)(self + 0x304);
        func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x54) + (int)p), (char *)(*(int *)(p + 0x58) + (int)p), 3, 0, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1: {
        moveMotion__FP8cObjBase(self);
        float one = 1.0f;
        addNullSpeed_Rotation__8cObjBasef(self, one);
        addNullSpeed__8cObjBasef(self, one);
    }
    }
    if (func_002DDAB0(*(void **)(self + 0xF0), 10.0f, 0)) {
        *(unsigned char *)(self + 0x2F7) = 0;
        *(unsigned char *)(self + 0x2F5) = 2;
        *(unsigned char *)(self + 0x2F4) = 0;
        *(unsigned char *)(self + 0x2F6) = 0;
    }
}

extern "C" void func_00277C48(char *self)
{
    void *e = func_002DDAB0(*(void **)(self + 0xF0), 15.0f, 0);
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p = *(char **)(self + 0x304);
        func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x5C) + (int)p), (char *)(*(int *)(p + 0x60) + (int)p), 3, 0, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            if (e)
                dieCommon__7cOmBase(e);
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
        float one = 1.0f;
        addNullSpeed_Rotation__8cObjBasef(self, one);
        addNullSpeed__8cObjBasef(self, one);
    }
}

extern "C" void func_00279750(char *self)
{
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    *(float *)(self + 0x54C) = 3.0f;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p = *(char **)(self + 0x304);
        func_002A8578(0.0f, self, (char *)(*(int *)(p + 0xC) + (int)p), (char *)(*(int *)(p + 0x10) + (int)p), 0, 0, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            *(unsigned char *)(self + 0x2F4) = 2;
            *(unsigned char *)(self + 0x2F5) = 1;
            *(unsigned char *)(self + 0x2F7) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
        } else {
            float one = 1.0f;
            addNullSpeed_Rotation__8cObjBasef(self, one);
            addNullSpeed__8cObjBasef(self, one);
        }
    }
}
