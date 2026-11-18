extern "C" void *func_002CC4C8(void *, int);
extern "C" void func_002CDA48(void *);
extern "C" void *GetSeData__4cSndi(void *, int);
extern "C" void func_002CF310(void *);
extern "C" void *func_002D2DB0(void *, int);
extern "C" void func_002CC578(void *);
extern "C" void *GetBgmData__4cSndi(void *, int);
extern "C" void func_002CFF90(void *);

// FUNCTION: GAME 0x2CA148
extern "C" void func_002CA148(char *self)
{
    *(int *)(self + 0x1C) = 0;
    for (int i = 0; i < 0x40; i++)
        func_002CDA48(func_002CC4C8(self, i));
    for (int i = 0; i < 0x34; i++)
        func_002CF310(GetSeData__4cSndi(self, i));
    *(int *)(self + 0x18) = 0;
    for (int i = 0; i < 0x10; i++)
        func_002CC578(func_002D2DB0(self, i));
    for (int i = 0; i < 2; i++)
        func_002CFF90(GetBgmData__4cSndi(self, i));
}
