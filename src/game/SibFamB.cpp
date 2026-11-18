// Siblings of matched anchors (identical instruction skeleton, new constants/callees/globals).
#include "game/CustomIDWork.h"
#include "game/cDamageManage.h"

extern "C" {

void func_001B6FB8(void *self);
void func_001FD580(cDamageGive *);
void func_001FCDE8(cDamageGive *);
int func_0030FB70(void *p);
void *func_0030FE68(void *a, void *b);
void execute__12cTaskManagerRFv_vi(void *, void (*)(void *), void *);
void func_002AE838(void *);
extern char GlobalTask;
extern unsigned D_00747A84[];

struct SFB_Om { char _pad[0x5B8]; unsigned m_f; };

// FUNCTION: GAME 0x3069A8
int func_003069A8(char *a, unsigned b, int *c) {
    *c = 0;
    if (b >= *(unsigned *)(a + 4))
        return 0;
    int *t = (int *)(a + 0x10);
    int o = t[b];
    if (o == 0)
        return 0;
    *c = (int)(a + o);
    return 1;
}

// FUNCTION: GAME 0x1BE918
int func_001BE918(SFB_Om *self)
{
    func_001B6FB8(self);
    self->m_f |= 8;
    return 1;
}

// FUNCTION: GAME 0x30FAC8
void *func_0030FAC8(void *a, void *b)
{
    if (!func_0030FB70(a))
        return 0;
    return func_0030FE68(a, b);
}

// FUNCTION: GAME 0x1FE278
int func_001FE278(void *self, cDamageGive *give)
{
    if (!give)
        return 0;
    func_001FD580(give);
    func_001FCDE8(give);
    return 1;
}

// FUNCTION: GAME 0x2AE7F0
void func_002AE7F0(int a) { D_00747A84[1] |= 0x80000000u; execute__12cTaskManagerRFv_vi(&GlobalTask, func_002AE838, (void *)a); }

}

#include "game/cCoreSave.h"
extern unsigned int D_00747A38;

// FUNCTION: GAME 0x1FAE60
extern "C" int func_001FAE60(cCoreSave *self)
{
    if (self->m_save == 0)
        return 0;
    if (D_00747A38 & 0x8000000)
        *((unsigned char *)self->m_save + 0x154) = 0xD;
    return *((unsigned char *)self->m_save + 0x154);
}

// FUNCTION: GAME 0x1FAEA0
extern "C" int func_001FAEA0(cCoreSave *self)
{
    if (self->m_save == 0)
        return 0;
    if (D_00747A38 & 0x8000000)
        *((unsigned char *)self->m_save + 0x155) = 5;
    return *((unsigned char *)self->m_save + 0x155);
}

extern "C" {
extern char D_005F3970[];
void func_001B76D8(void *);
int func_001B76B0(void *);
void func_002CDA48(void *);
void *memset(void *, int, unsigned int);

// FUNCTION: GAME 0x2C0A28
void func_002C0A28(void *a, int b)
{
    if (b == 0xFFFF && a) {
        char *s = D_005F3970;
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(char (*)[16])(s + 0x190)));
        char *q = s + 0x28A;
        for (int i = 0x7F; i != -1; i--) {
            q[4] = 0;
            q += 0x10;
        }
        *(int *)(s + 0xB8C) = 0;
    }
}

// FUNCTION: GAME 0x1F9FC0
void func_001F9FC0(cCoreSave *self)
{
    if (self->m_save)
        memset((char *)self->m_save + 0x180, 0, 0x30);
}

// FUNCTION: GAME 0x1B7168
void func_001B7168(void *self)
{
    if (func_001B76B0(self))
        func_001B76D8(self);
}

// FUNCTION: GAME 0x1C90B0
void func_001C90B0(void *self)
{
    if (func_001B76B0(self))
        func_001B76D8(self);
}

// FUNCTION: GAME 0x2CDA08
void *func_002CDA08(void *self)
{
    func_002CDA48(self);
    return self;
}

// FUNCTION: GAME 0x38BB48
struct SFB_F { unsigned f; };
void func_0038BB48(SFB_F *self, int on)
{
    if (on)
        self->f |= 0x200;
    else
        self->f &= ~0x200;
}

// FUNCTION: GAME 0x38BB70
void func_0038BB70(SFB_F *self, int on)
{
    if (on)
        self->f |= 2;
    else
        self->f &= ~2;
}
}
