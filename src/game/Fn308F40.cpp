extern "C" void *memset(void *, int, unsigned);

struct IDP {
    char _0[2]; char b2; char b3; char _4[4]; float f8; float fC; int w10; int w14; int w18;
    char _1c[0xC]; float f28; float f2C; float f30; char _34[0x14]; float f48; float f4C; int w50;
    char _54[4]; char b58; char _59; short h5A; char _5c[0xC]; char b68; char b69; char b6A; char b6B;
    short h6C; short h6E; char _70[0x1B0 - 0x70]; short h1B0; char _1b2[0x214 - 0x1B2]; short h214;
    char _216[0x278 - 0x216]; short h278; char _27a[0x2DC - 0x27A]; int w2DC;
};

class cIDParam {
public:
    void initialize();
};

// DRAFT: GAME 0x308F40
#ifdef NONMATCHING
// 29 words differ (register allocation of the constants); tried plain byte offsets (35), hoisted constant temps (42).
void cIDParam::initialize()
{
    IDP *p = (IDP *)this;
    memset(p, 0, 0x2E0);
    p->w2DC = 0x80808080;
    p->b58 = 6;
    p->h5A = 5;
    p->f8 = 256.0f;
    p->fC = 224.0f;
    p->b3 = -1;
    p->f30 = 1.0f;
    p->b69 = 1;
    p->h278 = 1;
    p->w50 = 0x80808080;
    p->b2 = -1;
    p->w10 = 0;
    p->w14 = 0;
    p->w18 = 0;
    p->f48 = 1.0f;
    p->f4C = 1.0f;
    p->f28 = 1.0f;
    p->f2C = 1.0f;
    p->b6A = 1;
    p->b6B = 1;
    p->h6E = 1;
    p->h6C = 1;
    p->h1B0 = 1;
    p->h214 = 1;
}
#endif
