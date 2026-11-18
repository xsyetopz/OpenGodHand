// COMPILER: ee-gcc2.96
struct S { char c; char _p[55]; };
extern struct S D_003DED70[];

// FUNCTION: GAME 0x336530
struct S *func_00336530(void)
{
    struct S *r = 0;
    int i;
    for (i = 0; i < 0x28; i++) {
        if (D_003DED70[i].c == 0) {
            r = &D_003DED70[i];
            break;
        }
    }
    return r;
}

struct O {
    char _a[0x54];
    char m54;
};
extern int D_003E0710;
extern int D_003E0708;
extern int D_003E0738;

// FUNCTION: GAME 0x337B30
void func_00337B30(struct O *o, int v)
{
    if (D_003E0710 == 1 && D_003E0708 <= 0) {
        return;
    }
    if (o->m54 != v) {
        if (D_003E0738 != 0 || v != 1) {
            o->m54 = v;
        }
    }
}

// FUNCTION: GAME 0x3387C8
void func_003387C8(int *o, int i, int v)
{
    int t;
    if (D_003E0710 == 1 && D_003E0708 <= 0) {
        return;
    }
    t = v < -15 ? -15 : v;
    t = t > 15 ? 15 : t;
    o[i + 0x10] = t;
}

// FUNCTION: GAME 0x33D4D8
void func_0033D4D8(short *d, short *s, int n)
{
    while (n > 0) {
        *d++ = *s++;
        n--;
    }
}
