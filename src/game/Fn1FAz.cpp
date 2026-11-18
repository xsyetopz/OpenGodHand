extern int D_003BF160[5];
extern "C" int getGameLevel__9cCoreSave(void *);
struct W { char _p[0x1C]; short m_1C; };

// FUNCTION: GAME 0x1FA080
// DIVNOP: 2
extern "C" float func_001FA080(W **self)
{
    if (!*self)
        return 0.0f;
    int i = getGameLevel__9cCoreSave(self) - 1;
    int hi = D_003BF160[i];
    int lo;
    if (i <= 0)
        lo = 0;
    else
        lo = D_003BF160[i - 1];
    float d = (float)(hi - lo);
    int n = (*self)->m_1C - lo;
    if (d <= 0.0f)
        d = 1000.0f;
    return (float)n / d;
}
