// Mid-size units in 0x1C0000-0x1E0000.
#include "game/cVec.h"

struct sFlag1D {
    char *m_obj;
    unsigned int m_flags;
};

// FUNCTION: GAME 0x1D0D90
extern "C" void func_001D0D90(sFlag1D *self, int a)
{
    long v = self->m_flags;
    if (((v >> 1) & 1) == 0)
        return;
    {
        if (((v >> 2) & 1) == 0) {
            if (a) {
                self->m_flags |= 4;
            } else {
                *(float *)(self->m_obj + 0x104) = 3.1415927f;
                *(int *)&self->m_flags &= -3;
            }
        }
    }
}

// FUNCTION: GAME 0x1D6EC8
extern "C" void func_001D6EC8(sFlag1D *self, int a)
{
    long v = self->m_flags;
    if (((v >> 3) & 1) == 0)
        return;
    {
        if (((v >> 4) & 1) == 0) {
            if (a) {
                self->m_flags |= 0x10;
            } else {
                *(float *)(self->m_obj + 0x104) = 3.1415927f;
                *(int *)&self->m_flags &= -9;
            }
        }
    }
}

// FUNCTION: GAME 0x1D48B0
extern "C" int func_001D48B0(char *self)
{
    if (*(unsigned short *)(self + 0x17FC) != 2)
        return 0;
    char *a = **(char ***)(self + 0x17D4);
    char *b = **(char ***)(self + 0x17D8);
    int x = *(int *)(a + 0x604);
    int y = *(int *)(b + 0x604);
    if ((x == 0 && (unsigned)(y - 9) < 4) || (y == 0 && (unsigned)(x - 9) < 4))
        return 1;
    return 0;
}

// FUNCTION: GAME 0x1D4918
extern "C" int func_001D4918(char *self)
{
    if (*(unsigned short *)(self + 0x17FE) != 2)
        return 0;
    char *a = **(char ***)(self + 0x17E8);
    char *b = **(char ***)(self + 0x17EC);
    int x = *(int *)(a + 0x604);
    int y = *(int *)(b + 0x604);
    if ((x == 0 && (unsigned)(y - 9) < 4) || (y == 0 && (unsigned)(x - 9) < 4))
        return 1;
    return 0;
}

// FUNCTION: GAME 0x1D0090
extern "C" void func_001D0090(char *self, int a)
{
    char *t = *(char **)(self + 0x600);
    if (t) {
        *(cVec *)(self + 0x490) = **(cVec **)(t + 0xF0);
    }
    *(float *)(self + 0x24C) = 1.0f;
    *(unsigned *)(self + 0x250) &= ~0x10u;
    *(int *)(self + 0x670) = a;
    *(char *)(self + 0x2F5) = 0xF;
    *(int *)(self + 0x600) = 0;
    *(int *)(self + 0x630) = 0;
    *(char *)(self + 0x2F4) = 0;
    *(char *)(self + 0x2F6) = 0;
    *(char *)(self + 0x2F7) = 0;
}

#ifdef NONMATCHING
class cOmThrow {
public:
    void SetFall();
};

// DRAFT: GAME 0x1C8CB8 - 7 words differ: original has sink sw in beqz delay slot after 0x644 store, ours puts 0x644 sw in delay and sink after join; sink-before, if/else, ternary variants tried
void cOmThrow::SetFall()
{
    char *self = (char *)this;
    volatile int sink;
    unsigned char b = *(unsigned char *)(self + 0x2B4);
    *(char *)(self + 0x2F5) = 2;
    *(float *)(self + 0x614) = 0.065f;
    *(char *)(self + 0x2F4) = 0;
    *(char *)(self + 0x2F6) = 0;
    *(char *)(self + 0x2F7) = 0;
    *(int *)(self + 0x610) = 0;
    *(int *)(self + 0x618) = 0;
    *(int *)(self + 0x644) = 0;
    char *w = b ? **(char ***)(self + 0x278) : 0;
    sink = b;
    if (w) {
        cVec *d = *(cVec **)(w + 0xD0);
        *d = *(cVec *)(self + 0x630);
        *(int *)(w + 0x100) = 0;
        *(int *)(w + 0x104) = 0;
        *(int *)(w + 0x108) = 0;
    }
}
#endif

extern char g_CollScr[];
extern "C" int func_001331B8(void *, long, int);

// FUNCTION: GAME 0x1CF340
extern "C" void func_001CF340(char *self)
{
    *(unsigned *)(self + 0x250) &= ~0x10u;
    *(float *)(self + 0x24C) = 1.0f;
    *(char *)(self + 0x2F5) = 2;
    *(int *)(self + 0x630) = 0;
    *(char *)(self + 0x2F4) = 0;
    *(char *)(self + 0x2F6) = 0;
    *(char *)(self + 0x2F7) = 0;
    func_001331B8(g_CollScr, *(long *)(self + 0x540), 0);
}
