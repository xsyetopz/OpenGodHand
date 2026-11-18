extern "C" void sceVu0ApplyMatrix(float *, float *, float *);
static inline int InRange(const int &n, int i) { return i >= 0 && i < n; }
static inline char *SlotN(char *o, int i)
{
    if ((unsigned char)InRange(*(unsigned char *)(o + 0x2B4), i))
        return ((char **)*(char ***)(o + 0x278))[i];
    return 0;
}
struct V3 { float x, y, z; };
static inline void Cp(V3 *d, V3 *s) { d->x = s->x; d->y = s->y; d->z = s->z; }

// FUNCTION: GAME 0x279B20
extern "C" void func_00279B20(char *self)
{
    char *par = *(char **)(self + 0x1580);
    if (par) {
        char *s = SlotN(par, *(int *)(self + 0x1584));
        if (s) {
            V3 *src = (V3 *)(self + 0x1590);
            V3 **dstp = (V3 **)(self + 0xF0);
            if (*dstp != src)
                Cp(*dstp, src);
            sceVu0ApplyMatrix((float *)*dstp, (float *)(s + 0x80), (float *)*dstp);
            char *q = *(char **)(self + 0x1580);
            V3 *e = (V3 *)(q + 0x100);
            V3 *d = (V3 *)(self + 0x100);
            if (d != e)
                Cp(d, e);
            par = *(char **)(self + 0x1580);
            *(float *)(self + 0x24C) = *(float *)(par + 0x24C);
            if (*(unsigned *)(par + 0x250) & 0x10)
                *(unsigned *)(self + 0x250) |= 0x10;
            else
                *(unsigned *)(self + 0x250) &= ~0x10u;
        }
    }
}

// FUNCTION: GAME 0x279FF0
extern "C" void func_00279FF0(char *self)
{
    char *par = *(char **)(self + 0x1580);
    if (par) {
        char *s = SlotN(par, *(int *)(self + 0x1584));
        if (s) {
            V3 *src = (V3 *)(self + 0x1590);
            V3 **dstp = (V3 **)(self + 0xF0);
            if (*dstp != src)
                Cp(*dstp, src);
            sceVu0ApplyMatrix((float *)*dstp, (float *)(s + 0x80), (float *)*dstp);
            char *q = *(char **)(self + 0x1580);
            V3 *e = (V3 *)(q + 0x100);
            V3 *d = (V3 *)(self + 0x100);
            if (d != e)
                Cp(d, e);
            par = *(char **)(self + 0x1580);
            *(float *)(self + 0x24C) = *(float *)(par + 0x24C);
            if (*(unsigned *)(par + 0x250) & 0x10)
                *(unsigned *)(self + 0x250) |= 0x10;
            else
                *(unsigned *)(self + 0x250) &= ~0x10u;
        }
    }
}

// FUNCTION: GAME 0x27D300
extern "C" void func_0027D300(char *self)
{
    char *par = *(char **)(self + 0x1580);
    if (par) {
        char *s = SlotN(par, *(int *)(self + 0x1584));
        if (s) {
            V3 *src = (V3 *)(self + 0x1590);
            V3 **dstp = (V3 **)(self + 0xF0);
            if (*dstp != src)
                Cp(*dstp, src);
            sceVu0ApplyMatrix((float *)*dstp, (float *)(s + 0x80), (float *)*dstp);
            char *q = *(char **)(self + 0x1580);
            V3 *e = (V3 *)(q + 0x100);
            V3 *d = (V3 *)(self + 0x100);
            if (d != e)
                Cp(d, e);
            par = *(char **)(self + 0x1580);
            *(float *)(self + 0x24C) = *(float *)(par + 0x24C);
            if (*(unsigned *)(par + 0x250) & 0x10)
                *(unsigned *)(self + 0x250) |= 0x10;
            else
                *(unsigned *)(self + 0x250) &= ~0x10u;
        }
    }
}

// FUNCTION: GAME 0x27E950
extern "C" void func_0027E950(char *self)
{
    char *par = *(char **)(self + 0x1580);
    if (par) {
        char *s = SlotN(par, *(int *)(self + 0x1584));
        if (s) {
            V3 *src = (V3 *)(self + 0x1590);
            V3 **dstp = (V3 **)(self + 0xF0);
            if (*dstp != src)
                Cp(*dstp, src);
            sceVu0ApplyMatrix((float *)*dstp, (float *)(s + 0x80), (float *)*dstp);
            char *q = *(char **)(self + 0x1580);
            V3 *e = (V3 *)(q + 0x100);
            V3 *d = (V3 *)(self + 0x100);
            if (d != e)
                Cp(d, e);
            par = *(char **)(self + 0x1580);
            *(float *)(self + 0x24C) = *(float *)(par + 0x24C);
            if (*(unsigned *)(par + 0x250) & 0x10)
                *(unsigned *)(self + 0x250) |= 0x10;
            else
                *(unsigned *)(self + 0x250) &= ~0x10u;
        }
    }
}

// FUNCTION: GAME 0x280DB8
extern "C" void func_00280DB8(char *self)
{
    char *par = *(char **)(self + 0x1580);
    if (par) {
        char *s = SlotN(par, *(int *)(self + 0x1584));
        if (s) {
            V3 *src = (V3 *)(self + 0x1590);
            V3 **dstp = (V3 **)(self + 0xF0);
            if (*dstp != src)
                Cp(*dstp, src);
            sceVu0ApplyMatrix((float *)*dstp, (float *)(s + 0x80), (float *)*dstp);
            char *q = *(char **)(self + 0x1580);
            V3 *e = (V3 *)(q + 0x100);
            V3 *d = (V3 *)(self + 0x100);
            if (d != e)
                Cp(d, e);
            par = *(char **)(self + 0x1580);
            *(float *)(self + 0x24C) = *(float *)(par + 0x24C);
            if (*(unsigned *)(par + 0x250) & 0x10)
                *(unsigned *)(self + 0x250) |= 0x10;
            else
                *(unsigned *)(self + 0x250) &= ~0x10u;
        }
    }
}

// FUNCTION: GAME 0x283070
extern "C" void func_00283070(char *self)
{
    char *par = *(char **)(self + 0x1580);
    if (par) {
        char *s = SlotN(par, *(int *)(self + 0x1584));
        if (s) {
            V3 *src = (V3 *)(self + 0x1590);
            V3 **dstp = (V3 **)(self + 0xF0);
            if (*dstp != src)
                Cp(*dstp, src);
            sceVu0ApplyMatrix((float *)*dstp, (float *)(s + 0x80), (float *)*dstp);
            char *q = *(char **)(self + 0x1580);
            V3 *e = (V3 *)(q + 0x100);
            V3 *d = (V3 *)(self + 0x100);
            if (d != e)
                Cp(d, e);
            par = *(char **)(self + 0x1580);
            *(float *)(self + 0x24C) = *(float *)(par + 0x24C);
            if (*(unsigned *)(par + 0x250) & 0x10)
                *(unsigned *)(self + 0x250) |= 0x10;
            else
                *(unsigned *)(self + 0x250) &= ~0x10u;
        }
    }
}
