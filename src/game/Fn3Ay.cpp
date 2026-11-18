// ProDG libc-adjacent game code in 0x3A53A8-0x3AF7B8 (errno-capturing syscall wrappers).
extern int D_0077DB88;
extern "C" long func_003B0450(int, int);
extern "C" long func_003B0390(int, int, int);
extern "C" long func_003B02E8(int, int, int);
extern "C" int func_003B0398(int);
extern "C" long func_003B0268(int, int, int);

// FUNCTION: GAME 0x3ADFA8
extern "C" long func_003ADFA8(int *self, int a1, int a2)
{
    D_0077DB88 = 0;
    long r = func_003B0450(a1, a2);
    if (r == -1 && D_0077DB88)
        *self = D_0077DB88;
    return r;
}

// FUNCTION: GAME 0x3AE008
extern "C" long func_003AE008(int *self, int a1, int a2, int a3)
{
    D_0077DB88 = 0;
    long r = func_003B0390(a1, a2, a3);
    if (r == -1 && D_0077DB88)
        *self = D_0077DB88;
    return r;
}

// FUNCTION: GAME 0x3AE068
extern "C" long func_003AE068(int *self, int a1, int a2, int a3)
{
    D_0077DB88 = 0;
    long r = func_003B02E8(a1, a2, a3);
    if (r == -1 && D_0077DB88)
        *self = D_0077DB88;
    return r;
}

// FUNCTION: GAME 0x3AE0C8
extern "C" int func_003AE0C8(int *self, int a1)
{
    D_0077DB88 = 0;
    unsigned r = func_003B0398(a1);
    if (r == -1 && D_0077DB88)
        *self = D_0077DB88;
    return r;
}

// FUNCTION: GAME 0x3AE128
extern "C" long func_003AE128(int *self, int a1, int a2, int a3)
{
    D_0077DB88 = 0;
    long r = func_003B0268(a1, a2, a3);
    if (r == -1 && D_0077DB88)
        *self = D_0077DB88;
    return r;
}
