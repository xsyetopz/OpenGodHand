struct V { float x, y, z, w; };
struct Obj { char pad[0x100]; V v; };
extern V D_00567FC0[];
class cOl2b {
public:
    void setInitFix();
    char _p0[0x278];
    Obj **objs;
    char _p1[0x2B4 - 0x27C];
    unsigned char num;
    char _p2[0x2F4 - 0x2B5];
    char c4, c5, c6, c7;
    char _p3[0xA24 - 0x2F8];
    int flag;
};
#ifdef NONMATCHING
// DRAFT: GAME 0x001804F8
// DRAFT: orig spills num to stack (sw v1,0(sp)) and keeps lo=0 in a reg (slt vs movn); store order of tail c7,flag,c4,c5,c6 matches; tried inline range helper (const ref), explicit u8 ok flag
void cOl2b::setInitFix() {
    if (flag != 0) {
        int i;
        V *src = D_00567FC0;
        for (i = 0; i < 3; i++) {
            unsigned char n = num;
            unsigned char ok = 0;
            if (i >= 0) ok = i < n;
            Obj *o;
            if (ok) o = objs[i];
            else o = 0;
            if (o != 0 && &o->v != src) {
                o->v.x = src->x;
                o->v.y = src->y;
                o->v.z = src->z;
            }
            src++;
        }
        c7 = 0;
        flag = 0;
        c4 = 0;
        c5 = 0;
        c6 = 0;
    }
}
#endif
