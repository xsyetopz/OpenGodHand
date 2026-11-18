extern "C" int func_001FD908(void *);
extern "C" int func_001FC988(void *, int, int, int, int, int, void *);

// FUNCTION: GAME 0x1FD9D8
extern "C" int func_001FD9D8(char *self, int a1, int a2, int a3, int a4)
{
    if (self[0x49] == 0)
        return -1;
    char *vt = *(char **)(self + 0x50);
    char *o = ((char *(*)(char *))*(void **)(vt + 0x14))(self + *(short *)(vt + 0x10));
    if (!o)
        return -1;
    if (!func_001FD908(self))
        return -1;
    int r = func_001FC988(o, func_001FD908(self), a1, a2, a3, a4, self);
    if (r == -1)
        return -1;
    char *h = *(char **)(self + 0x3C);
    char *p;
    if (h) {
        p = h;
        if (*(char **)(p + 0x24)) {
            do {
                p = *(char **)(p + 0x24);
            } while (*(char **)(p + 0x24));
        }
        *(char **)(p + 0x24) = o;
        *(char **)(o + 0x20) = p;
    } else {
        *(char **)(self + 0x3C) = o;
    }
    return r;
}
