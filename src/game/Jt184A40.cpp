// Jump-table unit; this file holds no other .rodata.
extern "C" void func_001852E8(char *, int);

// DRAFT: GAME 0x184A40 (shared tail matches in shape; delay-slot fill and div.s scheduling differ)
#ifdef NONMATCHING
extern "C" void func_00184A40(char *self)
{
    float r = (float)*(short *)(self + 0x61E) / (float)*(short *)(self + 0x62C);
    int n;
    switch (*(unsigned char *)(self + 0x655)) {
    case 0:
        n = 1; if (r <= 0.75f) goto adv;
        break;
    case 1:
        n = 2; if (r <= 0.5f) goto adv;
        break;
    case 2:
        n = 3; if (r <= 0.25f) goto adv;
        break;
    case 3:
        n = 4;
        if (r <= 0.0f) {
        adv:
            func_001852E8(self, n);
            *(unsigned char *)(self + 0x655) = *(unsigned char *)(self + 0x655) + 1;
        }
        break;
    case 4:
        *(unsigned char *)(self + 0x65C) = 1;
        break;
    }
}
#endif
