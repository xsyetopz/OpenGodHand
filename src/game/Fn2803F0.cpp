struct sObjA {
    char _0[0x2F4];
    char b4, b5;
    unsigned char st, f7;
    char _2f8[0x304 - 0x2F8];
    char *tbl;
};
extern char Snd;
extern "C" void func_002A8578(void *, void *, void *, int, int);
extern "C" short GetSeqSEBase__FP8cObjBase(void *);
extern "C" void SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, short, void *);
extern "C" int moveMotion__FP8cObjBase(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x2803F0
// 56 words differ (180 vs 264 bytes): unfinished first transcription, switch/prologue and extern linkage (GetSeqSEBase mismatched target) not worked; no variants tried.
extern "C" void func_002803F0(sObjA *o)
{
    switch (o->st) {
    case 0: {
        char *t = o->tbl;
        func_002A8578(o, t + *(int *)(t + 0x100), t + *(int *)(t + 0x104), 2, 0);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(&Snd, 1, GetSeqSEBase__FP8cObjBase(o), o);
        o->st++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(o) != 0) {
            o->f7 = 0;
            o->b4 = 0;
            o->b5 = 0;
            o->st = 0;
        }
        return;
    }
}
#endif
