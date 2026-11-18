// Virtual dispatch for selected command ids; sole switch of 0x160B90.
struct JtV30 {
    char _p[0x30];
    short adj;
    short _pad;
    void (*fn)(void *);
};
extern int D_00747A2C[];
extern "C" void func_00160D50(void *);
extern "C" char *func_00161288(void *);

// FUNCTION: GAME 0x160B90
extern "C" void func_00160B90(char *self)
{
    if (D_00747A2C[0] < 0)
        return;
    if (D_00747A2C[0x50 / 4] & 0x100000)
        return;
    func_00160D50(self);
    char *o = func_00161288(self);
    if (!o)
        return;
    if (*(unsigned char *)(o + 0x59))
        return;
    unsigned short *hp = (unsigned short *)(self + 0x50);
    int t = *hp - 4;
    switch ((short)t) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 6:
    case 10:
    case 13: {
        JtV30 *v = *(JtV30 **)(o + 0x70);
        v->fn(o + v->adj);
        break;
    }
    case 3:
    case 5:
    case 7:
    case 8:
    case 9:
    case 11:
    case 12:
    default:
        break;
    }
}
