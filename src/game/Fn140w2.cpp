// FUNCTION: GAME 0x155D60
extern "C" void func_00155D60(char *self, long a, int idx)
{
    int n = *(unsigned char *)(self + 0x385);
    do {
    } while (--n);
    *(long *)(self + idx * 0xB0 + 0x30) = a;
}

// FUNCTION: GAME 0x1C2558
class cOmItem {
public:
    char _p[0x668];
    long blk;
    void setBlockObj(const char *);
};
void cOmItem::setBlockObj(const char *s)
{
    long v = 0;
    int i = 0;
    if (*s) {
        do {
            long c = *s;
            int sh = i * 8;
            i++;
            s++;
            v |= c << sh;
        } while (i < 8 && *s);
    }
    blk = v;
}
