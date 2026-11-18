// God Hand: units in 0x280000-0x2A0000
extern char D_Ev297AA8[];
extern char D_Ev297BF8[];
extern "C" int func_0(char *);

class cEvent {
public:
    void startCreateWork();
};

// FUNCTION: GAME 0x2979F0
void cEvent::startCreateWork()
{
    if (!func_0(D_Ev297AA8) || !func_0(D_Ev297BF8))
        ((unsigned *)this)[2] |= 0x10000000;
    else {
        func_0(D_Ev297BF8);
        func_0(D_Ev297BF8);
    }
}

struct sRS { int *p; };
extern sRS g_RoomSave;
extern "C" void func_002BEDC8(sRS *, int);
extern "C" void func_002BEDE8(sRS *, int, int *);
extern "C" void func_00295600(int *);
// FUNCTION: GAME 0x294B98
extern "C" int func_00294B98(int *self, int *p)
{
    unsigned m = 0x80000000;
    if (*g_RoomSave.p >= 0) {
        if (!p)
            return 0;
        self[2] = (int)p;
        if (p[0] != 0x534D45) {
            self[2] = 0;
            return 0;
        }
        if (p[1] == 0) {
            func_002BEDC8(&g_RoomSave, 0);
            *(unsigned *)g_RoomSave.p |= m;
            self[2] = 0;
            return 0;
        }
        self[3] = (int)(p + 3);
        func_002BEDE8(&g_RoomSave, p[1], p + 3);
        func_00295600(self);
        *(unsigned *)g_RoomSave.p |= m;
    }
    return 1;
}
