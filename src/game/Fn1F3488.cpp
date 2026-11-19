// Fn1F3488: CustomIDWork display state switch.
extern "C" void ResetColorAnim__12CustomIDWork(void *);
extern "C" void SetChildNoDisp__12CustomIDWorkb(void *, int);
extern "C" void SetColorAnimNormal__12CustomIDWorkG3COLUs(void *, unsigned, unsigned);
extern "C" void SetMoveOffsetPosX__12CustomIDWorkiiUs(void *, int, int, unsigned);
extern "C" void SetNoDisp__12CustomIDWorkb(void *, int);
extern "C" void SetOffsetPosX__12CustomIDWorki(void *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x1F3488
// 3 words differ: case 3 emits daddu a0 before lui a1 (beq vs beql); tried hoisted constant local, p set once, if/else split, swapped case 3 NoDisp/ChildNoDisp calls (5 words)
extern "C" void func_001F3488(char *self, unsigned a)
{
    int s = a & 0xFFFF;
    char *p;
    switch (s) {
    case 0:
    default:
        p = self + 0x980;
        SetOffsetPosX__12CustomIDWorki(p, 0x258);
        ResetColorAnim__12CustomIDWork(p);
        SetNoDisp__12CustomIDWorkb(p, 1);
        SetChildNoDisp__12CustomIDWorkb(p, 1);
        break;
    case 1:
        p = self + 0x980;
        SetOffsetPosX__12CustomIDWorki(p, 0);
        ResetColorAnim__12CustomIDWork(p);
        goto tail;
    case 2:
        p = self + 0x980;
        SetMoveOffsetPosX__12CustomIDWorkiiUs(p, 0x258, 0, 10);
tail:
        SetNoDisp__12CustomIDWorkb(p, 0);
        SetChildNoDisp__12CustomIDWorkb(p, 0);
        break;
    case 3:
        p = self + 0x980;
        SetColorAnimNormal__12CustomIDWorkG3COLUs(p, 0x80000000, 8);
        SetNoDisp__12CustomIDWorkb(p, 0);
        SetChildNoDisp__12CustomIDWorkb(p, 0);
        break;
    }
}
#endif
