#include "game/cVec.h"
#include "game/cObj.h"

struct cV4 : cVec {
    float w;
};

extern "C" {
void func_00150138(void *);
void func_001501D0(void *, unsigned);
void func_002AD2B8(void *, int, const void *, int, const void *, int, float);
}
extern const unsigned char D_00422A10[];
extern const char D_00422A20[];
extern const char D_00422A58[];

class cOl30 {
public:
    void SetInitialPosition(const cVec &pos, const cVec &rot);
    void calcNullPart() __asm__("calcNullPart__6cModel");

    char _pad0[0xF0];
    cVec *m_pos;
    char _padF4[0xC];
    cVec m_rot;
    char _pad10C[0x250 - 0x10C];
    unsigned int m_flags;
    char _pad254[0x278 - 0x254];
    cObjParts **m_parts;
    char _pad27C[0x2B4 - 0x27C];
    unsigned char m_partsNum;
    char _pad2B5[0xB10 - 0x2B5];
    int m_stride;
    char _padB14[0xC];
    char *m_arr;
};

#ifdef NONMATCHING
// 0x182FF8 near-miss: frame 0xB0 vs 0x100 (original keeps inRange temp on stack and has 9 saved regs), pad loops compile differently, 548 vs 584 bytes
// FUNCTION: GAME 0x182FF8
void cOl30::SetInitialPosition(const cVec &pos, const cVec &rot)
{
    *m_pos = pos;
    m_rot = rot;
    calcNullPart();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 7; j++) {
            int idx = D_00422A10[j] + i;
            cObjParts *p = 0;
            if (idx >= 0 && idx < m_partsNum)
                p = ((cObjParts **)m_parts)[idx];
            func_00150138(p);
            func_001501D0(p, m_flags);
            cV4 t;
            t.x = *(float *)((char *)p + 0xB0);
            t.y = *(float *)((char *)p + 0xB4);
            t.z = *(float *)((char *)p + 0xB8);
            t.w = 1.0f;
            *(cVec *)(m_arr + (m_stride * i + i + j) * 0x50) = t;
        }
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 7; j++) {
        }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 7; j++) {
        }
    func_002AD2B8(&m_stride, 14, D_00422A20, 14, D_00422A58, 7, 5.0f);
}
#endif
