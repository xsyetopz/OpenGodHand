// BGM table slot update by state; sole switch of SetBgmTbl.
extern char Snd[];
struct BgmEnt { unsigned short id; int v[5]; };
extern BgmEnt D_003C3138[];
extern "C" void SetBgmState__4cSnd9eBgmState(void *, int);

// DRAFT: GAME 0x2D0AC0 - 8 words differ: gcc if-converts the search to movz; original uses beql and copies the table base into v1
#ifdef NONMATCHING
extern "C" void SetBgmTbl__FUs9eBgmReqNo9eBgmState(unsigned short id, int val, int state)
{
    BgmEnt *found = 0;
    BgmEnt *p = D_003C3138;
    do {
        if (p->id == id)
            found = p;
        p++;
    } while (p < D_003C3138 + 44);
    if (found) {
        SetBgmState__4cSnd9eBgmState(Snd, state);
        switch (state) {
        case 0:
            found->v[0] = val;
            break;
        case 1:
            found->v[1] = val;
            break;
        case 2:
            found->v[2] = val;
            break;
        case 3:
            found->v[3] = val;
            break;
        case 4:
            found->v[4] = val;
            break;
        }
    }
}
#endif
