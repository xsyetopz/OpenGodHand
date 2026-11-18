// Jump-table unit; this file holds no other .rodata.
extern "C" void displayScrollLayer__FUib(unsigned, int);
extern "C" int GetOliviaCostumeNo__9cCoreSave(void *);
extern char CoreSave[];

// FUNCTION: GAME 0x2987F8
extern "C" void func_002987F8(unsigned a, float x)
{
    if (x == 0.0f) {
        switch (a) {
        case 0:
        case 14:
        case 23:
            displayScrollLayer__FUib(0x1E, 0);
            displayScrollLayer__FUib(0x1F, 0);
            break;
        case 13:
        case 22:
            if (GetOliviaCostumeNo__9cCoreSave(CoreSave)) {
                displayScrollLayer__FUib(0x1E, 0);
                displayScrollLayer__FUib(0x1F, 1);
            } else {
                displayScrollLayer__FUib(0x1E, 1);
                displayScrollLayer__FUib(0x1F, 0);
            }
            break;
        }
    }
}
