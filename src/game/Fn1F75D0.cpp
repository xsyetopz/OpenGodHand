extern "C" void func_001F6F58(int);
extern "C" void func_001F7228(void *);
#ifdef NONMATCHING
// DRAFT: GAME 0x001F75D0
// DRAFT: orig keeps base copy in s2, off in s1, counter s3 (no CSE of base+0x104 with ptr) and materializes ==1 bool (xori/sltiu); tried ==1==1, ok var, struct array
extern "C" void func_001F75D0(int base) {
    int off;
    unsigned int i;
    char *p;
    p = (char *)(base + 0x104);
    off = 0;
    i = 0;
    do {
        if (((*(unsigned *)p & 0x201) == 1) == 1) {
            if (*(int *)(p + 0x24) != 3) {
                func_001F7228(p);
            } else {
                func_001F6F58(base + (off + 0x104));
            }
        }
        i += 1;
        off += 0x44;
        p += 0x44;
    } while (i < 8U);
}
#endif
