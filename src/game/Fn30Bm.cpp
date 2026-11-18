// Unnamed units in 0x30B000-0x31C000.
extern unsigned D_00754250[];
extern int D_003C3D08;

#ifdef NONMATCHING
// DRAFT: GAME 0x30F2B0 (6 words off: t1/t2 swapped; local n and declaration-order swap tried, no change)
extern "C" void func_0030F2B0(unsigned seed)
{
    D_00754250[0] = seed;
    D_003C3D08 = 1;
    do {
        int i = D_003C3D08;
        unsigned x = D_00754250[i - 1];
        x ^= x >> 30;
        int n = i + 1;
        D_003C3D08 = n;
        D_00754250[i] = (unsigned)((unsigned long)x * 0x6C078965UL) + i;
        if (n >= 0x270)
            break;
    } while (1);
}
#endif

extern "C" void *getMeshPtr__6cModeli(void *, int);
extern "C" int getMeshNum__C6cModel(void *);
extern "C" void func_00148F00(void *, unsigned);
extern "C" void func_00155BE8(void *, unsigned, unsigned);
extern char Sys[];

// FUNCTION: GAME 0x319CC0
extern "C" void func_00319CC0(void *self, unsigned a)
{
    int i = 0;
    int n = getMeshNum__C6cModel(self);
    if (n > 0) {
        do {
            void *m = getMeshPtr__6cModeli(self, i);
            i++;
            func_00148F00(m, a | 0x80000000u);
        } while (i < n);
    }
    char *sys = Sys;
    func_00155BE8(self, a, *(unsigned *)(sys + 0x210) & 1);
}

extern "C" void func_00317FF0(int *, int *, int *);

#ifdef NONMATCHING
// DRAFT: GAME 0x3129D0 (37 words off: *self reload and register roles differ)
extern "C" int *func_003129D0(int **self, int val)
{
    int *v = *self;
    unsigned n = 0;
    if (v)
        n = v[2] - v[1] >> 2;
    v = *self;
    unsigned m = 0;
    if (v)
        m = v[3] - v[1] >> 2;
    if (n < m) {
        v = *self;
        int *cur = (int *)v[2];
        if (cur == (int *)v[3]) {
            func_00317FF0(v, cur, &val);
        } else {
            if (cur)
                *cur = val;
            v[2] += 4;
        }
        return (int *)((*self)[2] - 4);
    }
    return 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x31B410 (about 19 words off: gcc schedules the byte-store run and load registers differently)
extern "C" void func_0031B410(int unused, unsigned char *p)
{
    unsigned long m = 0x000F00807FF00000UL;
    *(unsigned long *)(p + 0x40) &= m;
    *(unsigned long *)(p + 0x38) &= m;
    *(unsigned long *)(p + 0x28) &= m;
    *(unsigned long *)(p + 0x30) &= m;
    *(unsigned long *)(p + 0x00) = *(unsigned long *)(p + 0x18) & m;
    p[0x6B] = 0x80;
    p[0x7B] = 0;
    p[0x68] = 0x80;
    p[0x69] = 0x80;
    p[0x6A] = 0x80;
    p[0x6F] = 0;
    p[0x6E] = 0;
    p[0x6C] = 0;
    p[0x6D] = 0;
    p[0x70] = 0;
    p[0x73] = 0;
    p[0x71] = 0;
    p[0x72] = 0;
    p[0x74] = 0;
    p[0x75] = 0;
    p[0x76] = 0;
    p[0x77] = 0;
    p[0x78] = 0;
    p[0x79] = 0;
    p[0x7A] = 0;
}
#endif

extern "C" float func_002DA940(float, float);

// FUNCTION: GAME 0x31B2E0
extern "C" int func_0031B2E0(int unused, char *p)
{
    *(int *)(p + 0x8C) = 0;
    if (*(unsigned short *)(p + 0x78)) {
        float a = func_002DA940(*(float *)(p + 0x88), *(float *)(p + 0x7C));
        if (a > 0.7853982f || a < -0.7853982f)
            *(int *)(p + 0x8C) += 2;
        if (a > 1.5707964f || a < -1.5707964f)
            *(int *)(p + 0x8C) += 2;
        if (a > 2.3561945f || a < -2.3561945f)
            *(int *)(p + 0x8C) += 4;
    }
    *(float *)(p + 0x88) = *(float *)(p + 0x7C);
    return *(int *)(p + 0x8C);
}

// FUNCTION: GAME 0x312DB8
extern "C" int *func_00312DB8(int *first, int *last, const int *val)
{
    int trip = (last - first) >> 2;
    for (; trip > 0; --trip) {
        if (*first == *val) return first;
        ++first;
        if (*first == *val) return first;
        ++first;
        if (*first == *val) return first;
        ++first;
        if (*first == *val) return first;
        ++first;
    }
    switch (last - first) {
    case 3:
        if (*first == *val) return first;
        ++first;
    case 2:
        if (*first == *val) return first;
        ++first;
    case 1:
        if (*first == *val) return first;
        ++first;
    case 0:
    default:
        return last;
    }
}

extern char GlobalTask[];
extern char Movie[];
extern "C" int Start__6cMovieib(void *, int, int);
extern "C" int GetStatus__6cMovieUi(void *, int);
extern "C" void Stop__6cMovieUi(void *, int);
extern "C" void sleep__9cTaskWorkUs(void *, unsigned short);
extern "C" void execute__12cTaskManagerRFv_vi(void *, void (*)(), int);
extern "C" void exit__9cTaskWork(void *);
extern "C" void func_002A5998();
extern "C" void func_0030D5C8();

#ifdef NONMATCHING
// DRAFT: GAME 0x30DA08 (6 words off: s2/s3 roles of the Movie and GlobalTask addresses swapped; declaration-order swap no change)
extern "C" void func_0030DA08()
{
    int id = Start__6cMovieib(Movie, 0, 1);
    while (GetStatus__6cMovieUi(Movie, id))
        sleep__9cTaskWorkUs(*(void **)(GlobalTask + 4), 1);
    Stop__6cMovieUi(Movie, id);
    execute__12cTaskManagerRFv_vi(GlobalTask, func_002A5998, 0);
    execute__12cTaskManagerRFv_vi(GlobalTask, func_0030D5C8, 3);
    exit__9cTaskWork(*(void **)(GlobalTask + 4));
}
#endif

extern "C" int printf(const char *, ...);
extern "C" int func_00397630(int);
extern "C" int func_003979E0(int, int, void *);
extern char D_00450D80[];
extern char D_00450D90[];
extern char D_00450DA8[];

#ifdef NONMATCHING
// DRAFT: GAME 0x31A718 (about 20 words off: original keeps 0xFF in v0 across the printf, store order and loop base differ)
extern "C" void func_0031A718(char *self)
{
    while (!func_00397630(0))
        printf(D_00450D80);
    if (!func_003979E0(0, 0, self))
        printf(D_00450D90);
    int r = func_003979E0(1, 0, self + 0x380);
    if (!r)
        printf(D_00450DA8);
    unsigned char v = 0xFF;
    *(unsigned char *)(self + 0x15A) = 0xFF;
    *(unsigned char *)(self + 0x4B8) = 1;
    *(short *)(self + 0x148) = 0;
    *(int *)(self + 0x154) = 0;
    *(short *)(self + 0x14A) = 0;
    *(unsigned char *)(self + 0x158) = 0;
    *(unsigned char *)(self + 0x159) = 1;
    *(unsigned char *)(self + 0x15D) = 0xFF;
    *(unsigned char *)(self + 0x15C) = 0xFF;
    *(unsigned char *)(self + 0x15B) = 0xFF;
    for (int i = 5; i != -1; i--)
        self[0x360 + i] = 0;
}
#endif
