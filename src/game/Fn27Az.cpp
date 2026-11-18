#include "game/cVec.h"
extern "C" void func_001038E0(void *, void *, void *, float, float);
extern char D_003BFB48[], D_003BFB90[], D_003BFB60[], D_003BFB78[], D_003BFBA8[], D_003BFBF8[], D_003BFC48[], D_00585240[];
struct Q {
    char _p0[0x2130];
    int m2130; char *m2134; char *m2138; int m213C, m2140, m2144; char *m2148; char *m214C; int m2150, m2154;
    char *m2158; char *m215C; char *m2160; char *m2164; int m2168; float m216C, m2170; int m2174; float m2178, m217C, m2180; int m2184, m2188, m218C;
    cVec m2190; char _p1[0x2];
};
// FUNCTION: GAME 0x27A600
extern "C" void func_0027A600(Q *self)
{
    self->m2130 = 20;
    self->m2134 = D_003BFB48; self->m2138 = D_003BFB90;
    self->m213C = 0; self->m2140 = 0; self->m2144 = 0;
    self->m2148 = D_003BFB60; self->m214C = D_003BFB78;
    self->m2150 = 0; self->m2154 = 0;
    self->m2158 = D_003BFBA8; self->m215C = D_003BFBF8; self->m2160 = D_003BFC48; self->m2164 = D_00585240;
    self->m2168 = 0;
    self->m216C = 0.015f; self->m2170 = 0.8f; self->m2174 = 1;
    self->m2188 = 0; self->m2178 = 0; self->m217C = 0.5f; self->m2180 = 0.5f;
    self->m2184 = 0; self->m218C = 256;
    struct { cVec c; float w; } v;
    v.c.x = 0; v.c.y = 0; v.c.z = 0; v.w = 1.0f;
    self->m2190 = v.c;
    *(float *)((char *)self + 0x21A0) = 1.0471976f;
    func_001038E0(self, (char *)self + 0x2130, (char *)self + 0x5B0, 0.1f, 0);
}
