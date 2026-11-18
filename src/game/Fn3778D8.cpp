struct Src3778 {
    unsigned short h0; char _2[2]; int w4; unsigned short h8, hA, hC; unsigned char bE, bF; char _10[2]; unsigned short h12;
    char _14[0x78 - 0x14]; int w78, w7C, w80, w84, w88, w8C; char _90[0xA0 - 0x90];
};
struct Dst3778 {
    unsigned short h0; unsigned char b2, b3; int w4; unsigned short h8, hA, hC, hE; int w10, w14, w18, w1C, w20, w24; char _28[0x40 - 0x28];
};
extern Dst3778 D_0076AFC0[];
extern Src3778 D_0076E910[];

// DRAFT: GAME 0x3778D8
// 33 words differ (lui order, bnel/delay-slot fill, scheduling); tried do-while vs for, if/else swap, pointer decl order.
#ifdef NONMATCHING
extern "C" void func_003778D8(void)
{
    Dst3778 *d = D_0076AFC0;
    Src3778 *s = D_0076E910;
    int i = 1;
    do {
        unsigned t = s->h0;
        if (t == 0) {
            d->h0 = 0;
            d->w4 = 0;
        } else {
            d->h0 = t;
            d->b2 = s->bE;
            d->b3 = s->bF;
            d->w4 = s->w4;
            d->h8 = s->h8;
            d->hA = s->hA;
            d->hC = s->hC;
            d->hE = s->h12;
            d->w10 = s->w78;
            d->w14 = s->w7C;
            d->w18 = s->w80;
            d->w1C = s->w84;
            d->w20 = s->w88;
            d->w24 = s->w8C;
        }
        d++;
        i--;
        s++;
    } while (i >= 0);
}
#endif
