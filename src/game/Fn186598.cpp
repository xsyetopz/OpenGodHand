extern "C" float func_0031CF30(void);
extern "C" int irand__Fv(void);
struct W { char _p[0xE10]; float m_E10, m_E14, m_E18, m_E1C; };

// FUNCTION: GAME 0x186598
// DIVNOP: 2
extern "C" void func_00186598(W *self, float x)
{
    float k = 20.0f;
    if (k < x)
        x = k;
    if (x < 5.0f)
        x = 5.0f;
    float r = x / k;
    self->m_E10 = r * 0.09f;
    float a = func_0031CF30();
    r *= 0.03490658476948738f;
    self->m_E14 = r * a;
    float b = func_0031CF30();
    self->m_E18 = r * b;
    if (irand__Fv() & 1)
        self->m_E1C = 0.0f;
    else
        self->m_E1C = 3.1415927410125732f;
}
