// COMPILER: ee-gcc2.9-991111

extern long func_003B8E88(long, long);
struct N { int _0[4]; unsigned fl; int _14; int gen; };
struct H { struct N *n; int gen; };

// FUNCTION: GAME 0x3B3328
int func_003B3328(struct H *h)
{
    struct N *n = h->n;
    if (n) {
        if (h->gen == n->gen) {
            if (n->fl & 1) goto ok;
        }
    }
    return 0;
ok:
    return 1;
}

// FUNCTION: GAME 0x3B7590
void func_003B7590(long x, int *a, int *b)
{
    int q = func_003B8E88(x, 0x8CA0000);
    if (a) *a = q;
    if (b) *b = (int)func_003B8E88((x - (unsigned long)((unsigned)q) * 0x8CA0000u) * 1000000, 0x8CA0000);
}
