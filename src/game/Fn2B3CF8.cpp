extern "C" int BgmEventStart__4cSnd9eBgmReqNoii(void *, unsigned short, int, int);
extern char Snd[];
struct S3 { char pad[0x8C]; struct { short a; unsigned short b; } *p; };
#ifdef NONMATCHING
// DRAFT: GAME 0x2B3CF8
// 26 differing words: original switch on id has dead li 6/0x2F, empty switch is eliminated by gcc (sq/lq frame differs).
extern "C" int func_002B3CF8(char *self) {
    unsigned short id = (*(unsigned short **)(self + 0x8C))[1];
    BgmEventStart__4cSnd9eBgmReqNoii(Snd, id, 0, 0);
    switch (id) {
    case 0xB:
        break;
    case 0x2E:
        break;
    }
    *(short *)(self + 0x2E) = 0x1E;
    return 0;
}
#endif
