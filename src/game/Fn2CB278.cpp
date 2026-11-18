#ifdef NONMATCHING
extern unsigned D_00747A84;
extern "C" int func_002CB4E8(int, int);
extern "C" int func_002CB5B8(int);
extern "C" int func_002CB3A8(int, int);
extern "C" int func_002CF6F8(int, int, int);
extern "C" int GetSeData__4cSndi(int, int);

// DRAFT: GAME 0x2CB278
// 12 words differ: original sets s3=-1 after the 4E8 call and puts -1 in the first bnez delay slot, compiled copies the call result into s3; tried early returns, ret var, hoisted -1 local, swapped compare.
extern "C" int func_002CB278(int a, int b)
{
    if (!(D_00747A84 & 0x20000000)) {
        if ((unsigned)(b - 0x200) < 0xFF) {
            if (func_002CB4E8(a, b) == -1) {
                int r = func_002CB5B8(a);
                if (r != -1) {
                    int t = func_002CB3A8(a, b);
                    return func_002CF6F8(GetSeData__4cSndi(a, r), r, t) != 0 ? r : -1;
                }
            }
        }
    }
    return -1;
}
#endif
