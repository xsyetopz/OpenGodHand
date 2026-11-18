// COMPILER: ee-gcc2.9-991111
// SCE-built C++ library code in 0x3875A8-0x390000 (sd/ld prologues, not ProDG sq).
struct VT { char pad[0x5C]; int (*f5C)(void *); };
struct O { int flags; int w4, w8, wC, w10, w14, w18; char pad[0x50 - 0x1C]; VT *vt; char pad2[0x1C]; };
extern "C" {
void func_0038C768(O *, char *, char *, int);
// FUNCTION: GAME 0x38CB28
O *func_0038CB28(O *t, char *p, long n) {
    if (t->vt->f5C(t) == -1)
        return 0;
    if (p == 0 || n == 0) {
        t->flags |= 2;
        func_0038C768(t, (char *)t + 0x4B, (char *)t + 0x4C, 0);
    } else {
        t->flags &= ~2;
        func_0038C768(t, p, p + n, 0);
    }
    t->w18 = 0;
    t->w14 = 0;
    t->w10 = 0;
    t->w8 = 0;
    t->w4 = 0;
    t->wC = 0;
    return t;
}
}

struct SB38 { int w0, w4, w8; };
struct IOS38 { SB38 *sb; void *tie; char pad[0x12]; unsigned char b1A; };
struct IS38 { IOS38 *ios; int gcount; };
extern "C" void func_00389268(void *);
static inline int ipfx38(IS38 *t) {
    if (t->ios->b1A) {
        t->ios->b1A |= 2;
        return 0;
    } else {
        void *tie = t->ios->tie;
        if (tie) {
            SB38 *sb = t->ios->sb;
            if (sb->w8 == sb->w4)
                func_00389268(tie);
        }
    }
    return 1;
}
extern "C" {
int func_0038E258(SB38 *, char *, int, int, int, int *);
// FUNCTION: GAME 0x38AA60
IS38 *func_0038AA60(IS38 *t, char *buf, int n, char delim) {
    t->gcount = 0;
    if (n <= 0) {
        t->ios->b1A |= 2;
        return t;
    }
    if (ipfx38(t)) {
        int local;
        t->gcount = func_0038E258(t->ios->sb, buf, n - 1, delim, -1, &local);
        if (t->gcount == 0 && local == -1)
            t->ios->b1A |= 3;
    }
    buf[t->gcount] = 0;
    return t;
}
}

extern "C" {
int func_0038EAE0(IS38 *);
char *func_0038AB70(IS38 *, long *, char);
char *func_00030F578(int);
void func_003A5148(char *, char *, int);
// FUNCTION: GAME 0x38AB70
char *func_0038AB70(IS38 *is, long *len, char delim) {
    char buf[0x200];
    int ch;
    int n = func_0038E258((SB38 *)is, buf, 0x200, delim, -1, &ch);
    if (ch != -1)
        ch = func_0038EAE0(is);
    long base = *len;
    *len = base + (unsigned)n;
    char *r;
    if (ch != -1 && ch != delim) {
        *len = *len + 1;
        r = func_0038AB70(is, len, delim);
        if (r) {
            int b = (int)base;
            func_003A5148(r + b, buf, n);
            r[b + n] = (char)ch;
        }
    } else {
        r = func_00030F578((int)(*len + 1));
        if (r) {
            r[(int)*len] = 0;
            func_003A5148(r + (int)*len - n, buf, n);
        }
    }
    return r;
}
}
