// COMPILER: ee-gcc2.96

extern int func_0034C890();
extern int func_0034CAF8();
extern int func_0034CCB0();
extern int WaitSema();
extern int SignalSema();
extern int func_0034DEC8();
extern int func_0034DD70();
extern int func_00357140();
extern int func_00357350();
extern int func_0034BFF8();
extern int func_0035BA48();
extern int func_0034B6D0();
extern int func_00359DF0();
extern int func_0035A260();
#ifdef NONMATCHING
extern int func_003589C0();
#endif
#ifdef NONMATCHING
extern int func_0034C2B8();
extern int func_003518D8();
extern int func_00351AB0();
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x351780 3 words: branch sense (bnez vs beqz) and zero-store order
void func_00351780(char *a, int *b)
{
    int v[8];
    if (!func_0034C2B8(a, *(int *)(a + 0x1FC8), v)) {
        b[1] = 0;
        b[0] = 0;
    } else {
        b[0] = v[0];
        b[1] = v[1];
    }
}

// DRAFT: GAME 0x351888 3 words: epilogue order (return value set before s0 reload)
int func_00351888(int a, int b)
{
    int r = func_003518D8(a, b);
    if (r != -1)
        func_00351AB0(a, b);
    return 0;
}
#endif

// FUNCTION: GAME 0x352DC0
void func_00352DC0(char *a, int *b)
{
    int x;
    b[0] = *(int *)(a + 0x10);
    b[1] = *(int *)(a + 0x1C);
    b[2] = *(int *)(a + 0x20);
    b[3] = *(int *)(a + 0x24);
    b[4] = *(int *)(a + 0x28);
    b[5] = *(int *)(a + 0x2C);
    x = *(int *)(a + 0x14);
    b[6] = x;
    *(short *)(b + 7) = *(char *)(a + 0x54);
    *((short *)b + 15) = 0;
}

// FUNCTION: GAME 0x3545F8
void func_003545F8(char *a)
{
    int v[4];
    func_0034C890(a, *(int *)(a + 0x1FC8), v);
    if (v[0]) {
        func_0034CAF8(v[0], v + 1, v + 2);
        *(long *)(a + 0x9A0) = func_0034CCB0(*(long *)(a + 0x9A0), v[1]);
    }
}

// FUNCTION: GAME 0x355BB8
void func_00355BB8(int *a, int b)
{
    WaitSema(a[0x10]);
    a[5] += b;
    *(long *)(a + 0x12) += b;
    SignalSema(a[0x10]);
}

// FUNCTION: GAME 0x356EF8
int func_00356EF8(int *a)
{
    int r = func_0034DEC8(a);
    if (r) {
        func_0034DD70(0, 0xFF000141);
        return 0;
    }
    return a[0x14];
}

// FUNCTION: GAME 0x3570F8
int func_003570F8(int a)
{
    if (func_0034DEC8(a))
        return func_0034DD70(0, 0xFF000143);
    return func_00357140(a);
}

// FUNCTION: GAME 0x3572F8
int func_003572F8(int a)
{
    if (func_0034DEC8(a))
        return func_0034DD70(0, 0xFF000138);
    func_00357350(a);
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x358968 2 words: epilogue restore order (ld ra before ld s0)
void func_00358968(int *a)
{
    if (func_0034DEC8(a)) {
        func_0034DD70(0, 0xFF000133);
        return;
    }
    func_003589C0(a);
    a[0x11] = 1;
}
#endif

// FUNCTION: GAME 0x359270
int func_00359270(int a, int b)
{
    if (func_0034DEC8(a))
        return func_0034DD70(0, 0xFF000139);
    return func_0034BFF8(a, b);
}

// FUNCTION: GAME 0x359758
int func_00359758(char *a, int b)
{
    if (func_0034DEC8(a))
        return func_0034DD70(0, 0xFF000151);
    *(int *)(a + 0x36B0) = b;
    return 0;
}

// FUNCTION: GAME 0x359C58
void func_00359C58(char *a, int b)
{
    if (func_0034DEC8(a)) {
        func_0034DD70(0, 0xFF00015C);
        return;
    }
    {
        char *p = *(char **)(a + 0x36B0);
        if (p)
            *(int *)(p + 0xDD4) = b;
    }
}

// FUNCTION: GAME 0x35AE70
int func_0035AE70(char *a, int b)
{
    if (func_0034DEC8(a))
        return func_0034DD70(0, 0xFF000124);
    *(int *)(a + 0xD48) = b;
    return 0;
}

// FUNCTION: GAME 0x357150
int func_00357150(int a, int b)
{
    if (func_0034DEC8(a))
        return func_0034DD70(0, 0xFF000144);
    func_0035BA48(a, b);
    func_0034B6D0(a, b);
    return 0;
}

// FUNCTION: GAME 0x359AF0
int func_00359AF0(char *a, int b)
{
    int r = func_0034DEC8(a);
    char *p;
    if (r)
        return func_0034DD70(0, 0xFF000159);
    p = *(char **)(a + 0x36B0);
    if (!p)
        return r;
    *(int *)(p + 0xDC4) = b;
    func_00359DF0(a);
    return 0;
}

// FUNCTION: GAME 0x359B60
int func_00359B60(char *a, int b, int c)
{
    int r = func_0034DEC8(a);
    char *p;
    if (r)
        return func_0034DD70(0, 0xFF00015A);
    p = *(char **)(a + 0x36B0);
    if (!p)
        return r;
    *(int *)(p + 0xDC8) = b;
    *(int *)(p + 0xDCC) = c;
    func_00359DF0(a);
    return 0;
}

// FUNCTION: GAME 0x359BE8
int func_00359BE8(char *a, int b)
{
    int r = func_0034DEC8(a);
    char *p;
    if (r)
        return func_0034DD70(0, 0xFF00015B);
    p = *(char **)(a + 0x36B0);
    if (!p)
        return r;
    *(int *)(p + 0xDD0) = b;
    func_00359DF0(a);
    return 0;
}

// FUNCTION: GAME 0x35A1E0
int func_0035A1E0(int a, int b, int c)
{
    if (func_0034DEC8(a))
        return func_0034DD70(0, 0xFF000117, c);
    func_0035A260(a, b, c);
    return 0;
}
