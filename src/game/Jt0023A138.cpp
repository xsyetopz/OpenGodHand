// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern char g_CollSolidManage[];
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);

struct Ek {
    char _pad0[0x2F6];
    unsigned char m_2F6;
    char _pad1[0x304 - 0x2F7];
    char *m_304;
    char _pad2[0x54C - 0x308];
    float m_54C;
};

#define LOADAB(o1, o2)                                                     \
    p = self->m_304;                                                       \
    *((char *)self + 0x1864) = 0;                                          \
    a = *(int *)(p + o1);                                                  \
    b = *(int *)(p + o2)
#define CALLAB() func_002A8578(self, a + (int)p, b + (int)p, 0, 0, 0, 0.0f)

// FUNCTION: GAME 0x23A138
extern "C" void func_0023A138(Ek *self)
{
    char *p;
    int a, b;
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    self->m_54C = 3.0f;
    switch (self->m_2F6) {
    case 0:
        LOADAB(0x2C8C, 0x2C90);
        CALLAB();
        self->m_2F6++;
        goto walk;
    case 2:
        LOADAB(0x2C94, 0x2C98);
        CALLAB();
        self->m_2F6++;
        goto walk;
    case 4:
        LOADAB(0x2C9C, 0x2CA0);
        CALLAB();
        self->m_2F6++;
    case 1:
    case 3:
    case 5:
    walk:
        if (moveMotion__FP8cObjBase(self))
            self->m_2F6++;
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    case 6:
        LOADAB(0x2CA4, 0x2CA8);
        CALLAB();
        *(short *)((char *)self + 0x56E) = 0xF;
        self->m_2F6++;
    case 7:
        if (moveMotion__FP8cObjBase(self)) {
            *((char *)self + 0x2F4) = 0;
            *((char *)self + 0x2F5) = 0x6C;
            *((char *)self + 0x2F6) = 0;
            *((char *)self + 0x2F7) = 0;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    }
}
