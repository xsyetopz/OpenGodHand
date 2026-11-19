extern char Snd[], Dvd[];
extern "C" void *memset(void *, int, unsigned);
extern "C" int free__5cHeapPv(void *, void *);
extern "C" void func_002CBE68(char *, int, int);
extern "C" int func_002CF830(char *);
extern "C" void func_00200F50(char *, int);
extern "C" int func_002CFD38(char *, int);
extern "C" int func_00323000(int);
extern "C" void func_00322F58(void);
extern "C" void func_00375A78(short);
extern "C" void func_003B5A50(int);
extern "C" void func_002CFE48(char *, int);

// FUNCTION: GAME 0x2CF310
extern "C" void func_002CF310(char *self)
{
    func_002CBE68(Snd, *(int *)(self + 0x2C), 0);
    if (!func_002CF830(self)) func_00200F50(Dvd, *(int *)(self + 0x38));
    if (func_002CFD38(self, 4) == 1 && func_002CFD38(self, 8) == 0 && func_00323000(*(int *)(self + 0x28)) == 2)
        func_00322F58();
    if (*(int *)(self + 0x10)) {
        if (!func_002CFD38(self, 0x100)) {
            void *q = *(void **)(self + 0x10);
            void *h = *(void **)(self + 8);
            if (q) free__5cHeapPv(h, q);
        }
        func_00375A78(*(short *)(self + 0x2C));
    }
    if (*(int *)(self + 0x18)) func_003B5A50(*(int *)(self + 0x18));
    if (*(int *)(self + 0x1C)) func_002CFE48(self, *(int *)(self + 0x1C));
    if (*(int *)(self + 0x24)) free__5cHeapPv(*(void **)(self + 8), *(void **)(self + 0x24));
    memset(self, 0, 0x40);
    *(int *)(self + 0x28) = -1;
    *(int *)(self + 0x3C) = -1;
}
