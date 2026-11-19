extern char Dvd[];
extern "C" int Check__4cDvd6eDvdId(void *, int);
extern "C" int func_001FF540(char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x1FF238
// 10 words differ: r==2 branch layout (original bnel-less beq + b); tried if/else chains, switch, nested else, merged-tail fallthrough (28), && form (15), ok-flag (12), goto set (15)
extern "C" int func_001FF238(char *self)
{
    if (*(int *)(self + 8) & 1) {
        int r = Check__4cDvd6eDvdId(Dvd, *(int *)(self + 0x1C));
        if (r == 1)
            return 0;
        if (r == 0)
            *(int *)(self + 8) &= ~1;
        else {
            if (r == 2)
                return 0;
        }
    }
    if (*(int *)(self + 0x20) == 0xFFFF || func_001FF540(self) != 0) {
        *(int *)self = 2;
        return 1;
    }
    return 0;
}
#endif
