// COMPILER: ee-gcc2.9-991111
// SDK stubs: no-op returns (0x3951B0-0x3951D0) and EE kernel syscall wrappers (0x3B64E8-0x3B7C08).

#define NOP_STUB(name) \
    void name(void) \
    { \
        __asm__ volatile("nop
	nop"); \
    }

#define SYSCALL_STUB(name, n) \
    void name(void) \
    { \
        __asm__ volatile("li $3,%0
	syscall" ::"i"(n)); \
    }

// FUNCTION: GAME 0x3951B0
NOP_STUB(func_003951B0)

// FUNCTION: GAME 0x3951C0
NOP_STUB(func_003951C0)

// FUNCTION: GAME 0x3951D0
NOP_STUB(func_003951D0)

// FUNCTION: GAME 0x3B64E8
SYSCALL_STUB(func_003B64E8, 0x83)

// FUNCTION: GAME 0x3B6600
SYSCALL_STUB(func_003B6600, 0x74)

// FUNCTION: GAME 0x3B6668
SYSCALL_STUB(func_003B6668, 0x74)

// FUNCTION: GAME 0x3B6678
SYSCALL_STUB(func_003B6678, 0x5A)

// FUNCTION: GAME 0x3B66C0
SYSCALL_STUB(func_003B66C0, 0x5B)

// FUNCTION: GAME 0x3B6850
SYSCALL_STUB(func_003B6850, 0x74)

// FUNCTION: GAME 0x3B6860
SYSCALL_STUB(func_003B6860, 0x5A)

// FUNCTION: GAME 0x3B68A8
SYSCALL_STUB(func_003B68A8, 0x5B)

// FUNCTION: GAME 0x3B7AD8
SYSCALL_STUB(func_003B7AD8, 0x5A)

// FUNCTION: GAME 0x3B7B20
SYSCALL_STUB(func_003B7B20, 0x5B)

// FUNCTION: GAME 0x3B7B30
SYSCALL_STUB(func_003B7B30, 0x74)

// FUNCTION: GAME 0x3B7C08
SYSCALL_STUB(func_003B7C08, 0x56)

// FUNCTION: GAME 0x3B06C8
int func_003B06C8(void)
{
    int r;
    __asm__ volatile(".set noreorder\n\tmfc0 %0,$12\n\t.set reorder" : "=r"(r));
    return (r ^ 1) & 1;
}

// FUNCTION: GAME 0x3B0A40
struct Ent { unsigned char a, b; };
struct Q { int m0; unsigned m4; struct Ent e[0x200]; };
extern int D_003FAE48;
extern struct Q D_0077DF98;
extern int D_0077DF90;
extern int func_003AFBE0(void);
extern void iSignalSema(int);
int func_003B0A40(int a)
{
    unsigned s;
    __asm__ volatile("li $3,-0x2F\n\tsyscall\n\tmove %0,$2" : "=r"(s));
    if (s != a)
        return func_003AFBE0();
    if (!(s < 0x100) || !D_003FAE48)
        return -1;
    {
        unsigned i = D_0077DF98.m4 & 0x1FF;
        D_0077DF98.m4 = i + 1;
        D_0077DF98.e[i].a = 0;
        D_0077DF98.e[i].b = s;
    }
    iSignalSema(D_0077DF90);
    return s;
}
