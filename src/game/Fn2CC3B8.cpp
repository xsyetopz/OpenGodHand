extern "C" {
int func_002C9C88(void *);
void func_002CC500(void *);
void func_002CDA08(void *);
void func_002CF2D0(void *);
void func_002CFF30(void *);
extern char D_005FEFF0[], D_005FFCF0[], D_005FFD80[], D_00601180[], Snd[];
}

// FUNCTION: GAME 0x2CC3B8
extern "C" void func_002CC3B8(int a, int b) {
    if (b == 0xFFFF && a != 0) {
        func_002C9C88(Snd);
        int i1 = 0x33;
        char *p1 = D_005FEFF0;
        do { i1--; func_002CF2D0(p1); p1 += 0x40; } while (i1 != -1);
        int i2 = 1;
        char *p2 = D_005FFCF0;
        do { i2--; func_002CFF30(p2); p2 += 0x44; } while (i2 != -1);
        int i3 = 0x3F;
        char *p3 = D_005FFD80;
        do { i3--; func_002CDA08(p3); p3 += 0x50; } while (i3 != -1);
        int i4 = 0xF;
        char *p4 = D_00601180;
        do { i4--; func_002CC500(p4); p4 += 0xDC; } while (i4 != -1);
    }
}
