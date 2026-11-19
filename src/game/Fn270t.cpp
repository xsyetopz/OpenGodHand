// Small units in 0x270000-0x290000.
extern "C" int moveMotion__FP8cObjBase(void *);

#define B(o) (*(unsigned char *)(self + (o)))

#ifdef NONMATCHING
// DRAFT: GAME 0x27DB20 - 3 words best (case0/default shared tail, v=5 per case); beq vs beql at 0x27DB28 and case-1 sb delay slot differ; tried tail perms (5/3/5/3/3/5), hoisted v (9), if-chain (11), case-1-before-default (13)
extern "C" void func_0027DB20(char *self, int k)
{
    int v;
    switch (k) {
    case 0:
    default:
        v = 5;
        B(0x2F7) = 0;
        break;
    case 1:
        v = 5;
        B(0x2F7) = k;
        break;
    }
    B(0x2F5) = v;
    B(0x2F6) = 0;
    B(0x2F4) = 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x27DBF8 - 16 words best (per-case duplicated tails, 80 vs 84 bytes: target has one extra insn); case-0 split from default gives 22; earlier switch/if forms 19-26
extern "C" void func_0027DBF8(char *self, int k)
{
    switch (k) {
    case 1:
        B(0x2F5) = 7;
        B(0x2F6) = 2;
        B(0x2F7) = 0;
        B(0x2F4) = 0;
        return;
    case 2:
        B(0x2F5) = 7;
        B(0x2F6) = 4;
        B(0x2F7) = 0;
        B(0x2F4) = 0;
        return;
    default:
        B(0x2F5) = 7;
        B(0x2F6) = 0;
        B(0x2F7) = 0;
        B(0x2F4) = 0;
        return;
    }
}
#endif

// FUNCTION: GAME 0x27E3F8
// Switch fallthrough with B()++ reuses the compare constant 1.
extern "C" void func_0027E3F8(char *self)
{
    unsigned char s = B(0x2F6);
    switch (s) {
    case 0:
        B(0x2F6)++;
    case 1:
        moveMotion__FP8cObjBase(self);
    }
}
