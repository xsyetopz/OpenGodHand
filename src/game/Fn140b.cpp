// Small units in .text 0x140000-0x16FFFF.

extern int D_007476B0;
extern "C" {
void func_0015B0C0();
void func_00155DC8(int a, int b);
void func_001574F0(int a, int b);
void func_00141678(void *p);
void func_002A9790(void *a);
void func_001508F8(void *p);
void func_001612C8(void *p);
}
extern char D_004A6E10[];
extern char *D_00566E10;
extern char D_00464080[];
extern char D_00466470[];
extern char cVram_work[];
extern char D_00566E50[];

extern char D_00506E10[];
extern "C" void trans__7cIDBase(void *self);

// FUNCTION: GAME 0x15B0F0
extern "C" char *func_0015B0F0(int n)
{
    char *cur = D_00566E10;
    char *nw = cur + n;
    if (D_00506E10 + (D_007476B0 & 1) * 0x60000 < nw)
        return 0;
    D_00566E10 = nw;
    return cur;
}

// FUNCTION: GAME 0x146E20
extern "C" void func_00146E20(char *self)
{
    signed char t = self[0x79];
    if (t != 0 && t != 6) {
        if (*(unsigned short *)(self + 0xF8) == 0)
            trans__7cIDBase(self);
        else
            trans__7cIDBase(self + 0xA0);
    }
}

extern void *func_SetEffect(int, int, void *, void *, int, unsigned) __asm__("SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2");

// FUNCTION: GAME 0x16FE68
extern "C" void func_0016FE68(void *self)
{
    func_SetEffect(1, 3, self, 0, -1, 0xFFFFFFFF);
}

extern "C" {
void func_0013E400(void *p);
void func_0013C930(void *p);
void func_0013F510(void *p);
void func_0013E908(void *p);
void func_00147188(void *p);
void initData__10cCockPlBar(void *p);
void func_00144C90(void *p);
}

// FUNCTION: GAME 0x141628
extern "C" void func_00141628(char *self)
{
    func_0013E400(self + 0x1910);
    func_0013C930(self + 0x1DC0);
    func_0013F510(self + 0x1E90);
    func_0013E908(self + 0x2220);
    func_00147188(self + 0x1A20);
    initData__10cCockPlBar(self + 0x460);
}

// FUNCTION: GAME 0x145410
extern "C" void func_00145410(char *self)
{
    if (*(int *)(self + 0x90) & 0x40000000) {
        func_00144C90(self);
        *(int *)(self + 0x90) &= 0xEFFFFFFF;
    }
}

extern "C" {
char *getMeshPtr__6cModeli(void *self, int i);
void func_002A9680(void *heap, void *p);
void func_0030F5A0(void *p);
}
// FUNCTION: GAME 0x14D7D0
extern "C" void func_0014D7D0(char *self)
{
    char *mesh = getMeshPtr__6cModeli(self, 0);
    char *x = *(char **)(mesh + 0x388);
    char *volatile keep = x;
    int ok = *(unsigned short *)(x + 8) >= 2;
    self[0x2BE] = ok ? 0x16 : 0x18;
}

// FUNCTION: GAME 0x1483C8
extern "C" void func_001483C8(char *self, int flags)
{
    char *p = *(char **)(self + 0x408);
    if (p)
        func_002A9680(*(void **)(p - 0x20), p);
    if (flags & 1)
        func_0030F5A0(self);
}

extern "C" void func_002AAC28(void *p);
// FUNCTION: GAME 0x1678B8
extern "C" void func_001678B8(char *self)
{
    int s = self[0x5A];
    if (s >= 0) {
        if (s >= 2) {
            if (s < 4)
                func_002AAC28(self + 0xC0);
        }
    }
    func_002AAC28(self);
}

extern "C" void func_0013C618(void *p);
extern unsigned short D_00747A50;
// FUNCTION: GAME 0x146F18
extern "C" void func_00146F18(float *self)
{
    func_0013C618(self);
    if (D_00747A50 == 0x20) {
        self[0x18] = -130.0f;
        self[0x19] = 5.0f;
    } else {
        self[0x18] = 0;
        self[0x19] = 0;
    }
}

struct D747BA0 { char _pad[0x14]; int key; char _pad2[0xB0 - 0x18]; };
extern D747BA0 D_00747BA0[];
// FUNCTION: GAME 0x150D78
extern "C" int func_00150D78(int unused, int key)
{
    int n = 0x100;
    int i = 0;
    if (!key)
        return 0;
    int *b = (int *)D_00747BA0;
    int *p = b + 5;
    do {
        if (*p == key)
            return (short)i;
        p += 0x2C;
        n--;
        i++;
    } while (n);
    return -1;
}

// FUNCTION: GAME 0x151630
extern "C" int func_00151630(char *s)
{
    if (s[0] == 0x54) {
        if (s[3] == 0x33)
            return s[5] == 6;
        if (s[3] == 0x32)
            return 0;
        if (s[1] == 0x4D)
            return 3;
    }
    return 2;
}
