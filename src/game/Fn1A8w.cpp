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

static inline int Gt(const int &v, int k) { return v > k; }
static inline char *Slot(char *o, int i)
{
    if (Gt(*(unsigned char *)(o + 0x2B4), i))
        return (*(char ***)(o + 0x278))[i];
    return 0;
}
// FUNCTION: GAME 0x1AD818
extern "C" void func_001AD818(char *self)
{
    if (Slot(self, 1))
        *(int *)(Slot(self, 1) + 0x104) = 0;
    if (Slot(self, 2))
        *(int *)(Slot(self, 2) + 0x104) = 0;
}

struct OmC { char pad[0x538]; long l538, l540; char p2[0x5B0 - 0x548]; unsigned w5B0; char p3[4]; unsigned w5B8; };
extern char g_CollScr[]; extern char g_CollSolidManage[];
extern int D_00747A84;
extern "C" void func_002BECB0(SaveT *, long);
extern "C" void func_001331B8(void *, long, int);
extern "C" void ReleaseUnit__21cCollisionSolidManageP8cGameObj(void *, void *);
// FUNCTION: GAME 0x1B7908
extern "C" void func_001B7908(OmC *s)
{
    long f = s->w5B8;
    if (((f >> 9) & 1) == 0 && (D_00747A84 & 0x1000000) == 0) {
        s->w5B8 = (int)s->w5B8 & -0x41;
    }
    func_002BECB0(&g_RoomSave, s->l538);
    func_001331B8(g_CollScr, s->l540, 0);
    ReleaseUnit__21cCollisionSolidManageP8cGameObj(g_CollSolidManage, s);
    func_001B7BB8((OmB *)s);
    s->w5B0 = ((int)s->w5B0 | 2) & -9;
}

struct OmD { char pad[0x2F4]; unsigned char b4, b5, b6, b7; char p1[0x60E - 0x2F8]; short h60E; };
// FUNCTION: GAME 0x1C2C40
extern "C" void func_001C2C40(OmD *s)
{
    switch (s->b5) {
    case 0:
        (*(void (**)(void *))(*(char **)((char *)s + 0x214) + 0xAC))((char *)s + *(short *)(*(char **)((char *)s + 0x214) + 0xA8));
        (*(void (**)(void *))(*(char **)((char *)s + 0x214) + 0xBC))((char *)s + *(short *)(*(char **)((char *)s + 0x214) + 0xB8));
        s->h60E = 3;
        s->b5 = 1;
        s->b6 = 0;
        s->b7 = 0;
    case 1:
        if (--s->h60E <= 0) {
            s->b4 = 0;
            s->b5 = 0;
            s->b6 = 0;
            s->b7 = 0;
        }
    }
}
