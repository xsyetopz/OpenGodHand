// Small units in 0x270000-0x290000.
extern "C" int moveMotion__FP8cObjBase(void *);

#define B(o) (*(unsigned char *)(self + (o)))

#ifdef NONMATCHING
// DRAFT: GAME 0x27DB20 - 8-9 words: target branches case0 first and fills li 5 in delay slots; tried switch/if/goto forms and all 3-store orders
extern "C" void func_0027DB20(char *self, int k)
{
    switch (k) {
    case 0:
        B(0x2F7) = 0;
        break;
    case 1:
        B(0x2F7) = k;
        break;
    default:
        B(0x2F7) = 0;
        break;
    }
    B(0x2F5) = 5;
    B(0x2F4) = 0;
    B(0x2F6) = 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x27DBF8 - 19 words: target duplicates default-path stores (k==0/default block with 2F7,2F5,2F4,2F6 order); tried switch w/ early-return default, if-chains: 16-26 words
extern "C" void func_0027DBF8(char *self, int k)
{
    int s;
    switch (k) {
    case 1:
        s = 2;
        break;
    case 2:
        s = 4;
        break;
    default:
        s = 0;
        break;
    }
    B(0x2F5) = 7;
    B(0x2F6) = s;
    B(0x2F7) = 0;
    B(0x2F4) = 0;
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
