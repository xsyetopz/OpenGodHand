extern "C" void displayScrollLayer__FUib(unsigned, int);
struct T5 { int a[5]; };
extern T5 D_0042BAF0;

// FUNCTION: GAME 0x1E6FE8
extern "C" void func_001E6FE8(char *s)
{
    unsigned v = *(unsigned short *)(s + 0x3E8);
    if (v & 0x8000) {
        v++;
        *(unsigned short *)(s + 0x3E8) = v;
        if ((v & 0x3FF) >= 8) {
            T5 t = D_0042BAF0;
            unsigned short w = (~v & 0x4000) | (v & 0x3800) | 0x8000;
            unsigned k;
            *(unsigned short *)(s + 0x3E8) = w;
            k = (w >> 11) & 7;
            if (w & 0x4000) {
                unsigned *p = (unsigned *)(s + 0x3A0);
                int i = 0;
                for (; i < 5; i++)
                    displayScrollLayer__FUib(*(unsigned *)((char *)p + ((unsigned)t.a[i] << 2)), i == k);
            } else {
                unsigned *p = (unsigned *)(s + 0x3A0);
                int i = 0;
                for (; i < 5; i++)
                    displayScrollLayer__FUib(*(unsigned *)((char *)p + ((unsigned)t.a[i] << 2)), 0);
            }
        }
    }
}
