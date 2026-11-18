// God Hand: small functions in 0x1F0000-0x1F4000
extern "C" void func_001EF978(char *);
extern "C" int strcmp(const char *, const char *);
extern "C" void func_001F00E8(char *, char *, float);
extern char D_0042BE90[];
// FUNCTION: GAME 0x1F2698
extern "C" void func_001F2698(char *self)
{
    switch (*(int *)(self + 0xB94)) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        break;
    case 1:
        *(int *)(self + 0xB94) = 2;
        break;
    }
}
// FUNCTION: GAME 0x1F0360
extern "C" void func_001F0360(char *self, char *e)
{
    if (e && *(short *)(e + 0x54A) > 0) {
        if (!strcmp(D_0042BE90, *(const char **)(e + 0x4AC)))
            func_001F00E8(self, e, *(float *)(e + 0x16CC) + 0.1f);
        else
            func_001F00E8(self, e, 0.5f);
    }
}

struct EmW { unsigned char id; } __attribute__((aligned(16)));
extern char g_EmSet[];
extern "C" void func_001EF978(char *);
extern "C" int func_001EF8B8(char *);
extern "C" void setEm__11cEmSetParamUc(char *, unsigned char);
extern "C" void StartAction__7cEmWrap(EmW *);
// FUNCTION: GAME 0x1F0538
extern "C" void func_001F0538(char *self)
{
    EmW w;
    switch (*(int *)(self + 0xB94)) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xBA0) = 0x12C;
        *(int *)(self + 0xB94) += 1;
        break;
    case 1:
        if (!func_001EF8B8(self) || *(int *)(self + 0xBA0) == 0) {
            w.id = 2;
            setEm__11cEmSetParamUc(g_EmSet, 2);
            StartAction__7cEmWrap(&w);
            *(int *)(self + 0xB8C) += 1;
            *(int *)(self + 0xB94) += 1;
        } else {
            *(int *)(self + 0xBA0) -= 1;
        }
        break;
    }
}

extern unsigned char D_00586AA5;
// FUNCTION: GAME 0x1F05F8
extern "C" void func_001F05F8(char *self)
{
    EmW a, b, c, d;
    switch (*(int *)(self + 0xB94)) {
    case 0:
        D_00586AA5 = 0;
        a.id = 0;
        StartAction__7cEmWrap(&a);
        b.id = 1;
        StartAction__7cEmWrap(&b);
        *(int *)(self + 0xB94) += 1;
        break;
    case 1:
        if (*(int *)(self + 0xB88) >= 2) {
            a.id = 2;
            StartAction__7cEmWrap(&a);
            c.id = 3;
            StartAction__7cEmWrap(&c);
            d.id = 4;
            StartAction__7cEmWrap(&d);
            *(int *)(self + 0xB94) += 1;
        }
        break;
    }
}

// FUNCTION: GAME 0x1F07C0
extern "C" void func_001F07C0(char *self)
{
    EmW w;
    switch (*(int *)(self + 0xB94)) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xBA0) = 0x258;
        *(int *)(self + 0xB94) += 1;
        break;
    case 1:
        if (*(int *)(self + 0xB88) >= 2 || *(int *)(self + 0xBA0) == 0) {
            w.id = 0;
            setEm__11cEmSetParamUc(g_EmSet, 0);
            StartAction__7cEmWrap(&w);
            *(int *)(self + 0xB8C) += 1;
            *(int *)(self + 0xB94) += 1;
        } else {
            *(int *)(self + 0xBA0) -= 1;
        }
        break;
    }
}
extern "C" int func_001C2490(int);
// FUNCTION: GAME 0x1F0978
extern "C" void func_001F0978(char *self)
{
    switch (*(int *)(self + 0xB94)) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xB94) += 1;
        break;
    case 1:
        if (*(int *)(self + 0xC64))
            if (func_001C2490(*(int *)(self + 0xC64))) *(int *)(self + 0xC64) = 0;
        if (*(int *)(self + 0xC68))
            if (func_001C2490(*(int *)(self + 0xC68))) *(int *)(self + 0xC68) = 0;
        if (*(int *)(self + 0xC6C))
            if (func_001C2490(*(int *)(self + 0xC6C))) *(int *)(self + 0xC6C) = 0;
        break;
    }
}

extern "C" {
void __7cIDBase(char *);
void __12CustomIDWork(char *);
}
// FUNCTION: GAME 0x1F2708
extern "C" char *func_001F2708(char *self)
{
    *(int *)self = 0;
    __7cIDBase(self + 0x10);
    char *p = self + 0x60;
    for (int i = 0x11; i != -1; i--, p += 0x7C)
        __12CustomIDWork(p);
    __7cIDBase(self + 0x930);
    p = self + 0x980;
    for (int i = 2; i != -1; i--, p += 0x7C)
        __12CustomIDWork(p);
    return self;
}
extern "C" void func_001F29C0(char *, int, int);
// FUNCTION: GAME 0x1F2A88
extern "C" void func_001F2A88(char *self, int f)
{
    func_001F29C0(self, 0x12, 0);
    func_001F29C0(self, 5, 1);
    func_001F29C0(self, 6, 1);
    if (f) {
        func_001F29C0(self, 7, 1);
        func_001F29C0(self, 8, 1);
        func_001F29C0(self, 9, 1);
        func_001F29C0(self, 10, 1);
    }
}
extern "C" void SetDisp__12CustomIDWorkb(char *, int);
// FUNCTION: GAME 0x1F29C0
extern "C" void func_001F29C0(char *self, int idx, int on)
{
    if (on) {
        if (idx == 0x12) {
            char *p = self + 0x60;
            for (int i = 0x11; i >= 0; i--, p += 0x7C)
                SetDisp__12CustomIDWorkb(p, 1);
        } else
            SetDisp__12CustomIDWorkb(self + (idx * 0x7C + 0x60), 1);
    } else {
        if (idx == 0x12) {
            char *p = self + 0x60;
            for (int i = 0x11; i >= 0; i--, p += 0x7C)
                SetDisp__12CustomIDWorkb(p, 0);
        } else
            SetDisp__12CustomIDWorkb(self + (idx * 0x7C + 0x60), 0);
    }
}
extern "C" void StartAction__7cEmWrap(EmW *);
// FUNCTION: GAME 0x1F1C50
extern "C" void func_001F1C50(char *self)
{
    EmW w;
    switch (*(int *)(self + 0xB94)) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xBA0) = 0x708;
        *(int *)(self + 0xB94) += 1;
        break;
    case 1:
        if (*(int *)(self + 0xB88) >= 2 || *(int *)(self + 0xBA0) == 0) {
            w.id = 1;
            setEm__11cEmSetParamUc(g_EmSet, 1);
            StartAction__7cEmWrap(&w);
            *(int *)(self + 0xB8C) += 1;
            *(int *)(self + 0xB94) += 1;
        } else {
            *(int *)(self + 0xBA0) -= 1;
        }
        break;
    }
}
extern "C" int GetVitalMax__7cEmWrap(EmW *);
extern "C" void SetVital__7cEmWrapi(EmW *, int);
// FUNCTION: GAME 0x1F1038
extern "C" void func_001F1038()
{
    EmW a, b, c;
    a.id = 0;
    b.id = 1;
    c.id = 2;
    SetVital__7cEmWrapi(&a, (int)(GetVitalMax__7cEmWrap(&a) * 0.15f));
    SetVital__7cEmWrapi(&b, (int)(GetVitalMax__7cEmWrap(&b) * 0.15f));
    SetVital__7cEmWrapi(&c, (int)(GetVitalMax__7cEmWrap(&c) * 0.15f));
}
