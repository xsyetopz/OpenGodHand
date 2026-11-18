extern "C" void sceVu0ApplyMatrix(float *, float *, float *);
extern "C" int SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, void *, void *, int, unsigned);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(char *, int, int, void *, int, int, int, int);
extern char Snd[];
static inline int InRange(const int &n, int i) { return i >= 0 && i < n; }
static inline char *SlotN(char *o, int i)
{
    if ((unsigned char)InRange(*(unsigned char *)(o + 0x2B4), i))
        return ((char **)*(char ***)(o + 0x278))[i];
    return 0;
}
struct V3 { float x, y, z; };
static inline void Cp(V3 *d, V3 *s) { d->x = s->x; d->y = s->y; d->z = s->z; }

// FUNCTION: GAME 0x1B1630
extern "C" void func_001B1630(char *self)
{
    char *par = *(char **)(self + 0x600);
    if (par) {
        char *s = SlotN(par, *(int *)(self + 0x604));
        V3 *src = (V3 *)(self + 0x610);
        V3 **dstp = (V3 **)(self + 0xF0);
        if (*dstp != src)
            Cp(*dstp, src);
        sceVu0ApplyMatrix((float *)*dstp, (float *)(s + 0x80), (float *)*dstp);
        par = *(char **)(self + 0x600);
        *(float *)(self + 0x24C) = *(float *)(par + 0x24C);
        if (*(unsigned *)(par + 0x250) & 0x10)
            *(unsigned *)(self + 0x250) |= 0x10;
        else
            *(unsigned *)(self + 0x250) &= ~0x10u;
        if (*(unsigned char *)(self + 0x667) == 0) {
            *(unsigned char *)(self + 0x667) = 1;
            SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0x58, 5, self, 0, 7, 0xFFFFFFFF);
            *(int *)(self + 0x668) = SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 0, 0x117, self, 0, 0, 0, 0);
        }
    }
}
