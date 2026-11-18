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

// DRAFT: GAME 0x12C4F0 - movn/xor shape differs: original loads 1 into v0 in the beq delay slot and ends with movn v0,zero,v1; mine emits sltiu or bne/movn into a0 (8-12 words)
#ifdef NONMATCHING
extern "C" int func_0012C4F0(char *self)
{
    long m = *(long *)(self + 0x2F0) & 0xFFFF00000000L;
    int r = 1;
    if (m != 0x60100000000L) {
        if (m != 0x50100000000L)
            r = 0;
    }
    return r;
}
#endif

// DRAFT: GAME 0x12BAF0 - 5 words: original range test is slti+beqz then bltz sharing one 'return 0'; mine duplicates return 0; tried uchar a=m<4 (6), result var r (6), nested m<4/m>=0 (5, kept)
#ifdef NONMATCHING
extern "C" int func_0012BAF0(char *self)
{
    if (*(unsigned *)(self + 0x15F4) & 0x400)
        return 1;
    if (*(unsigned char *)(self + 0x2F4))
        return 0;
    int m = *(unsigned char *)(self + 0x2F5);
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

// DRAFT: GAME 0x12C758 - 20 words: original tests m_unk698 with beql into the m_unk6A0 test and an explicit 'return 0' branch; mine emits bnez
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

// DRAFT: GAME 0x12BAB8 - 5 words: original range test is slti+beqz then bltz sharing one 'return 0'; tried early-return pair (6), nested m<4/m>=0 (5, kept), single-nest (11), m<4&&m>=0 (folds to sltiu)
#ifdef NONMATCHING
extern "C" int CkSubScreen__4pl00(char *self)
{
    if (*(unsigned char *)(self + 0x2F4))
        return 0;
    int m = *(unsigned char *)(self + 0x2F5);
    if (m < 4) {
        if (m >= 0)
            return 1;
    }
    return 0;
}
#endif

// DRAFT: GAME 0x124FD8 - original keeps both range tests as unfolded slti pairs with andi 0xFF bool temps; gcc folds them to addiu+sltiu
#ifdef NONMATCHING
extern "C" int func_00124FD8(pl00 *self, cEm00 *em)
{
    int v = em->m_unk2FE;
    bool a = v >= 0x200 && v < 0x300;
    if (!a)
        return 0;
    bool b = v >= 0x2A0 && v < 0x300;
    if (b)
        return 0;
    return em->ckDown() != 0;
}
#endif

// DRAFT: GAME 0x123908 - 11 words: original has a 0x20 frame with s0 = &CamManager and a call to isCk_CamClass; mine is a plain 0x10 frame
#ifdef NONMATCHING
extern "C" int func_00123908()
{
    return CamManager.isCk_CamClass(1);
}
#endif
