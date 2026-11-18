extern "C" void *GetSeData__4cSndi(int, int);
extern "C" int func_002CB3A8();
extern "C" int func_002CFC78(void *);
extern "C" int func_002CFC88(void *);
extern int D_0044CE48[];

#ifdef NONMATCHING
// DRAFT: GAME 0x2CB4E8
// 26 words; register allocation (a/i/p/1-const regs rotated) and i++ delay-slot placement; tried ternary k, hoisted p, i++ at top, k copy before call
extern "C" int func_002CB4E8(int a, int b)
{
    int t = func_002CB3A8();
    unsigned i = 0;
    int k = t > 0 ? t : b;
    int *p = D_0044CE48;
    do {
        if (func_002CFC78(GetSeData__4cSndi(a, *p)) == 1) {
            i++;
        } else if (*(int *)((char *)GetSeData__4cSndi(a, *p) + 0x3C) != k) {
            i++;
        } else {
            i++;
            if (func_002CFC88(GetSeData__4cSndi(a, *p)) != 1)
                return *p;
        }
        p++;
    } while (i < 12);
    return -1;
}
#endif
