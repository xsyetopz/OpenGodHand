// COMPILER: ee-gcc2.9-991111
float fRand1_1();
extern "C" float func_0031D108();

// FUNCTION: GAME 0x31D050
float frand(float a, float b)
{
    float h = (b - a) * 0.5f;
    return h * fRand1_1() + (a + h);
}

// FUNCTION: GAME 0x31D168
extern "C" float func_0031D168(float a, float b)
{
    float h = (b - a) * 0.5f;
    return h * func_0031D108() + (a + h);
}
