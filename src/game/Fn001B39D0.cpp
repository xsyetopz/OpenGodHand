// Small free units in 0x1B39D0-0x1B6F30: two VU0 zero-fill init helpers and the object init they call.
extern "C" void __8cGameObj(void *);
extern "C" void *func_001B6E90(void *self);
extern "C" void func_0016F640(void *p, int v);
extern const char D_004289F0[];
extern const char D_00428778[];
extern const char D_00428840[];
extern const char D_00428A20[];

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")
#define ZQO(p, o) __asm__ volatile("sqc2 $vf0, %1(%0)" : "+r"(p) : "i"(o) : "memory")

#ifdef NONMATCHING
// DRAFT: GAME 0x1B6E90
// 32 differing words: vtable and D_004289F0 lui/addiu register and order ($v0 vs $v1), lw 0x5B8 scheduled early, trailing stores use self offsets; ZQO "+r" fixed the 0x30 frame and $s1 copy; variants: alias removed (41), ZQO (42), hoisted vtable (32, no change), |= for 0x5B8 (32, no change, reverted).
extern "C" void *func_001B6E90(void *arg0)
{
    char *self = (char *)arg0;
    __8cGameObj(self);
    *(int *)(self + 0x5B0) = 0;
    *(int *)(self + 0x5B4) = 0;
    *(const void **)(self + 0x214) = D_00428A20;
    *(int *)(self + 0x5B8) = 0;
    ZQO(self, 0x5C0);
    ZQO(self, 0x5D0);
    *(int *)(self + 0x560) = 0xFFFF;
    *(const void **)(self + 0x4AC) = D_004289F0;
    *(int *)(self + 0x5E0) = 0;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(int *)(self + 0x5EC) = 0;
    *(short *)(self + 0x5F4) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(int *)(self + 0x490) = 0;
    *(int *)(self + 0x498) = 0;
    *(int *)(self + 0x494) = 0;
    *(int *)(self + 0x5D0) = 0;
    *(int *)(self + 0x5D8) = 0;
    *(int *)(self + 0x5D4) = 0;
    *(int *)(self + 0x5B8) = *(int *)(self + 0x5B8) | 0x10;
    return self;
}
#endif

// FUNCTION: GAME 0x1B39D0
extern "C" void *func_001B39D0(void *arg0)
{
    char *self = (char *)arg0;
    char *p = self + 0x660;
    func_001B6E90(self);
    *(int *)(self + 0x600) = 0;
    *(const void **)(self + 0x214) = D_00428778;
    for (int i = 7; i != -1; i--) {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    }
    *(int *)(self + 0x64C) = 0;
    *(int *)(self + 0x650) = 0;
    *(int *)(self + 0x654) = 0;
    *(int *)(self + 0x658) = 0;
    *(int *)(self + 0x648) = 0;
    return self;
}

// FUNCTION: GAME 0x1B56D8
extern "C" void *func_001B56D8(void *arg0)
{
    char *self = (char *)arg0;
    char *p = self + 0x610;
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00428840;
    for (int i = 5; i != -1; i--) {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    }
    *(int *)(self + 0x608) = 0;
    *(int *)(self + 0x604) = 0;
    *(int *)(self + 0x600) = 0;
    return self;
}
