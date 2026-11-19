// Clears flag bit 2 on the entries named by a u16 index range.
struct Entry12F600 {
    char _p[0x10];
    unsigned int m_flags;
};

struct Owner12F600 {
    char _p0[0x14];
    char *m_entries;
    char _p1[0x4];
    unsigned short *m_idx;
};

struct Range12F600 {
    unsigned int m_first;
    unsigned char m_n0, m_n1, m_n2;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x12F600 - 77 words differ; the n0 guard folds to beqz on m_n0 where the original does addiu and compares to a 0xFFFFFFFF register. Tried signed/unsigned n, while form, volatile byte, (int) casts: 77-82.
extern "C" void func_0012F600(Owner12F600 *self, Range12F600 *r, int flags)
{
    unsigned short *base = self->m_idx + r->m_first;
    int n;
    unsigned short *p;
    unsigned short idx;

    if (flags & 1) {
        n = r->m_n0 - 1;
        p = base;
        if (n != 0xFFFFFFFF) {
            do {
                idx = *p;
                n--;
                p++;
                ((Entry12F600 *)(self->m_entries + idx * 0x14))->m_flags &= 0xFFFFFFFB;
            } while (n != 0xFFFFFFFF);
        }
    }
    if (flags & 2) {
        n = r->m_n1 - 1;
        p = base + r->m_n0;
        if (n != 0xFFFFFFFF) {
            do {
                idx = *p;
                n--;
                p++;
                ((Entry12F600 *)(self->m_entries + idx * 0x14))->m_flags &= 0xFFFFFFFB;
            } while (n != 0xFFFFFFFF);
        }
    }
    if (flags & 4) {
        n = r->m_n2 - 1;
        p = base + r->m_n0 + r->m_n1;
        if (n != 0xFFFFFFFF) {
            do {
                idx = *p;
                n--;
                p++;
                ((Entry12F600 *)(self->m_entries + idx * 0x14))->m_flags &= 0xFFFFFFFB;
            } while (n != 0xFFFFFFFF);
        }
    }
}

struct Vec4F131 { float x, y, z, w; };

extern char EspSys[];
extern char g_DmgManage[];
extern "C" int func_001B6FB8(char *);
extern "C" char *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(char *, char *, int, float, float, float, float);
char *CreateDamageTake(char *, char *, int);
extern "C" void func_001FD9D8(char *, char *, void *, void *);
extern "C" void func_001C28A0(char *, int, int, int);
extern "C" void effDataRegist__6espSys12eEffDataTypePv(void *, int, void *);
extern "C" void setObjCollision__7cOmDoor(char *);
extern "C" void func_001BBF68(char *);

// DRAFT: GAME 0x16F790 - 85 words differ (352 vs 336 bytes); frame layout and vector arguments do not match the original yet.
extern "C" int func_0016F790(char *self)
{
    Vec4F131 a = {2.6f, 1.5f, 1.2f, 1.0f};
    Vec4F131 b = {0.0f, 0.0f, 0.0f, 1.0f};
    char *t;

    func_001B6FB8(self);
    t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2, a.x, a.y, a.z, a.w);
    *(char **)(self + 0x600) = t;
    if (t != 0) {
        Vec4F131 c = {0.0f, 0.0f, 0.0f, 1.0f};
        func_001FD9D8(t, self + 0x80, &b, &c);
    }
    *(int *)(self + 0x5E4) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(int *)(self + 0x5F0) = 0x259;
    *(int *)(self + 0x5E8) = 0x259;
    *(char **)(self + 0x608) = self + 0x620;
    *(int *)(self + 0x60C) = 9;
    *(int *)(self + 0x5F4) = -1;
    *(int *)(self + 0x5EC) = 1;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    func_001C28A0(self, 9, -1, 0x259);
    {
        char *p = *(char **)(self + 0x304);
        effDataRegist__6espSys12eEffDataTypePv(EspSys, 0x259, p + *(int *)(p + 0xC));
    }
    *(int *)(self + 0x5A0) = *(int *)(self + 0x5A0) | 0x10;
    return 1;
}

// DRAFT: GAME 0x17E8D8 - 82 words differ (332 vs 300 bytes); conditional stores around 0x610-0x618 and the CreateDamageTake signature are unverified.
extern "C" int func_0017E8D8(char *self)
{
    Vec4F131 a = {2.13f, 3.78f, 0.2f, 1.0f};
    Vec4F131 b;
    char *t;

    func_001B6FB8(self);
    b.x = a.x * -0.5f;
    b.y = 0.0f;
    b.z = 0.0f;
    b.w = 1.0f;
    t = CreateDamageTake(g_DmgManage, self, 2);
    *(char **)(self + 0x600) = t;
    if (t != 0) {
        Vec4F131 c = {0.0f, 0.0f, 0.0f, 1.0f};
        func_001FD9D8(t, self + 0x80, &b, &c);
    }
    *(float *)(self + 0x610) = a.x;
    *(float *)(self + 0x614) = a.y;
    *(float *)(self + 0x618) = a.z;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    setObjCollision__7cOmDoor(self);
    *(int *)(self + 0x624) = 1;
    *(char **)(self + 0x628) = self + 0x650;
    func_001BBF68(self);
    *(int *)(self + 0x5B8) = *(int *)(self + 0x5B8) | 2;
    return 1;
}
#endif
