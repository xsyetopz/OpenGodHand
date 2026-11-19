// Player-family helpers in 0x120000-0x130000.
#include "game/pl00Decls.h"

// FUNCTION: GAME 0x1268B0
extern "C" void func_001268B0(char *self, int v)
{
    unsigned i = 0;
    int k = 15;
    int *p = (int *)(self + 0x1644);
    for (; i < 5; i++, p++) {
        if (*p == 0) {
            *p = v;
            *(int *)(self + 0x1658) = k;
            return;
        }
    }
}

// DRAFT: GAME 0x12C4F0 - 3 words: tail uses bne+daddu vs original xor+movn v0,zero,v1; kept int r=1 nested-if return 0 form; tried early return r=0 (9), (m^B)?0:1 (8), if(m^B) r=0 with early return (9), nested if(m^B) r=0 (12), r declared before m (9), ||, ternaries, xor forms, == (8-14)
#ifdef NONMATCHING
extern "C" int func_0012C4F0(char *self)
{
    long m = *(long *)(self + 0x2F0) & 0xFFFF00000000L;
    int r = 1;
    if (m != 0x60100000000L)
        if (m != 0x50100000000L)
            return 0;
    return r;
}
#endif

// DRAFT: GAME 0x12BAF0 - 5 words: m reuses a0 (self-reuse, matches lbu a0); original shares one 'return 0' at 0x12BB14 for beqz/bltz, mine duplicates it; tried uchar a=m<4 (6), result var r (6), nested m<4/m>=0 (5), self-reuse a0 (5, kept)
#ifdef NONMATCHING
extern "C" int func_0012BAF0(char *self)
{
    if (*(unsigned *)(self + 0x15F4) & 0x400)
        return 1;
    if (*(unsigned char *)(self + 0x2F4))
        return 0;
    self = (char *)(unsigned)*(unsigned char *)(self + 0x2F5);
    int m = (int)self;
    if (m < 4) {
        if (m >= 0)
            return 1;
    }
    return 0;
}
#endif

extern char D_0041D540[];

// FUNCTION: GAME 0x12E5C8
extern "C" char *func_0012E5C8(char *p)
{
    *(char **)(p + 0x198) = D_0041D540;
    __asm__ volatile("sqc2 $vf0,0x30(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0x40(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0x50(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0x90(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0xA0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0xB0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0xC0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0xD0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0xE0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0xF0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0x100(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0x120(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0x130(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0x150(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 $vf0,0x160(%0)" : : "r"(p) : "memory");
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0x8) = 0;
    *(int *)(p + 0x14) = 0;
    *(int *)(p + 0xC) = 0;
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0x1C) = 0;
    *(int *)(p + 0x190) = 0;
    *(int *)(p + 0x194) = 0;
    return p;
}

// DRAFT: GAME 0x12C758 - 20 words: original tests m_unk698 with beql into the m_unk6A0 test and a shared epilogue at 0x12C7C0; mine emits bnez; tried && chain (20), int r=0 (27), || early return (20), early return on 0x608 (21), early return on m_unk698 with && call (20), nested m_unk6A0 early return (20), nested m_unk698/m_unk6A0 == 0 wrapping call (20, kept)
#ifdef NONMATCHING
extern "C" int func_0012C758(pl00 *self)
{
    if (D_00747A50 == 0x608) {
        if (self->m_unk698 == 0) {
            if (self->m_unk6A0 == 0) {
                if (func_002C2568(&g_SceAt, self->m_pos, 0) == 1) {
                    func_002DBE98();
                    return 1;
                }
            }
        }
    }
    return 0;
}
#endif

// DRAFT: GAME 0x12BAB8 - 5 words: m reuses a0 (self-reuse, matches lbu a0); original shares one 'return 0' at 0x12BAC4 for beqz/bltz, mine duplicates it; tried early-return pair (6), nested m<4/m>=0 (5, kept), flag-outer nesting (11), m>=4||m<0 (11), goto shared exit (11), m<4&&m>=0 (folds to sltiu)
#ifdef NONMATCHING
extern "C" int CkSubScreen__4pl00(char *self)
{
    if (*(unsigned char *)(self + 0x2F4))
        return 0;
    self = (char *)(unsigned)*(unsigned char *)(self + 0x2F5);
    int m = (int)self;
    if (m < 4) {
        if (m >= 0)
            return 1;
    }
    return 0;
}
#endif

// DRAFT: GAME 0x124FD8 - 23 words (76 vs 108): original keeps both range tests as unfolded slti pairs with andi 0xFF bool temps; gcc folds them to addiu+sltiu. tried unsigned char && temps (23), a=0 then if(v>=0x200) a=v<0x300 (24, movz), bitwise & of compares (23, kept)
#ifdef NONMATCHING
extern "C" int func_00124FD8(pl00 *self, cEm00 *em)
{
    int v = em->m_unk2FE;
    unsigned char a = (v >= 0x200) & (v < 0x300);
    if (!a)
        return 0;
    unsigned char b = (v >= 0x2A0) & (v < 0x300);
    if (b)
        return 0;
    return em->ckDown() != 0;
}
#endif

// DRAFT: GAME 0x123908 - 4 words: 0x20 frame, sq and s0 match; original does lui v0 / addiu s0,v0 before sd ra, compiled does lui s0 after addiu a1; tried asm "+r" (12), r-first decl with "r"(p) after call (4, kept), unsigned cast (4), char offset (4), "+r" read-write barrier (4), p-> vs CamManager. and memory clobber
#ifdef NONMATCHING
extern "C" int func_00123908()
{
    int r;
    cCamManager *p = &CamManager;
    r = p->isCk_CamClass(1);
    __asm__ volatile("" : : "r"(p));
    return r;
}
#endif
