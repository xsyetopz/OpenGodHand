struct Ent {
    char pad[6];
    short v;
    char pad2[12];
};
extern Ent D_003F21E8[], D_003F2368[], D_003F24D0[];
extern char D_0045B758[], D_0045B760[];
extern "C" void func_002E0DE8(int, int, int, const char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x00379838 -- ~40 words differ: orig shares mult/lh tail with per-case lb 0x25 and pre-shifted s; tried per-case switch, goto tail, int s

extern "C" void func_00379838(char *self)
{
    short s = 3;
    switch (self[7]) {
    case 0:
        s = D_003F21E8[self[0x25]].v + 3;
        break;
    case 1:
        s = D_003F2368[self[0x25]].v + 3;
        break;
    case 2:
        s = D_003F24D0[self[0x25]].v + 3;
        break;
    }
    func_002E0DE8(0x19, s, 0xC, D_0045B758);
    func_002E0DE8(0x2E, s, 0xC, D_0045B760);
}
#endif
