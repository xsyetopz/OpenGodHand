#include "cVec.h"

struct Vq {
    float x, y, z, w;
    Vq(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};
extern char g_DmgManage[];
extern char Snd[];
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, char *, int);
extern "C" int func_001FD9D8(char *, char *, const Vq &, const Vq &, const Vq &);
extern "C" void setObjCollision__7cOmDoor(char *);
extern "C" int func_001BBF68(char *);
extern "C" void initMove1_pos__6cOmSubP4cObjiUiRC4cVecff(char *, char *, int, unsigned int, const Vq &, float, float);
extern "C" void initMove3_y__6cOmSubP4cObjiRC4cVecfff(char *, char *, int, const Vq &, float, float, float);
extern "C" int move__6cOmSub(char *);
extern "C" void SeCall__4cSnd6eSeBlksssUii(char *, int, int, int, int, int, int);
extern "C" void func_001F29C0(char *, int, int);
extern "C" void SetColorAnimNormal__12CustomIDWorkG3COLT1Us(char *, int, int, unsigned short);
extern "C" void SetColorAnimSin__12CustomIDWorkG3COLT1Us(char *, int, int, unsigned short);

#ifdef NONMATCHING
// DRAFT: GAME 0x0019D3F0 16 differing words: stack-vector store order, $s1/$s2 swap, constant reg assignment; variants: cVec copy, sh order, sb/sw order, decl swap, V4 pointer pattern (45), c.x assignment (24), c before b with d at top (76), b = a copy (66), b before a (22), folded c.x to -0.75f (60).
extern "C" int func_0019D3F0(char *self)
{
    func_001B6FB8(self);
    Vq a(1.5f, 3.1f, 0.2f, 1.0f);
    Vq b(1.5f, 3.1f, 0.2f, 1.0f);
    Vq c(-a.x * 0.5f, 0.0f, 0.0f, 1.0f);
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        Vq d(0.0f, 0.0f, 0.0f, 1.0f);
        func_001FD9D8((char *)t, self + 0x80, c, d, b);
    }
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    *(cVec *)(self + 0x610) = *(cVec *)&a;
    setObjCollision__7cOmDoor(self);
    *(char **)(self + 0x628) = self + 0x650;
    *(char *)(self + 0x624) = 7;
    func_001BBF68(self);
    return 1;
}

// DRAFT: GAME 0x001BD780 8 differing words: constant 1 register ($v1 original, $v0 compiled); hoisted constant temp no gain; block-1 orders ABCD/BACD/BADC/ABDC 8, DABC 10; int one hoisted into block-1 stores 75; (int) switch cast 8.
extern "C" void func_001BD780(char *self)
{
    switch (*(unsigned char *)(self + 0x2F5)) {
    case 0:
        if (*(unsigned char *)(self + 0x774) == 1) return;
        if (*(int *)(self + 0x778) == 0) {
            Vq v(0.0f, *(float *)(self + 0x770), 0.0f, 1.0f);
            initMove1_pos__6cOmSubP4cObjiUiRC4cVecff(self + 0x610, self, -1, 0x1E, v, 0.2f, 0.2f);
        } else {
            Vq v(0.0f, 0.0f, 0.0f, 1.0f);
            initMove3_y__6cOmSubP4cObjiRC4cVecfff(self + 0x610, self, -1, v, -0.02f, -*(float *)(self + 0x770), 0.0f);
        }
        SeCall__4cSnd6eSeBlksssUii(Snd, 2, 0xBA, -1, -1, 0, 0);
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F5) = 1;
        *(unsigned char *)(self + 0x775) = 1;
        *(unsigned char *)(self + 0x2F7) = 0;
        /* fallthrough */
    case 1:
        if (move__6cOmSub(self + 0x610) == 0) {
            *(unsigned char *)(self + 0x2F7) = 0;
            *(unsigned char *)(self + 0x774) = 1;
            *(unsigned char *)(self + 0x775) = 0;
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
        }
        return;
    }
}

// DRAFT: GAME 0x001F3118 67 differing words: bit-test branch form (original beqz with addiu in delay slot, compiled beql); variants: if/else-if 74, bit-type 74, guard-return switch 77, nested-if switch 67 (kept).
extern "C" void func_001F3118(char *self, int c1, int c2, int unused, int c3)
{
    if (((long)*(unsigned int *)self >> 1) & 1) {
        switch (*(int *)(self + 0x920)) {
        case 0:
            SetColorAnimNormal__12CustomIDWorkG3COLT1Us(self + 0x158, 0,
                (((((c1 & ~0xFF) | 0x73) & 0xFFFF00FF) | 0x7300) & 0x7373) | 0x730000 | 0x80000000, 0xF);
            func_001F29C0(self, 2, 1);
            *(int *)(self + 0x924) = 0xF;
            *(int *)(self + 0x920) = *(int *)(self + 0x920) + 1;
            return;
        case 1: {
            int t = *(int *)(self + 0x924);
            if (t == 0) {
                SetColorAnimSin__12CustomIDWorkG3COLT1Us(self + 0x158,
                    (((((((c3 & ~0xFF) | 0x73) & 0xFFFF00FF) | 0x7300) & 0xFF00FFFF) | 0x730000) & 0xFFFFFF) | 0x80000000,
                    (((((((c2 & ~0xFF) | 0xA8) & 0xFFFF00FF) | 0xA800) & 0xFF00FFFF) | 0xA80000) & 0xFFFFFF) | 0x80000000,
                    3);
                *(int *)(self + 0x920) = *(int *)(self + 0x920) + 1;
            } else {
                *(int *)(self + 0x924) = t - 1;
            }
            return;
        }
        }
    }
}
#endif
