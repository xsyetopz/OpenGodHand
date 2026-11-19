// Units at 0x2B0A58, 0x2B0BE0, 0x2CCBF8, 0x308A38, 0x30B298.
extern "C" float func_002B0F20(void *, int, float *);
extern "C" float func_002B1168(void *, int, float *);
extern "C" int func_002B1270(void *, unsigned short *);
extern "C" int func_002B1290(void *);
extern "C" int func_002B12A0(unsigned short *);
extern "C" float func_002B12D8();
extern "C" int func_002A4B88(void *, unsigned short);
extern "C" int func_002A4BA0(void *, unsigned short);
extern void *Font;

// FUNCTION: GAME 0x2B0A58
extern "C" float func_002B0A58(char *self, unsigned short *p, float *f)
{
    unsigned short t = *p;
    float r;
    if ((t >> 15) != 0) {
        switch (t & 0xFF00) {
        case 0xA800:
            r = *f * *(float *)(self + 0x40) * *(float *)(self + 0x48) * 26.0f;
            break;
        case 0x9300:
            r = func_002B0F20(self, func_002B1270(self, p), f);
            break;
        case 0x9400:
            r = func_002B1168(self, func_002B1290(self), f);
            break;
        default:
            r = 0.0f;
            break;
        }
    } else {
        int flag;
        float k;
        if (func_002B12A0(p) != 0) {
            r = func_002B12D8() * (*f * *(float *)(self + 0x40) * (k = *(float *)(self + 0x48)));
            flag = *(int *)self & 1;
        } else {
            r = (float)func_002A4B88(Font, *p) * (*f * *(float *)(self + 0x40) * (k = *(float *)(self + 0x48)));
            flag = *(int *)self & 1;
        }
        if (flag != 0)
            r += (*(float *)(self + 0x38) + 12.0f) * k;
    }
    return r;
}

// FUNCTION: GAME 0x2B0BE0
extern "C" float func_002B0BE0(char *self, unsigned short *p, float *f)
{
    unsigned short t = *p;
    float r;
    if ((t >> 15) != 0) {
        switch (t & 0xFF00) {
        case 0xA800:
            r = *f * *(float *)(self + 0x40) * *(float *)(self + 0x48) * 26.0f;
            break;
        case 0x9300:
            r = func_002B0F20(self, func_002B1270(self, p), f);
            break;
        case 0x9400:
            r = func_002B1168(self, func_002B1290(self), f);
            break;
        default:
            r = 0.0f;
            break;
        }
    } else {
        int flag;
        float k;
        if (func_002B12A0(p) != 0) {
            r = func_002B12D8() * (*f * *(float *)(self + 0x40) * (k = *(float *)(self + 0x48)));
            flag = *(int *)self & 1;
        } else {
            r = (float)func_002A4BA0(Font, *p) * (*f * *(float *)(self + 0x40) * (k = *(float *)(self + 0x48)));
            flag = *(int *)self & 1;
        }
        if (flag != 0)
            r += (*(float *)(self + 0x38) + 12.0f) * k;
    }
    return r;
}
