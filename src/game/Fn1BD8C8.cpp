extern "C" void initMove1_pos__6cOmSubP4cObjiUiRC4cVecff(char *, char *, int, unsigned, const void *, float, float);
extern "C" void initMove3_y__6cOmSubP4cObjiRC4cVecfff(char *, char *, int, const void *, float, float, float);
extern "C" int move__6cOmSub(char *);
extern char ZeroVec[];

// FUNCTION: GAME 0x1BD8C8
extern "C" void func_001BD8C8(char *self)
{
    float v[4];
    switch (*(unsigned char *)(self + 0x2F5)) {
    case 0:
        if (*(unsigned char *)(self + 0x774) == 0) {
            *(unsigned char *)(self + 0x2F7) = 0;
            goto clr;
        }
        if (*(int *)(self + 0x778) == 0) {
            initMove3_y__6cOmSubP4cObjiRC4cVecfff(self + 0x610, self, -1, ZeroVec, -0.02f, -*(float *)(self + 0x770), 0.2f);
        } else {
            v[0] = 0;
            v[1] = *(float *)(self + 0x770);
            v[2] = 0;
            v[3] = 1.0f;
            initMove1_pos__6cOmSubP4cObjiUiRC4cVecff(self + 0x610, self, -1, 30, v, 0.2f, 0.2f);
        }
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x775) = 1;
        *(unsigned char *)(self + 0x2F5) = 1;
        *(unsigned char *)(self + 0x2F7) = 0;
    case 1:
        if (move__6cOmSub(self + 0x610) == 0) {
            *(unsigned char *)(self + 0x2F7) = 0;
            *(unsigned char *)(self + 0x774) = 0;
            *(unsigned char *)(self + 0x775) = 0;
        clr:
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F4) = 0;
        }
    }
}
