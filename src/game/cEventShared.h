#ifndef CEVENT_SHARED_H
#define CEVENT_SHARED_H

#include "game/cEvent.h"

extern unsigned int D_00747A84;

struct EvPair {
    char _pad0[0x10];
    void *m_p;
    int m_q;
};

struct EvSrc {
    char _pad0[4];
    int m_q;
    char _pad8[8];
    char m_data[1];
};

struct EvTable {
    char _pad0[4];
    char *m_arr;
    char _pad8[8];
    int m_idx;
};

struct EvFlags {
    char _pad0[8];
    unsigned m_flags;
    char _pad[0x14 - 0xC];
};

extern char D_Ev297AA8[];
extern "C" int func_0(char *);
extern int D_Ev297B98;
extern EvTable D_Ev297BF8;

struct EvObj {
    char _pad0[0x250];
    unsigned m_flags;
    char _pad254[0x2FE - 0x254];
    unsigned short m_kind;
};

extern char Event[];
extern char CoreSave[]; // 0x569B70
extern char D_0044A9B0[];
extern char D_0044A9B8[];
extern char D_0044A9D0[];
extern char D_0044A9D8[];
extern "C" int getCostumeNo__9cCoreSave(char *);
extern "C" void setMeshDisplay__6cModelPCcb(EvObj *, char *, int);
extern "C" void displayScrollLayer__FUib(int, int);
extern "C" void func_00298088(EvObj *);
extern "C" void func_00298110(EvObj *, int, int);
extern "C" void func_002981D8(EvObj *, int, int);
extern "C" void func_002982A0(EvObj *);
extern "C" void func_00298338(int, float);
extern "C" void func_002983D0(int, float);
extern "C" void func_00298460();

struct EvQw {
    long lo, hi;
};

struct EvPk {
    EvQw *cur;
    EvQw *start;
    long x8;
    unsigned cnt;
    unsigned short tag;
};

struct EvBuf {
    char _pad[0x10000];
    EvPk pk;
};

struct EvPk2 {
    char _p[0x4080];
    EvQw *cur;
    EvQw *start;
    long x8;
    int cnt;
    char _q[0x24 - 0x14];
    int m_a4, m_a8, m_ac, m_b0;
    char _r[0x48 - 0x34];
    long m_c8;
};

extern "C" void func_002987F8();
extern "C" void func_002988A8();
extern "C" void func_00298A78();
extern "C" void func_00298C18(int);
extern "C" void func_00298EF8(EvObj *, unsigned char);
extern "C" void func_002991D8();

extern "C" void func_00297C80(int *, int);

struct EvCfgEnt {
    int m_0;
    int m_4;
    int m_8;
};

extern EvCfgEnt D_003C0550[];

class cEventConfig {
public:
    void setEventNo(int n);
    EvCfgEnt *m_ent;
    int m_val;
};

class classCFILTER_TAG {
public:
    void initialize();
};

extern unsigned char D_003C0548[3];
extern unsigned char D_003C0549;
extern unsigned char D_003C054A;
extern "C" void func_00298DB8();

extern char D_0044ABE0[];
extern char objbaseArray[];
extern "C" EvObj *SearchOM__13cObjBaseArrayUl(char *, unsigned long);
extern "C" void func_00298CF0();

extern char D_0044AB60[], D_0044AB68[], D_0044AB70[], D_0044AB78[], D_0044AB80[], D_0044AB88[], D_0044AB90[], D_0044AB98[];

extern char Snd[];
extern "C" void *GetBgmData__4cSndi(char *, int);
extern "C" void func_002D0220(void *, int, char *);
extern char D_0044AC00[], D_0044AC08[], D_0044AC10[];

extern char D_0044AC28[], D_0044AC30[];
extern "C" void func_002990A0();
static inline unsigned long KeyOf(char *s)
{
    unsigned long key = 0;
    int i = 0;
    while (i < 8 && s[i]) {
        key |= (long)s[i] << (i * 8);
        i++;
    }
    return key;
}

extern "C" int func_00297AA8();
extern "C" void func_00297B20(void *, void *);
extern "C" void func_00297B40(void *, void *);
extern "C" void func_00297B60(void *, void *);
extern "C" void func_00297BA8();
extern "C" int func_00297B80(char *self);
extern "C" int func_00297B98();
extern "C" void func_00297BF8();
extern "C" void func_00297C88(char *self, short v);
extern "C" void func_00297CA0(EvPair *self, void *p, int q);
extern "C" void func_00297CB0(EvPair *self, EvSrc *src);
extern "C" int func_00298028(char *self, unsigned mask);
extern "C" void func_00297CE8(EvPair *self, void *p, int q);
extern "C" void func_00297CF8(EvPair *self, EvSrc *src);
extern "C" void func_00297D30(EvPair *self, void *p, int q);
extern "C" void func_00297D40(EvPair *self, EvSrc *src);
extern "C" void func_00297D78(EvPair *self, void *p, int q);
extern "C" void func_00297D88(EvPair *self, EvSrc *src);
extern "C" void func_00297DC0(EvPair *self, void *p, int q);
extern "C" void func_00297DD0(EvPair *self, EvSrc *src);
extern "C" void func_00297E08(EvPair *self, void *p, int q);
extern "C" void func_00297E18(EvPair *self, EvSrc *src);
extern "C" void func_00297E50(EvPair *self, void *p, int q);
extern "C" void func_00297E60(EvPair *self, EvSrc *src);
extern "C" void func_00297E98(EvPair *self, void *p, int q);
extern "C" void func_00297EA8(EvPair *self, EvSrc *src);
extern "C" void func_00297EE0(EvPair *self, void *p, int q);
extern "C" void func_00297EF0(EvPair *self, EvSrc *src);
extern "C" void func_00297F28(EvPair *self, void *p, int q);
extern "C" void func_00297F38(EvPair *self, EvSrc *src);
extern "C" void func_00297F70(EvPair *self, void *p, int q);
extern "C" void func_00297F80(EvPair *self, EvSrc *src);
extern "C" void func_00297FB8(EvPair *self, void *p, int q);
extern "C" void func_00297FC8(EvPair *self, EvSrc *src);
extern "C" void func_00298000(int a, int b);
extern "C" void func_00298038();
extern "C" void func_002980E8();
extern "C" void func_002981B0();
extern "C" void func_00298278();
extern "C" void func_00298310();
extern "C" void func_00298388();
extern "C" void func_002987B0();
extern "C" void func_00298A50();
extern "C" void func_00298BF0();
extern "C" void func_00298ED0();
extern "C" void func_002991B0();
extern "C" void func_00299860();
extern "C" void func_00299868(EvBuf *self, long a, long b);
extern "C" void func_00299348(EvBuf *self0);
extern "C" void func_002998A0(EvBuf *self, long a, float x, float y);
extern "C" void func_002998D8(EvBuf *self, int tag, long b);
extern "C" void func_002999D0(EvBuf *self, long a, long b);
extern "C" void func_00299908(EvBuf *self);
extern "C" void func_00298060();
extern "C" void func_00298C58();
extern "C" void func_00298F88();
extern "C" void func_0029FDE0(EvBuf *b, int h);

#endif
