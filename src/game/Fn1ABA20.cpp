extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void setMotionInfo__FP8cObjBaseUiUiUiffUs(void *, int, int, int, float, float, int);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);

#define B(o) (*(unsigned char *)(self + (o)))

#ifdef NONMATCHING
// DRAFT: GAME 0x1ABA20
// 1 word off: case 2 store uses v1 not v0 (tried =2, =3-1, self[]=2, int copy of switch var)
extern "C" void func_001ABA20(char *self)
{
    if (*(int *)(self + 0x9D4))
        (*(int *)(self + 0x9D4))--;
    switch (B(0x2F6)) {
    case 0: {
        char *o = *(char **)(self + 0x304);
        *(unsigned *)(self + 0x9D0) &= 0xBFFFFFFF;
        setMotionInfo__FP8cObjBaseUiUiUiffUs(self, *(int *)(o + 0x40) + (int)o, *(int *)(o + 0x68) + (int)o, 0, 0.0f, 0.0f, 0);
        moveMotion__FP8cObjBase(self);
        B(0x2F6)++;
    }
    case 1:
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    case 2:
        B(0x2F6) = 2;
    case 3:
        if (moveMotion__FP8cObjBase(self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    }
}
#endif
