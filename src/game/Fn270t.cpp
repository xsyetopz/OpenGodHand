// Small units in 0x270000-0x290000.
extern "C" int moveMotion__FP8cObjBase(void *);

#define B(o) (*(unsigned char *)(self + (o)))

#ifdef NONMATCHING
// DRAFT: GAME 0x27DB20 - 9 words: target shares the 5-store and branches case0 first
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
// DRAFT: GAME 0x27DBF8 - 19 words: target duplicates default-path stores
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

#ifdef NONMATCHING
// DRAFT: GAME 0x27E3F8 - 18 words: target sets v0=1 in beqz delay slot
extern "C" void func_0027E3F8(char *self)
{
    unsigned char s = B(0x2F6);
    if (s == 0) {
        B(0x2F6) = 1;
        moveMotion__FP8cObjBase(self);
    } else if (s == 1)
        moveMotion__FP8cObjBase(self);
}
#endif
