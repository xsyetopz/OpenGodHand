// 0x1CFB28: clear damage-take link, restore position and reset model state.
struct Vec3 {
    float x, y, z;
};
struct IV {
    int x, y, z;
};
struct Mdl {
    char p0[0xD0];
    IV *d;
    char p1[0x2C];
    int a, b, c;
    char p2[0x38];
    char *owner;
};
struct W {
    int f, g, h, i;
};
extern "C" void calcParts__6cModel(void *, void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x1CFB28
extern "C" void func_001CFB28(char *self, Vec3 *pos, int arg)
{
    char *dt = *(char **)(self + 0x600);
    if (dt) {
        Vec3 *src = *(Vec3 **)(dt + 0xF0);
        Vec3 *dst = (Vec3 *)(self + 0x490);
        if (dst != src) {
            dst->x = src->x;
            dst->y = src->y;
            dst->z = src->z;
        }
    }
    *(float *)(self + 0x24C) = 1.0f;
    *(unsigned *)(self + 0x250) = *(unsigned *)(self + 0x250) & 0xFFFFFFEF;
    *(int *)(self + 0x600) = 0;
    *(int *)(self + 0x630) = 0;
    W w;
    w.f = *(unsigned char *)(self + 0x2B4);
    Mdl *m = w.f ? **(Mdl ***)(self + 0x278) : 0;
    if (m) {
        m->owner = self;
        m->a = 0;
        m->b = 0;
        m->c = 0;
        m->d->x = 0;
        m->d->y = 0;
        m->d->z = 0;
        calcParts__6cModel(self, m);
        Vec3 *d2 = (Vec3 *)(self + 0x640);
        if (d2 != pos) {
            d2->x = pos->x;
            d2->y = pos->y;
            d2->z = pos->z;
        }
        *(int *)(self + 0x670) = arg;
        *(unsigned char *)(self + 0x2F5) = 4;
        *(unsigned char *)(self + 0x2F4) = 0;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
}
#endif
