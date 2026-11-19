// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern char Dvd[];
extern char D_00580D40[];
extern int D_00752C38[];
extern "C" int FileNameFromObjId__FPc6eObjId(char *, int);
extern "C" int func_001FFA28(char *, char *);
extern "C" int func_00200B88(char *, char *, int, int, int, int, int);
extern "C" void func_00201108(char *, int);

// FUNCTION: GAME 0x30D8E0
extern "C" void func_0030D8E0(int id)
{
    char name[16];
    int id2 = 0x101;
    switch (id) {
    case 0x100:
        break;
    case 0x109:
        id2 = 0x10A;
        break;
    case 0x105:
    case 0x10F:
        id2 = 0x106;
        break;
    case 0x107:
    case 0x110:
        id2 = 0x108;
        break;
    case 0x10E:
    case 0x111:
        id2 = 0x112;
        break;
    }
    FileNameFromObjId__FPc6eObjId(name, id);
    func_001FFA28(D_00580D40, name);
    int r = func_00200B88(Dvd, name, D_00752C38[0], 0, 0, 0, 0);
    func_00201108(Dvd, r);
    FileNameFromObjId__FPc6eObjId(name, id2);
    func_001FFA28(D_00580D40, name);
    func_00200B88(Dvd, name, D_00752C38[1], r, 0, 0, 0);
    func_00201108(Dvd, r);
}
