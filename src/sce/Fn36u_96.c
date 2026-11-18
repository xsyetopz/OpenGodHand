// COMPILER: ee-gcc2.96
extern void func_00360298();
extern void func_00368E80();
extern int strncmp();
extern char D_0045A218[];
extern char D_0045A230[];
extern int func_00365EB0();
extern void func_00363528();
extern void func_003600E8();
extern void func_00360428();
extern int func_00360790();
extern int D_003EEA6C;
extern int D_00766CA4;
extern int func_00368FC0();

// FUNCTION: GAME 0x360280
void func_00360280(void) { func_00360298(); }

// FUNCTION: GAME 0x366960
void func_00366960(void *d, void *s, int n) { memcpy(d, s, n); }

// FUNCTION: GAME 0x368E68
void func_00368E68(void) { func_00368E80(); }

// FUNCTION: GAME 0x3607C8
int func_003607C8(char *s, int n)
{
    if (s == 0 || n < 0)
        return 0;
    return strncmp(s + 0x12, D_0045A218, 1) == 0;
}

// FUNCTION: GAME 0x360808
int func_00360808(char *s, int n)
{
    if (s == 0 || n < 0)
        return 0;
    return strncmp(s + 0x13, D_0045A230, 1) == 0;
}

// FUNCTION: GAME 0x3634E0
void func_003634E0(int a, int b, int *c)
{
    int v = *c;
    if (v == 0)
        v = func_00365EB0();
    func_00363528(a, b, v);
}

// FUNCTION: GAME 0x3603D8
void func_003603D8(int a, int b, int c)
{
    int x[2];
    func_003600E8(a, b, x, x + 1);
    func_00360428(a, x[0], x[1], c);
}

extern void func_00368EE0();
extern int *D_003F1A98;

// FUNCTION: GAME 0x368E90
int func_00368E90(char *o, int v)
{
    if (o == 0)
        func_00368EE0(D_003F1A98, v);
    else
        func_00368EE0(o + 4, v);
    return v;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x360740
// diff: orig reads D_003EEA6C into v1 for the test and reloads a0 after the call; ours reuses v0 (10 words)
void func_00360740(void)
{
    if (D_003EEA6C <= 0)
        D_00766CA4 = func_00360790();
    D_003EEA6C++;
}

// DRAFT: GAME 0x366D28
// diff: orig copies a2 to s1 and stores E8 first; ours allocates s1=a1 and stores E4 first (4 words)
void func_00366D28(char *o, int a, int b)
{
    if (func_00368FC0() == 0) {
        int *q = (int *)o;
        q[0xE8 / 4] = b;
        q[0xE4 / 4] = a;
    }
}
#endif
