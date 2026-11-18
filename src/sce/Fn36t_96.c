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
