#ifndef CSND_H
#define CSND_H

class cSnd;

enum eBgmState { eBgmState_0 };
enum eBgmReqNo { eBgmReqNo_0 };

struct sHitBe {
    char _pad0[4];
    float m_ver;
    unsigned short m_count;
};

struct sHitEntry {
    char _pad0[0x28];
    signed char m_id;
    unsigned char m_flag;
    char _pad2A[0x6C - 0x2A];
};

class cSeData {
public:
    int IsAlive();

    char _pad0[0x3C];
    int m_unk3C;
    char _pad40[0x40 - 0x40];
};

struct sBgmHead {
    unsigned m_count;
};

struct sBgmTbl {
    char _pad0[0xB];
    unsigned char m_unkB;
    char _padC[0x11 - 0xC];
    unsigned char m_unk11;
    unsigned char m_unk12;
};

class cBgmData {
public:
    sBgmHead *GetHeadPtr();
    sBgmTbl *GetTblPtr(int i);

    char _pad[0x44];
};

struct sBgmNode {
    char _pad0[0x5E];
    unsigned char m_unk5E;
    char _pad5F;
    unsigned char m_unk60;
    char _pad61[0x88 - 0x61];
    sBgmNode *m_next;
    int m_kind;
    int m_a;
    int m_b;
    int m_flags;
    char _pad9C[0xB0 - 0x9C];
    int m_state;
};

enum eBgmPt { eBgmPt_0 };
enum eObjId { eObjId_0 };
enum eSeBlk { eSeBlk_0 };
enum eSndId { eSndId_0 };

extern int D_0044CE48[12];
extern char D_0044D100[];
extern unsigned int D_00747A84;

extern "C" {
void func_002CC628(sBgmNode *);
int func_00373A78(sBgmNode *);
void func_002D0EA0(cSnd *);
int strcmp(const char *, const char *);
int func_002D1DD0(cSnd *, int, int);
void *func_002CBEC0(cSnd *);
int func_002CDF18(void *, short, short, short, short, unsigned, int);
int func_002CDE28(void *, short, short, float *, unsigned, int);
void func_002CD470(sBgmNode *, float);
int func_002CB3A8(cSnd *, eObjId);
int func_002CFC88(cSeData *);
void func_002CCAC8(sBgmNode *);
int func_002CC900(void *, int, int, int, unsigned, int, int);
void func_00373A18(void *, int);
void *func_002CBF48(cSnd *, eSndId);
int func_00375050(eSndId, int);
void func_002D0658(cSnd *, unsigned, int, float);
void func_002D0728(cSnd *, unsigned, float);
void func_002CD500(sBgmNode *, int, float);
void func_002CD4A8(sBgmNode *, float);
void *func_002D2228(cSnd *);
void *func_002D22B0(cSnd *, int, int);
void func_002CCB10(void *);
void func_00373488(sBgmNode *);
int func_00373A58(sBgmNode *);
float func_00373938(void *, int);
void func_00373560(void *, int, float);
void func_002CD4E0(void *, float, float);
int func_002CFF78(cBgmData *);
int func_002CFF68(cBgmData *);
int func_002CC9C0(void *, int, int, int, unsigned, int, int);
void func_002CFF90(cBgmData *);
void func_002D0128(cBgmData *, int, unsigned);
}

class cSnd {
public:
    cSeData *GetSeData(int i);
    void SetBgmState(eBgmState s);
    void SetBgmLevel(int a, eBgmReqNo b, int c, float f);
    cBgmData *GetBgmData(int i);

    int SeEndCk(eSndId id);
    void SetBgmTblNo(unsigned a, int b);
    void SetBgmDefAttr(unsigned a, float f);
    int SeFadeOut(eSndId id, short t);
    void SeStop(eSndId id);
    void BattleBgmAllPause(float f);
    void BgmEventSet(eBgmReqNo r, int a, int b);
    void BgmEvDataInit(unsigned a);
    void BgmEvAllSuspend(float f);
    void DieDemoStart();
    void BgmControl();
    void BgmEvReStart(eBgmPt a, eBgmReqNo b, int c);
    void BgmEvFadeSet(eBgmPt a, eBgmReqNo b, float x, float y, float z);
    void BgmHitBeSet(bool b, unsigned short id);
    void BgmEvCutSet(int x);
    int BgmEvCutCheck(int x);
    int SeCall(eSeBlk b, short s1, short s2, short s3, unsigned u, int i);
    int SeCall(eSeBlk b, short s, float *f, unsigned u, int i);
    int EmSeCheck(eObjId id);
    void BgmEventStart(eBgmReqNo r, int a, int b);
    void BgmEventStop(bool b);
    int BgmEvStart(eBgmPt a, eBgmReqNo b, int c);
    void BgmEvDataEnd();
    int BgmEvDataCheck();
    int BgmEvSet(eBgmPt a, eBgmReqNo b);
    void BgmEvPause(eBgmPt a, eBgmReqNo b);
    void BgmFadeOutAll(float f, eBgmPt a, eBgmReqNo b);
    void BgmEventFade(eBgmReqNo r, float a, float b, float c);

    char _pad0[0x18];
    sBgmNode *m_bgmList;
    char _pad1C[0x24 - 0x1C];
    sHitBe *m_hitBe;
    char _pad28[0x3C - 0x28];
    cSeData *m_seData;
    cBgmData *m_bgmData;
    char _pad44[0xAC - 0x44];
    unsigned m_flagsAC;
    unsigned m_flagsB0;
    char _padB4[0x118 - 0xB4];
    int m_bgmLvA;
    int m_bgmLvB;
    int m_bgmLvC;
    float m_bgmLvF;
    int m_unk128;
    char _pad12C[0x138 - 0x12C];
    int m_unk138;
    int m_bgmState;
    eSndId m_seSlot[8];
};

#endif
