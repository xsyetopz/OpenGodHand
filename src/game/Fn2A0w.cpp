// FUNCTION: GAME 0x2A7280
extern "C" int func_002A7280(char *self)
{
    if (!*(int *)self)
        return 0;
    char *vt = *(char **)(self + 0x18);
    ((void (*)(char *, int))(*(void **)(vt + 0x1C)))(self + *(short *)(vt + 0x18), *(int *)self);
    *(int *)self = 0;
    return 1;
}

// FUNCTION: GAME 0x2AF348
extern "C" int func_002AF348(int n)
{
    int c = 1;
    int m = 10;
    if (n >= 10) {
        do {
            m *= 10;
            c++;
        } while (n >= m);
    }
    return c;
}
