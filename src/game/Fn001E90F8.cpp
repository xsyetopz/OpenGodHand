extern "C" {
void *memset(void *, int, unsigned);
void func_001ECA80(char *);
void func_001ED548(char *);
void func_001EDE38(char *);
void func_001EE768(char *);
}

// FUNCTION: GAME 0x1E90F8
extern "C" char *__7DogRace(char *self)
{
    memset(self, 0, 0x54);
    *(int *)(self + 0x54) = 0;
    char *p = self + 0x5C;
    int i = 4;
    do {
        func_001EE768(p);
        i--;
        p += 0x40;
    } while (i != -1);
    func_001ECA80(self + 0x210);
    func_001ED548(self + 0x1840);
    func_001EDE38(self + 0x1B90);
    *(int *)(self + 0x200) = 0;
    *(unsigned short *)(self + 0x1B0) = 0xFFFF;
    int *c = (int *)(self + 0x1C4);
    int *a = (int *)(self + 0x19C);
    int *b = (int *)(self + 0x1EC);
    int j;
    for (j = 9; j >= 0; j--) c[j] = 0;
    for (j = 4; j >= 0; j--) a[j] = 0;
    for (j = 4; j >= 0; j--) b[j] = 0;
    return self;
}
