struct S1F6A80 {
    int a, b, c;
    int n;
    int v[8];
};

// FUNCTION: GAME 0x1F6A80
extern "C" void func_001F6A80(S1F6A80 *p) {
    int i = p->n - 1;
    while (i >= 0) {
        if (p->v[i] != 0) {
            p->n = i;
            return;
        }
        i--;
    }
    int t = p->n;
    int j = 3;
    if (t < 3) {
        long n = t;
        int *q = &p->v[3];
        for (;;) {
            if (*q != 0) {
                p->n = j;
                return;
            }
            j--;
            q--;
            if (!(n < j)) break;
        }
    }
}
