extern "C" void func_00185E68(void *, int);
// FUNCTION: GAME 0x184FE0
extern "C" void func_00184FE0(char *self)
{
    float r = (float)*(short *)(self + 0x626) / (float)*(short *)(self + 0x634);
    switch (*(unsigned char *)(self + 0x659)) {
    case 0:
        if (r <= 0.5f) {
            func_00185E68(self, 1);
            *(unsigned char *)(self + 0x659) += 1;
        }
        break;
    case 1:
        if (r <= 0.0f) {
            func_00185E68(self, 4);
            *(unsigned char *)(self + 0x659) += 1;
        }
        break;
    case 2:
        *(unsigned char *)(self + 0x660) = 1;
        break;
    }
}
