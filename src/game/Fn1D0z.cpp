// Flag-driven angle ramps. The flag word is read as a 64-bit signed value
// (`long f = o->f`; lwu+dsra) and each bit is tested as `((f >> n) & 1) == 1`.

extern "C" float Adjust_theta__Ff(float);
struct O {
    char *m;
    unsigned int f;
};

// FUNCTION: GAME 0x1D0CE8
extern "C" void func_001D0CE8(O *o)
{
    long f = o->f;
    if (((f >> 1) & 1) == 1) return;
    if (((f >> 2) & 1) != 1) return;
    *(float *)(o->m + 0x104) += 0.15707964f;
    *(float *)(o->m + 0x104) = Adjust_theta__Ff(*(float *)(o->m + 0x104));
    if (0.0f <= *(float *)(o->m + 0x104)) {
        *(float *)(o->m + 0x104) = 0.0f;
        *(int *)&o->f = (*(int *)&o->f | 2) & -5;
    }
}

// FUNCTION: GAME 0x1D0DF8
extern "C" void func_001D0DF8(O *o)
{
    long f = o->f;
    if (((f >> 1) & 1) != 1) return;
    if (((f >> 2) & 1) != 1) return;
    *(float *)(o->m + 0x104) += 0.15707964f;
    if (3.1415927f <= *(float *)(o->m + 0x104)) {
        *(float *)(o->m + 0x104) = 3.1415927f;
        int *p = (int *)&o->f;
        *p &= -3;
        *p &= -5;
    }
    *(float *)(o->m + 0x104) = Adjust_theta__Ff(*(float *)(o->m + 0x104));
}

// FUNCTION: GAME 0x1D6E20
extern "C" void func_001D6E20(O *o)
{
    long f = o->f;
    if (((f >> 3) & 1) == 1) return;
    if (((f >> 4) & 1) != 1) return;
    *(float *)(o->m + 0x104) += 0.20943951f;
    *(float *)(o->m + 0x104) = Adjust_theta__Ff(*(float *)(o->m + 0x104));
    if (0.0f <= *(float *)(o->m + 0x104)) {
        *(float *)(o->m + 0x104) = 0.0f;
        *(int *)&o->f = (*(int *)&o->f | 8) & -17;
    }
}

// FUNCTION: GAME 0x1D6F30
extern "C" void func_001D6F30(O *o)
{
    long f = o->f;
    if (((f >> 3) & 1) != 1) return;
    if (((f >> 4) & 1) != 1) return;
    *(float *)(o->m + 0x104) += 0.20943951f;
    if (3.1415927f <= *(float *)(o->m + 0x104)) {
        *(float *)(o->m + 0x104) = 3.1415927f;
        int *p = (int *)&o->f;
        *p &= -9;
        *p &= -17;
    }
    *(float *)(o->m + 0x104) = Adjust_theta__Ff(*(float *)(o->m + 0x104));
}

extern "C" void func_002D57C8(char *);
extern "C" void sleep__9cTaskWorkUs(void *, unsigned short);
extern char GlobalTask[];

// FUNCTION: GAME 0x2D52A0
extern "C" void func_002D57C8(char *);
extern "C" void func_002D52A0(char *self)
{
    unsigned i;
    int off;
    i = 0;
    if (*(unsigned short *)(self + 0xC) != 0) {
        off = 0;
        do {
            char *cur = *(char **)self + off;
            long f = *(unsigned *)(self + 0x2C);
            *(unsigned *)(self + 8) = i;
            *(char **)(self + 4) = cur;
            long a = f & 1, b, c;
            if (a && (*(unsigned char *)(cur + 0x50) & 1) == 0)
                goto next;
            b = (f >> 1) & 1;
            if (b) {
                c = *(unsigned char *)(cur + 0x50);
                if (((c >> 1) & 1) == 0)
                    goto next;
            }
            func_002D57C8(cur);
        next:
            i++;
            off += 0x58;
        } while (i < *(unsigned short *)(self + 0xC));
    }
    *(int *)(self + 4) = 0;
    *(int *)(self + 8) = -1;
}

// FUNCTION: GAME 0x2D5358
extern "C" void func_002D57C8(char *);
extern "C" void sleep__9cTaskWorkUs(void *, unsigned short);
extern char GlobalTask[];
extern "C" void func_002D5358(char *self)
{
    unsigned i;
    int off;
    char *gt;
    *(unsigned short *)(self + 0x34) = 0;
    i = 0;
    if (*(unsigned short *)(self + 0xC) != 0) {
        off = 0;
        gt = GlobalTask;
        do {
            char *cur = *(char **)self + off;
            long f = *(unsigned *)(self + 0x2C);
            long a = f & 1, b, c;
            *(unsigned *)(self + 8) = i;
            *(char **)(self + 4) = cur;
            if (a && (*(unsigned char *)(cur + 0x50) & 1) == 0)
                goto next;
            b = (f >> 1) & 1;
            if (b) {
                c = *(unsigned char *)(cur + 0x50);
                if (((c >> 1) & 1) == 0)
                    goto next;
            }
            *(unsigned short *)(self + 0x34) = 0;
            func_002D57C8(cur);
            {
                unsigned short s = *(unsigned short *)(self + 0x34);
                if (s) {
                    unsigned short t = s;
                    __asm__("" : "+r"(t));
                    off -= 0x58;
                    i--;
                    sleep__9cTaskWorkUs(*(void **)(gt + 4), t);
                }
            }
        next:
            i++;
            off += 0x58;
        } while (i < *(unsigned short *)(self + 0xC));
    }
    *(int *)(self + 4) = 0;
    *(int *)(self + 8) = -1;
}
