// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern char g_EmSet[];
extern unsigned char D_00586AA5;
extern "C" void func_001EF978(char *);
extern "C" void setEm__11cEmSetParamUc(char *, unsigned char);
extern "C" void StartAction__7cEmWrap(unsigned char *);

#define EMCASE(k)                                          \
    case k:                                                \
        if (*(int *)(self + 0xBA0) == 0) {                 \
            D_00586AA5 = 0;                                \
            unsigned char w = k;                           \
            setEm__11cEmSetParamUc(g_EmSet, k);            \
            StartAction__7cEmWrap(&w);                     \
            *(int *)(self + 0xB8C) += 1;                   \
            *(int *)(self + 0xBA0) = 0xF0;                 \
            *(int *)(self + 0xB94) += 1;                   \
        } else {                                           \
            *(int *)(self + 0xBA0) -= 1;                   \
        }                                                  \
        break;

// FUNCTION: GAME 0x1F0A28
extern "C" void func_001F0A28(char *self)
{
    switch (*(unsigned *)(self + 0xB94)) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xBA0) = 0xF0;
        *(int *)(self + 0xB94) += 1;
        break;
    EMCASE(1)
    EMCASE(2)
    EMCASE(3)
    EMCASE(4)
    EMCASE(5)
    EMCASE(6)
    EMCASE(7)
    }
}
