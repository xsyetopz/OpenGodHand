// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" void func_00185BD0(char *, int);
extern "C" void func_00185CB8(char *, int);

// FUNCTION: GAME 0x184E60
// DIVNOP: 2
extern "C" void func_00184E60(char *self)
{
    float r = (float)*(short *)(self + 0x624) / (float)*(short *)(self + 0x632);
    switch (*(unsigned char *)(self + 0x658)) {
    case 0:
        if (r <= 0.95f) {
            func_00185BD0(self, 1);
            *(unsigned char *)(self + 0x658) += 1;
        }
        break;
    case 1:
        if (r <= 0.9f) {
            func_00185BD0(self, 4);
            *(unsigned char *)(self + 0x658) += 1;
        }
        break;
    case 2:
        if (r <= 0.75f) {
            func_00185CB8(self, 1);
            *(unsigned char *)(self + 0x658) += 1;
        }
        break;
    case 3:
        if (r <= 0.5f) {
            func_00185CB8(self, 2);
            *(unsigned char *)(self + 0x658) += 1;
        }
        break;
    case 4:
        if (r <= 0.25f) {
            func_00185CB8(self, 3);
            *(unsigned char *)(self + 0x658) += 1;
        }
        break;
    case 5:
        if (r <= 0.0f) {
            func_00185CB8(self, 4);
            *(unsigned char *)(self + 0x658) += 1;
        }
        break;
    case 6:
        *(unsigned char *)(self + 0x65F) = 1;
        break;
    }
}
