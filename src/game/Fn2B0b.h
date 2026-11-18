#ifndef GAME_FN2B0B_H
#define GAME_FN2B0B_H

struct MsgT { char _p[0xBDC]; int t[1]; };

extern MsgT *Message;

extern "C" void func_002B4560(void *);
extern "C" void func_00345610(void *);
extern "C" void func_002BB010(void *);
extern "C" void func_00394F20(int);
extern "C" void func_00394D58(int);
extern "C" void func_002BF170(void *);

extern "C" void MtxCopy__FR7cMatrixRC7cMatrix(void *, void *);
extern "C" void _$_8cObjBase(void *);
extern "C" void func_002BE858(void *, int);
extern "C" void func_002B6370(void *);
extern "C" void func_002B8990(void *);
extern "C" void *memset(void *, int, unsigned);
extern "C" void func_002BA428(int, int);
extern "C" void func_002BE510(int, int);
extern "C" void func_002BE560(char *);
extern "C" void func_002BE8E8(int, int);

extern "C" void free__5cHeapPv(void *, void *);
extern int D_005E8600;
extern "C" void func_002BE630(char *, void *, const char *);

class cRelSys {
public:
    enum eRelType { REL_0 };
    void linkNoAlloc(void *, const char *, eRelType);
};

extern "C" void func_0031EEC8(void *, char *);
extern int D_00460D58[], D_00460D60[], D_00460D68[];
extern char D_0044B330[], D_0044BE98[], D_0044BF60[];

extern char GlobalTask;
extern unsigned char D_003C2554;
extern "C" void func_002B6600();
extern "C" void execute__12cTaskManagerRFv_vi(void *, void (*)(), int);

struct SceRoom {
    unsigned short id;
    char _p[0x12];
};
extern SceRoom SceRoomTable[];

extern "C" int func_002B4F98();
extern "C" void func_002D42E0(int);
extern unsigned D_00747A84[];

#endif
