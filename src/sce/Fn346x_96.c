// COMPILER: ee-gcc2.96
extern char D_004588B0[];
extern char D_00458928[];
extern char D_00458900[];
extern char D_004588D8[];
void func_00348BE0();
void func_00349840(char *);
int func_003492E8(void);
int func_00349468(char *);
char *func_00348938(char *);
int func_00348968(char *);
int func_003472D8(char *);
int func_0035CE60(int, int, int, int);
int func_00358A38(char *);
int func_0034AFE0();
int func_00329438(int, int, int);
void func_0032AF40(int, int);
void func_00346798(int, int, int);
int func_0035A1C8(char *, int);
int func_00349A40(int);
int func_00347DF8(int);
int func_00349B88(int);
void func_00358F68(int);

// FUNCTION: GAME 0x00346E70
int func_00346E70(unsigned a)
{
    int r;
    switch (a) {
    case 1: r = 1; break;
    case 2: r = 2; break;
    case 3: r = 3; break;
    default:
        func_00348BE0(D_004588B0);
        r = 3;
        break;
    }
    return r;
}

// FUNCTION: GAME 0x00347080
int func_00347080(char *p)
{
    int r = 3;
    switch (*(unsigned *)(p + 0x88)) {
    case 1: r = 1; break;
    case 2: r = 2; break;
    case 3: break;
    default: func_00348BE0(D_004588D8); break;
    }
    return r;
}

// FUNCTION: GAME 0x003470F0
int func_003470F0(char *p)
{
    int r = 1;
    switch (*(unsigned *)(p + 0x8C)) {
    case 1: break;
    case 2: r = 2; break;
    case 3: r = 3; break;
    default: func_00348BE0(D_00458900); break;
    }
    return r;
}

// FUNCTION: GAME 0x00347160
int func_00347160(int a)
{
    int r = 1;
    switch (a) {
    case 0: r = 0; break;
    case 1: break;
    default:
        func_00348BE0(D_00458928);
        break;
    }
    return r;
}

// FUNCTION: GAME 0x003483F8
void func_003483F8(char *p, int a)
{
    char *v = func_00348938(p);
    if (a && v && *(void (**)(int))(v + 0x10))
        (*(void (**)(int))(v + 0x10))(a);
}

// FUNCTION: GAME 0x00349250
int func_00349250(char *p)
{
    int r = 0;
    func_00349840(p);
    if (func_003492E8() == 1)
        r = func_00349468(p);
    return r;
}

// FUNCTION: GAME 0x00348550
void func_00348550(char *p, int a)
{
    if (func_00348968(p) == 1) {
        char *vt = *(char **)(p + 8);
        int arg = *(int *)(p + 0x1C);
        if (vt) {
            void (*fn)(int, int) = *(void (**)(int, int))(vt + 0x24);
            if (fn)
                fn(arg, a);
        }
    }
}

// FUNCTION: GAME 0x003485B0
void func_003485B0(char *p, int a)
{
    if (func_00348968(p) == 1) {
        char *vt = *(char **)(p + 8);
        int arg = *(int *)(p + 0x1C);
        if (vt) {
            void (*fn)(int, int) = *(void (**)(int, int))(vt + 0x28);
            if (fn)
                fn(arg, a);
        }
    }
}

// FUNCTION: GAME 0x00348610
void func_00348610(char *p, int a)
{
    if (func_00348968(p) == 1) {
        char *vt = *(char **)(p + 8);
        int arg = *(int *)(p + 0x1C);
        if (vt) {
            void (*fn)(int, int) = *(void (**)(int, int))(vt + 0x30);
            if (fn)
                fn(arg, a);
        }
    }
}

// FUNCTION: GAME 0x003455D8
void func_003455D8(float *p)
{
    func_00346798(0, 0x1B, (int)*p);
    func_00346798(0, 7, 1);
}

// FUNCTION: GAME 0x0034B6D0
void func_0034B6D0(char *p, int a)
{
    if (func_0035A1C8(p, 6)) {
        void (*fn)(char *, int) = *(void (**)(char *, int))(*(char **)(p + 0x2114) + 0x14);
        if (fn)
            fn(p, a);
    }
}

// FUNCTION: GAME 0x003491D0
void func_003491D0(char *p)
{
    if (*(int *)(p + 0x40) && func_00349A40(*(int *)(p + 0x40)))
        *(int *)(p + 4) = 4;
    if (*(int *)(p + 0x48) && func_00347DF8(*(int *)(p + 0x48)) == 1)
        *(int *)(p + 4) = 4;
}

// FUNCTION: GAME 0x00346158
void func_00346158(char *p)
{
    int s = *(int *)(p + 0x3C);
    if (*(int *)(p + 0x40) && func_00349B88(*(int *)(p + 0x40)) == 3)
        func_00358F68(s);
}

// FUNCTION: GAME 0x003473A0
int func_003473A0(char *p)
{
    if (func_003472D8(p) == 1)
        return 0;
    {
        int v = *(int *)(p + 0x17C);
        if (!v)
            return 0;
        return func_0035CE60(*(int *)(p + 0x3C), 2, v, 0) ? -1 : 0;
    }
}

// FUNCTION: GAME 0x00347698
int func_00347698(char *p)
{
    if (func_003472D8(p) == 1)
        return 0;
    if (!*(int *)(p + 0x17C))
        return 0;
    return func_0035CE60(*(int *)(p + 0x3C), 2, 0, 0) ? -1 : 0;
}

// FUNCTION: GAME 0x00344FD8
struct E { int a, b, c, d, e; };
struct P { char pad[0xB4]; int x, y, z; struct E t[8]; };
void func_00344FD8(struct P *p)
{
    int i;
    p->x = 0;
    p->y = 0;
    p->z = 0;
    for (i = 0; i < 8; i++) {
        p->t[i].a = 0;
        p->t[i].b = 0;
        p->t[i].c = 0;
        p->t[i].d = 0;
        p->t[i].e = 0x11;
    }
}

// FUNCTION: GAME 0x0034AF70
int func_0034AF70(char *p)
{
    int s;
    if (func_00358A38(p) != 1)
        s = func_00329438(*(int *)(p + 0xC), *(int *)(p + 0x18), *(int *)(p + 0x14));
    else
        s = func_0034AFE0();
    if (s == 0)
        return 0;
    func_0032AF40(s, 0);
    return s;
}
