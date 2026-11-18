// COMPILER: ee-gcc2.96
extern int D_003E0710, D_003E0708, D_003EADA8;
extern volatile int D_003E3A88;
extern char D_00455900[], D_00455A60[], D_00455BB8[];
extern void *memset(void *, int, unsigned);
extern void func_003331E0(), func_00331C98(), func_00331CE0(), func_0033B670(), func_0033F130(), func_00340A20(), func_00340740(), func_00340AE8(), func_003B0640();
extern volatile int D_003E3A90, D_003EADB0;

// FUNCTION: GAME 0x338338
void func_00338338(char *p, int v)
{
    if (D_003E0710 != 1 || D_003E0708 > 0)
        p[0x50] = v;
}

// FUNCTION: GAME 0x3386E0
void func_003386E0(char *p, int v)
{
    if (D_003E0710 != 1 || D_003E0708 > 0)
        p[0x52] = v;
}

// FUNCTION: GAME 0x338378
void func_00338378(char *p, int v)
{
    if (D_003E0710 != 1 || D_003E0708 > 0)
        p[0x5B] = v;
}

// FUNCTION: GAME 0x338818
void func_00338818(char *p, int v)
{
    if (D_003E0710 != 1 || D_003E0708 > 0)
        *(int *)(p + 0x5C) = v;
}

// FUNCTION: GAME 0x3389C8
void func_003389C8(void)
{
    D_003E3A90--;
    if (D_003E3A90 == 0)
        D_003E3A88 = 0;
}

// FUNCTION: GAME 0x338990
void func_00338990(void)
{
    D_003E3A90++;
    if (D_003E3A90 == 1)
        D_003E3A88 = 0;
}

// FUNCTION: GAME 0x33E618
void func_0033E618(void)
{
    D_003EADB0++;
    if (D_003EADB0 == 1)
        D_003EADA8 = 0;
}

// FUNCTION: GAME 0x33E648
void func_0033E648(void)
{
    D_003EADB0--;
    if (D_003EADB0 == 0)
        D_003EADA8 = 0;
}

// FUNCTION: GAME 0x3332B0
void func_003332B0(void)
{
    func_003331E0();
}

// FUNCTION: GAME 0x333F60
void func_00333F60(void)
{
    func_00331C98();
}

// FUNCTION: GAME 0x333F80
void func_00333F80(void)
{
    func_00331CE0();
}

// FUNCTION: GAME 0x33FC88
void func_0033FC88(void)
{
    func_0033B670();
}

// FUNCTION: GAME 0x33FCB0
void func_0033FCB0(void)
{
    func_0033F130();
}

// FUNCTION: GAME 0x336E58
void func_00336E58(int *p)
{
    func_00340A20(p[58]);
}

// FUNCTION: GAME 0x336E70
void func_00336E70(int a, int b)
{
    func_0033F130(b);
}

// FUNCTION: GAME 0x332BE0
void func_00332BE0(void *p)
{
    memset(p, 0, 0x48);
}

// FUNCTION: GAME 0x334500
void func_00334500(void *p)
{
    memset(p, 0, 0x30);
}

// FUNCTION: GAME 0x336588
void func_00336588(void *p)
{
    memset(p, 0, 0x38);
}

// FUNCTION: GAME 0x336E38
void func_00336E38(int *p, short s)
{
    func_00340740(p[58], s);
}

// FUNCTION: GAME 0x338A28
void func_00338A28(void)
{
    func_00340AE8(D_00455900);
}

// FUNCTION: GAME 0x339438
void func_00339438(void)
{
    func_00340AE8(D_00455A60);
}

// FUNCTION: GAME 0x33A028
void func_0033A028(void)
{
    func_00340AE8(D_00455BB8);
}
