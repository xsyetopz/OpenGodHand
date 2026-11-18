// Jump-table unit; this file holds no other .rodata.
extern "C" void func_00185910(char *, int);
extern "C" void func_00185A20(char *, int);

// FUNCTION: GAME 0x184CE0
// DIVNOP: 2
extern "C" void func_00184CE0(char *self)
{
    float r = (float)*(short *)(self + 0x622) / (float)*(short *)(self + 0x630);
    switch (*(unsigned char *)(self + 0x657)) {
    case 0:
        if (r <= 0.95f) {
            func_00185910(self, 1);
            *(unsigned char *)(self + 0x657) = *(unsigned char *)(self + 0x657) + 1;
        }
        break;
    case 1:
        if (r <= 0.9f) {
            func_00185910(self, 4);
            *(unsigned char *)(self + 0x657) = *(unsigned char *)(self + 0x657) + 1;
        }
        break;
    case 2:
        if (r <= 0.75f) {
            func_00185A20(self, 1);
            *(unsigned char *)(self + 0x657) = *(unsigned char *)(self + 0x657) + 1;
        }
        break;
    case 3:
        if (r <= 0.5f) {
            func_00185A20(self, 2);
            *(unsigned char *)(self + 0x657) = *(unsigned char *)(self + 0x657) + 1;
        }
        break;
    case 4:
        if (r <= 0.25f) {
            func_00185A20(self, 3);
            *(unsigned char *)(self + 0x657) = *(unsigned char *)(self + 0x657) + 1;
        }
        break;
    case 5:
        if (r <= 0.0f) {
            func_00185A20(self, 4);
            *(unsigned char *)(self + 0x657) = *(unsigned char *)(self + 0x657) + 1;
        }
        break;
    case 6:
        *(unsigned char *)(self + 0x65E) = 1;
        break;
    }
}
