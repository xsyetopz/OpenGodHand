#ifndef COBJ_H
#define COBJ_H

#include "game/cVec.h"

struct cObjVEnt {
    short delta;
    short _pad;
    void *fn;
};

struct cVec16 {
    float x, y, z, w;
} __attribute__((aligned(16)));

inline void cObjCopyVec(cVec16 *dst, const cVec *src)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(dst), "r"(src) : "memory");
}

struct cObjParts {
    char _pad0[0x100];
    cVec m_v;
};

class cObj {
public:
    void R0_scenario();
    void Release();
    void setSuspend(bool b);

    cVec *vGetPos()
    {
        cObjVEnt *e = (cObjVEnt *)((char *)m_vt + 0x80);
        return ((cVec * (*)(void *)) e->fn)((char *)this + e->delta);
    }
    void vSetPos(const cVec &p)
    {
        cObjVEnt *e = (cObjVEnt *)((char *)m_vt + 0x70);
        ((void (*)(void *, const cVec &))e->fn)((char *)this + e->delta, p);
    }

    static bool inRange(int i, const int &lo, const int &hi)
    {
        bool r = 0;
        if (i >= lo) {
            bool t = i < hi;
            r = t;
        }
        return r;
    }
    cObjParts *getParts(int i)
    {
        if (inRange(i, 0, m_partsNum))
            return m_parts[i];
        return 0;
    }

    char _pad0[0x214];
    char *m_vt;
    char _pad218[0x250 - 0x218];
    unsigned int m_flags;
    char _pad254[0x278 - 0x254];
    cObjParts **m_parts;
    char _pad27C[0x2B4 - 0x27C];
    unsigned char m_partsNum;
    char _pad2B5[0x2F4 - 0x2B5];
    unsigned char m_act0;
    unsigned char m_act1;
    unsigned char m_act2;
    unsigned char m_act3;
};

#endif
