// Jump-table unit; this file holds no other .rodata.
extern "C" void func_001852E8(char *, int);

// FUNCTION: GAME 0x184A40
// DIVNOP: 2
extern "C" void func_00184A40(char *self)
{
    float r = (float)*(short *)(self + 0x61E) / (float)*(short *)(self + 0x62C);
    switch (*(unsigned char *)(self + 0x655)) {
    case 0:
        if (r <= 0.75f) {
            func_001852E8(self, 1);
            *(unsigned char *)(self + 0x655) = *(unsigned char *)(self + 0x655) + 1;
        }
        break;
    case 1:
        if (r <= 0.5f) {
            func_001852E8(self, 2);
            *(unsigned char *)(self + 0x655) = *(unsigned char *)(self + 0x655) + 1;
        }
        break;
    case 2:
        if (r <= 0.25f) {
            func_001852E8(self, 3);
            *(unsigned char *)(self + 0x655) = *(unsigned char *)(self + 0x655) + 1;
        }
        break;
    case 3:
        if (r <= 0.0f) {
            func_001852E8(self, 4);
            *(unsigned char *)(self + 0x655) = *(unsigned char *)(self + 0x655) + 1;
        }
        break;
    case 4:
        *(unsigned char *)(self + 0x65C) = 1;
        break;
    }
}
