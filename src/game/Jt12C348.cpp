// Jump-table unit; this file holds no other .rodata.
extern unsigned D_00747A2C;
extern unsigned D_00747A04;
extern char g_ps2[];
extern "C" void Pad_act_set__13classPAD_WORKUiUi(void *, unsigned, unsigned);

#define ACT(m) Pad_act_set__13classPAD_WORKUiUi(g_ps2, 0x3FF0000, (m) << D_00747A04)

// FUNCTION: GAME 0x12C348
extern "C" void func_0012C348(void *self, unsigned idx)
{
    if (D_00747A2C & 0x8000000)
        return;
    switch (idx) {
    case 0:
    default: ACT(0x40000); break;
    case 1: ACT(0x60000); break;
    case 2: ACT(0xA0000); break;
    case 3: ACT(0xE0000); break;
    case 4: Pad_act_set__13classPAD_WORKUiUi(g_ps2, 0x3280000, 0x20000 << D_00747A04); break;
    }
}
