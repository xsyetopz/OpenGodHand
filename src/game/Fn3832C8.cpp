extern "C" {
void func_0032A6D0(int, int, short);
int func_0032DCD0(int, int);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3832C8  44 words; gcc strength-reduces the short* index; variants: hoisted bases, array index, for-loop
extern "C" void func_003832C8(int, char *p, int flag) {
    if (flag & 0xFF) {
        char *q = p + 0xA4;
        char *b1 = p + 0x1C, *b2 = p + 0x26;
        int i;
        for (i = 0; i < *(int *)(q + 8);) {
            int n = i + 1;
            int r = func_0032DCD0(*(int *)(q + 0x20), i);
            i = n;
            func_0032A6D0(r, 0, *(short *)(b1 + n * 2));
            func_0032A6D0(r, 1, *(short *)(b2 + n * 2));
        }
    } else {
        char *q = p + 0x34;
        func_0032A6D0(*(int *)(q + 0x30), 0, *(short *)(p + 0x1C));
        func_0032A6D0(*(int *)(q + 0x30), 1, *(short *)(p + 0x26));
    }
}
#endif
