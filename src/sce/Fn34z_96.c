// COMPILER: ee-gcc2.96
extern int D_003EE2C0;

// FUNCTION: GAME 0x340308
void func_00340308(char *a)
{
    *(int *)(a + 0x3C) = 0;
    a[1] = 1;
}

// FUNCTION: GAME 0x344770
void func_00344770(int *a)
{
    a[0x80]++;
}

// FUNCTION: GAME 0x344780
void func_00344780(int *a)
{
    a[0x80]--;
}

// FUNCTION: GAME 0x346FB0
void func_00346FB0(int *a, int b, int c, int d)
{
    a[0] = b;
    a[1] = c;
    a[2] = d;
}

// FUNCTION: GAME 0x3472D8
int func_003472D8(int *a)
{
    return a[2] == 2;
}

// FUNCTION: GAME 0x34B290
int func_0034B290(int a)
{
    D_003EE2C0 = a;
    return 0;
}

extern int D_003EC450;
int func_0034C390(int, int, int);
int func_0035A1C8(int, int);
int func_0034B3E0(int, int);
void func_00348210(int *, int *, int *);
int func_00328098(void);

// FUNCTION: GAME 0x340520
void func_00340520(void)
{
    D_003EC450--;
}

// FUNCTION: GAME 0x343AD0
void func_00343AD0(char *a, int b, int c, int d)
{
    int *p = (int *)(a + 0x160);
    p[0] = b;
    p[1] = c;
    p[2] = d;
    *(int **)(a + 0x178) = p;
}

// FUNCTION: GAME 0x346828
int func_00346828(int *a)
{
    int r = 0;
    if (a) r = *a;
    return r;
}

// FUNCTION: GAME 0x347400
void func_00347400(char *a)
{
    int *p = (int *)(a + 0x194);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    *(int *)(a + 0x190) = -1;
}

// FUNCTION: GAME 0x34AA00
void func_0034AA00(char *a, int b)
{
    func_0034C390((int)a, *(int *)(a + 0x200C), b);
    // barrier blocks sibcall; original 2.96 build kept jal+jr (K&R, int return, void+return all tail-call)
    __asm__ volatile("");
}

// FUNCTION: GAME 0x34B2A8
int func_0034B2A8(int a)
{
    func_0034B3E0(a, 0);
    return 0;
}

// FUNCTION: GAME 0x34B8D8
int func_0034B8D8(int a)
{
    func_0035A1C8(a, 6);
    return 0;
}

// FUNCTION: GAME 0x34BFA8
void func_0034BFA8(int *a, int b, int c)
{
    a[0] = b;
    a[1] = c;
    a[2] = 0;
    a[3] = 0;
    a[0x13] = 9;
    a[0x14] = 9;
}

// FUNCTION: GAME 0x3481D8
void func_003481D8(void)
{
    int x[3];
    func_00348210(&x[0], &x[1], &x[2]);
}

// FUNCTION: GAME 0x349A40
int func_00349A40(void)
{
    return func_00328098() == 4;
}

void func_00328C80(int);
void func_00348CE0(int *);
unsigned func_00329F98(void);
void func_00329EA8(int);

// FUNCTION: GAME 0x349A68
void func_00349A68(int a)
{
    if (a) func_00328C80(a);
}

// FUNCTION: GAME 0x34ABD0
int func_0034ABD0(void)
{
    if (func_00329F98() < 2) return 0;
    return 1;
}

// FUNCTION: GAME 0x34B2C8
int func_0034B2C8(char *a)
{
    func_00329EA8(**(int **)(a + 0x2004));
    return 0;
}

// FUNCTION: GAME 0x348CB8
void func_00348CB8(int *a)
{
    if (a[0x18] == 1) func_00348CE0(a);
}

// FUNCTION: GAME 0x34C7B0
int func_0034C7B0(char *a, int b)
{
    a += b * 0x74;
    return *(int *)(a + 0x132C);
}

// FUNCTION: GAME 0x34C7D0
int func_0034C7D0(char *a, int b)
{
    a += b * 0x74;
    return *(int *)(a + 0x1344);
}

// FUNCTION: GAME 0x34CD48
int func_0034CD48(int a)
{
    return func_0035A1C8(a, 0x31) != 0;
}

// FUNCTION: GAME 0x34D080
void func_0034D080(int *a)
{
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[0x24] = 0;
}

// FUNCTION: GAME 0x34D098
void func_0034D098(int *a)
{
    a[0] = 0;
    a[3] = 0;
    a[0x24] = 0;
}

// FUNCTION: GAME 0x34DC88
void func_0034DC88(int *a)
{
    a += 0x7F;
    a[0] = 0;
    a[1] = 0;
}
