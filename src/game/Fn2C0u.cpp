// Mid-size unnamed units in 0x2C0000-0x2E0000 (ee-gcc2.95.3-136, C++).

#ifdef NONMATCHING
// DRAFT: GAME 0x2D0220
// diff: 29 words, return-0 stub placement (orig has stub A shared by ==0x80 and !exist after FileExist, plus separate fail stub, success last; ours merges all return-0 into one). Tried: nested if(exist), swapped success/fail order, != 0x80 wrapper; none better than 24-29
struct Fn2Dw { char _0[8]; char *w8; void *wC; char _10[8]; int w18; void *w1C; int w20; char name[0x40]; };
extern char Dvd[], SoundHeap[], D_0044D0A0[];
extern "C" {
char *strcpy(char *, const char *);
int sprintf(char *, const char *, ...);
int FileExist__4cDvdPCc(char *, char *);
void *ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(char *, char *, void **, char *, int, unsigned, unsigned, unsigned);
void func_002CFF90(Fn2Dw *);
void func_002D0350(Fn2Dw *, int);
}
extern "C" int func_002D0220(Fn2Dw *s, int kind, char *name)
{
    char buf[0x40];
    s->w18 = kind + 0x80;
    s->w8 = SoundHeap;
    s->w20 = -1;
    strcpy(s->name, name);
    if (s->w18 == 0x80) return 0;
    if (s->w18 == 0x81) sprintf(buf, D_0044D0A0, name);
    if (!FileExist__4cDvdPCc(Dvd, buf)) return 0;
    s->w1C = ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(Dvd, buf, &s->wC, s->w8, 0, 0, 0, 0);
    if (!s->w1C || !s->wC) {
        func_002CFF90(s);
        return 0;
    }
    func_002D0350(s, 1);
    return 1;
}
#endif
