// COMPILER: ee-gcc2.96

extern int D_003D846C;
extern int D_003D8468;
void func_00331C78();
void func_00331310();
long func_00331DB8();
long func_00331FA8();
int func_00331E70();

typedef struct S {
    char pad0[2];
    signed char step;
    char padx;
    int state;
    char pad[0x10];
    int i18;
    int pad1c;
    int i20;
    int pad24;
    long q28;
    int h30;
    int e34;
} S;

// DRAFT: GAME 0x331900
// diff: switch operand is lb in the original; mine reuses the lbu in a0 (sll/sra), 1 extra word at the head; rest follows.
#ifdef NONMATCHING
void func_00331900(S *o) {
    unsigned char s = ((unsigned char *)o)[2];
    long r;
    int t;
    if (o->state == 1) {
        switch (o->step) {
        case 2:
            func_00331310(o);
            o->step = 0;
            D_003D846C++;
        case 1:
        case 3:
        case 9:
            o->step = 0;
            s = 0;
        case 0:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        default:
            o->state = 0;
        }
    }
    if ((char)s == 1) {
        func_00331C78(0x2000);
        r = func_00331DB8(o->h30, o->q28 << 11, 0);
        func_00331C78(0x2001);
        if (r < 0) {
            o->step = 9;
            o->e34 = r;
        }
        func_00331C78(0x2100);
        r = func_00331FA8(o->h30, o->i18, o->i20);
        func_00331C78(0x2101);
        if (r >= 0) {
            o->step = 2;
            D_003D8468++;
            s = 2;
        } else {
            o->step = 9;
            o->e34 = r;
            s = 9;
        }
    }
    if ((char)s == 2) {
        func_00331C78(0x2200);
        if (func_00331E70(o->h30, 1, &t) < 0) {
            func_00331C78(0x2201);
            o->step = 9;
            o->e34 = -1;
        } else {
            func_00331C78(0x2202);
            if (t == 0) {
                o->step = 3;
                D_003D846C++;
            }
        }
    }
}
#endif
