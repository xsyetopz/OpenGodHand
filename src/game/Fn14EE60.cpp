extern "C" int func_0031ED08(float);
extern "C" int setMotionInfo__FP8cObjBaseUiUiUiffUs(char *, int, int, int, float, float, unsigned short);
extern "C" int moveMotion__FP8cObjBase(char *);
extern "C" void GetEulerXYZ__C10QuaternionR4cVec(char *, char *);
extern "C" void func_001506F0(int, char *);

// FUNCTION: GAME 0x14EE60
extern "C" void func_0014EE60(char *s)
{
    switch ((unsigned char)s[0x2F6]) {
    case 0:
        setMotionInfo__FP8cObjBaseUiUiUiffUs(s, *(int *)(s + 0x428), *(int *)(s + 0x42C), func_0031ED08(*(float *)(s + 0x438)), *(float *)(s + 0x440), *(float *)(s + 0x430), *(unsigned short *)(s + 0x434));
        s[0x2F6] = (unsigned char)s[0x2F6] + 1;
    case 1:
        if (moveMotion__FP8cObjBase(s)) s[0x2F6]++;
        GetEulerXYZ__C10QuaternionR4cVec(s + 0x340, s + 0x100);
        func_001506F0(*(int *)(s + 0xF0), s + 0x310);
        break;
    case 2:
        moveMotion__FP8cObjBase(s);
        GetEulerXYZ__C10QuaternionR4cVec(s + 0x340, s + 0x100);
        func_001506F0(*(int *)(s + 0xF0), s + 0x310);
        break;
    }
}
