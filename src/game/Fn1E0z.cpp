extern "C" void func_2D65D0(char *, float *);
extern "C" void func_2D65A0(char *, int);
extern "C" void func_2D6838(char *, int, int);
extern "C" void func_1F2D60(char *);
extern "C" void func_1F3118(char *);
extern "C" void func_1F32A0(char *);
extern "C" void func_2D5DE0(char *);
extern "C" void func_2AAA40(char *);

// FUNCTION: GAME 0x001F28F0
extern "C" void func_001F28F0(char *s)
{
    int i;
    char *p;
    func_1F2D60(s);
    func_1F3118(s);
    func_1F32A0(s);
    p = s + 0x60;
    for (i = 17; i >= 0; i--) {
        func_2D5DE0(p);
        p += 0x7C;
    }
    func_2AAA40(s + 0x10);
    char *q = s + 0x930;
    p = s + 0x980;
    int j = 2;
    for (; j >= 0; j--) {
        func_2D5DE0(p);
        p += 0x7C;
    }
    func_2AAA40(q);
}

// FUNCTION: GAME 0x001F8810
extern "C" int func_001F8810(float *a, float *b, float t)
{
    float lo = a[1];
    float hi = lo + a[2];
    float y = b[1] * t;
    if (y < lo) return 0;
    if (hi < y) return 0;
    float dx = b[0] - a[4] * t;
    float dz = b[2] - a[5] * t;
    float d = dx * dx + dz * dz;
    __asm__ volatile("nop\n\tnop\n\tsqrt.s %0,%0" : "+f"(d));
    if (d < a[3]) return 1;
    return 0;
}

// FUNCTION: GAME 0x001F5510
extern "C" void func_001F5510(char *s, int a, int b)
{
    float v;
    func_2D65D0(s + 0x30D0, &v);
    float r = (float)b / (float)a;
    if (r > 1.0f) r = 1.0f;
    func_2D65A0(s + 0x31C8, (int)(v * r));
    func_2D6838(s + 0x2F5C, -3, 0x10);
    func_2D6838(s + 0x2FD8, 3, 0x10);
}
