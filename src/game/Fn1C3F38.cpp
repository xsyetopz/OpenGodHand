struct cOmSub;
typedef int (cOmSub::*OmFn)();
struct OmTbl {
    OmFn f[3];
};
extern OmTbl D_00429D80;

struct cOmSub {
    char pad0[2];
    unsigned char idx;
    char pad3[5];
    int active;
    int move();
};

// FUNCTION: GAME 0x1C3F38
int cOmSub::move() {
    int r;
    if (active) {
        OmTbl t = D_00429D80;
        r = (this->*t.f[idx])();
    } else
        r = 0;
    return r;
}
