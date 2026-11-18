// 0x1F9CB0: apply loaded save data (time, world time, player vitals).
struct SaveHdr {
    unsigned a;
    unsigned b;
    unsigned c;
    unsigned short d;
    unsigned short e;
};
struct SysT {
    char pad[0x5B4];
    unsigned short t0, t1;
};
extern SysT Sys;
extern char WorldTime[];
extern "C" void *Getplayer__Fv();
extern "C" void func_001F9E00(void *);
extern "C" void func_001F9E68(void *);
extern "C" void func_001F9EB0(void *);
extern "C" void func_001F9F50(void *);
extern "C" void func_002D9D48(void *, int);
extern "C" short getVitalMax__9cCoreSave(void *);
extern "C" int getVital__9cCoreSave(void *);
extern "C" void setGlobalTime__10cWorldTimeUi(void *, unsigned);

// FUNCTION: GAME 0x1F9CB0
extern "C" void func_001F9CB0(SaveHdr **self, int flag)
{
    if (flag) {
        Sys.t0 = (*self)->d;
        Sys.t1 = (*self)->e;
        func_001F9F50(self);
        setGlobalTime__10cWorldTimeUi(WorldTime, (*self)->a);
        func_002D9D48(WorldTime, (*self)->b);
        char *p = (char *)Getplayer__Fv();
        *(short *)(p + 0x548) = getVitalMax__9cCoreSave(self);
        if (getVital__9cCoreSave(self) > 0) {
            p = (char *)Getplayer__Fv();
            int v = getVital__9cCoreSave(self);
            if (v >= *(short *)(p + 0x548))
                *(unsigned short *)(p + 0x54A) = *(unsigned short *)(p + 0x548);
            else
                *(short *)(p + 0x54A) = v;
        } else {
            char *q = (char *)Getplayer__Fv();
            int one = 1;
            if (*(short *)(q + 0x548) <= one)
                *(unsigned short *)(q + 0x54A) = *(unsigned short *)(q + 0x548);
            else
                *(short *)(q + 0x54A) = one;
        }
        func_001F9E00(self);
        func_001F9E68(self);
        func_001F9EB0(self);
    }
}
