extern "C" int sprintf(char *, const char *, ...);

struct ObjIdEnt {
    char name[4];
    int id;
};
extern ObjIdEnt D_003C2F88[];
extern const char D_0044C2B8[];
extern const char D_0044C2C0[];

enum eObjId { OBJID_0 };

class cScenario {
public:
    void getStrFromObjId(char *buf, eObjId id);
};

#ifdef NONMATCHING
// DRAFT: GAME 0x2C4D50
// 2 words: lui a1 (format) and addiu v1 (id ptr) swapped in preheader; tried hoisted fmt, decl reorder, ip from name+4, ip=&id, ObjIdEnt* walk (worse).
void cScenario::getStrFromObjId(char *buf, eObjId id)
{
    char *name = D_003C2F88[0].name;
    int hi = id & 0xFF00;
    unsigned int i = 0;
    int *ip = (int *)(name + 4);
    do {
        i++;
        if (hi == *ip) {
            sprintf(buf, D_0044C2B8, name, id & 0xFF);
            return;
        }
        name += 8;
        ip += 2;
    } while (i < 5);
    sprintf(buf, D_0044C2C0, name, id);
}
#endif
