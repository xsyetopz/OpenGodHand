extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void func_00124EC0(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern "C" void SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, void *, void *, unsigned, int);
extern "C" void DieDemoStart__4cSnd(void *);
extern "C" void addGameLevelPoint__9cCoreSavei(void *, int);
extern "C" void func_0012C348(void *, int);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" void func_001DBFB8(void *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *);
extern "C" void closeAll__8cMessage(void *);
extern "C" void KeyStop__Fv();
extern "C" void *Getplayer__Fv();
extern "C" void DiscardWeapon__4pl00(void *);
extern "C" void DiscardThrowObj__4pl00(void *);
extern "C" void start__9classFADEUiUiUiUiUiUi(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" float Turn_dest__FPCffT0f(const float *, float, const float *, float);
extern "C" float capVu0MagnitudeSqXZ__FPCfT0(const float *, const float *);
extern "C" void func_002DC390(void *);
extern char Snd;
extern char CoreSave;
extern char Fade;
extern char *Message;
extern char *g_Sce;
extern unsigned D_00747A24;
extern unsigned D_00747A50;
extern unsigned D_00747A78;
extern unsigned D_00747A80;
extern unsigned D_00747A84;
extern unsigned short D_005CAE40;

// DRAFT: GAME 0x122D18
// 6 differing words: adds s2/s1 are scheduled before the t0..t3/a1 zeroing; asm does zeroing first. Two orderings tried.
#ifdef NONMATCHING
extern "C" void func_00122D18(char *self)
{
    int v;
    int *p;
    int s1, s2;

    *(float *)(self + 0x54C) = 30.0f;
    v = *(unsigned char *)(self + 0x2F6);
    if (v != 1) {
        if (v >= 2)
            return;
        if (v != 0)
            return;
        p = *(int **)(self + 0x304);
        s2 = *(int *)((char *)p + 0x16C) + (int)p;
        s1 = *(int *)((char *)p + 0x170) + (int)p;
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(&Snd, 0, 0xD6, self, 0, 0, 0, 0);
        DieDemoStart__4cSnd(&Snd);
        addGameLevelPoint__9cCoreSavei(&CoreSave, -1000);
        func_0012C348(self, 3);
        func_002A8578(self, s2, s1, 2, 0, 0, 0.0f);
        *(int *)(self + 0x15B0) = 0x82;
        *(unsigned char *)(self + 0x2F6) = *(unsigned char *)(self + 0x2F6) + 1;
    }
    func_00124EC0(self);
    if (*(int *)(self + 0x15B0) != 0) {
        *(int *)(self + 0x15B0) -= 1;
    } else {
        D_00747A24 |= 8;
    }
    if (moveMotion__FP8cObjBase(self)) {
        D_00747A24 |= 8;
        *(unsigned char *)(self + 0x2F6) += 1;
    }
    addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
    addNullSpeed__8cObjBasef(self, 1.0f);
}
#endif

struct Sub1DCC {
    char pad[0x604];
    int k;
};
struct Obj1DCC {
    Sub1DCC *s;
    int flags;
};

// DRAFT: GAME 0x1DCC30
// 75 differing words, 404 vs 372 bytes: pair search and flag-clear loops compile to a different layout; size too large.
#ifdef NONMATCHING
extern "C" int func_001DCC30(char *self)
{
    unsigned short x[5], y[5];
    unsigned short pr[2];
    unsigned short *p;
    unsigned short cnt;
    int n, i, j;
    Obj1DCC **arr;
    Obj1DCC **q;

    func_001DBFB8(self, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]);
    cnt = 0;
    p = y;
    n = 4;
    do {
        if (*p == 2)
            cnt = (cnt + 1) & 0xFFFF;
        p++;
    } while (--n >= 0);
    if (cnt != 1)
        return 0;
    arr = (Obj1DCC **)(self + 0x3004);
    i = 0;
    while (i < 4) {
        for (j = i + 1; j < 5; j++) {
            if (arr[i]->s->k == arr[j]->s->k) {
                pr[0] = i;
                pr[1] = j;
                break;
            }
        }
        i = j;
    }
    q = arr;
    n = 4;
    do {
        (*q)->flags &= -5;
        q++;
    } while (--n >= 0);
    arr[pr[0]]->flags |= 4;
    arr[pr[1]]->flags |= 4;
    return 1;
}
#endif

// DRAFT: GAME 0x1FC810
// 84 differing words, 368 vs 368 bytes: float-keyed selection sort and filtered copy loop order differs.
#ifdef NONMATCHING
extern "C" void func_001FC810(char *a0, int arg1, int arg2)
{
    char *t0 = *(char **)(a0 + 0x28);
    char *t3;
    int *e;
    float *f;
    int n, i, j, idx;
    unsigned short t6 = 0;
    int *out = (int *)arg1;
    if (t0 != 0 && ((*(int *)t0 & 0x203) ^ 3) == 0) {
        t3 = t0 + 0x38;
        n = *(int *)(t3 + 0xA0);
        if (n > 0) {
            if (n >= 2) {
                e = (int *)t3;
                f = (float *)(t0 + 0x88);
                for (i = 0; i < n - 1; i++) {
                    for (j = i; j < *(int *)(t3 + 0xA0); j++) {
                        if (f[j] < f[i]) {
                            int tmp = e[i];
                            float tf = f[i];
                            e[i] = e[j];
                            f[i] = f[j];
                            e[j] = tmp;
                            f[j] = tf;
                        }
                    }
                }
            }
            t0 = *(char **)(a0 + 0x28);
            if (*(int *)(t0 + 0xD8) > 0) {
                idx = 0;
                for (;;) {
                    int *p;
                    if ((unsigned)idx < (unsigned)*(int *)(t0 + 0x38 + 0xA0))
                        p = (int *)((int *)(t0 + 0x38))[idx];
                    else
                        p = 0;
                    if (p == 0 || ((*p & 0x203) == 3) != 1) {
                        idx++;
                        if (idx >= *(int *)(t0 + 0xD8)) break;
                    } else {
                        out[t6] = (int)p;
                        t6 = (unsigned short)(t6 + 1);
                        if (t6 >= (unsigned short)arg2) break;
                        idx++;
                        if (idx >= *(int *)(t0 + 0xD8)) break;
                    }
                }
            }
        }
    }
}
#endif

// DRAFT: GAME 0x1FFF80
// 83 differing words, 368 vs 376 bytes: flag-test branch layout and the Fade/Message call order differ.
#ifdef NONMATCHING
extern "C" void setDoorJump__5cDoor(char *self)
{
    int flags;
    if (D_00747A84 & 0x2000000) return;
    if (D_00747A24 & 0x100) {
        D_00747A24 &= 0xFFFFFEFF;
    } else {
        closeAll__8cMessage(Message);
    }
    flags = *(int *)(self + 0x18);
    if (flags & 1) {
        start__9classFADEUiUiUiUiUiUi(&Fade, 0, 10, 0, 0xA0A0A0, 0x80A0A0A0, 30);
        D_005CAE40 = 30;
    } else if (flags & 2) {
        start__9classFADEUiUiUiUiUiUi(&Fade, 0, 10, 0, 0, 0xFF000000, 30);
        D_005CAE40 = 30;
    }
    self[0x39] = 0;
    self[0x38] = 0;
    D_00747A84 |= 0x2000000;
    KeyStop__Fv();
    D_00747A78 |= 0x800000 | 0x4000000 | 0x400000 | 0x100000;
    D_00747A80 |= 0x100000;
    *(unsigned *)(g_Sce + 0x48) |= 1;
    if (*(unsigned short *)&D_00747A50 != 0x20) {
        char *pl = (char *)Getplayer__Fv();
        DiscardWeapon__4pl00(pl);
        DiscardThrowObj__4pl00(pl);
        *(float *)(pl + 0x54C) = 1000.0f;
    }
}
#endif

// DRAFT: GAME 0x271298
// 93 differing words, 360 vs 376 bytes: player and target pointer loads are re-read; float compare shape differs.
#ifdef NONMATCHING
extern "C" void func_00271298(char *self)
{
    char *s2;
    char *s1;
    char *s0;
    float f0, f1, f2;
    if (4 < *(unsigned char *)(self + 0x2B4))
        s2 = *(char **)(*(char **)(self + 0x278) + 0x10);
    else
        s2 = 0;
    s1 = (char *)Getplayer__Fv();
    if (!(0.0f < *(float *)(s1 + 0x54C))) {
        if (*(int *)(s1 + 0x6A0) == 0 && s2 != 0) {
            s0 = *(char **)((char *)Getplayer__Fv() + 0xF0);
            f0 = Turn_dest__FPCffT0f((const float *)s0,
                                     *(float *)((char *)Getplayer__Fv() + 0x104),
                                     *(const float **)(s2 + 0xF0), 3.14159265f);
            f1 = (f0 < 0.0f) ? -f0 : f0;
            if (!(0.78539819f < f1)) {
                f1 = ((float *)*(char **)(s1 + 0xF0))[1] - ((float *)*(char **)(self + 0xF0))[1];
                f2 = (f1 < 0.0f) ? -f1 : f1;
                if (!(0.5f < f2)) {
                    if (capVu0MagnitudeSqXZ__FPCfT0(*(const float **)((char *)Getplayer__Fv() + 0xF0),
                                                    *(const float **)(s2 + 0xF0)) < 9.0f) {
                        func_002DC390(self);
                    }
                }
            }
        }
    }
}
#endif
