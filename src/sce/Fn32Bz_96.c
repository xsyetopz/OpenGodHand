// COMPILER: ee-gcc2.96
extern void func_00327728(void);
// FUNCTION: GAME 0x0032BB20
void func_0032BB20(void) { func_00327728(); }
extern int func_0034DEC8(void);
extern int func_0035A1C8(int, int);
extern int func_0034DD70(int, int);
// FUNCTION: GAME 0x0035A128
int func_0035A128(int a, int b, int *out)
{
    if (a == 0) {
        *out = *(int *)(0x3EE0C0 + b * 4);
    } else {
        if (func_0034DEC8() != 0) return func_0034DD70(0, 0xFF000113);
        *out = func_0035A1C8(a, b);
    }
    return 0;
}
extern int func_0035AB80(char *);
extern int func_0036C920(int, int, int);
// FUNCTION: GAME 0x0035AAC8
int func_0035AAC8(char *base, int *out, int *q)
{
    char *s1 = base + 0xE48;
    char *s3 = base + 0xD30;
    int r = func_0035AB80(base);
    int k = *q;
    if (k == 1) return r;
    if (k == *(int *)(s3 + 0x148)) {
        *out = *out + *(int *)(s3 + 0x144);
    } else if (*(int *)s1 != 0) {
        *out = *out + func_0036C920(*(int *)(s1 + 0x24), k, *(int *)(s1 + 0x28));
    }
    return r;
}
extern int func_0034CD48(char *);
extern int func_00359DA8(char *);
extern int func_00359DF0(char *);
// FUNCTION: GAME 0x00359CB8
int func_00359CB8(char *p)
{
    char *s4 = p + 0xDC4;
    char *s1 = p + 0x36B4;
    char *s0 = *(char **)(p + 0x36B0);
    int s3;
    if (func_0034CD48(p)) return;
    s3 = 0;
    if (*(int *)(s0 + 0xDAC) <= 0) {
        int a, v;
        if (*(int *)(s1 + 4) == -3) a = 0;
        else a = *(int *)(s0 + 0xDD4);
        if (a >= 0) {
            v = func_00359DA8(p);
            if (v != -1) {
                s3 = 1;
                *(int *)(s0 + 0xDAC) = a + v;
            }
        }
    }
    if (*(int *)(s0 + 0xDB0) <= 0) {
        int v = *(int *)(s4 + 0x24);
        if (v > 0) {
            *(int *)(s0 + 0xDB0) = v;
            s3 = 1;
            *(int *)(s0 + 0xDB4) = *(int *)(s4 + 0x28);
        }
    }
    if (s3) return func_00359DF0(p);
    return;
}
extern int D_003EE278;
// FUNCTION: GAME 0x0035B8C0
void func_0035B8C0(char *p, int *out, float x, float y)
{
    float f = (float)*(int *)(p + 0xAC4);
    char *q = p + 0xD30;
    int t;
    if (y + f < x) { *out = 0; return; }
    if (x <= y - f) {
        *out = 1;
        if (*(float *)(q + 0x2C8) == x) return;
        if (*(float *)(q + 0x2C0) == x) return;
        *(int *)(q + 0x2BC) = *(int *)(q + 0x2BC) + 1;
        *(float *)(q + 0x2C0) = x;
        return;
    }
    t = 0;
    if (D_003EE278 == 0xEA24 && *(int *)(p + 0x920) < 3)
        t = (*(int *)(q + 0x2AC) == 0x3E8);
    if (*(int *)(q + 0x2BC) <= t) {
        *out = *(int *)(q + 0x2C4);
    } else {
        if (y < x) *out = 0; else *out = 1;
    }
    *(int *)(q + 0x2BC) = 0;
    *(float *)(q + 0x2C8) = x;
    *(int *)(q + 0x2C4) = *out;
}
