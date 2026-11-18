// Fn1F3488: CustomIDWork display state switch.
extern "C" void ResetColorAnim__12CustomIDWork(void *);
extern "C" void SetChildNoDisp__12CustomIDWorkb(void *, int);
extern "C" void SetColorAnimNormal__12CustomIDWorkG3COLUs(void *, unsigned, unsigned);
extern "C" void SetMoveOffsetPosX__12CustomIDWorkiiUs(void *, int, int, unsigned);
extern "C" void SetNoDisp__12CustomIDWorkb(void *, int);
extern "C" void SetOffsetPosX__12CustomIDWorki(void *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x1F3488
extern "C" void func_001F3488(char *self, unsigned a)
{
    unsigned s = a & 0xFFFF;
    char *p = self + 0x980;
    if (s != 1) {
        switch (s) {
        case 3:
            SetColorAnimNormal__12CustomIDWorkG3COLUs(p, 0x80000000, 8);
            SetNoDisp__12CustomIDWorkb(p, 0);
            SetChildNoDisp__12CustomIDWorkb(p, 0);
            return;
        default:
            SetOffsetPosX__12CustomIDWorki(p, 0x258);
            ResetColorAnim__12CustomIDWork(p);
            SetNoDisp__12CustomIDWorkb(p, 1);
            SetChildNoDisp__12CustomIDWorkb(p, 1);
            return;
        case 2:
            SetMoveOffsetPosX__12CustomIDWorkiiUs(p, 0x258, 0, 10);
            goto tail;
        }
    } else {
        SetOffsetPosX__12CustomIDWorki(p, 0);
        ResetColorAnim__12CustomIDWork(p);
tail:
        SetNoDisp__12CustomIDWorkb(p, 0);
        SetChildNoDisp__12CustomIDWorkb(p, 0);
    }
}
#endif
