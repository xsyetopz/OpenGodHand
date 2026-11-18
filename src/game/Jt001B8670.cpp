// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern char CoreSave[];
extern "C" int getGameLevel__9cCoreSave(char *);

// FUNCTION: GAME 0x1B8670
extern "C" void func_001B8670(char *self)
{
    switch (getGameLevel__9cCoreSave(CoreSave)) {
    case 1:
    default: *(float *)(self + 0x604) = 600.0f; break;
    case 2: *(float *)(self + 0x604) = 500.0f; break;
    case 3: *(float *)(self + 0x604) = 400.0f; break;
    case 4: *(float *)(self + 0x604) = 400.0f; break;
    case 5: *(float *)(self + 0x604) = 300.0f; break;
    }
}
