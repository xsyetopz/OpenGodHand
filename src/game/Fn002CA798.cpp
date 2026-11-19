extern "C" void *GetSeData__4cSndi(void *, int);
extern "C" void *GetBgmData__4cSndi(void *, int);
extern "C" void func_002CF310(void *);
extern "C" void func_002CB638(void *, int, void *);
extern "C" int func_002CB778(void *, int);
extern "C" void func_002D5250(int);
extern "C" void func_002CFF90(void *);
extern "C" void func_002D0128(void *, int, int);
extern "C" int func_002CFF78(void *);
extern "C" int func_002CFF68(void *);
extern char D_0044CE28[];
extern char D_0044CE30[];

#ifdef NONMATCHING
// DRAFT: GAME 0x2CA798
// 2 differing words: a2=0 / a0=v0 order before func_002D0128 call; tried temp, arg types int/unsigned/long/void*/float
extern "C" void func_002CA798(void *snd)
{
    func_002CF310(GetSeData__4cSndi(snd, 0));
    func_002CB638(snd, 0, D_0044CE28);
    while (!func_002CB778(snd, 0)) func_002D5250(1);
    func_002CF310(GetSeData__4cSndi(snd, 3));
    func_002CB638(snd, 3, D_0044CE30);
    while (!func_002CB778(snd, 3)) func_002D5250(1);
    func_002CFF90(GetBgmData__4cSndi(snd, 0));
    func_002D0128(GetBgmData__4cSndi(snd, 0), 0, 0);
    if (func_002CFF78(GetBgmData__4cSndi(snd, 0)) != 1) {
        while (!func_002CFF68(GetBgmData__4cSndi(snd, 0))) func_002D5250(1);
    }
}
#endif
