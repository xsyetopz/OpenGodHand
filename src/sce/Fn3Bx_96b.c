// COMPILER: ee-gcc2.96
// Error-hook helpers near 0x3B9D30 compile with ee-gcc 2.96 (dead sd/ld ra around a tail jump).

extern void func_003BA088();
extern void func_003BA058();
extern void func_0033F130(int);
extern void func_0033B658(void);
extern void func_0033B670(void);
extern void (*D_003FC7AC)(int, int);
extern int D_003FC7B0;
extern int D_003FC50C;
extern int D_003FC7A8;
extern char D_003FC7B8[];
extern char D_00460900[];
extern char D_00460928[];

extern void *memset(void *, int, unsigned);
extern void func_003B9DE0(const char *);

extern void *memset(void *, int, unsigned);
extern void func_003B9DE0(const char *);
extern void func_003B9FB8();
extern void func_003B9FD0();
extern void func_003BA058();
extern void func_003BA8C0();
extern void func_003BA900();
extern void func_003B9E10();
extern void func_003B9D98();
extern void func_003B9D48();
extern void func_003B9D30();
extern char D_00460818[];
extern char D_00460840[];
extern char D_004608B0[];
extern char D_00460888[];
extern void (*D_003D141C)();
extern void (*D_003E9D20)();
extern void (*D_003D1420)();
extern void (*D_003E9D18)();
extern void (*D_003E9D1C)();
extern void func_003B9B20();
extern void func_003B9BF0();
extern void func_003B9BB8();
extern void func_003B9CE8();
extern void func_00329EA8();
extern void func_003B9AF8();
extern void func_00326220();
extern void func_00326238();
extern void func_00325C60();
extern void func_0033F1A8();
extern void func_00325C78();
extern void func_00326250();
extern void func_003B9E60();
extern int func_003BA800();
extern void func_003BA000();
extern void func_003BA0C8();
extern void func_003BA830();
extern int *func_003B9F60(void);
extern int *func_003B9EB0();


extern void func_003B9FB8();
extern void func_003BA878();
extern void func_003BA8C0();
extern int func_003B63A0();
extern void func_003B63F0();
extern char D_004608D8[];
extern char D_00460AD0[];
extern char D_00460AF8[];
extern char D_00460B20[];
extern char D_00460B48[];
extern char D_00460B70[];


// FUNCTION: GAME 0x3B9CE8
void func_003B9CE8(int a, int b)
{
    int x;
    func_003BA878(a, 0, &x);
    func_003BA8C0(a, b, x);
}

// FUNCTION: GAME 0x3B9E60
void func_003B9E60(void)
{
    int *c = &D_003FC7A8;
    if (*c == 1)
        memset(D_003FC7B8, 0, 0x3C);
    *c = *c - 1;
}

// FUNCTION: GAME 0x3BA000
void func_003BA000(int *p)
{
    if (!p) {
        func_003B9DE0(D_004608D8);
        return;
    }
    ((void (*)())func_003BA058)();
    func_003B9FB8(p);
    p[1] = 1;
}

// FUNCTION: GAME 0x3BA830
void func_003BA830(int *a, int *b, int *c)
{
    if (!a) {
        func_003B9DE0(D_00460AD0);
        return;
    }
    if (b)
        *b = a[7];
    if (c)
        *c = a[8];
}

// FUNCTION: GAME 0x3BA878
void func_003BA878(int *a, int *b, int *c)
{
    if (!a) {
        func_003B9DE0(D_00460AF8);
        return;
    }
    if (b)
        *b = a[4];
    if (c)
        *c = a[5];
}

// FUNCTION: GAME 0x3BA8C0
void func_003BA8C0(int *a, int b, int c)
{
    if (!a || !b || !c) {
        func_003B9DE0(D_00460B20);
        return;
    }
    a[4] = b;
    a[5] = c;
}

// FUNCTION: GAME 0x3BA900
void func_003BA900(int *a, int b)
{
    if (!a) {
        func_003B9DE0(D_00460B48);
        return;
    }
    if (b <= 0) {
        func_003B9DE0(D_00460B70);
        return;
    }
    a[6] = 144000 / (b * 1536) + 1;
}

// 0x3B9F60 near-miss: original is a do-while over D_003FC7B8 (stride 0x3C) with two induction pointers and loop padding; ours folds the one-element loop (24 vs 84 bytes)

extern void *memcpy(void *, const void *, unsigned);
extern char D_00460A70[];
extern char D_00460A38[];

struct IoBuf {
    void *p;
    int n;
};
struct IoVt {
    char pad[0x18];
    int (*rd)();
    int (*unk)();
    int (*wr)();
};
struct IoDev {
    struct IoVt *vt;
};
struct IoObj {
    char pad0[8];
    char *buf;
    int cap;
    int pad1;
    struct IoDev *dev;
};

// 0x3BA708 near-miss: second rd() call loads the device into v0 plus a0 copy and a nop delay slot; original keeps it in t0 with a0 copied in the jalr delay slot (rest matches)
#ifdef NONMATCHING
// DRAFT: GAME 0x3BA708
int func_003BA708(struct IoObj *o)
{
    struct IoBuf b;
    int left = 0x1800;
    int done;
    struct IoDev *d;
    o->dev->vt->rd(o->dev, 0, 0x1800, &b);
    memcpy(b.p, o->buf, b.n);
    done = b.n;
    left -= done;
    o->dev->vt->wr(o->dev, 1, &b);
    if (left > 0) {
        d = o->dev;
        d->vt->rd(d, 0, left, &b);
        memcpy(b.p, o->buf + done, b.n);
        o->dev->vt->wr(o->dev, 1, &b, b.n);
        left -= b.n;
    }
    if (left) {
        func_003B9DE0(D_00460A70);
        return -1;
    }
    return 0;
}
#endif

#ifdef NONMATCHING
extern char D_00460978[];
extern char D_004609A8[];
extern char D_004609D8[];
extern int D_003FC518[];
extern int D_003FC528[];
extern int D_003FC5C8[][40];

// DRAFT: GAME 0x3BA3D8
// 1 word differs at +0xFC: lui v1 vs lw v1 (table base hoist); matched only with a preceding live 0x3BA708
int func_003BA3D8(int *o, unsigned char *p)
{
    unsigned c, i;
    int skip;
    if (p[0] == 0xB && p[1] == 0x77) {
        o[10] = 1;
        skip = 4;
    } else if (p[0] == 0x77 && p[1] == 0xB) {
        o[10] = 2;
        skip = 5;
    } else {
        func_003B9DE0(D_00460978);
        return -1;
    }
    p += skip;
    c = *p >> 6;
    if (c >= 3) {
        func_003B9DE0(D_004609A8);
        return -1;
    }
    o[11] = D_003FC518[c];
    i = *p & 0x3F;
    if (i >= 0x26) {
        func_003B9DE0(D_004609D8);
        return -1;
    }
    o[12] = D_003FC528[i];
    o[13] = D_003FC5C8[c][i] << 1;
    return 0;
}
#endif

struct IoObj2 {
    char pad0[8];
    char *buf;
    int cap;
    struct IoDev *dev;
    char pad1[0x20];
    int len;
};

// 0x3BA5A0 near-miss: same second rd() call scheduling difference as 0x3BA708 (8 bytes larger)
#ifdef NONMATCHING
// DRAFT: GAME 0x3BA5A0
int func_003BA5A0(struct IoObj2 *o)
{
    struct IoBuf b;
    int left = o->len;
    int off = 8;
    o->dev->vt->rd(o->dev, 1, left, &b);
    memcpy(o->buf + off, b.p, b.n);
    left -= b.n;
    off += b.n;
    o->dev->vt->wr(o->dev, 0, &b);
    if (left > 0) {
        o->dev->vt->rd(o->dev, 1, left, &b);
        memcpy(o->buf + off, b.p, b.n);
        left -= b.n;
        off += b.n;
        o->dev->vt->wr(o->dev, 0, &b);
    }
    if (left) {
        func_003B9DE0(D_00460A38);
        return -1;
    }
    memset(o->buf + off, 0, o->cap - off);
    return 0;
}
#endif

extern char D_00460AA8[];

// FUNCTION: GAME 0x3BA800
int func_003BA800(int *o)
{
    if (!o) {
        func_003B9DE0(D_00460AA8);
        return -1;
    }
    return o[1];
}
