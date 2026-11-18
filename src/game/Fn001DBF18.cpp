struct Inner001DBF18 {
    char pad[0x600];
    int kind;
};

struct Obj001DBF18 {
    Inner001DBF18 *inner;
};

// FUNCTION: GAME 0x1DBF18
extern "C" void func_001DBF18(char *self, unsigned short *c0, unsigned short *c1, unsigned short *c2, unsigned short *c3)
{
    *c0 = 0;
    *c1 = 0;
    *c2 = 0;
    *c3 = 0;
    Obj001DBF18 **p = (Obj001DBF18 **)(self + 0x3004);
    for (int i = 0; i < 5; i++) {
        switch ((*p++)->inner->kind) {
        case 0:
        default:
            (*c0)++;
            break;
        case 1:
            (*c1)++;
            break;
        case 2:
            (*c2)++;
            break;
        case 3:
            (*c3)++;
            break;
        }
    }
}
