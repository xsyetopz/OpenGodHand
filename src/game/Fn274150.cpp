extern unsigned short D_00747A50;
extern char g_SceAt;
extern "C" int func_002C2490(void *, int, void *);

// DRAFT: GAME 0x274150
// 13 words differ (branch layout of the 0x260/0x26A early-return chain and the final ==1 test); tried flat || chain (45), range as && (38), int r=1 pre-set (worse), int ret single exit (56), != 1 early return (13)
#ifdef NONMATCHING
extern "C" int func_00274150(char *self)
{
    if (D_00747A50 == 0x200 || D_00747A50 == 0x204) {
        int s = *(int *)(self + 0x564);
        if (s == 0x260)
            return 0;
        if (s >= 0x261) {
            if (s < 0x264) {
            } else if (s < 0x266) {
                return 0;
            } else if (s == 0x26A) {
                return 0;
            }
        } else if (s < 0x224) {
            if (s >= 0x220)
                return 0;
        }
        if (0.0f < *(float *)(self + 0x1734))
            return 0;
        if (func_002C2490(&g_SceAt, *(int *)(self + 0xF0), self + 0x6C0) == 1) {
            *(float *)(self + 0x1734) = 300.0f;
            return 1;
        }
        return 0;
    }
    return 0;
}
#endif
