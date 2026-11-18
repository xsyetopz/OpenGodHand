// Second half of ConstRef (split to keep files under 300 lines).
// Const-ref temporaries reproduce the lbu/sw-to-stack then register-branch pattern.
static inline int IsSet(const int &v) { return v != 0; }
static inline int Lt(const int &v, int n) { return n < v; }
static inline char *Slot0(char *o)
{
    if (IsSet(*(unsigned char *)(o + 0x2B4)))
        return **(char ***)(o + 0x278);
    return 0;
}
static inline int InRange(const int &n, int i) { return i >= 0 && i < n; }
static inline char *SlotN(char *o, int i)
{
    if ((unsigned char)InRange(*(unsigned char *)(o + 0x2B4), i))
        return ((char **)*(char ***)(o + 0x278))[i];
    return 0;
}


struct V3 {
    float x, y, z;
    void set(const V3 &o)
    {
        if (this != &o) {
            x = o.x;
            y = o.y;
            z = o.z;
        }
    }
};

// FUNCTION: GAME 0x282F40
extern "C" void func_00282F40(char *self, char *par, int idx, V3 *a, V3 *b)
{
    char *c = SlotN(par, idx);
    if (c) {
        char *o = Slot0(self);
        if (o) {
            V3 *d0 = *(V3 **)(o + 0xD0);
            *(char **)(o + 0x148) = c;
            *(int *)(o + 0x100) = 0;
            *(int *)(o + 0x104) = 0;
            *(int *)(o + 0x108) = 0;
            d0->set(*a);
            ((V3 *)(o + 0x100))->set(*b);
            *(int *)(self + 0x1584) = idx;
            *(char **)(self + 0x1580) = par;
            ((V3 *)(self + 0x1590))->set(*a);
            ((V3 *)(self + 0x15A0))->set(*b);
            ((V3 *)(self + 0x110))->set(*(V3 *)(par + 0x110));
        }
    }
}

extern V3 V0001;
extern "C" int setupModel__6cModelPC10SCR_HEADERUibT3(char *, char *, unsigned, int, int);
extern "C" void calcParts__6cModel(char *);
extern "C" void func_00276C88(char *);

// FUNCTION: GAME 0x276808
extern "C" int func_00276808(char *self)
{
    int ok = 0;
    char *h = *(char **)(self + 0x304);
    if (setupModel__6cModelPC10SCR_HEADERUibT3(self, (char *)(*(int *)(h + 4) + (int)h), *(int *)(h + 8) + (int)h, 0, 0)) {
        *(unsigned *)(self + 0x2F0) |= 0x40;
        *(char *)(self + 0x531) = -1;
        ok = 1;
        *(unsigned *)(self + 0x250) |= 0x10000;
        *(int *)(self + 0x21B0) = 0;
        if (Slot0(self)) {
            char *o = Slot0(self);
            V3 *d = (V3 *)(o + 0xE0);
            d->x = V0001.x;
            d->y = V0001.y;
            d->z = V0001.z;
            V3 *e = *(V3 **)(Slot0(self) + 0xD0);
            e->x = V0001.x;
            e->y = V0001.y;
            e->z = V0001.z;
        }
        calcParts__6cModel(self);
        func_00276C88(self);
    }
    return ok;
}

extern "C" void func_0027A600(char *);
// FUNCTION: GAME 0x27A180
extern "C" int func_0027A180(char *self)
{
    int ok = 0;
    char *h = *(char **)(self + 0x304);
    if (setupModel__6cModelPC10SCR_HEADERUibT3(self, (char *)(*(int *)(h + 4) + (int)h), *(int *)(h + 8) + (int)h, 0, 0)) {
        *(unsigned *)(self + 0x2F0) |= 0x40;
        *(char *)(self + 0x531) = -1;
        ok = 1;
        *(unsigned *)(self + 0x250) |= 0x10000;
        *(int *)(self + 0x21B0) = 0;
        if (Slot0(self)) {
            char *o = Slot0(self);
            V3 *d = (V3 *)(o + 0xE0);
            d->x = V0001.x;
            d->y = V0001.y;
            d->z = V0001.z;
            V3 *e = *(V3 **)(Slot0(self) + 0xD0);
            e->x = V0001.x;
            e->y = V0001.y;
            e->z = V0001.z;
        }
        calcParts__6cModel(self);
        func_0027A600(self);
    }
    return ok;
}

extern "C" void func_0027B0F8(char *);
// FUNCTION: GAME 0x27AC70
extern "C" int func_0027AC70(char *self)
{
    int ok = 0;
    char *h = *(char **)(self + 0x304);
    if (setupModel__6cModelPC10SCR_HEADERUibT3(self, (char *)(*(int *)(h + 4) + (int)h), *(int *)(h + 8) + (int)h, 0, 0)) {
        *(unsigned *)(self + 0x2F0) |= 0x40;
        *(char *)(self + 0x531) = -1;
        ok = 1;
        *(unsigned *)(self + 0x250) |= 0x10000;
        *(int *)(self + 0x21B0) = 0;
        if (Slot0(self)) {
            char *o = Slot0(self);
            V3 *d = (V3 *)(o + 0xE0);
            d->x = V0001.x;
            d->y = V0001.y;
            d->z = V0001.z;
            V3 *e = *(V3 **)(Slot0(self) + 0xD0);
            e->x = V0001.x;
            e->y = V0001.y;
            e->z = V0001.z;
        }
        calcParts__6cModel(self);
        func_0027B0F8(self);
    }
    return ok;
}

extern "C" void func_00283968(char *);
// FUNCTION: GAME 0x2834E8
extern "C" int func_002834E8(char *self)
{
    int ok = 0;
    char *h = *(char **)(self + 0x304);
    if (setupModel__6cModelPC10SCR_HEADERUibT3(self, (char *)(*(int *)(h + 4) + (int)h), *(int *)(h + 8) + (int)h, 0, 0)) {
        *(unsigned *)(self + 0x2F0) |= 0x40;
        *(char *)(self + 0x531) = -1;
        ok = 1;
        *(unsigned *)(self + 0x250) |= 0x10000;
        *(int *)(self + 0x21B0) = 0;
        if (Slot0(self)) {
            char *o = Slot0(self);
            V3 *d = (V3 *)(o + 0xE0);
            d->x = V0001.x;
            d->y = V0001.y;
            d->z = V0001.z;
            V3 *e = *(V3 **)(Slot0(self) + 0xD0);
            e->x = V0001.x;
            e->y = V0001.y;
            e->z = V0001.z;
        }
        calcParts__6cModel(self);
        func_00283968(self);
    }
    return ok;
}

extern "C" void func_00284350(char *);
// FUNCTION: GAME 0x283EC8
extern "C" int func_00283EC8(char *self)
{
    int ok = 0;
    char *h = *(char **)(self + 0x304);
    if (setupModel__6cModelPC10SCR_HEADERUibT3(self, (char *)(*(int *)(h + 4) + (int)h), *(int *)(h + 8) + (int)h, 0, 0)) {
        *(unsigned *)(self + 0x2F0) |= 0x40;
        *(char *)(self + 0x531) = -1;
        ok = 1;
        *(unsigned *)(self + 0x250) |= 0x10000;
        *(int *)(self + 0x21B0) = 0;
        if (Slot0(self)) {
            char *o = Slot0(self);
            V3 *d = (V3 *)(o + 0xE0);
            d->x = V0001.x;
            d->y = V0001.y;
            d->z = V0001.z;
            V3 *e = *(V3 **)(Slot0(self) + 0xD0);
            e->x = V0001.x;
            e->y = V0001.y;
            e->z = V0001.z;
        }
        calcParts__6cModel(self);
        func_00284350(self);
    }
    return ok;
}
