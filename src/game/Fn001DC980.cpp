extern "C" void func_001DBFB8(void *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *);

extern float D_00568150[];
extern float D_00568160[];
extern float D_00568170[];
extern float D_005681C0[];

struct Sub1DC {
    char pad[0x604];
    int k;
};
struct Obj1DC {
    Sub1DC *s;
    int flags;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x1DC980
// 55 words: orig computes nxt at run time and keeps arr in a separate copy; compiled folds nxt and CSEs base/arr. Tried 8 variants, none below 55.
extern "C" int func_001DC980(char *self)
{
    unsigned short x[5], y[5];
    int i;
    func_001DBFB8(self, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]);
    for (i = 0; i < 5; i++) {
        if (y[i] == 3) {
            int cur = 0;
            int nxt = cur + 1;
            Obj1DC **base = (Obj1DC **)(self + 0x3004);
            Obj1DC **arr = base;
            unsigned short cnt;
            for (;;) {
                Obj1DC **p = base;
                int n = 4;
                int k;
                do {
                    (*p)->flags &= ~4;
                    p++;
                } while (--n >= 0);
                cnt = 0;
                for (k = nxt; k < 5; k++) {
                    if (arr[cur]->s->k == arr[k]->s->k) {
                        cnt = cnt + 1;
                        arr[cur]->flags |= 4;
                        arr[k]->flags |= 4;
                    }
                }
                if (cnt == 2)
                    break;
                cur = nxt;
                nxt = cur + 1;
                if (!(cur < 4))
                    break;
            }
            return 1;
        }
    }
    return 0;
}

// DRAFT: GAME 0x1DCAD8
// 34 words: orig keeps arr hoisted in t5 with a separate inner base a3; bne at 0x1DCB58 is 0x33 words vs 0x30. Tried 8 variants (tag type, arr hoist, loop shape), best 34.
extern "C" int func_001DCAD8(char *self)
{
    unsigned short x[5], y[5];
    unsigned short *q;
    unsigned short cnt;
    int n;
    int cur;
    func_001DBFB8(self, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]);
    cnt = 0;
    q = y;
    n = 4;
    do {
        if (*q == 2)
            cnt = (cnt + 1) & 0xFFFF;
        q++;
    } while (--n >= 0);
    if (cnt != 2)
        return 0;
    for (cur = 0; cur < 5; cur++) {
        Obj1DC **arr = (Obj1DC **)(self + 0x3004);
        signed char tag = cur;
        int j = 0;
        do {
            if (cur != j && arr[cur]->s->k == arr[j]->s->k) {
                tag = -1;
                break;
            }
            j++;
        } while (j < 5);
        if (tag != -1) {
            int m = 0;
            do {
                if (m == cur)
                    arr[m]->flags &= ~4;
                else
                    arr[m]->flags |= 4;
                m++;
            } while (m < 5);
        }
    }
    return 1;
}

// DRAFT: GAME 0x1DCEF0
// 80 words: base-pointer order differs (compiled lui $t0 first, orig lui $a0) and sw $zero where orig uses swc1 $f0. Tried ascending store order, row pointer (82) and zero/one locals (84); none below 80.
extern "C" void func_001DCEF0(int a0, int a1)
{
    if (a1 == 0xFFFF && a0 != 0) {
        D_00568170[0] = -0.278f;
        D_00568170[1] = 0.024f;
        D_00568170[2] = 0.0f;
        D_00568170[3] = 1.0f;
        D_00568170[4] = -0.139f;
        D_00568170[5] = 0.024f;
        D_00568170[6] = 0.0f;
        D_00568170[7] = 1.0f;
        D_00568170[8] = 0.0f;
        D_00568170[9] = 0.024f;
        D_00568170[10] = 0.0f;
        D_00568170[11] = 1.0f;
        D_005681C0[0] = -0.1112f;
        D_00568170[12] = 0.139f;
        D_00568170[13] = 0.024f;
        D_00568170[14] = 0.0f;
        D_00568170[15] = 1.0f;
        D_005681C0[1] = 0.024f;
        D_005681C0[2] = 0.0f;
        D_005681C0[3] = 1.0f;
        D_00568160[0] = 0.238f;
        D_00568150[0] = 0.0f;
        D_00568150[3] = 1.0f;
        D_00568160[1] = 0.184f;
        D_00568160[3] = 1.0f;
        D_00568170[16] = 0.278f;
        D_00568170[19] = 1.0f;
        D_005681C0[4] = 0.1112f;
        D_00568150[1] = 0.0f;
        D_00568150[2] = 0.0f;
        D_00568160[2] = 0.0f;
        D_00568170[17] = 0.024f;
        D_00568170[18] = 0.0f;
        D_005681C0[5] = 0.024f;
        D_005681C0[7] = 1.0f;
        D_005681C0[6] = 0.0f;
    }
}
#endif
