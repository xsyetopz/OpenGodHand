// Jump-table switch unit (own file: its .rodata must be exactly the table).
struct EmW { unsigned char id; } __attribute__((aligned(16)));
extern char g_EmSet[];
extern "C" void func_001EF978(char *);
extern "C" int func_001EF8B8(char *);
extern "C" void setEm__11cEmSetParamUc(char *, unsigned char);
extern "C" void StartAction__7cEmWrap(EmW *);

#define EMCASE(k)                                                  \
    case k:                                                        \
        if (*(int *)(self + 0xBA0) == 0 || !func_001EF8B8(self)) { \
            w.id = k;                                              \
            setEm__11cEmSetParamUc(g_EmSet, k);                    \
            StartAction__7cEmWrap(&w);                             \
            *(int *)(self + 0xB8C) += 1;                           \
            *(int *)(self + 0xBA0) = 0x168;                        \
            *(int *)(self + 0xB94) += 1;                           \
        } else {                                                   \
            *(int *)(self + 0xBA0) -= 1;                           \
        }                                                          \
        break;

// FUNCTION: GAME 0x1F1EE0
extern "C" void func_001F1EE0(char *self)
{
    EmW w;
    switch (*(unsigned *)(self + 0xB94)) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xBA0) = 0x168;
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
