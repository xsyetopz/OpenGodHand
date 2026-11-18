extern "C" int moveMotion__FP8cObjBase(char *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(char *, float);
extern "C" void addNullSpeed__8cObjBasef(char *, float);
extern "C" void func_002A8578(char *, int, float, int, int, int, int);

struct T3 {
    int a, b, c;
};

// FUNCTION: GAME 0x1AB8F8
extern "C" void func_001AB8F8(char *self)
{
    char *p = *(char **)(self + 0x304);
    int s = *(unsigned char *)(self + 0x2F6);
    T3 u;
    T3 t;
    t.a = *(int *)(p + 0x18) + (int)p;
    t.b = *(int *)(p + 0x24) + (int)p;
    t.c = *(int *)(p + 0x30) + (int)p;
    u = t;
    switch (s) {
    case 0:
        if (!(*(unsigned *)(self + 0x9D0) & 0x40000000)) {
            *(int *)(self + 0x9D4) = 0x3C;
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
            return;
        }
        func_002A8578(self, *(int *)((int)&u + (*(unsigned char *)(self + 0x2F7) << 2)), 0.0f, 0, 10, 0, 0);
        *(unsigned char *)(self + 0x2F6) += 1;
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
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
