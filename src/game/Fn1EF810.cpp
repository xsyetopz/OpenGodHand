extern "C" void func_001EEC68();
extern "C" void func_001EFC48(char *, int);
extern "C" void func_001EFD00(char *);
extern unsigned char D_0074748C;

#ifdef NONMATCHING
// DRAFT: GAME 0x1EF810
// 41 words differ: original compares v1==1 then v1<2 then v1!=0 and shares the increment tail, gcc tests v1==0 first; tried goto tail, case order, unsigned switch, default
extern "C" void func_001EF810(char *self)
{
    switch (*(int *)(self + 8)) {
    case 0:
        if ((D_0074748C >> 2) & 1) {
            func_001EEC68();
            func_001EFC48(self, 0);
            goto next;
        }
        break;
    case 1:
        if ((D_0074748C >> 2) & 1) {
            *(int *)(self + 0x54) |= 1;
            func_001EFD00(self);
        next:
            *(int *)(self + 8) += 1;
        }
        break;
    default:
        break;
    }
}
#endif
