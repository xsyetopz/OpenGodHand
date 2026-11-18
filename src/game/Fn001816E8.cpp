extern "C" void func_001B6FB8(void *);
extern "C" void func_001BBF68(void *);
extern "C" void setObjCollision__7cOmDoor(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x1816E8
// 33 words differ: compiler forwards the local constants instead of lwc1 reloading from the stack, so constant order and the copy differ; tried array local, ctor struct, operator= struct, asm barrier.
extern "C" int func_001816E8(char *self)
{
    func_001B6FB8(self);
    float a[8];
    a[0] = 1.66f;
    a[1] = 4.47f;
    a[2] = 0.2f;
    a[3] = 1.0f;
    a[4] = -0.83f;
    *(int *)&a[5] = 0;
    *(int *)&a[6] = 0;
    a[7] = 1.0f;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    float *d = (float *)(self + 0x610);
    if (d != a) {
        d[0] = a[0];
        d[1] = a[1];
        d[2] = a[2];
    }
    setObjCollision__7cOmDoor(self);
    *(char *)(self + 0x624) = 1;
    *(char **)(self + 0x628) = self + 0x650;
    func_001BBF68(self);
    *(int *)(self + 0x5B8) |= 2;
    return 1;
}
#endif
