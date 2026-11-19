// Unnamed units in slice F159 (free units: 0x2D82A0, 0x3001D0, 0x3066D0, 0x380720).

#ifdef NONMATCHING
// DRAFT: GAME 0x380720
// 31 differing words (184 vs 188 bytes). The original is one instruction longer than this if-form.
// Tried: else-form (31), deferred stores (31), hoisted v/6000 (31), ms-first store (31),
// else-form with deferred stores (44), else-form with ms-first (45), v/6000 split (46).
extern "C" void func_00380720(int, int a1, int a2, int *h, int *m, int *s, int *ms)
{
    int v = 0;
    if (a1 > 0 || a2 > 0) {
        v = (int)((float)a2 / (float)a1 * 100.0f);
    }
    int hh = v / 360000;
    int mm = v / 6000 - hh * 60;
    int ss = v / 100 - hh * 3600 - mm * 60;
    *h = hh;
    *m = mm;
    *s = ss;
    *ms = v % 100;
}
#endif
