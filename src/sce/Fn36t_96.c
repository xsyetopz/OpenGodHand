// COMPILER: ee-gcc2.96

extern int func_0036D688();
extern int func_0036D8E8();
extern void *memset();
extern void *memcpy();
extern int D_0045A580[];
extern int D_0045A590[];

// FUNCTION: GAME 0x36DC70
void func_0036DC70(char *p, int *a, int *b)
{
    char *q = p + 0x160;
    if (func_0036D688(p)) {
        func_0036D8E8(0, 0xFF03020E);
        return;
    }
    *a = *(int *)(q + 0xD0);
    *b = *(int *)(q + 0xD4);
}

// FUNCTION: GAME 0x36E308
void func_0036E308(int *p)
{
    int x;
    int t;
    if (p[0x118 / 4] == 3) {
        p[0x3C8 / 4] = 0;
        p[0x3C4 / 4] = 0;
    } else {
        x = p[0x3C8 / 4];
        p[0x3C8 / 4] = x + 1;
        p[0x3C4 / 4] = x % 2;
    }
    t = p[0x114 / 4];
    p[0x320 / 4] = D_0045A580[t];
    p[0x330 / 4] = D_0045A590[t];
}

typedef struct Buf {
    char *data;
    int size;
    int pos;
} Buf;

// FUNCTION: GAME 0x36F008
void func_0036F008(char *p, void *src, int n)
{
    Buf *b = (Buf *)(p + 0x14C);
    int room = b->size - b->pos;
    char *d;
    if (n < room)
        room = n;
    d = b->data + b->pos;
    b->pos += room;
    memcpy(d, src, room);
}

// FUNCTION: GAME 0x36E2B8
void func_0036E2B8(int *p)
{
    if (p[0x48 / 4] == 1 || p[0x118 / 4] == 1 || p[0x118 / 4] == 2)
        p[0x38 / 4] = 1;
    else if (p[0x134 / 4] == 1)
        p[0x38 / 4] = 3;
    else
        p[0x38 / 4] = 2;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x36EB58
// diff: 70 words (204 vs 288 bytes). The original keeps all 8 bytes loaded and merged with a non-folded 96-bit constant; mine folds it.
unsigned char *func_0036EB58(char *p, unsigned char *s)
{
    int *q = (int *)(p + 0x160);
    unsigned char *a;
    int sh;
    unsigned w1, w2, v;
    q[0x420 / 4] = 1;
    q[0x430 / 4]++;
    if (q[0x308 / 4] == 0 || q[0x308 / 4] == 0x80) {
        if (q[0x30C / 4])
            q[0x494 / 4]++;
    } else {
        q[0x494 / 4]++;
    }
    a = (unsigned char *)((unsigned)s & ~3);
    sh = (s - a) * 8;
    w1 = ((signed char)a[0] << 24) | (a[1] << 16) | (a[2] << 8) | a[3];
    w2 = ((signed char)a[4] << 24) | (a[5] << 16) | (a[6] << 8) | a[7];
    v = (w1 << sh) | (w2 >> (32 - sh));
    if (sh == 0)
        q[0x2C / 4] = w1;
    else
        q[0x2C / 4] = v;
    q[0x30C / 4] = 0;
    q[0x308 / 4] = 0;
    return s + 4;
}
#endif
