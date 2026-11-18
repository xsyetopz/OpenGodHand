#ifndef CEVCMD_H
#define CEVCMD_H
// Event script command handlers (.text 0x2B0000 range).

struct cEvCmdData {
    unsigned short m_op;
    unsigned short m_arg;
    short m_s4;
};

struct cEvNode {
    unsigned short m_h0;
    short m_h2;
    cEvNode *m_prev;
    cEvNode *m_next;
};

struct cEvCmd {
    char _pad0[0xC];
    unsigned char m_c;
    unsigned char m_d;
    unsigned char m_e;
    unsigned char m_f;
    int m_10;
    int m_flags;
    int m_18;
    int m_1c;
    int m_20;
    unsigned short m_24[2];
    unsigned short m_28;
    char _pad2A[2];
    unsigned char m_2c;
    unsigned char m_2d;
    unsigned short m_2e;
    signed char m_30;
    unsigned char m_31;
    char _pad32[2];
    int m_34;
    unsigned short m_38;
    char _pad3A[2];
    unsigned char m_3c;
    char _pad3D[0x44 - 0x3D];
    unsigned char m_44;
    char _pad45[0x4C - 0x45];
    unsigned char m_4c;
    char _pad4D[3];
    int m_50;
    char _pad54[0x70 - 0x54];
    unsigned char m_70;
    char _pad71[0x8C - 0x71];
    cEvCmdData *m_data;
    char _pad90[0x94 - 0x90];
    unsigned short m_94;
    short m_96;
    float m_98;
    float m_9c;
    float m_a0;
    unsigned char m_a4;
    char _padA5;
    unsigned short m_a6;
    unsigned short m_a8;
    unsigned short m_aa;
    unsigned short m_ac;
    unsigned short m_ae;
    unsigned short m_b0;
    unsigned char m_b2;
    char _padB3;
    int m_b4;
    int m_b8;
};

extern "C" {
int func_002B1C80(cEvCmd *self);
void func_002B1F80(float, float, float, float);
void func_002B21F0(cEvCmd *self, unsigned short v);
void func_002B2A88(cEvCmd *self);
void func_002B22E0(cEvCmd *self, int v);
void func_002B4528(cEvCmd *self, const char *name);
void func_002B4428(cEvCmd *self, int a, void *b);
int func_002B4228(cEvCmd *self);
void func_002B42F0(cEvCmd *self);
void func_002B45C8(cEvCmd *self);
void func_002B45E0(cEvCmd *self, unsigned short v);
void func_002B45F0(cEvCmd *self);
int func_002B45F8(cEvCmd *self, cEvCmdData *d, unsigned int m);
}
void *SearchCameraData(const char *);
extern "C" void func_002B41F0(cEvCmd *self);
#endif
