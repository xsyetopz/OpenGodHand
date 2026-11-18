// Small leaf units in .text 0x280000-0x30FFFF.
class cPadVib { public: void stopSeq(); };
class cRoomJump { public: cRoomJump(); void setTblAddr(unsigned int *p); };
class PathFinding { public: PathFinding(); };
extern unsigned int D_00747A44;
struct sM1 { char _p[0x24C]; char m_24c; };
struct sM2 { char _p[0x400]; int m_400; int m_404; };

// FUNCTION: GAME 0x2BDFD8
void cPadVib::stopSeq() { ((int *)this)[1] = 0; }

// FUNCTION: GAME 0x2BE990
void cRoomJump::setTblAddr(unsigned int *p) { *(unsigned int **)this = p; }

extern "C" {
// FUNCTION: GAME 0x28FE20
int func_0028FE20() { return 0; }

// FUNCTION: GAME 0x28FE28
int func_0028FE28() { return 0; }

// FUNCTION: GAME 0x28FE30
int func_0028FE30() { return 0; }

// FUNCTION: GAME 0x28FE38
int func_0028FE38() { return 0; }

// FUNCTION: GAME 0x28FE40
int func_0028FE40() { return 0; }

// FUNCTION: GAME 0x28FE50
int func_0028FE50() { return 0; }

// FUNCTION: GAME 0x2FBE08
int func_002FBE08() { return 0; }

// FUNCTION: GAME 0x2FBEC8
int func_002FBEC8() { return 1; }

// FUNCTION: GAME 0x2FEBE0
void func_002FEBE0(sM1 *s, char v) { s->m_24c = v; }

// FUNCTION: GAME 0x305C10
void func_00305C10(sM2 *s, int v) { s->m_400 = v; }

// FUNCTION: GAME 0x305C18
void func_00305C18(sM2 *s, int v) { s->m_404 = v; }
}

struct sC1 { char _p[0x15B0]; int m_15b0; };
struct sC2 { char _p[0x34]; float m_34; float m_38; float m_3c; float m_40; float m_44; float m_48; int m_4c; int m_50; };
struct sC3 { int m_0; };
extern unsigned char D_0061B670;

extern "C" {
// FUNCTION: GAME 0x2AF678
void func_002AF678(sC2 *s, float a, float b)
{
    s->m_34 = a;
    s->m_38 = b;
}

// FUNCTION: GAME 0x2AF688
void func_002AF688(sC2 *s, float a, float b)
{
    s->m_3c = a;
    s->m_40 = b;
}

// FUNCTION: GAME 0x2AF698
void func_002AF698(sC2 *s, float a, float b)
{
    s->m_44 = a;
    s->m_48 = b;
}

// FUNCTION: GAME 0x2AF6A8
void func_002AF6A8(sC2 *s, int a, int b)
{
    s->m_4c = a;
    s->m_50 = b;
}

// FUNCTION: GAME 0x2F1A90
unsigned char func_002F1A90() { return D_0061B670; }

// FUNCTION: GAME 0x30A298
int func_0030A298(int i) { return i * 4 + 0x1C00; }

// FUNCTION: GAME 0x3183C0
int func_003183C0() { return 0; }
}

class cSeData { public: int IsAlive(); };

// FUNCTION: GAME 0x2CFC68
int cSeData::IsAlive() { return ((sC3 *)this)->m_0 == 2; }

// FUNCTION: GAME 0x2BE968
cRoomJump::cRoomJump() { *(unsigned int *)this = D_00747A44; }

// FUNCTION: GAME 0x31BE58
PathFinding::PathFinding()
{
    char *p = (char *)this;
    p[0] = 0;
    ((int *)this)[1] = 0;
    ((int *)this)[3] = 0;
}
