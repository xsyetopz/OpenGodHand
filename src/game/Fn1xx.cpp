// Small leaf units in .text 0x150000-0x1DFFFF.
class cParts { public: void setRotationOrder(unsigned char v); };
class cObjBase;
class cOmWeapon { public: unsigned char ckGetEnable(); };
struct sL1 { char _p[0x56]; char m_56; };
struct sL2 { char _p[0x424]; int m_424; };
struct sL3 { char _p[0x630]; int m_630; };
struct sL4 { char _p[0x664]; unsigned char m_664; unsigned char m_665; };
struct sL5 { char _p[0x684]; float m_684; char _p2[0x68C - 0x688]; int m_68c; };

// FUNCTION: GAME 0x150128
void cParts::setRotationOrder(unsigned char v) { ((char *)this)[0x140] = v; }

// FUNCTION: GAME 0x1595F0
int GetSeqSEBase(cObjBase *o) { return ((sL2 *)o)->m_424; }

// FUNCTION: GAME 0x1D07E0
unsigned char cOmWeapon::ckGetEnable() { return ((sL4 *)this)->m_664; }

extern "C" {
// FUNCTION: GAME 0x1C2370
void func_001C2370(sL3 *s) { s->m_630 = 0; }

// FUNCTION: GAME 0x1C5F40
int func_001C5F40() { return 1; }

// FUNCTION: GAME 0x1D07E8
unsigned char func_001D07E8(sL4 *s) { return s->m_665; }

// FUNCTION: GAME 0x1D0B30
void func_001D0B30(sL5 *s, float f) { s->m_684 = f; }

// FUNCTION: GAME 0x1D0C10
int func_001D0C10(sL5 *s) { return s->m_68c; }

// FUNCTION: GAME 0x1D0C18
void func_001D0C18(sL5 *s) { s->m_68c = 0; }

// FUNCTION: GAME 0x1DEBE8
void func_001DEBE8(sL1 *s, char v) { s->m_56 = v; }
}
