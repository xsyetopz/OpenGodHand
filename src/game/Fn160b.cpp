// Small units in .text 0x160000-0x16FFFF: two-state setters, loops over child pointers and effect starters.
extern "C" void move__7cIDBase(void *);
extern "C" void func_001614D0(void *);
extern "C" int SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, void *, void *, int, unsigned);

// FUNCTION: GAME 0x161B30
extern "C" void func_00161B30(char *self)
{
    switch (*(unsigned char *)(self + 0x64)) {
    case 0:
        *(int *)(self + 0x60) = 10;
        break;
    case 1:
        *(int *)(self + 0x60) = -1;
        break;
    }
}

// FUNCTION: GAME 0x162720
extern "C" void func_00162720(char *self)
{
    switch (*(unsigned char *)(self + 0x64)) {
    case 0:
        *(int *)(self + 0x60) = 10;
        break;
    case 1:
        *(int *)(self + 0x60) = -1;
        break;
    }
}

// FUNCTION: GAME 0x1661A0
extern "C" void func_001661A0(char *self)
{
    move__7cIDBase(self + 0x100);
    move__7cIDBase(self + 0x180);
    move__7cIDBase(self + 0x230);
}

// FUNCTION: GAME 0x167328
extern "C" void func_00167328(char *self)
{
    int **p = (int **)(self + 0x80);
    unsigned i = 0;
    do {
        int *o = *p;
        i++;
        p++;
        o[0x2C / 4] |= 0x8000000;
    } while (i < 0x18);
}

// FUNCTION: GAME 0x167EE8
extern "C" void func_00167EE8(char *self)
{
    int **p = (int **)(self + 0x80);
    unsigned i = 0;
    do {
        int *o = *p;
        i++;
        p++;
        o[0x2C / 4] |= 0x8000000;
    } while (i < 0x10);
}

// FUNCTION: GAME 0x167F70
extern "C" void func_00167F70(char *self)
{
    func_001614D0(self);
    *(unsigned char *)(self + 0x5A) = 0;
    *(unsigned char *)(self + 0x5B) = 0;
    *(unsigned char *)(self + 0x5C) = 0;
    *(unsigned char *)(self + 0x5D) = 0;
    *(unsigned char *)(self + 0x90) = 0;
}

// FUNCTION: GAME 0x16F608
extern "C" void func_0016F608(char *self)
{
    if (*(int *)(self + 0x5EC))
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(*(int *)(self + 0x5F0), *(int *)(self + 0x5EC), self, 0, -1, 0xFFFFFFFF);
}

// FUNCTION: GAME 0x16F900
extern "C" void func_0016F900(char *self)
{
    if (*(int *)(self + 0x5EC))
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(*(int *)(self + 0x5F0), *(int *)(self + 0x5EC), self, 0, -1, 0xFFFFFFFF);
}

// FUNCTION: GAME 0x16EDE0
extern "C" void func_0016EDE0(char *self)
{
    switch (*(unsigned char *)(self + 0x64)) {
    case 0:
        *(int *)(self + 0x60) = -1;
        break;
    case 1:
        *(int *)(self + 0x60) = 10;
        break;
    }
}
