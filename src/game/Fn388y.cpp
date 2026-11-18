// COMPILER: ee-gcc2.9-991111
struct VT { char p0[0x34]; int (*f34)(void *, const char *, int); };
struct SB { char p0[0x50]; VT *m50; };
struct Ios { SB *sb; Ios *tie; int width; int mC; unsigned long long fl; char fill; char pad; unsigned char st; };
struct Os { Ios *ios; };
extern char D_0045D130[];
extern "C" {
void flush__7ostream(Ios *);
unsigned strlen(const char *);
long func_0038E138(SB *, int, long);
void func_00389548(Os *);
// FUNCTION: GAME 0x388E30
Os *__ls__7ostreamPCc(Os *s, const char *p)
{
    int ok;
    if (s->ios->st) {
        ok = 0;
    } else {
        if (s->ios->tie)
            flush__7ostream(s->ios->tie);
        ok = 1;
    }
    if (ok) {
        int len, pad;
        int w;
        unsigned long long fl;
        char fill;
        SB *sb;
        Ios *ios;
        pad = 0;
        if (!p)
            p = D_0045D130;
        len = strlen(p);
        ios = s->ios;
        w = ios->width;
        fl = ios->fl;
        fill = ios->fill;
        sb = ios->sb;
        if (len < w)
            pad = w - len;
        else
            pad = 0;
        ios->width = 0;
        if (!(fl & 2) && pad > 0) {
            if (func_0038E138(sb, fill, pad) != pad)
                goto bad;
        }
        if (sb->m50->f34(sb, p, len) != len) {
        bad:
            s->ios->st |= 4;
            goto done;
        }
        if (s->ios->fl & 2) {
            if (pad > 0 && func_0038E138(sb, fill, pad) != pad) {
                s->ios->st |= 4;
            }
        }
        if (s->ios->fl & 0x6000)
            func_00389548(s);
    }
done:
    return s;
}
}
