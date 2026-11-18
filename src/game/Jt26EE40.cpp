// Jump-table unit (own file: its .rodata must be exactly the two tables).
extern "C" int getGameLevel__9cCoreSave(void *);
extern "C" void func_00292018(void *, int);
extern char CoreSave[];
extern char g_EmManage[];

// FUNCTION: GAME 0x26EE40
extern "C" void func_0026EE40(char *self, int a1, int a2)
{
    switch (getGameLevel__9cCoreSave(CoreSave) - 1) {
    case 0:
    case 1:
    default:
        a1 = a1 / 2;
        break;
    case 2:
    case 3:
        a1 = a1 / 4;
        break;
    case 4:
        a1 = 0;
        break;
    }
    if (a1 < 0) a1 = 0;
    *(int *)(self + 0x16DC) = a1;
    switch (getGameLevel__9cCoreSave(CoreSave) - 1) {
    case 0:
    case 1:
    default:
        a2 = a2 / 2;
        break;
    case 2:
    case 3:
        a2 = a2 / 4;
        break;
    case 4:
        a2 = 0;
        break;
    }
    if (a2 > 0) func_00292018(g_EmManage, a2);
}
