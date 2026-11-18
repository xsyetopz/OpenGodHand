// Free units in 0x130000-0x140000 (area cam data, camera state step).

struct D { long a, b, c, d, e; int f; } __attribute__((packed));
extern "C" void func_00137AA0(char *);
// FUNCTION: GAME 0x137AE8
extern "C" int SetData__15cAreaCamManagerUi(char *self, char *src) {
    if (src) {
        *(D *)(self + 4) = *(D *)src;
        if (*(int *)(self + 4) == 0x444341) {
            if (*(int *)(self + 8) == 1) {
                *(char **)self = src + 0x18;
                *(float *)(self + 0x1C) = 1.06f;
            } else
                *(char **)self = src + 0x2C;
            return 1;
        }
    }
    func_00137AA0(self);
    return 0;
}

class cVec { public:
    cVec() {}
    cVec &operator=(const cVec &o) { if (this != &o) { x = o.x; y = o.y; z = o.z; } return *this; }
    float x, y, z, w; };
class cCamera { public:
    virtual void vf0(); virtual void vf1();
    cVec calcRotation(const cVec &, const cVec &) const;
    char _p0[0x200-4+4]; cVec v200, v210, v220; char _p1[0x520-0x230]; int m520; };
typedef void (cCamera::*PM)();
struct D16 { long a, b; } __attribute__((packed));
extern int D_00747A78;
extern char D_0041D970[];
// FUNCTION: GAME 0x139C88
extern "C" void func_00139C88(cCamera *self) {
    if (D_00747A78 < 0) return;
    if (D_00747A78 & 0x800000) return;
    PM tbl[2];
    *(D16 *)tbl = *(D16 *)D_0041D970;
    (self->*tbl[self->m520])();
    self->v220 = self->calcRotation(self->v210, self->v200);
}
