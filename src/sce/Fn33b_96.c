// COMPILER: ee-gcc2.96
extern int D_003E0710, D_003E0708, D_003EADA8;
extern volatile int D_003E3A88;
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
