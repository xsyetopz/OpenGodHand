// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" void *Getplayer__Fv();
extern "C" int CkSubScreen__4pl00(void *);
extern "C" int ckAtkActBtnEnable__4pl00(void *);

struct Ja { char _p[0x1C]; unsigned m_1C; };

// FUNCTION: GAME 0x1F7050
extern "C" int func_001F7050(Ja *self)
{
    switch (self->m_1C) {
    case 0: case 1: case 2: case 6: case 8: case 9: case 10: case 11: case 14:
    case 21: case 23: case 24: case 25: case 28: case 29: case 30: case 31:
    case 32: case 34: case 35: case 36: case 39: case 40: case 41: case 42:
    case 43: case 44: case 45: case 46: case 47:
        return CkSubScreen__4pl00(Getplayer__Fv());
    case 3: case 4: case 5: case 7: case 12: case 13: case 15: case 16: case 17:
    case 18: case 22: case 26: case 33: case 38:
        return ckAtkActBtnEnable__4pl00(Getplayer__Fv());
    case 19: case 20: case 27: case 37: case 50:
        return 1;
    default:
        return 0;
    }
}
