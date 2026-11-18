// COMPILER: ee-gcc3.2-030926
// SCE library code (sd s0 prologues), built with ee-gcc 3.2 at -O2 -G0.

void func_003403C8(char *);
void func_003404B0(char *);
void func_003403E0();
void func_00340520(char *);
void func_003389F8(char *);
void func_00338A10();
void func_003B9AF8(char *);
void func_003298C0(char *);

// FUNCTION: GAME 0x340480
void func_00340480(char *p)
{
    func_003403C8(p);
    func_003404B0(p);
    func_003403E0();
}

// FUNCTION: GAME 0x3404F0
void func_003404F0(char *p)
{
    func_003403C8(p);
    func_00340520(p);
    func_003403E0();
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3402E0
// diff: original loads ra before `sb zero,(s0)`; ours stores first (2 words)
void func_003402E0(char *p)
{
    func_003389F8(p);
    *p = 0;
    func_00338A10();
}

// DRAFT: GAME 0x342A08
// diff: original loads ra before `daddu a0,s0`; ours reloads a0 first (2 words)
void func_00342A08(char *p)
{
    func_003B9AF8(p);
    func_003298C0(p);
}
#endif

void func_0033B658(char *);
void func_0033B670();
void func_0033B790(char *);
void func_003428A0(char *, int, int, int);
void func_00342910(char *);
void func_00348870(char *);
void func_00324950(char *);

// FUNCTION: GAME 0x3403C8
void func_003403C8(char *p)
{
    func_0033B658(p);
}

// FUNCTION: GAME 0x3403E0
void func_003403E0()
{
    func_0033B670();
}

// FUNCTION: GAME 0x340AE8
void func_00340AE8(char *p)
{
    func_0033B790(p);
}

// FUNCTION: GAME 0x342870
void func_00342870(char *p, int b, int c)
{
    func_003428A0(p, b, c, 1);
}

// FUNCTION: GAME 0x342888
void func_00342888(char *p)
{
    func_00342910(p);
}

// FUNCTION: GAME 0x342910
void func_00342910(char *p)
{
    func_00348870(p + 0x284);
}

// FUNCTION: GAME 0x342928
void func_00342928(char *p)
{
    func_00324950(p);
}
