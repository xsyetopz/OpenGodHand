// FUNCTION: GAME 0x2B3190
// DIVNOP: 2 0
extern "C" int func_002B3190(char *self)
{
    int n = *(int *)(self + 0x10) + 1;
    int sq = n * n;
    float x = (float)n / 6.0f;
    float y = (float)sq / 36.0f;
    float z = x + x - y;
    *(int *)(self + 0x10) = n;
    *(float *)(self + 0xA0) = y;
    *(float *)(self + 0x98) = z;
    *(float *)(self + 0x9C) = z;
    return n == 6;
}
