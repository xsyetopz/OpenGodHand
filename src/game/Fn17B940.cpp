extern "C" {
extern unsigned char D_00421AD0[];
int func_001B6FB8();
void func_0017C028(void *, int, void *);

// DRAFT: GAME 0x17B940
// 46 words differ: u8 range-flag idiom (spilled u8 + slt/andi 0xFF) and loop mod/idx layout; one variant tried (nested for, i%2, u8 ok flag)
#ifdef NONMATCHING
int func_0017B940(char *self)
{
    func_001B6FB8();
    func_0017C028(self, *(int *)(self + 0xF0), self + 0x100);
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < 5; j++) {
            if (i % 2 == 0) {
                int idx = D_00421AD0[i / 2] + j - 1;
                unsigned char ok = 0;
                if (idx >= 0)
                    ok = idx < *(unsigned char *)(self + 0x2B4);
                char *o = 0;
                if (ok)
                    o = *(char **)(*(char **)(self + 0x278) + idx * 4);
                *(int *)(o + 0x154) |= 0x18;
            }
        }
    }
    return 1;
}
#endif
}
