// Local file name lookup by language slot; sole switch of 0x2ACFA8.
extern "C" int memset(void *, int, unsigned);
extern "C" int sprintf(char *, const char *, ...);
extern "C" char *strcpy(char *, const char *);
extern const char D_0044AF78[], D_0044AF80[], D_0044AF90[], D_0044AFA8[], D_0044AFC0[], D_0044AFD8[], D_0044AFF0[], D_0044B008[];
extern signed char D_00747A0C;
extern char Dvd[];
extern "C" int FileExist__4cDvdPCc(void *, const char *);

// DRAFT: GAME 0x2ACFA8 - 4 words differ: sb of buf[0] before the sd ra save, and -1 held in v1 instead of v0
#ifdef NONMATCHING
extern "C" int getLocalFileName__10cIDManagerPcT1Sc(void *self, char *out, char *name, signed char lang)
{
    char buf[0x80];
    buf[0] = D_0044AF78[0];
    int n = lang;
    memset(buf + 1, 0, 0x7F);
    if (n == -1)
        n = D_00747A0C;
    switch (n) {
    case 0:
        sprintf(buf, D_0044AF80, name);
        break;
    case 1:
        sprintf(buf, D_0044AF90, name);
        break;
    case 2:
        sprintf(buf, D_0044AFA8, name);
        break;
    case 3:
        sprintf(buf, D_0044AFC0, name);
        break;
    case 4:
        sprintf(buf, D_0044AFD8, name);
        break;
    case 5:
        sprintf(buf, D_0044AFF0, name);
        break;
    case 6:
        sprintf(buf, D_0044B008, name);
        break;
    }
    if (FileExist__4cDvdPCc(Dvd, buf)) {
        strcpy(out, buf);
        return 1;
    }
    sprintf(buf, D_0044AF80, name);
    strcpy(out, buf);
    return 0;
}
#endif
