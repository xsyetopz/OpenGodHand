extern "C" void func_00161590(void *self);
extern "C" void func_001615F0(void *self);
extern "C" void release__7cIDBase(void *self);
struct sInner168080 {
    char _pad0[0xB0];
    int m_b0;
    int m_b4;
};
struct sIDSys168080 {
    sInner168080 *m_inner;
};
extern sIDSys168080 *IDSys;

#ifdef NONMATCHING
// DRAFT: GAME 0x168080
// 3 differing words: IDSys lui/lw use v1/v0 in original, v0/v1 here; tried struct/ptr-ptr forms, local copy, store order.
extern "C" void func_00168080(unsigned char *self)
{
    func_001615F0(self);
    if (self[0x64] == 1)
        self[0x90] = 0;
    release__7cIDBase(self);
    sIDSys168080 *s = IDSys;
    sInner168080 *in = s->m_inner;
    in->m_b4 = 0;
    in->m_b0 = 0;
    func_00161590(self);
}
#endif
