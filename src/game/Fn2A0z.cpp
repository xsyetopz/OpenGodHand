// God Hand: small units in 0x2A0000-0x2C0000
extern "C" void __7cIDBase(void *);
extern char D_005F38F0[];
// FUNCTION: GAME 0x2BF820
extern "C" void func_002BF820(int a, int b)
{
    if (b == 0xFFFF && a) {
        char *o = D_005F38F0;
        __asm__("" : "+r"(o));
        __7cIDBase(o + 0x20);
    }
}
