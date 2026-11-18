// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" int getGameLevel__9cCoreSave(char *);
extern "C" void setGameLevel__9cCoreSavei(char *, int);
extern unsigned D_00747A84;

// FUNCTION: GAME 0x1FA558
extern "C" void GameLevelUp__9cCoreSave(char *self)
{
    if (*(int *)self != 0 && (D_00747A84 & 0x400000) == 0) {
        switch (getGameLevel__9cCoreSave(self)) {
        case 1:
        default: setGameLevel__9cCoreSavei(self, 2); break;
        case 2: setGameLevel__9cCoreSavei(self, 3); break;
        case 3: setGameLevel__9cCoreSavei(self, 5); break;
        case 4: setGameLevel__9cCoreSavei(self, 5); break;
        case 5: return;
        }
        *(*(char **)self + 0x1E) = 2;
    }
}
