// FUNCTION: GAME 0x2755E0
extern "C" void setDevilFlag__5cEm00(char *self)
{
    switch (*(int *)(self + 0x564)) {
    case 0x208: case 0x209: case 0x20B: case 0x20E: case 0x213: case 0x214:
    case 0x215: case 0x217: case 0x21C: case 0x21F: case 0x220: case 0x221:
    case 0x222: case 0x223: case 0x250: case 0x251: case 0x252: case 0x256:
    case 0x260: case 0x264: case 0x265: case 0x26A: case 0x270: case 0x271:
    case 0x272: case 0x273: case 0x274: case 0x275: case 0x276: case 0x278:
    case 0x279: case 0x27E:
        return;
    }
    *(unsigned *)(self + 0x16D0) |= 0x200;
    *(unsigned *)(self + 0x16D4) |= 0x1000000;
}

class cFnA;
typedef void (cFnA::*cFnAPmf)();
class cFnA {
public:
    virtual void v();
    char pad[0x2F5];
    unsigned char type;
};
struct PmfTbl2 { cFnAPmf p[2]; };
extern PmfTbl2 D_00447D28;
extern PmfTbl2 D_00448170;
extern PmfTbl2 D_004482B8;

// FUNCTION: GAME 0x279678
extern "C" void func_00279678(cFnA *self)
{
    PmfTbl2 t = D_00447D28;
    if (self->type >= 2)
        self->type = 0;
    (self->*t.p[self->type])();
}

// FUNCTION: GAME 0x27D000
extern "C" void func_0027D000(cFnA *self)
{
    PmfTbl2 t = D_00448170;
    if (self->type >= 2)
        self->type = 0;
    (self->*t.p[self->type])();
}

// FUNCTION: GAME 0x27E4E8
extern "C" void func_0027E4E8(cFnA *self)
{
    PmfTbl2 t = D_004482B8;
    if (self->type >= 2)
        self->type = 0;
    (self->*t.p[self->type])();
}
