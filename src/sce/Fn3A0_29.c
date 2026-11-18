// COMPILER: ee-gcc2.9-991111
// SCE helpers in 0x39B000-0x3A4AF0 (continuation of Fn39x_29.c).

extern void func_0039EC20(void *, unsigned int);
extern void func_0039E7C0(void);

// FUNCTION: GAME 0x39ECF0
void func_0039ECF0(void *s, unsigned int v)
{
    func_0039EC20(s, v);
}

// FUNCTION: GAME 0x3A0E20
void func_003A0E20(void *s, unsigned int v)
{
    func_0039EC20(s, v);
}

// FUNCTION: GAME 0x3A0F80
void func_003A0F80(void *s)
{
    func_003A0E20(s, 0x20);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x39ECB8
// diff: 8 words, register numbering only (2 variants tried)
void func_0039ECB8(void)
{
    volatile unsigned int *p = (volatile unsigned int *)0x10002010;
    unsigned int m = 0x80004000;
    unsigned int v = *p;
    if ((v & m) == 0x80000000)
        func_0039E7C0();
}
#endif

extern int func_003A3768(float *);
extern float func_003A4830(float, float, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x3A1AE8
// diff: 4 words, addiu sp scheduled after the lui/ori pair (5 variants tried)
float func_003A1AE8(float x)
{
    float y[2];
    int n, ix;
    union { float value; int word; } u;
    u.value = x;
    ix = u.word;
    ix &= 0x7FFFFFFF;
    if (ix <= 0x3F490FDA)
        return func_003A4830(x, 0.0f, 1);
    if (ix > 0x7F7FFFFF)
        return x - x;
    n = func_003A3768(y);
    return func_003A4830(y[0], y[1], 1 - ((n & 1) << 1));
}
#endif
