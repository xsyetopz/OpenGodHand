#include "game/cEventShared.h"

// FUNCTION: GAME 0x298CF0
extern "C" void func_00298CF0()
{
    char *arr = objbaseArray;
    char *s = D_0044ABE0;
    unsigned long key = 0;
    int i = 0;
    while (i < 8 && s[i]) {
        key |= (long)s[i] << (i * 8);
        i++;
    }
    EvObj *o = SearchOM__13cObjBaseArrayUl(arr, key);
    if (o) {
        o->m_flags &= ~2;
    }
}

// near-miss: 16 differing words, same size; original loads into v1 and orders tail blocks 3DA,2A2,2A3,2A6; mine loads into v0
#ifdef NONMATCHING
// DRAFT: GAME 0x298EF8
extern "C" void func_00298EF8(EvObj *self, unsigned char idx)
{
    int v;
    if (!self)
        return;
    switch (self->m_kind) {
    case 0x3DA:
        v = D_003C0548[idx];
        break;
    case 0x2A2:
        v = D_003C0548[0];
        break;
    case 0x2A6:
        v = D_003C054A;
        break;
    case 0x2A3:
        v = D_003C0549;
        break;
    default:
        return;
    }
    if (!v) {
        self->m_flags |= 0x8002;
    }
}
#endif

// FUNCTION: GAME 0x2988A8
extern "C" void func_002988A8(EvObj *self, int, int n)
{
    if (self) {
        switch (self->m_kind) {
        case 0x600:
            if (n < 13) {
                setMeshDisplay__6cModelPCcb(self, D_0044AB60, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044AB68, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044AB70, 1);
                setMeshDisplay__6cModelPCcb(self, D_0044AB78, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044AB80, 1);
                setMeshDisplay__6cModelPCcb(self, D_0044AB88, 0);
            } else {
                setMeshDisplay__6cModelPCcb(self, D_0044AB60, 1);
                setMeshDisplay__6cModelPCcb(self, D_0044AB68, 1);
                setMeshDisplay__6cModelPCcb(self, D_0044AB70, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044AB78, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044AB80, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044AB88, 1);
            }
            break;
        case 0x602:
            if (n < 13) {
                setMeshDisplay__6cModelPCcb(self, D_0044AB60, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044AB70, 1);
                setMeshDisplay__6cModelPCcb(self, D_0044AB78, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044AB80, 1);
                setMeshDisplay__6cModelPCcb(self, D_0044AB88, 0);
            } else {
                setMeshDisplay__6cModelPCcb(self, D_0044AB60, 1);
                setMeshDisplay__6cModelPCcb(self, D_0044AB70, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044AB78, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044AB80, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044AB88, 1);
            }
            break;
        case 0x626:
            setMeshDisplay__6cModelPCcb(self, D_0044AB90, 0);
            setMeshDisplay__6cModelPCcb(self, D_0044AB98, 0);
            break;
        }
    }
}

// FUNCTION: GAME 0x298DB8
extern "C" void func_00298DB8()
{
    int n = 0;
    int i;
    for (i = 0; i < 3; i++) {
        if (D_003C0548[i]) n++;
    }
    switch (n) {
    case 1:
        func_00297C88(Event, 0x1001);
        func_002D0220(GetBgmData__4cSndi(Snd, 1), 1, D_0044AC00);
        break;
    case 2:
        func_00297C88(Event, 0x1002);
        func_002D0220(GetBgmData__4cSndi(Snd, 1), 1, D_0044AC08);
        break;
    case 3:
        func_00297C88(Event, 0x1003);
        func_002D0220(GetBgmData__4cSndi(Snd, 1), 1, D_0044AC10);
        break;
    }
}

// FUNCTION: GAME 0x298F88
extern "C" void func_00298F88()
{
    EvObj *o = SearchOM__13cObjBaseArrayUl(objbaseArray, KeyOf(D_0044AC28));
    if (o) {
        o->m_flags |= 2;
    }
    o = SearchOM__13cObjBaseArrayUl(objbaseArray, KeyOf(D_0044AC30));
    if (o) {
        o->m_flags |= 2;
    }
    func_00297B60(Event, (void *)func_002990A0);
}

// FUNCTION: GAME 0x2990A0
extern "C" void func_002990A0()
{
    EvObj *o = SearchOM__13cObjBaseArrayUl(objbaseArray, KeyOf(D_0044AC28));
    if (o) {
        o->m_flags &= ~2;
    }
    o = SearchOM__13cObjBaseArrayUl(objbaseArray, KeyOf(D_0044AC30));
    if (o) {
        o->m_flags &= ~2;
    }
}

#ifdef NONMATCHING
extern int DISPLAY_W, D_003C11C8, D_003C11AC, D_003C11B4, D_00586B80;
// near-miss: 26 differing words, same size; loop register allocation differs (original keeps 0x800 inside the loop, mine hoists constants into different saved regs)
// DRAFT: GAME 0x29FDE0
extern "C" void func_0029FDE0(EvBuf *b, int h)
{
    int i = 0;
    func_00299868(b, 0x3F, 0xFF);
    func_00299868(b, 0, 0x306);
    unsigned v = (unsigned)(D_003C11AC + D_003C11C8 * h) >> 5;
    func_00299868(b, 0x4D, (long)(DISPLAY_W / 128) << 16 | v);
    for (; i < DISPLAY_W / 64; i++) {
        func_00299868(b, 0x41, (long)(0x1F + i * 0x20) << 16 | (i << 5) | (long)(D_003C11B4 - 1) << 48);
        func_00299868(b, 0xD, (long)(D_00586B80 << 4) << 16 | ((0x800 - DISPLAY_W / 2) << 4) | 0xFFFF00000000L);
        func_00299868(b, 5, (long)((D_00586B80 + D_003C11B4) << 4) << 16 | 0xFFFF00008000L);
    }
}
#endif
