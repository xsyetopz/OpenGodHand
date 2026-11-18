// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" char *getMeshPtr__6cModelPCc(void *, const char *);
extern "C" int getGameLevel__9cCoreSave(void *);
extern const char D_004479A0[];
extern char CoreSave[];

// DRAFT: GAME 0x2760C0
// 40 words: switch compiles to a compare chain not the jump table; orig stores 300.0f before the getGameLevel call (reg not kept across it); tried pre-store (f20 hoist), xori form, case grouping.
#ifdef NONMATCHING
extern "C" void offSunglass__5cEm00b(char *self)
{
    if ((*(int *)(self + 0x564) ^ 0x256) == 0) {
        char *m = getMeshPtr__6cModelPCc(self, D_004479A0);
        if (m) {
            *(unsigned *)(m + 0x380) |= 1;
        }
        *(unsigned *)(self + 0x16D4) |= 0x4000000;
        *(int *)(self + 0x174C) = 0;
        switch (getGameLevel__9cCoreSave(CoreSave)) {
        case 1:
        default:
            *(float *)(self + 0x1750) = 300.0f;
            break;
        case 2:
            *(float *)(self + 0x1750) = 450.0f;
            break;
        case 3:
        case 4:
        case 5:
            *(float *)(self + 0x1750) = 600.0f;
            break;
        }
        *(unsigned char *)(self + 0x2F7) = 0;
        *(unsigned char *)(self + 0x2F5) = 0x8D;
        *(unsigned char *)(self + 0x2F4) = 0;
        *(unsigned char *)(self + 0x2F6) = 0;
    }
}
#endif
