#include "game/cSnd.h"

extern "C" {
void func_003735E0(void *, int, float, float);
}

extern "C" {

// FUNCTION: GAME 0x2CABE0
void func_002CABE0()
{
}

// FUNCTION: GAME 0x2CB200
void func_002CB200()
{
}

// FUNCTION: GAME 0x2CB070
void func_002CB070(int *p)
{
    p[9] = 0;
    p[8] = 0;
    p[10] = 0;
}

// FUNCTION: GAME 0x2CC568
int func_002CC568(sBgmNode *n)
{
    return n->m_b != 0;
}

// FUNCTION: GAME 0x2CFC78
int func_002CFC78(int *p)
{
    return p[0] == 0;
}

// FUNCTION: GAME 0x2CFF78
int func_002CFF78(cBgmData *p)
{
    return ((int *)p)[1] == 0;
}

// FUNCTION: GAME 0x2CFF68
int func_002CFF68(cBgmData *p)
{
    return ((int *)p)[1] == 0xF;
}

// FUNCTION: GAME 0x2CFC88
int func_002CFC88(cSeData *p)
{
    return ((int *)p)[0] == 3;
}

// FUNCTION: GAME 0x2D0770
int func_002D0770(int *p)
{
    return p[0x50 / 4];
}

// FUNCTION: GAME 0x2D0748
void func_002D0748(int *p, int m)
{
    p[0x50 / 4] |= m;
}

// FUNCTION: GAME 0x2D0758
void func_002D0758(int *p, int m)
{
    p[0x50 / 4] &= ~m;
}

// FUNCTION: GAME 0x2D3200
void *func_002D3200(void *p)
{
    return p;
}

// FUNCTION: GAME 0x2D5070
void *func_002D5070(void *p)
{
    return p;
}

// FUNCTION: GAME 0x2D3210
int func_002D3210(int *p)
{
    return p[0] & 1;
}

// FUNCTION: GAME 0x2D5788
void func_002D5788(int *p, int v)
{
    p[2] = v;
}

// FUNCTION: GAME 0x2CD4E0
void func_002CD4E0(void *p, float a, float b)
{
    func_003735E0(p, -1, a, b);
}

}
