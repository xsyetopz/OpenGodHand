// Small leaf units in .text 0x280000-0x30FFFF.
class cPadVib { public: void stopSeq(); };
class cRoomJump { public: void setTblAddr(unsigned int *p); };
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
