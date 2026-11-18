struct D4A5D80Ent {
    unsigned a;
    unsigned b;
};
extern D4A5D80Ent D_004A5D80[];

#ifdef NONMATCHING
// DRAFT: GAME 0x155AE8
// ~55 words: original does base+n*0xB0 via mtlo/madd (t-reg copies of a1/a2); gcc emits mult+addu; tried char* arith, (int) arith, -mmad flag
extern "C" void func_00155AE8(char *base, int idx, int n)
{
    char *e = (char *)((int)base + n * 0xB0);
    if (idx >= 0) {
        int i = idx & 0xFF;
        *(long *)(e + 0x70) = (long)(unsigned long)(D_004A5D80[i].b | 0x30000000) | ((long)(D_004A5D80[i].a & 0x0FFFFFFF) << 32);
        *(long *)(e + 0x80) = (long)(unsigned long)(D_004A5D80[i + 1].b | 0x30000000) | ((long)(D_004A5D80[i + 1].a & 0x0FFFFFFF) << 32);
        return;
    }
    int i = idx & 0xFF;
    *(long *)(e + 0x70) = 0x10000000;
    *(long *)(e + 0x80) = (long)(unsigned long)(D_004A5D80[i + 1].b | 0x30000000) | ((long)(D_004A5D80[i + 1].a & 0x0FFFFFFF) << 32);
}
#endif
