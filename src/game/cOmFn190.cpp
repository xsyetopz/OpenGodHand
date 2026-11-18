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

extern "C" void func_001C7D98(void *self);
extern const char D_004241F0[];
extern const char D_00424C30[];
extern const char D_004250F0[];
extern const char D_00425290[];
extern const char D_00425378[];
extern const char D_00425460[];
extern const char D_00425548[];

// FUNCTION: GAME 0x191FA0
extern "C" void *func_00191FA0(char *self)
{
    char *p = self + 0x650;
    func_001BBEB8(self);
    *(const void **)(self + 0x214) = D_004241F0;
    for (int i = 0; i != -1; i--) {
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

// FUNCTION: GAME 0x195C20
extern "C" void *func_00195C20(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00424C30;
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

// FUNCTION: GAME 0x198FB8
extern "C" void *func_00198FB8(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_004250F0;
    for (int i = 8; i != -1; i--) {
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

// FUNCTION: GAME 0x199FD0
extern "C" void *func_00199FD0(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00425290;
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

// FUNCTION: GAME 0x19A240
extern "C" void *func_0019A240(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00425378;
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

// FUNCTION: GAME 0x19A4A8
extern "C" void *func_0019A4A8(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00425460;
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

// FUNCTION: GAME 0x19A720
extern "C" void *func_0019A720(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00425548;
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

extern const char D_00420070[];
extern const char D_00420158[];
extern const char D_00420240[];
extern const char D_00420328[];
extern const char D_00420410[];
extern const char D_004204F8[];
extern const char D_00420FE0[];
extern const char D_004210D0[];
extern const char D_004213C0[];
extern const char D_004214A8[];

// FUNCTION: GAME 0x16F3B0
extern "C" void *func_0016F3B0(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00420070;
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

// FUNCTION: GAME 0x16F698
extern "C" void *func_0016F698(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00420158;
    for (int i = 8; i != -1; i--) {
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

// FUNCTION: GAME 0x16F988
extern "C" void *func_0016F988(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00420240;
    for (int i = 8; i != -1; i--) {
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

// FUNCTION: GAME 0x16FC80
extern "C" void *func_0016FC80(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00420328;
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

// FUNCTION: GAME 0x16FF68
extern "C" void *func_0016FF68(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00420410;
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

// FUNCTION: GAME 0x170250
extern "C" void *func_00170250(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004204F8;
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

// FUNCTION: GAME 0x1739F0
extern "C" void *func_001739F0(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_00420FE0;
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

// FUNCTION: GAME 0x1747A8
extern "C" void *func_001747A8(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_004210D0;
    for (int i = 12; i != -1; i--) {
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

// FUNCTION: GAME 0x1782B8
extern "C" void *func_001782B8(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004213C0;
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

// FUNCTION: GAME 0x178568
extern "C" void *func_00178568(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004214A8;
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

extern const char D_00421658[];
extern const char D_00421740[];
extern const char D_00421848[];
extern const char D_00421938[];
extern const char D_00421D68[];
extern const char D_00421E38[];
extern const char D_004220B0[];
extern const char D_004223D0[];
extern const char D_00422770[];
extern const char D_00422858[];

// FUNCTION: GAME 0x178A70
extern "C" void *func_00178A70(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00421658;
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

// FUNCTION: GAME 0x178D30
extern "C" void *func_00178D30(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00421740;
    for (int i = 17; i != -1; i--) {
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

// FUNCTION: GAME 0x178FC8
extern "C" void *func_00178FC8(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_00421848;
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

// FUNCTION: GAME 0x179D58
extern "C" void *func_00179D58(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_00421938;
    for (int i = 8; i != -1; i--) {
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

// FUNCTION: GAME 0x17C620
extern "C" void *func_0017C620(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_00421D68;
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

// FUNCTION: GAME 0x17D3D8
extern "C" void *func_0017D3D8(char *self)
{
    char *p = self + 0x650;
    func_001BBEB8(self);
    *(const void **)(self + 0x214) = D_00421E38;
    for (int i = 0; i != -1; i--) {
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

// FUNCTION: GAME 0x17E828
extern "C" void *func_0017E828(char *self)
{
    char *p = self + 0x650;
    func_001BBEB8(self);
    *(const void **)(self + 0x214) = D_004220B0;
    for (int i = 0; i != -1; i--) {
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

// FUNCTION: GAME 0x17F270
extern "C" void *func_0017F270(char *self)
{
    char *p = self + 0x650;
    func_001BBEB8(self);
    *(const void **)(self + 0x214) = D_004223D0;
    for (int i = 0; i != -1; i--) {
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

// FUNCTION: GAME 0x181638
extern "C" void *func_00181638(char *self)
{
    char *p = self + 0x650;
    func_001BBEB8(self);
    *(const void **)(self + 0x214) = D_00422770;
    for (int i = 0; i != -1; i--) {
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

// FUNCTION: GAME 0x181838
extern "C" void *func_00181838(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_00422858;
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

extern const char D_00422928[];
extern const char D_00422C18[];

// FUNCTION: GAME 0x1825E0
extern "C" void *func_001825E0(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00422928;
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

// FUNCTION: GAME 0x1835A0
extern "C" void *func_001835A0(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00422C18;
    for (int i = 0; i != -1; i--) {
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
