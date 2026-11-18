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

extern "C" void func_001B6E90(void *self);
extern const char D_00423148[];
extern const char D_00423338[];
extern const char D_00423608[];
extern const char D_00423700[];
extern const char D_00425FB0[];
extern const char D_00426098[];
extern const char D_00426180[];
extern const char D_00426268[];
extern const char D_00426350[];
extern const char D_004294F0[];
extern const char D_00423230[];
extern const char D_00423400[];
extern const char D_004234E8[];
extern const char D_00423B88[];
extern const char D_00426438[];
extern const char D_00426520[];
extern const char D_00426608[];
extern const char D_004266F0[];
extern const char D_004268C8[];
extern const char D_004269B0[];
extern const char D_00426A98[];
extern const char D_00426B80[];
extern const char D_00426C68[];
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

// FUNCTION: GAME 0x19D9C0
extern "C" void *func_0019D9C0(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00425FB0;
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

// FUNCTION: GAME 0x19DC48
extern "C" void *func_0019DC48(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00426098;
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

// FUNCTION: GAME 0x19DED0
extern "C" void *func_0019DED0(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00426180;
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

// FUNCTION: GAME 0x19E1C0
extern "C" void *func_0019E1C0(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00426268;
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

// FUNCTION: GAME 0x19E448
extern "C" void *func_0019E448(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00426350;
    for (int i = 9; i != -1; i--) {
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

// FUNCTION: GAME 0x187750
extern "C" void *func_00187750(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00423148;
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

// FUNCTION: GAME 0x187C88
extern "C" void *func_00187C88(char *self)
{
    char *p = self + 0x610;
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00423338;
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

// FUNCTION: GAME 0x188F80
extern "C" void *func_00188F80(char *self)
{
    char *p = self + 0x610;
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00423608;
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

// FUNCTION: GAME 0x18A598
extern "C" void *func_0018A598(char *self)
{
    char *p = self + 0x610;
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00423700;
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

// FUNCTION: GAME 0x1BDE50
extern "C" void *func_001BDE50(char *self)
{
    char *p = self + 0x600;
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_004294F0;
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

// FUNCTION: GAME 0x1879C8
extern "C" void *func_001879C8(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00423230;
    for (int i = 9; i != -1; i--) {
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

// FUNCTION: GAME 0x188A68
extern "C" void *func_00188A68(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00423400;
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

// FUNCTION: GAME 0x188CF8
extern "C" void *func_00188CF8(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004234E8;
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

// FUNCTION: GAME 0x18EA10
extern "C" void *func_0018EA10(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00423B88;
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

// FUNCTION: GAME 0x19E6C0
extern "C" void *func_0019E6C0(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00426438;
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

// FUNCTION: GAME 0x19E938
extern "C" void *func_0019E938(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00426520;
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

// FUNCTION: GAME 0x19EBB8
extern "C" void *func_0019EBB8(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00426608;
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

// FUNCTION: GAME 0x19EE30
extern "C" void *func_0019EE30(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004266F0;
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

// FUNCTION: GAME 0x19FEA8
extern "C" void *func_0019FEA8(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004268C8;
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

// FUNCTION: GAME 0x1A0120
extern "C" void *func_001A0120(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004269B0;
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

// FUNCTION: GAME 0x1A0390
extern "C" void *func_001A0390(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00426A98;
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

// FUNCTION: GAME 0x1A0608
extern "C" void *func_001A0608(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00426B80;
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

// FUNCTION: GAME 0x1A0880
extern "C" void *func_001A0880(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00426C68;
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

extern const char D_00426D50[];
// FUNCTION: GAME 0x1A0AF0
extern "C" void *func_001A0AF0(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00426D50;
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

extern const char D_00427060[];
// FUNCTION: GAME 0x1A3A98
extern "C" void *func_001A3A98(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00427060;
    for (int i = 19; i != -1; i--) {
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

extern const char D_00427148[];
// FUNCTION: GAME 0x1A3D10
extern "C" void *func_001A3D10(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_00427148;
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

extern const char D_004284A0[];
// FUNCTION: GAME 0x1B2220
extern "C" void *func_001B2220(char *self)
{
    char *p = self + 0x620;
    func_001C27E8(self);
    *(const void **)(self + 0x214) = D_004284A0;
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

extern const char D_00423078[];
// FUNCTION: GAME 0x186998
extern "C" void *func_00186998(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_00423078;
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

extern const char D_004237E8[];
// FUNCTION: GAME 0x18B290
extern "C" void *func_0018B290(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_004237E8;
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

extern const char D_004238D8[];
// FUNCTION: GAME 0x18C098
extern "C" void *func_0018C098(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_004238D8;
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

extern const char D_004239C8[];
// FUNCTION: GAME 0x18CEA0
extern "C" void *func_0018CEA0(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_004239C8;
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

extern const char D_00423AB8[];
// FUNCTION: GAME 0x18DC58
extern "C" void *func_0018DC58(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_00423AB8;
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

extern const char D_004267F8[];
// FUNCTION: GAME 0x19F0A8
extern "C" void *func_0019F0A8(char *self)
{
    char *p = self + 0x660;
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_004267F8;
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

extern const char D_00422F90[];
// FUNCTION: GAME 0x186738
extern "C" void *func_00186738(char *self)
{
    char *p = self + 0x650;
    func_001BBEB8(self);
    *(const void **)(self + 0x214) = D_00422F90;
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

extern const char D_00423D40[];
// FUNCTION: GAME 0x18EEA8
extern "C" void *func_0018EEA8(char *self)
{
    char *p = self + 0x650;
    func_001BBEB8(self);
    *(const void **)(self + 0x214) = D_00423D40;
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

extern const char D_00427690[];
// FUNCTION: GAME 0x1A8150
extern "C" void *func_001A8150(char *self)
{
    char *p = self + 0x650;
    func_001BBEB8(self);
    *(const void **)(self + 0x214) = D_00427690;
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
