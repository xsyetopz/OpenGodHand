extern "C" void func_001F38A0();
extern "C" void func_001F4428(char *, int);
extern "C" void func_001F44E0(char *);
extern unsigned char D_0074748C;
extern struct { char pad[0x10]; short a, b; } g_CasinoWork;

#ifdef NONMATCHING
// DRAFT: GAME 0x1F3D38
// 36 words differ: original is a switch (beq 1, slti 2, bnel 0; case 0 body first, g_CasinoWork stores via one addiu); ours if-chain. Variants: switch 0/1, switch 1/0, unsigned switch, default:, if-chain (best); switch gave 45
extern "C" void func_001F3D38(char *self)
{
    int s = *(int *)(self + 8);
    if (s == 1) {
        if ((D_0074748C >> 2) & 1) {
            g_CasinoWork.b = 0;
            g_CasinoWork.a = 0;
            *(int *)(self + 0x54) |= 1;
            func_001F44E0(self);
            *(int *)(self + 8) += 1;
        }
    } else if (s < 2 && s == 0) {
        if ((D_0074748C >> 2) & 1) {
            func_001F38A0();
            func_001F4428(self, 0);
            *(int *)(self + 8) += 1;
        }
    }
}
#endif
