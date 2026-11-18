#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")
extern "C" void *__7cCamera(void *);
extern "C" void *__9cPlCamera(char *);
extern "C" void func_001398D0(void *);
extern "C" void func_00137A48(void *);
extern "C" void func_00138C70(void *);
extern char D_0041D8F8[], D_0041DBB0[];
// FUNCTION: GAME 0x139BC8
extern "C" void *__9cPlCamera(char *p)
{
    __7cCamera(p);
    *(char **)(p + 0x35C) = D_0041D8F8;
    ZQ(p, 0x370);
    ZQ(p, 0x380);
    ZQ(p, 0x390);
    ZQ(p, 0x3B0);
    ZQ(p, 0x3C0);
    ZQ(p, 0x3D0);
    *(char **)(p + 0x35C) = D_0041DBB0;
    ZQ(p, 0x400);
    ZQ(p, 0x410);
    ZQ(p, 0x440);
    ZQ(p, 0x450);
    ZQ(p, 0x480);
    ZQ(p, 0x490);
    ZQ(p, 0x4C0);
    ZQ(p, 0x4D0);
    ZQ(p, 0x500);
    *(int *)(p + 0x528) = 0;
    *(int *)(p + 0x520) = 0;
    *(int *)(p + 0x524) = 0;
    *(int *)(p + 0x510) = 0;
    *(int *)(p + 0x514) = 0;
    return p;
}
// FUNCTION: GAME 0x138BE8
extern "C" void *func_00138BE8(char *s)
{
    char *c;
    __9cPlCamera(s);
    c = s + 0x530;
    __7cCamera(c);
    *(char **)(c + 0x35C) = D_0041D8F8;
    ZQ(s, 0x8A0);
    ZQ(s, 0x8B0);
    ZQ(s, 0x8C0);
    ZQ(s, 0x8E0);
    ZQ(s, 0x8F0);
    ZQ(s, 0x900);
    func_001398D0(s + 0x920);
    __7cCamera(s + 0xC90);
    func_00137A48(s + 0xFF4);
    *(int *)(s + 0xFF0) = 0;
    func_00138C70(s);
    return s;
}
struct Q { float x, y, z, w; };
extern Q D_00462F40[8];
extern Q D_00462F00[4];
// FUNCTION: GAME 0x133670
extern "C" void func_00133670(void *p, int id)
{
    if (id == 0xFFFF && p) {
        float n = -0.5f, h = 0.5f, o = 1.0f;
        Q *a = D_00462F40;
        Q *b = D_00462F00;
        a->x = n; a->y = h; a->z = n; a->w = o; a++;
        b->x = n; b->y = h; *(int *)&b->z = 0; b->w = o; b++;
        a->x = h; a->y = h; a->z = n; a->w = o; a++;
        b->x = h; b->y = h; *(int *)&b->z = 0; b->w = o; b++;
        a->x = h; a->y = h; a->z = h; a->w = o; a++;
        b->x = h; b->y = n; *(int *)&b->z = 0; b->w = o; b++;
        a->x = n; a->y = h; a->z = h; a->w = o; a++;
        b->x = n; b->y = n; *(int *)&b->z = 0; b->w = o;
        a->x = n; a->y = n; a->z = n; a->w = o; a++;
        a->x = h; a->y = n; a->z = n; a->w = o; a++;
        a->x = h; a->y = n; a->z = h; a->w = o; a++;
        a->x = n; a->y = n; a->z = h; a->w = o;
    }
}
