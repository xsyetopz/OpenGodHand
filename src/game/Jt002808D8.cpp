// Jump-table switch unit (own file: its .rodata must be exactly the table).
struct cObjBase;
extern "C" void *Getplayer__Fv();
extern "C" void SetMotionStep__FP8cObjBasef(cObjBase *, float);
extern "C" void func_002A8578(cObjBase *, float, int, int, int, int, int);
extern "C" int moveMotion__FP8cObjBase(cObjBase *);

#ifdef NONMATCHING
// DRAFT: GAME 0x2808D8
// 75 words off: original frame is 0x30 with $s1=0 set before Getplayer (unused local that survives); mine is 0x20 so everything shifts. Only one variant tried.
extern "C" void func_002808D8(char *self)
{
    int u = 0;
    float f = *(float *)((char *)Getplayer__Fv() + 0x5A8);
    *(float *)(self + 0x5A8) = f;
    SetMotionStep__FP8cObjBasef((cObjBase *)self, f);
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0:
    {
        char *tb = *(char **)(self + 0x304);
        func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x168) + (int)tb, *(int *)(tb + 0x16C) + (int)tb, 2, 0, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        moveMotion__FP8cObjBase((cObjBase *)self);
        break;
    case 2:
    {
        char *tb = *(char **)(self + 0x304);
        func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x170) + (int)tb, *(int *)(tb + 0x174) + (int)tb, 2, 0, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 3:
        moveMotion__FP8cObjBase((cObjBase *)self);
        break;
    case 4:
    {
        char *tb = *(char **)(self + 0x304);
        func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x178) + (int)tb, *(int *)(tb + 0x17C) + (int)tb, 2, 0, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 5:
        if (moveMotion__FP8cObjBase((cObjBase *)self)) {
            *(unsigned char *)(self + 0x2F7) = 0;
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
        }
        break;
    }
}
#endif
