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
