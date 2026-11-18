// FUNCTION: GAME 0x133330
extern "C" void SetLayerCollEnable__16cCollisionScrollUcb(char *self, unsigned char layer, int on)
{
    if (!*(char **)self || !*(unsigned short *)(*(char **)self + 0x28))
        return;
    unsigned i = 0;
    unsigned mask = ~2u;
    unsigned off = 0;
    do {
        char *e = (char *)(off + *(unsigned *)(self + 0x14));
        char *m = (char *)(*(unsigned short *)(e + 0xC) * 16 + *(unsigned *)(self + 8));
        if (*(unsigned char *)(m + 0xD) == layer) {
            if (on)
                *(unsigned *)(e + 0x10) &= mask;
            else
                *(unsigned *)(e + 0x10) |= 2;
        }
        i++;
        off += 0x14;
    } while (i < *(unsigned short *)(*(char **)self + 0x28));
}
