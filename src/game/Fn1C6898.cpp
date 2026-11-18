struct cVec { float x, y, z; cVec &operator=(const cVec &o) { x = o.x; y = o.y; z = o.z; return *this; } };
struct cObj;
extern "C" void func_001C6968(void *, unsigned int, const cVec *);

struct cOmSub {
    char pad0[4];
    cObj *o4;
    char *o8;
    char pad1[0x40 - 0xC];
    cVec *p40;
    char pad2[0x70 - 0x44];
    cVec v70;
    char pad3[4];
    cVec v80;
    void initMove1_pos(cObj *o, int i, unsigned int f, const cVec &v, float a, float b);
};


// FUNCTION: GAME 0x1C6898
void cOmSub::initMove1_pos(cObj *o, int i, unsigned int f, const cVec &v, float a, float b) {
    if (o) {
        char *t;
        if (i >= 0) {
            unsigned char n = *(unsigned char *)((int)o + 0x2B4);
            char *r;
            const int &rn = n;
            if (i < rn)
                r = ((char **)*(char **)((int)o + 0x278))[i];
            else
                r = 0;
            t = r;
        } else
            t = (char *)o;
        if (t) {
            o4 = o;
            o8 = t;
            if (i >= 0)
                p40 = *(cVec **)(t + 0xD0);
            else
                p40 = *(cVec **)(t + 0xF0);
            if (&v70 != p40) v70 = *p40;
            if (&v80 != (cVec *)(t + 0x100)) v80 = *(cVec *)(t + 0x100);
        }
    }
    func_001C6968(this, f, &v);
}
