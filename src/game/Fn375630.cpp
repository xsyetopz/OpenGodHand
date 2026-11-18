struct VolSrc { char b[16]; } __attribute__((packed));
struct Sde375 {
    char _0[0x28]; VolSrc v; short h38; short h3A, h3C, h3E, h40, h42;
};
extern Sde375 D_0076A790;

// FUNCTION: GAME 0x375630
extern "C" void SdeSystemVolSet(VolSrc *src)
{
    Sde375 *d = &D_0076A790;
    d->v = *src;
    d->h38 = 0;
    int a = *(short *)((char *)d + 0x2A) << 8;
    int b = *(short *)((char *)d + 0x28) << 8;
    d->h3A = a * *(short *)((char *)d + 0x2E) / 127;
    d->h3C = b * *(short *)((char *)d + 0x30) / 127;
    d->h3E = a * *(short *)((char *)d + 0x32) / 127;
    d->h40 = b * *(short *)((char *)d + 0x34) / 127;
    d->h42 = a * *(short *)((char *)d + 0x36) / 127;
}
