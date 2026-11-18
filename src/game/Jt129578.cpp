// Costume-dependent effect start; sole switch and jump table of 0x129578.
extern char CoreSave[];
extern "C" int getCostumeNo__9cCoreSave(char *);
extern "C" int SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, void *, void *, int, unsigned);

// FUNCTION: GAME 0x129578
extern "C" void func_00129578(char *self)
{
    int f = *(int *)(self + 0x15F4);
    if (f & 0x20) {
        *(int *)(self + 0x15F4) = f & ~0x20;
        switch (getCostumeNo__9cCoreSave(CoreSave)) {
        case 0:
        case 2:
        case 4:
        case 6:
        default:
            SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0, 0x19, self, 0, -1, 0xFFFFFFFF);
            break;
        case 1:
        case 3:
        case 5:
        case 7:
            SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0, 0x75, self, 0, -1, 0xFFFFFFFF);
            break;
        }
    }
    *(unsigned char *)(self + 0x649) = 0;
}
