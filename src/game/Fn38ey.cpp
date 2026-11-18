// COMPILER: ee-gcc2.9-991111
// libio file open in the SCE libstdc++ island.
struct FP { int flags; char p4[0x34]; int fileno; };
extern "C" {
int func_003B0360(const char *, int, int);
int _IO_seekoff(FP *, int, int, int);
void _IO_link_in(FP *);
// FUNCTION: GAME 0x38EDC0
FP *func_0038EDC0(FP *fp, const char *name, int mode, int prot)
{
    int posix, rw;
    int fd;
    if (fp->fileno >= 0)
        return 0;
    if (mode & 8)
        mode |= 2;
    if ((mode & 3) == 3) {
        posix = 2;
        rw = 0;
    } else if (mode & 2) {
        posix = 1;
        rw = 4;
    } else if (mode & 1) {
        posix = 0;
        rw = 8;
    } else {
        posix = 0;
        rw = 0xC;
    }
    if (mode & 0x80)
        mode &= ~0x80;
    if ((mode & 0x10) || mode == 2)
        posix |= 0x400;
    if (mode & 8) {
        posix |= 8;
        rw |= 0x1000;
    }
    if (!(mode & 0x20)) {
        if (mode != 1)
            posix |= 0x200;
    }
    fd = func_003B0360(name, (mode & 0x40) ? posix | 0x800 : posix, prot);
    if (fd < 0)
        return 0;
    fp->fileno = fd;
    fp->flags = (fp->flags & ~0x100C) | (rw & 0x100C);
    if (mode & 0xC) {
        if (_IO_seekoff(fp, 0, 2, 3) == -1)
            return 0;
    }
    _IO_link_in(fp);
    return fp;
}
}
