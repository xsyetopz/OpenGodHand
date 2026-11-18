// FUNCTION: GAME 0x31A0B8
extern "C" void func_0031A0B8(int p, unsigned bit)
{
    int b = p + 0x350;
    int o = (bit >> 5) << 2;
    unsigned *q = (unsigned *)(o + b);
    *q &= ~(0x80000000u >> (bit & 0x1F));
}
