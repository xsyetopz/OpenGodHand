// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" int func_001B6FB8(char *);
extern "C" void setTexChange__7cOmBaseUi(char *, unsigned);

#ifdef NONMATCHING
// DRAFT: GAME 0x1C8FF0 - 25 words: original calls setTexChange separately in case 0x3E4 (gcc here merges it into the shared call); 3E5 stores 0 then jumps to the call with a0 in the delay slot; tried goto/break/explicit-return forms, default first (23-28 words)
extern "C" int Initialize__8cOmTrumpQ28cOmTrump9eNumberId(char *self, int n)
{
    int v;
    func_001B6FB8(self);
    switch (*(unsigned short *)(self + 0x2FE)) {
    case 0x3E4:
        *(int *)(self + 0x600) = 4;
        setTexChange__7cOmBaseUi(self, 0);
        *(int *)(self + 0x604) = n;
        return 1;
    case 0x3E5:
        *(int *)(self + 0x600) = 0;
        goto call;
    case 0x3E6: v = 1; break;
    case 0x3E7: v = 2; break;
    case 0x3E8: v = 3; break;
    default:
        return 0;
    }
    *(int *)(self + 0x600) = v;
call:
    setTexChange__7cOmBaseUi(self, n);
    *(int *)(self + 0x604) = n;
    return 1;
}
#endif
