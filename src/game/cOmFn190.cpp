// Constructors of map objects that own an array of 0x60-byte sub-records (count+1 entries),
// each cleared with five zero quad stores and a flag reset.
extern "C" void func_0016F640(char *self, char v);
#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")
extern "C" void func_001BBEB8(void *self);
extern "C" void func_001C27E8(void *self);
extern const char D_00424040[];
extern const char D_00424128[];
extern const char D_004243F0[];
extern const char D_004244D8[];
extern const char D_004245C0[];
extern const char D_004246A8[];
extern const char D_00424790[];
extern const char D_00424878[];
extern const char D_00424960[];
extern const char D_00424A48[];

// FUNCTION: GAME 0x191AB0
extern "C" void *func_00191AB0(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00424040;
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

// FUNCTION: GAME 0x191D38
extern "C" void *func_00191D38(char *self)
{
    char *p = self + 0x650;
    func_001BBEB8(self);
    *(const void **)(self + 0x214) = D_00424128;
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

// FUNCTION: GAME 0x1929B0
extern "C" void *func_001929B0(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004243F0;
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

// FUNCTION: GAME 0x192C38
extern "C" void *func_00192C38(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004244D8;
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

// FUNCTION: GAME 0x192F68
extern "C" void *func_00192F68(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004245C0;
    for (int i = 4; i != -1; i--) {
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

// FUNCTION: GAME 0x1931F0
extern "C" void *func_001931F0(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004246A8;
    for (int i = 3; i != -1; i--) {
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

// FUNCTION: GAME 0x193468
extern "C" void *func_00193468(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00424790;
    for (int i = 4; i != -1; i--) {
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

// FUNCTION: GAME 0x193718
extern "C" void *func_00193718(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00424878;
    for (int i = 4; i != -1; i--) {
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

// FUNCTION: GAME 0x193998
extern "C" void *func_00193998(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00424960;
    for (int i = 4; i != -1; i--) {
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

// FUNCTION: GAME 0x193C20
extern "C" void *func_00193C20(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00424A48;
    for (int i = 3; i != -1; i--) {
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
