extern "C" void func_002B04C0(char *, unsigned short *, int);
extern "C" int func_002AF068(unsigned short);
extern "C" float func_002B0908(char *, unsigned short *, int);
extern "C" float func_002B0A58(char *, unsigned short *, int);
extern int getCodeSize__11cMessCommonUs(unsigned short);

#ifdef NONMATCHING
// DRAFT: GAME 0x2B0700
// 9 differing words: s3/s4 swapped (n vs mx regs); tried for(;;), goto form, z hoist, nn copy, m alias, register; 8 attempts
extern "C" unsigned short *func_002B0700(char *self, unsigned short *s, int n, float *out, float *mx)
{
    *out = 0.0f;
    *mx = 0.0f;
    float z = *mx;
    goto test;
add:
    *out += *(float *)(self + 0x2C) * *(float *)(self + 0x44);
body:
    {
        float a = func_002B0908(self, s, n);
        float b = func_002B0A58(self, s, n);
        if (a != z) *out += a;
        if (*mx < b) *mx = b;
        s += getCodeSize__11cMessCommonUs(*s);
    }
test:
    if (!(*s >> 15)) goto add;
    func_002B04C0(self, s, n);
    if (!func_002AF068(*s)) goto body;
    *out -= *(float *)(self + 0x2C) * *(float *)(self + 0x44);
    return s;
}
#endif
