// FUNCTION: GAME 0x31AF70
extern "C" int func_0031AF70(int x)
{
    int a = ((x << 24) + (int)0x80000000) >> 24;
    int r;
    if (a < 0)
        r = a < -0x3F;
    else {
        int hi = 0x3F;
        r = hi < a;
    }
    return r == 0 ? 0 : a;
}
