// Jump-table unit; this file holds no other .rodata.
extern "C" void *func_0030F578(unsigned);
extern "C" void EmClothInit__F6eObjIdP4cObjP8PEN_INFOP10CLOTH_INFO(int, void *, void *, void *);

// FUNCTION: GAME 0x28CDD0
extern "C" void func_0028CDD0(char *self)
{
    switch (*(int *)(self + 0x564)) {
    case 0x214:
    case 0x215:
    case 0x21C:
    case 0x223:
    case 0x243:
    case 0x244:
    case 0x250:
    case 0x251:
    case 0x252:
    case 0x256:
    case 0x270:
    case 0x271:
    case 0x272:
    case 0x273:
    case 0x274: {
        char *q = (char *)func_0030F578(0x1B80);
        char *v = q;
        for (int n = 0x2B; n != -1; n--) {
            __asm__ volatile("sqc2 $vf0,0x0(%0)\n\tsqc2 $vf0,0x10(%0)\n\tsqc2 $vf0,0x30(%0)\n\tsqc2 $vf0,0x40(%0)\n\tsqc2 $vf0,0x50(%0)\n\tsqc2 $vf0,0x80(%0)" : : "r"(q) : "memory");
            q += 0xA0;
        }
        *(char **)(self + 0x1630) = v;
        if (v)
            EmClothInit__F6eObjIdP4cObjP8PEN_INFOP10CLOTH_INFO(*(int *)(self + 0x564), self, v, self + 0x15B0);
    }
    }
}
