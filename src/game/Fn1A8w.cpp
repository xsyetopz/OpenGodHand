struct OmA { char pad[0x2F4]; unsigned char b4, b5, b6; char p1[0x5B0 - 0x2F7]; unsigned w5B0; char p2[0x630 - 0x5B4]; int w630; char p3[0x660 - 0x634]; unsigned char b660; char p4; unsigned short h662; };
struct SaveT;
extern SaveT CoreSave; extern SaveT g_RoomSave;
extern "C" void func_001FB2D8(SaveT *, int);
extern "C" void func_002BECB0(SaveT *, long);
// FUNCTION: GAME 0x1C24E8
extern "C" void func_001C24E8(OmA *s) {
    s->b6 = 4;
    s->b660 = 1;
    long f = s->w5B0;
    s->b4 = 0;
    s->b5 = 0;
    s->w630 = 0;
    if (((f >> 5) & 1) == 0) {
        func_001FB2D8(&CoreSave, s->h662);
    } else {
        func_002BECB0(&g_RoomSave, *(long *)((char *)s + 0x538));
    }
}

struct OmB { char pad[0xF0]; int w0F0; char p1[0x560 - 0xF4]; int w560; char p2[0x5B0 - 0x564]; unsigned w5B0; };
extern char g_EmManage[];
extern "C" int canItemDrop__7cOmBase(OmB *);
extern "C" void CreateItem__9cEmManageRC4cVec6eObjIdUi(void *, int, int, int);
// FUNCTION: GAME 0x1B7BB8
extern "C" void func_001B7BB8(OmB *s) {
    long f = s->w5B0;
    long a = (f >> 4) & 1;
    long k = 1;
    if (a != k) {
        s->w5B0 = (int)s->w5B0 | 0x10;
        if (canItemDrop__7cOmBase(s) == k) {
            if (s->w560 != 0xFFFF) {
                CreateItem__9cEmManageRC4cVec6eObjIdUi(g_EmManage, s->w0F0, s->w560, 0);
            } else {
                CreateItem__9cEmManageRC4cVec6eObjIdUi(g_EmManage, s->w0F0, 0xFFFF, 0);
            }
        }
    }
}
