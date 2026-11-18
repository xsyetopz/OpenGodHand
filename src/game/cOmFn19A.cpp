// Constructors of map objects that own an array of 0x60-byte sub-records,
// each cleared with five zero quad stores and a flag reset.
extern "C" void func_0016F640(char *self, char v);
#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")
extern "C" void func_001BBEB8(void *self);
extern "C" void func_001C27E8(void *self);
extern "C" void func_001C7D98(void *self);
extern const char D_00425630[];
extern const char D_00425718[];
extern const char D_004258F0[];
extern const char D_004259D8[];
extern const char D_00425B90[];
extern const char D_00425C78[];
extern const char D_00425D48[];

// FUNCTION: GAME 0x19A998
extern "C" void *func_0019A998(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00425630;
    for (int i = 6; i != -1; i--) {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    }
    return self;
}

// FUNCTION: GAME 0x19AC18
extern "C" void *func_0019AC18(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00425718;
    for (int i = 6; i != -1; i--) {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    }
    return self;
}

// FUNCTION: GAME 0x19BBB8
extern "C" void *func_0019BBB8(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004258F0;
    for (int i = 11; i != -1; i--) {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    }
    return self;
}

// FUNCTION: GAME 0x19BE28
extern "C" void *func_0019BE28(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004259D8;
    for (int i = 7; i != -1; i--) {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    }
    return self;
}

// FUNCTION: GAME 0x19C320
extern "C" void *func_0019C320(char *self)
{
    char *p = self + 0x650;
    func_001BBEB8(self);
    *(const void **)(self + 0x214) = D_00425B90;
    for (int i = 6; i != -1; i--) {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    }
    return self;
}

// FUNCTION: GAME 0x19C588
extern "C" void *func_0019C588(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_00425C78;
    for (int i = 5; i != -1; i--) {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    }
    return self;
}

// FUNCTION: GAME 0x19D340
extern "C" void *func_0019D340(char *self)
{
    char *p = self + 0x650;
    func_001BBEB8(self);
    *(const void **)(self + 0x214) = D_00425D48;
    for (int i = 6; i != -1; i--) {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    }
    return self;
}
