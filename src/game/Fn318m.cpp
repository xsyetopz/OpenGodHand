// Game functions at 0x318000-0x31C000, matched byte-identically.
extern "C" {
void calcParts__6cModel(void *);
void calcWorldParts__6cModel(void *);
void InverseKinematics__2IKP8cObjBase(void *, void *);
}

// FUNCTION: GAME 0x318468
extern "C" void func_00318468(char *self)
{
    if (!(*(int *)(self + 0x250) & 2)) {
        calcParts__6cModel(self);
        if (*(int *)(self + 0x258) >= 0) {
            InverseKinematics__2IKP8cObjBase(self + 0x448, self);
            calcWorldParts__6cModel(self);
        }
    }
}

extern "C" {
void Pad_act_all_stop__13classPAD_WORK(char *);
void func_0031BC98(char *, int);
void func_0031BD78(char *, int);
void func_00398128(int, int, char *);
extern char D_00747A2C[], D_00747A24[];
}

// FUNCTION: GAME 0x31BB80
extern "C" void func_0031BB80(char *self)
{
    char *h = self + 0x160;
    int i = 0;
    *(char *)(self + 0x360) = 0;
    *(char *)(self + 0x361) = 0;
    if ((*(unsigned *)D_00747A2C & 0x8000000) || !*(unsigned char *)(self + 0x4B8)) {
        Pad_act_all_stop__13classPAD_WORK(self);
    } else if (!(*(unsigned *)(D_00747A2C + 0x4C) & 0x4000000)) {
        for (; (unsigned)i < 0x20; i++, h += 0x10) {
            if (!(*(unsigned char *)h & 3))
                continue;
            if (*(unsigned short *)(h + 4)) {
                *(unsigned short *)(h + 4) = *(unsigned short *)(h + 4) - 1;
            } else if (*(unsigned short *)(h + 6)) {
                func_0031BC98(self, i);
                *(unsigned short *)(h + 6) = *(unsigned short *)(h + 6) - 1;
            } else {
                func_0031BD78(self, i);
            }
        }
    }
    if (!(*(unsigned *)D_00747A24 & 0x20000000))
        func_00398128(0, 0, self + 0x360);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x31B4B8 (16 words off: source in original sb order; scheduler still hoists the 0x6A sb ahead of the sd stores and a0/a3 load regs swap; moving 6A/7A around tried)
extern "C" void func_0031B4B8(void *, unsigned long *p)
{
    const unsigned long m = 0xF00807FF00000UL;
    unsigned long a = p[8] & m;
    unsigned long b = p[7] & m;
    unsigned long c = p[5] & m;
    unsigned long d = p[6] & m;
    unsigned long e = p[3] & m;
    unsigned char *q = (unsigned char *)p;
    p[8] = a;
    p[7] = b;
    p[0] = e;
    p[5] = c;
    p[6] = d;
    q[0x6B] = 0x80;
    q[0x7B] = 0;
    q[0x68] = 0x80;
    q[0x69] = 0x80;
    q[0x6F] = 0;
    q[0x6E] = 0;
    q[0x6C] = 0;
    q[0x6D] = 0;
    q[0x70] = 0;
    q[0x73] = 0;
    q[0x71] = 0;
    q[0x72] = 0;
    q[0x74] = 0;
    q[0x75] = 0;
    q[0x76] = 0;
    q[0x77] = 0;
    q[0x78] = 0;
    q[0x79] = 0;
    q[0x7A] = 0;
    q[0x6A] = 0x80;
}
#endif
