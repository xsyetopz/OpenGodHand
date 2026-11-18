// Non-family units in 0x1B0000-0x1C0000 (ee-gcc2.95.3-136, C++).
struct V4 {
    float x, y, z, w;
};
static inline int InRangeo(const int &n, int i) { return i >= 0 && i < n; }
static inline char *SlotNo(char *o, int i)
{
    if (InRangeo(*(unsigned char *)(o + 0x2B4), i))
        return ((char **)*(char ***)(o + 0x278))[i];
    return 0;
}

// FUNCTION: GAME 0x1B1938
extern "C" void func_001B1938(char *self)
{
    if (*(unsigned short *)(self + 0x2FE) == 0x364) {
        char *s = SlotNo(self, 1);
        if (s) {
            float f = *(float *)(self + 0x630) * 0.0066666668280959129f;
            if (f > 1.0f)
                f = 1.0f;
            if (f < 0.0f)
                f = 0.0f;
            *(float *)(s + 0x108) = (1.0f - f) * 1.5707963705062866f;
        }
    }
}

struct P {
    int id;
    float w;
};
struct T {
    P p[5];
};
extern const T D_00428068;
extern "C" float fRand0_1__Fv(void);
// FUNCTION: GAME 0x1B0150
extern "C" void func_001B0150(char *self)
{
    if (*(int *)(self + 0x560) == 0xFFFF) {
        float f = fRand0_1__Fv();
        T t = D_00428068;
        int v;
        for (unsigned i = 0; i < 5; i++) {
            if (f < t.p[i].w) {
                v = t.p[i].id;
                goto done;
            }
            f -= t.p[i].w;
        }
        v = 0x3E2;
    done:
        *(int *)(self + 0x560) = v;
    }
}

// FUNCTION: GAME 0x1B4460
extern "C" void func_001B4460(char *self)
{
    switch (*(unsigned char *)(self + 0x2F5)) {
    case 0:
        *(int *)(self + 0x63C) = 30;
        *(float *)(self + 0x640) = *(float *)(self + 0x104);
        *(unsigned char *)(self + 0x2F5) = 1;
    case 1:
        if (*(int *)(self + 0x63C) != 0) {
            float c = (float)(unsigned)(*(int *)(self + 0x63C) & 1);
            *(float *)(self + 0x104) = *(float *)(self + 0x640) + c * 0.06981316953897476f;
            *(int *)(self + 0x63C) -= 1;
        } else {
            *(unsigned char *)(self + 0x2F5) = 2;
        }
        break;
    case 2:
        *(unsigned char *)(self + 0x2F4) = 2;
        *(float *)(self + 0x104) = *(float *)(self + 0x640);
        *(unsigned char *)(self + 0x2F5) = 0;
        break;
    }
}

extern "C" void setMeshDispFromLayer__7cOmBaseUib(void *, unsigned, int);
extern "C" void func_001B7300(void *, int, int);
extern "C" void func_001BE498(void *, int, void *, void *);
// FUNCTION: GAME 0x1BE740
extern "C" void func_001BE740(char *self)
{
    setMeshDispFromLayer__7cOmBaseUib(self, 0, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x40, 1);
    func_001B7300(self, 0, 0);
    func_001B7300(self, 0x40, 0);
    *(unsigned *)(self + 0x250) |= 0x10000;
    V4 a, b;
    V4 *pb = &b;
    a.x = 0;
    a.y = 0;
    a.z = 0;
    a.w = 1.0f;
    b.x = 0;
    b.y = 0;
    b.z = 0;
    pb->w = 1.0f;
    for (int i = 1; i < 8; i++) {
        if (*(unsigned char *)(self + 0x2B4) == i)
            break;
        func_001BE498(self, i, &a, &b);
    }
}

extern "C" void setMeshColorFromLayer__7cOmBaseUifff(void *, unsigned, float, float, float);

// FUNCTION: GAME 0x1B0078
// DIVNOP: 2
extern "C" void func_001B0078(char *self)
{
    float r = (float)*(short *)(self + 0x54A) / (float)*(short *)(self + 0x548);
    if (SlotNo(self, 1)) {
        char *s = SlotNo(self, 1);
        *(float *)(*(char **)(s + 0xD0) + 4) = *(float *)(self + 0x60C) - r * 0.4f;
    }
    float g = r * 0.5f + 0.5f;
    setMeshColorFromLayer__7cOmBaseUifff(self, 0, 1.0f, g, g);
}

// FUNCTION: GAME 0x1B54E8
extern "C" void func_001B54E8(char *self)
{
    long f = *(unsigned *)(self + 0x600);
    long b = (f >> 4) & 1;
    if (b) {
        if (*(short *)(self + 0x644) == 0) {
            setMeshColorFromLayer__7cOmBaseUifff(self, 0, 1.0f, 1.0f, 1.0f);
            *(int *)(self + 0x600) &= ~0x10;
        } else {
            float d = 0.10471975803375244f;
            if (*(unsigned short *)(self + 0x644) % 2)
                d = -d;
            char *s = SlotNo(self, 0);
            *(float *)(s + 0x104) += d;
            *(unsigned short *)(self + 0x644) -= 1;
        }
    }
}
