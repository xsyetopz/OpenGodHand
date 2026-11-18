// Reset of a record whose halfword at 0xA is zero.
struct R { int w0, w4; char b8, b9; short h0A; int w0C; short h10, h12; };

// FUNCTION: GAME 0x306FC0
extern "C" void func_00306FC0(int a, R *r)
{
    if (r->h0A == 0) {
        r->w0 = 0;
        r->w4 = 0;
        r->b8 = 0;
        r->b9 = 0;
        r->h0A = 0;
        r->h10 = 0;
        r->w0C = 0;
        r->h12 = 0;
    }
}
