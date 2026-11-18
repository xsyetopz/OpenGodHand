typedef int (*Handler)(char *, char *, void *, char *);
extern Handler D_003F2628[];
extern char D_003F21E8[];
extern char D_003F2368[];
extern char D_003F24D0[];

#ifdef NONMATCHING
// DRAFT: GAME 0x37A740
// 17 words; switch value kept in a0 in original (ours v1), and return-0 tail via beqz instead of bnel; tried 4-arg handler (helped), t temp, r flag
extern "C" int func_0037A740(char *self)
{
    signed char t = *(signed char *)(self + 7);
    char *e = 0;
    switch (t) {
    case 0:
        e = D_003F21E8 + *(signed char *)(self + 0x25) * 0x14;
        break;
    case 1:
        e = D_003F2368 + *(signed char *)(self + 0x25) * 0x14;
        break;
    case 2:
        e = D_003F24D0 + *(signed char *)(self + 0x25) * 0x14;
        break;
    }
    if (*(int *)(self + 0x38) & 0xF000) {
        D_003F2628[*(signed char *)(e + 9)](self, e, D_003F2628, self);
        return 1;
    }
    return 0;
}
#endif
