// Shared libstdc++ iostream layouts and sentry helpers for the SCE 2.9 objects.
#ifndef SCE_IOSTREAM_H
#define SCE_IOSTREAM_H

struct SB {
    unsigned flags;
    int m4;
    int m8;
};

struct Ios {
    struct SB *sb;
    struct Ios *tie;
    char pad0[8];
    unsigned long long fl;
    char pad[2];
    unsigned char st;
};

struct Is {
    struct Ios *ios;
    int cnt;
};

void func_00389268(struct Ios *);

static inline int ipfx(struct Is *s)
{
    if (s->ios->st) {
        s->ios->st |= 2;
        return 0;
    }
    if (s->ios->tie) {
        if (s->ios->sb->m8 == s->ios->sb->m4)
            func_00389268(s->ios->tie);
    }
    return 1;
}

static inline int opfx(struct Is *s)
{
    if (s->ios->st)
        return 0;
    if (s->ios->tie)
        func_00389268(s->ios->tie);
    return 1;
}

#endif
