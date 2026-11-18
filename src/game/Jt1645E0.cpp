// Jump-table unit; this file holds no other .rodata.
extern char CoreSave[];
extern "C" int ckClearStage__9cCoreSaveUs(void *, unsigned short);

// FUNCTION: GAME 0x1645E0
extern "C" void func_001645E0(char *self)
{
    unsigned short n = 1;
    while (n < 9 && ckClearStage__9cCoreSaveUs(CoreSave, n))
        n++;
    n--;
    switch (n) {
    case 1: *(unsigned short *)(self + 0x134) = 0x200; break;
    case 2: *(unsigned short *)(self + 0x134) = 0x300; break;
    case 3: *(unsigned short *)(self + 0x134) = 0x400; break;
    case 4: *(unsigned short *)(self + 0x134) = 0x500; break;
    case 5: *(unsigned short *)(self + 0x134) = 0x600; break;
    case 6: *(unsigned short *)(self + 0x134) = 0x700; break;
    case 7: *(unsigned short *)(self + 0x134) = 0x802; break;
    case 8: *(unsigned short *)(self + 0x134) = 0x806; break;
    }
}
