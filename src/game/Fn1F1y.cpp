struct EmW { unsigned char id; } __attribute__((aligned(16)));
extern char g_EmSet[];
extern "C" void func_001EF978(char *);
extern "C" int func_001C2490(int);
extern "C" void setEm__11cEmSetParamUc(char *, unsigned char);
extern "C" void StartAction__7cEmWrap(EmW *);
// FUNCTION: GAME 0x1F1918
extern "C" void func_001F1918(char *self)
{
    EmW w;
    switch (*(int *)(self + 0xB94)) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xB94) += 1;
        break;
    case 1:
        if (*(int *)(self + 0xC64))
            if (func_001C2490(*(int *)(self + 0xC64))) {
                w.id = 2;
                setEm__11cEmSetParamUc(g_EmSet, 2);
                StartAction__7cEmWrap(&w);
                *(int *)(self + 0xC64) = 0;
                *(int *)(self + 0xB8C) += 1;
            }
        if (*(int *)(self + 0xC68))
            if (func_001C2490(*(int *)(self + 0xC68))) {
                w.id = 3;
                setEm__11cEmSetParamUc(g_EmSet, 3);
                StartAction__7cEmWrap(&w);
                *(int *)(self + 0xC68) = 0;
                *(int *)(self + 0xB8C) += 1;
            }
        if (*(int *)(self + 0xC6C))
            if (func_001C2490(*(int *)(self + 0xC6C))) {
                w.id = 4;
                setEm__11cEmSetParamUc(g_EmSet, 4);
                StartAction__7cEmWrap(&w);
                *(int *)(self + 0xC6C) = 0;
                *(int *)(self + 0xB8C) += 1;
            }
        if (*(int *)(self + 0xC70))
            if (func_001C2490(*(int *)(self + 0xC70))) {
                w.id = 5;
                setEm__11cEmSetParamUc(g_EmSet, 5);
                StartAction__7cEmWrap(&w);
                *(int *)(self + 0xC70) = 0;
                *(int *)(self + 0xB8C) += 1;
            }
        if (*(int *)(self + 0xC74))
            if (func_001C2490(*(int *)(self + 0xC74))) {
                w.id = 6;
                setEm__11cEmSetParamUc(g_EmSet, 6);
                StartAction__7cEmWrap(&w);
                *(int *)(self + 0xC74) = 0;
                *(int *)(self + 0xB8C) += 1;
            }
        if (*(int *)(self + 0xC78))
            if (func_001C2490(*(int *)(self + 0xC78))) {
                w.id = 7;
                setEm__11cEmSetParamUc(g_EmSet, 7);
                StartAction__7cEmWrap(&w);
                *(int *)(self + 0xC78) = 0;
                *(int *)(self + 0xB8C) += 1;
            }
        break;
    }
}

extern long D_00747650;
extern char Snd[];
extern "C" void func_001F6A80(char *);
extern "C" void func_001F6AF8(char *);
extern "C" void SeCall__4cSnd6eSeBlksssUii(char *, int, int, int, int, int, int);

// FUNCTION: GAME 0x1F60D8
extern "C" void func_001F60D8(char *self)
{
    long f = D_00747650;
    if (f & 0x8000000L) {
        func_001F6A80(self);
        SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15F, -1, -1, 0, 0);
    } else if (f & 0x4000000L) {
        func_001F6AF8(self);
        SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15F, -1, -1, 0, 0);
    } else if (f & 0x2000000L) {
        self[1] = 1;
        *(int *)(self + 0x20) = 0;
        self[2] = 0;
        self[3] = 0;
        SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15F, -1, -1, 0, 0);
    } else if (f & 0x1000000L) {
        self[1] = 2;
        self[2] = 0;
        self[3] = 0;
        SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15F, -1, -1, 0, 0);
    } else if (f & 0x1000000000L) {
        func_001F6A80(self);
        SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15F, -1, -1, 0, 0);
    } else if (f & 0x10000000000L) {
        func_001F6AF8(self);
        SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15F, -1, -1, 0, 0);
    }
}
