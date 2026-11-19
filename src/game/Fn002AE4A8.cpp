// Units 0x2AE4A8 (DllLoad__3cMcb), 0x2B4BE8 (Start__6cMovieib), 0x2CD1D0.

struct McObj { unsigned char unk0; void *unk4; };
struct GT { int p; void *t; };
extern GT GlobalTask;
extern char Dvd[];
extern char SubScrHeap[];
extern int D_00747A30;
extern char D_0044B0B0[], D_0044B0E8[];
extern char D_Ev297AA8[];
extern char D_005E7BF0[], D_005E7D10[];
extern int D_00747A0C, D_00747A80, D_00747A84, D_003C3CD4;

extern "C" {
int Check__4cDvd6eDvdId(void *, int);
void DllRelease__3cMc(void *);
void Move__3cMc(void *);
int ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(void *, char *, void **, void *, int, unsigned, unsigned, unsigned);
void Trans__3cMc(void *);
void func_0(void *);
int func_00394DD8(void *, int);
void sleep__9cTaskWorkUs(void *, unsigned short);
int sprintf(char *, const char *, ...);
int func_002B4F38(void);
int func_002B4F78(void *);
void func_002D3BA8(void *, void *);
}

// FUNCTION: GAME 0x2AE4A8
extern "C" void DllLoad__3cMcb(void *arg0, int arg1)
{
    McObj *o = (McObj *)arg0;
    char name[128];
    int id;
    if (o->unk0 != 1) {
        if (D_00747A30 & 0x400) {
            sprintf(name, D_0044B0B0);
        } else {
            sprintf(name, D_0044B0E8);
        }
        id = ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(Dvd, name, &o->unk4, SubScrHeap, 0, 0, 0, 0);
        if (id != 0) {
            while (Check__4cDvd6eDvdId(Dvd, id)) {
                if (arg1 == 1) {
                    Move__3cMc(arg0);
                    Trans__3cMc(arg0);
                }
                sleep__9cTaskWorkUs(GlobalTask.t, 1);
            }
            if (func_00394DD8(o->unk4, 0)) {
                DllRelease__3cMc(arg0);
                return;
            }
            o->unk0 = 1;
            func_0(D_Ev297AA8);
        }
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2B4BE8 59 words: arg0/idx swapped (orig s1/s2), save order follows; 8 variants tried, none below 59.
extern "C" int Start__6cMovieib(void *arg0, int arg1)
{
    char *self = (char *)arg0;
    int idx = func_002B4F38();
    if (idx < 0) {
        return 0;
    }
    char *p = *(char **)arg0 + idx * 0xAC;
    char *entry;
    int r;
    if (D_00747A0C != 0) {
        entry = D_005E7D10 + arg1 * 0x30;
    } else {
        entry = D_005E7BF0 + arg1 * 0x30;
    }
    func_002D3BA8(p, entry);
    r = func_002B4F78(arg0);
    ((int *)(self +4))[idx] = r;
    if (*(int *)(entry + 0x2C) & 0x20) {
        *(int *)(self +0x18) |= 1 << idx;
        D_00747A80 |= 0x800000;
        D_00747A80 |= 0x80000000;
        D_00747A80 |= 0x40000000;
        D_00747A80 |= 0x20000000;
        D_00747A80 |= 0x10000000;
        D_00747A80 |= 0x1000000;
        D_00747A80 |= 0x4000000;
        D_00747A80 |= 0x8000000;
    }
    D_003C3CD4 = 1;
    D_00747A84 |= 0x2000;
    return ((int *)(self +4))[idx];
}
#endif

struct Fn1D0Obj {
    char pad0[0x98];
    int unk98;
    int unk9C;
    unsigned short unkA0;
    short unkA2;
    char pad1[0xC];
    int unkB0;
    int unkB4;
    char pad2[0x10];
    float unkC8;
};

extern int Snd;
int func_002D0770(int *);

extern "C" {
int func_002CD398(void *);
void func_002CC5E8(void *);
void func_002CD4A8(void *, float);
void func_00373488(void *);
int func_00373770(void *);
void func_00373810(void *, int);
void func_00373858(void *, int);
int func_00373A58(void *);
}

// FUNCTION: GAME 0x2CD1D0
extern "C" void func_002CD1D0(void *arg0)
{
    Fn1D0Obj *o = (Fn1D0Obj *)arg0;
    float t;
    switch (o->unkB0) {
    case 0:
        if (func_002CD398(arg0) == 0) {
            return;
        }
        if (o->unkA0 & 1) {
            func_00373810(arg0, 8);
            o->unkB4 = (int)o->unkA2;
        }
        o->unkB0 = 1;
        /* fallthrough */
    case 1:
        if (!(func_002D0770(&Snd) & o->unk9C)) {
            func_00373858(arg0, 8);
            func_002CD4A8(arg0, 0.0f);
            o->unkB0 = 2;
        }
        if ((o->unk98 & 0x180000) && (func_00373A58(arg0) == 0)) {
            t = o->unkC8 - 1.0f;
            o->unkC8 = t;
            if (t < 0.0f) {
                o->unkC8 = 0.0f;
                func_00373488(arg0);
            }
        }
        /* fallthrough */
    case 2:
        if (func_00373770(arg0) == 0) {
            func_002CC5E8(arg0);
        }
        break;
    }
}
