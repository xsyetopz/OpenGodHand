// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" void *Getplayer__Fv();
extern "C" unsigned irand__Fv();
extern "C" int func_0012C748(void *);
extern "C" int func_0026F1D8(void *);
extern "C" int getGameLevel__9cCoreSave(void *);
extern char CoreSave[];
extern unsigned char D_005CB010;

struct Eh {
    char _pad0[0x2F4];
    unsigned char m_2F4;
    unsigned char m_2F5;
    unsigned char m_2F6;
    unsigned char m_2F7;
    char _pad1[0x3AC - 0x2F8];
    unsigned short m_3AC;
    char _pad2[0x5A8 - 0x3AE];
    float m_5A8;
    char _pad3[0x698 - 0x5AC];
    char *m_698;
    char _pad4[0x760 - 0x69C];
    float m_760;
    char _pad5[0x1740 - 0x764];
    float m_1740;
    char _pad6[0x17AC - 0x1744];
    int m_17AC;
    char _pad7[0x17BC - 0x17B0];
    unsigned char m_17BC;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x20CAC8 - 53 words (mostly branch offsets): gcc shares the `sltiu a0,a0,1` tail across the level arms and stores m_2F4..m_2F7 in a different order.
extern "C" int func_0020CAC8(Eh *self, int arg)
{
    void *pl = Getplayer__Fv();
    switch (self->m_17BC) {
    case 0:
    default:
        return 0;
    case 1:
        if (irand__Fv() & 1)
            return 0;
    case 2:
        break;
    }
    if (D_005CB010)
        return 0;
    if (func_0012C748(pl))
        return 0;
    if (func_0026F1D8(self))
        return 0;
    unsigned f = self->m_3AC;
    if (f & 0x100)
        return 0;
    if (self->m_17AC <= 0)
        return 0;
    if (self->m_760 > 2.3561945f)
        return 0;
    if (self->m_5A8 < 1.0f)
        return 0;
    if (self->m_1740 > 0.0f)
        return 0;
    if (f & 8)
        return 0;
    if (f & 0x20)
        return 0;
    if (f & 4)
        return 0;
    int s = *(short *)(*(char **)&self->m_698 + 0x46);
    if (s < 0x17)
        return 0;
    if (s > 0x18 && s != 0x1B)
        return 0;
    int r;
    switch (getGameLevel__9cCoreSave(CoreSave)) {
    case 1:
    default:
        r = (irand__Fv() & 7) == 0;
        break;
    case 2:
        r = irand__Fv() % 6 == 0;
        break;
    case 3:
    case 4:
        r = (irand__Fv() & 3) == 0;
        break;
    case 5:
        r = irand__Fv() % 3 == 0;
        break;
    }
    if (arg == 1)
        r = 1;
    if (!r)
        return 0;
    self->m_2F7 = 0;
    self->m_2F5 = 0x46;
    self->m_2F4 = 0;
    self->m_2F6 = 0;
    return 1;
}
#endif
