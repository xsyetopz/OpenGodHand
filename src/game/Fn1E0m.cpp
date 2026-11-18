extern "C" void Main__12CustomIDWork(void *);
extern "C" void move__7cIDBase(void *);

// FUNCTION: GAME 0x1E73C0
extern "C" void func_001E73C0(char *self)
{
    char *p = self + 0x580;
    int i;
    for (i = 1; i >= 0; i--, p += 0x7C)
        Main__12CustomIDWork(p);
    move__7cIDBase(self + 0x530);
    p = self + 0x50;
    for (i = 9; i >= 0; i--, p += 0x7C)
        Main__12CustomIDWork(p);
    move__7cIDBase(self);
}

extern unsigned D_00747A2C[];
extern char CoreSave;
extern "C" void addGold__9cCoreSaveib(void *, int, int);
extern "C" int getGold__9cCoreSave(void *);
extern "C" void func_001ED490(void *, int);

// FUNCTION: GAME 0x1EC8A8
extern "C" void func_001EC8A8(char *self)
{
    if (D_00747A2C[0] & 0x200) {
        if (*(unsigned long *)((char *)D_00747A2C - 0x3DC) & (0xCC00UL << 26)) {
            addGold__9cCoreSaveib(&CoreSave, 1000, 0);
            func_001ED490(self + 0x210, getGold__9cCoreSave(&CoreSave));
        }
    }
}

// FUNCTION: GAME 0x1F6AF8
extern "C" void func_001F6AF8(int *self)
{
    int i = self[3] + 1;
    int *p;
    for (p = self + 4 + i; i < 4; i++, p++) {
        if (*p != 0) {
            self[3] = i;
            return;
        }
    }
    for (i = 0, p = self + 4; i < self[3]; i++, p++) {
        if (*p != 0) {
            self[3] = i;
            return;
        }
    }
}
