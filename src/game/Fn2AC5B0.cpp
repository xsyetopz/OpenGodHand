extern "C" float ESHermite__5ESLibfffff(float, float, float, float, float);
struct HK { short _0, _2, m4, m6, y8, _a; };

// FUNCTION: GAME 0x2AC5B0
// DIVNOP: 2
extern "C" float func_002AC5B0(int, short x, int i, char *tab)
{
    HK *e = (HK *)(tab + i * 12);
    HK *n = e + 1;
    float t = (float)(x - e->y8) / (float)(n->y8 - e->y8);
    return ESHermite__5ESLibfffff(t, 0.0f, 1.0f, (float)e->m6 * 0.000244140625f, (float)n->m4 * 0.000244140625f);
}
