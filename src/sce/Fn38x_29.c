// COMPILER: ee-gcc2.9-991111
// SCE library units in 0x3875A8-0x3A3FFF built by SCE ee-gcc 2.9x (sd s0 prologues), -O2 -G0.

struct Obj39 {
    char pad[0x40];
    char *m_40;
};

void func_003BAA68(char *);
void func_003BAB50(char *);
int *func_003A4FB8(void);
void *func_0038CFC0(void *);

// FUNCTION: GAME 0x39AE50
int func_0039AE50(struct Obj39 *o)
{
    func_003BAA68(o->m_40 + 0x68);
    return 1;
}

// FUNCTION: GAME 0x39AE78
int func_0039AE78(struct Obj39 *o)
{
    func_003BAB50(o->m_40 + 0x68);
    return 1;
}

// FUNCTION: GAME 0x38B530
int func_0038B530(void)
{
    *func_003A4FB8() = 5;
    return -1;
}

// FUNCTION: GAME 0x38B578
void *func_0038B578(void *p)
{
    func_0038CFC0(p);
    return p;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x38B0B0
// diff: 5 words, register allocation of the vtable slot ($v0 vs $a1) and the adjust ($a2 vs $v1)
void func_0038B0B0(char *o)
{
    struct VT {
        char pad[0x10];
        short adj;
        short pad2;
        void (*fn)(char *);
    } *vt = *(struct VT **)(o + 0x50);
    vt->fn(o + vt->adj);
}
#endif

// FUNCTION: GAME 0x38C3F0
void func_0038C3F0(char *o)
{
    struct VT {
        char pad[0x14];
        void (*fn)(char *);
    } *vt = *(struct VT **)(o + 0x50);
    vt->fn(o);
}

// FUNCTION: GAME 0x38C9E8
void func_0038C9E8(char *o)
{
    struct VT {
        char pad[0x3C];
        void (*fn)(char *);
    } *vt = *(struct VT **)(o + 0x50);
    vt->fn(o);
}
