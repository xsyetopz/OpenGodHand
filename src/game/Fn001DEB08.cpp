struct COL {
    unsigned r : 8;
    unsigned g : 8;
    unsigned b : 8;
    unsigned a : 8;
};
extern "C" void SetColorAnimSin__12CustomIDWorkG3COLT1Us(void *, int, int, unsigned short);
extern "C" void ResetColorAnim__12CustomIDWork(void *);
struct T5 { int a[5]; };
extern T5 D_0042B5D0;

#ifdef NONMATCHING
// DRAFT: GAME 0x1DEB08
// 37 words differ: second COL constant folds to 0x80FFFFFF (original ORs a live 0x80000000 reg), table base reg t2 vs t3; tried COL bitfields, memory-backed COL, unsigned/int word math.
extern "C" void func_001DEB08(char *self, unsigned char k, int on, int alpha)
{
    if (k < 5) {
        T5 t = D_0042B5D0;
        if (on) {
            int hi = 0x80000000;
            int w = alpha & 0xFFFF;
            w |= hi;
            w |= 0x800000;
            w &= 0xFFFF00FF;
            w |= 0x8000;
            w &= ~0xFF;
            w |= 0x80;
            SetColorAnimSin__12CustomIDWorkG3COLT1Us(self + (t.a[k] * 0x7C + 0x60), w, 0xFFFFFF | hi, 0xC);
        } else {
            ResetColorAnim__12CustomIDWork(self + (t.a[k] * 0x7C + 0x60));
        }
    }
}
#endif
