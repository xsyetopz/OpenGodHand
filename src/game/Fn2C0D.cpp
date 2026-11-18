// Small unnamed units in 0x2C0000-0x2D0000.
#include "game/cCoreSave.h"
#include "game/cScenario.h"
extern cScenario *g_Sce;
extern cCoreSave CoreSave;
extern "C" void func_002C2368();
struct SndNode { int pad0[0x21]; SndNode *prev; SndNode *next; };
struct SndNode2 { SndNode2 *prev; SndNode2 *next; };
struct SndT { char pad[0x18]; SndNode *head; SndNode2 *head2; };
extern SndT Snd;
extern char D_00602F80[];
extern "C" void func_002CD668(char *, int, int);

// FUNCTION: GAME 0x2CC5C0
extern "C" void func_002CC5C0(SndNode *self)
{
    self->next = Snd.head;
    if (Snd.head)
        Snd.head->prev = self;
    Snd.head = self;
}

// FUNCTION: GAME 0x2CE3C0
extern "C" void func_002CE3C0(SndNode2 *self)
{
    self->next = Snd.head2;
    if (Snd.head2)
        Snd.head2->prev = self;
    Snd.head2 = self;
}

// FUNCTION: GAME 0x2CBF48
extern "C" char *func_002CBF48(char *self, int key)
{
    char *p = *(char **)(self + 0x1C);
    if (p) {
        do {
            if (*(int *)(p + 0x14) == key)
                return p;
            p = *(char **)(p + 4);
        } while (p);
    }
    return 0;
}

// FUNCTION: GAME 0x2CD638
extern "C" void func_002CD638()
{
    func_002CD668(D_00602F80, 0x5080, 0xFAF80);
}

// FUNCTION: GAME 0x2C2330
extern "C" int func_002C2330(void *self)
{
    g_Sce->taskExec((void *)func_002C2368, self, 1);
    return 1;
}

// FUNCTION: GAME 0x2C3820
extern "C" void func_002C3820(char *self)
{
    if (*(void (**)(int))(self + 0xEC)) {
        (*(void (**)(int))(self + 0xEC))(*(int *)(self + 0xF0));
        *(int *)(self + 0xEC) = 0;
    }
}

// FUNCTION: GAME 0x2C4DE0
extern "C" void func_002C4DE0(char *self)
{
    if (*(void (**)(int))(self + 0xF4)) {
        (*(void (**)(int))(self + 0xF4))(*(int *)(self + 0xF8));
        *(int *)(self + 0xF4) = 0;
    }
}

// FUNCTION: GAME 0x2C9B78
extern "C" void func_002C9B78(int *p, PL_SKILL s, unsigned char v)
{
    if (*p)
        CoreSave.setSkill(s, (signed char)v);
}

// FUNCTION: GAME 0x2C9BF8
extern "C" void func_002C9BF8(char *p, int i)
{
    if (*(int *)p)
        CoreSave.setSkill((PL_SKILL) * (signed char *)(p + i + 0x14), (signed char)-1);
}
