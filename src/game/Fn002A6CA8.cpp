extern "C" {
void *memset(void *, int, unsigned);
unsigned char func_00201960(void *);
void sleep__9cTaskWorkUs(void *, unsigned short);
long Gp_draw_poly4__FPA3_CfUiUiPC7GP_INFO7eOtTypeUi(float *, unsigned, unsigned, void *, int, unsigned);
}
extern char Dvd[];
extern void *D_00752C04;
extern float D_003C1184, D_003C1190;

struct PolyInfoB {
    unsigned flags;
    char _p0[0x2C];
    long attr;
    char _p1[0x18];
};

#ifdef NONMATCHING
// DRAFT: GAME 0x2A6CA8
// 49 words differ: zeros stored as sw zero not mtc1/swc1, D_003C1184/1190 loaded late, store order; tried element assignments (this form); aggregate init was worse (sp frame 0x100).
extern "C" void func_002A6CA8()
{
    while (func_00201960(Dvd) == 1) {
        float v[16];
        PolyInfoB info;
        info.flags = 0;
        memset(&info, 0, 0x48);
        info.flags |= 0x20;
        info.attr = 0x30000;
        v[0] = 0;
        v[1] = 0;
        v[2] = 65535.0f;
        v[3] = 1.0f;
        v[4] = 0;
        v[5] = D_003C1190;
        v[6] = 65535.0f;
        v[7] = 1.0f;
        v[8] = D_003C1184;
        v[9] = 0;
        v[10] = 65535.0f;
        v[11] = 1.0f;
        v[12] = D_003C1184;
        v[13] = D_003C1190;
        v[14] = 65535.0f;
        v[15] = 1.0f;
        Gp_draw_poly4__FPA3_CfUiUiPC7GP_INFO7eOtTypeUi(v, 0x80000000, 1, &info, 6, 5);
        sleep__9cTaskWorkUs(D_00752C04, 1);
    }
}
#endif
