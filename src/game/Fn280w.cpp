extern "C" void func_002A8578(void *, int, int, int, float, int, int);
extern "C" int moveMotion__FP8cObjBase(void *);

// FUNCTION: GAME 0x281D98
extern "C" void func_00281D98(char *s)
{
    int t = *(unsigned char *)(s + 0x15B0) ? 2 : 0;
    if (*(unsigned char *)(s + 0x15B0)) t = 2;
    switch (*(unsigned char *)(s + 0x2F6)) {
    case 0:
        switch (*(unsigned char *)(s + 0x2F7)) {
        default:
        case 0: {
            char *m = *(char **)(s + 0x304);
            func_002A8578(s, *(int *)(m + 0x2C) + (int)m, *(int *)(m + 0x30) + (int)m, 5, 0.0f, t, 0);
            break; }
        case 1: {
            char *m = *(char **)(s + 0x304);
            func_002A8578(s, *(int *)(m + 0x34) + (int)m, *(int *)(m + 0x38) + (int)m, 5, 0.0f, t, 0);
            break; }
        }
        *(unsigned char *)(s + 0x2F6) += 1;
    case 1:
        moveMotion__FP8cObjBase(s);
    }
}

#define CALL(o1, o2) func_002A8578(s, *(int *)(m + o1) + (int)m, *(int *)(m + o2) + (int)m, 2, 0.0f, 0, 0)
// FUNCTION: GAME 0x2826C8
extern "C" void func_002826C8(char *s)
{
    char *m;
    switch (*(unsigned char *)(s + 0x2F6)) {
    case 0:
        if (*(unsigned char *)(s + 0x2F7) != 0) {
            if (*(unsigned char *)(s + 0x15B0) != 0) {
                m = *(char **)(s + 0x304);
                CALL(0x100, 0x104);
            } else {
                m = *(char **)(s + 0x304);
                CALL(0xF0, 0xF4);
            }
        } else if (*(unsigned char *)(s + 0x15B0) != 0) {
            m = *(char **)(s + 0x304);
            CALL(0xF8, 0xFC);
        } else {
            m = *(char **)(s + 0x304);
            CALL(0xE8, 0xEC);
        }
        *(unsigned char *)(s + 0x2F6) += 1;
    case 1:
        moveMotion__FP8cObjBase(s);
    }
}

struct V3 { float x, y, z; void set(const V3 &o) { if (this != &o) { x = o.x; y = o.y; z = o.z; } } };
extern "C" void calcNullPart__6cModel(void *);
extern "C" void Add_nullspeed__FP8cObjBase(void *);
// FUNCTION: GAME 0x2865F0
extern "C" void func_002865F0(char *s)
{
    switch (*(unsigned char *)(s + 0x2F6)) {
    case 0: {
        char *m = *(char **)(s + 0x304);
        func_002A8578(s, *(int *)(m + 0x140) + (int)m, *(int *)(m + 0x144) + (int)m, 0xA, 0.0f, 0, 0);
        V3 *dst = (V3 *)(s + 0x5C0);
        V3 *src = *(V3 **)(s + 0xF0);
        dst->set(*src);
        *(unsigned char *)(s + 0x2F6) += 1;
    }
    case 1: {
        register V3 *d __asm__("$3") = *(V3 **)(s + 0xF0);
        d->x = d->x * 0.99f + *(float *)(s + 0x5C0) * 0.01f;
        register V3 *e __asm__("$2") = *(V3 **)(s + 0xF0);
        e->z = e->z * 0.99f + *(float *)(s + 0x5C8) * 0.01f;
        moveMotion__FP8cObjBase(s);
        calcNullPart__6cModel(s);
        Add_nullspeed__FP8cObjBase(s);
    }
    }
}

extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" void func_0028FB08(void *);
extern "C" void addKillNpcNum__9cCoreSave(void *);
extern "C" void SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern char g_CollSolidManage[];
extern char CoreSave[];
extern char Snd[];
// FUNCTION: GAME 0x288A58
extern "C" void func_00288A58(char *s)
{
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, s, 0);
    *(float *)(s + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s + 0x2F6)) {
    case 0: {
        func_0028FB08(s);
        addKillNpcNum__9cCoreSave(CoreSave);
        char *m = *(char **)(s + 0x304);
        func_002A8578(s, *(int *)(m + 0x90) + (int)m, *(int *)(m + 0x94) + (int)m, 5, 0.0f, 0, 0);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 1, 0x5F, s, 0, 0, 0, 0);
        register int k __asm__("$3") = *(unsigned char *)(s + 0x2F6);
        *(unsigned char *)(s + 0x2F6) = k + 1;
    }
    case 1:
        if (moveMotion__FP8cObjBase(s)) {
            *(unsigned char *)(s + 0x2F7) = 0;
            *(unsigned char *)(s + 0x2F4) = 2;
            *(unsigned char *)(s + 0x2F5) = 2;
            __asm__ volatile("");
            *(unsigned char *)(s + 0x2F6) = 0;
        } else {
            float one = 1.0f;
            addNullSpeed_Rotation__8cObjBasef(s, one);
            addNullSpeed__8cObjBasef(s, one);
        }
    }
}

extern "C" int irand__Fv();
extern "C" void calcNullPart__6cModel(void *);
// FUNCTION: GAME 0x2887D0
extern "C" void func_002887D0(char *s)
{
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, s, 0);
    *(unsigned *)(s + 0x15B0) |= 2;
    switch (*(unsigned char *)(s + 0x2F6)) {
    case 0: {
        if (irand__Fv() & 1) {
            char *m = *(char **)(s + 0x304);
            func_002A8578(s, *(int *)(m + 0xA8) + (int)m, *(int *)(m + 0xAC) + (int)m, 10, 0.0f, 0, 0);
        } else {
            char *m = *(char **)(s + 0x304);
            func_002A8578(s, *(int *)(m + 0xB0) + (int)m, *(int *)(m + 0xB4) + (int)m, 10, 0.0f, 0, 0);
        }
        if (*(unsigned char *)(s + 0x2F7) == 0)
            SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 1, 0x5C, s, 0, 0, 0, 0);
        *(unsigned char *)(s + 0x2F6) += 1;
    }
    case 1:
        if (moveMotion__FP8cObjBase(s)) {
            if (*(unsigned *)(s + 0x15B0) & 0x80) {
                *(unsigned char *)(s + 0x2F5) = 7;
                *(unsigned char *)(s + 0x2F6) = 0x12;
                *(unsigned char *)(s + 0x2F4) = 0;
                *(unsigned char *)(s + 0x2F7) = 0;
                break;
            }
            *(unsigned char *)(s + 0x2F4) = 0;
            *(unsigned char *)(s + 0x2F5) = 2;
            *(unsigned char *)(s + 0x2F6) = 0;
            *(unsigned char *)(s + 0x2F7) = 0;
        }
        calcNullPart__6cModel(s);
    }
}

// FUNCTION: GAME 0x288B78
extern "C" void func_00288B78(char *s)
{
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, s, 0);
    *(float *)(s + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s + 0x2F6)) {
    case 0: {
        func_0028FB08(s);
        addKillNpcNum__9cCoreSave(CoreSave);
        char *m = *(char **)(s + 0x304);
        func_002A8578(s, *(int *)(m + 0x130) + (int)m, *(int *)(m + 0x134) + (int)m, 5, 0.0f, 0, 0);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 1, 0x5F, s, 0, 0, 0, 0);
        register int k __asm__("$3") = *(unsigned char *)(s + 0x2F6);
        *(unsigned char *)(s + 0x2F6) = k + 1;
    }
    case 1:
        if (moveMotion__FP8cObjBase(s)) {
            *(unsigned char *)(s + 0x2F7) = 0;
            *(unsigned char *)(s + 0x2F4) = 2;
            *(unsigned char *)(s + 0x2F5) = 2;
            __asm__ volatile("");
            *(unsigned char *)(s + 0x2F6) = 0;
        } else {
            float one = 1.0f;
            addNullSpeed_Rotation__8cObjBasef(s, one);
            addNullSpeed__8cObjBasef(s, one);
        }
    }
}

// FUNCTION: GAME 0x28A560
extern "C" void func_0028A560(char *s)
{
    switch (*(unsigned char *)(s + 0x2F6)) {
    case 0: {
        int w = *(int *)(s + 0x564);
        if (w != 0x2A7 && w != 0x2AB) {
            char *m = *(char **)(s + 0x304);
            func_002A8578(s, *(int *)(m + 0x50) + (int)m, *(int *)(m + 0x54) + (int)m, 5, 0.0f, 0, 0);
        } else {
            char *m = *(char **)(s + 0x304);
            func_002A8578(s, *(int *)(m + 0x78) + (int)m, *(int *)(m + 0x7C) + (int)m, 5, 0.0f, 0, 0);
        }
        V3 *dst = (V3 *)(s + 0x5C0);
        V3 *src = *(V3 **)(s + 0xF0);
        dst->set(*src);
        *(unsigned char *)(s + 0x2F6) += 1;
    }
    case 1: {
        V3 *d = *(V3 **)(s + 0xF0);
        d->x = d->x * 0.99f + *(float *)(s + 0x5C0) * 0.01f;
        register V3 *e __asm__("$3") = *(V3 **)(s + 0xF0);
        e->z = e->z * 0.99f + *(float *)(s + 0x5C8) * 0.01f;
        *(unsigned *)(s + 0x15A0) |= 1;
        moveMotion__FP8cObjBase(s);
        calcNullPart__6cModel(s);
        Add_nullspeed__FP8cObjBase(s);
    }
    }
}

// FUNCTION: GAME 0x28A9E8
extern "C" void func_0028A9E8(char *s)
{
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, s, 0);
    *(float *)(s + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s + 0x2F6)) {
    case 0: {
        func_0028FB08(s);
        addKillNpcNum__9cCoreSave(CoreSave);
        int w = *(int *)(s + 0x564);
        char *m;
        if (w != 0x2A7 && w != 0x2AB) {
            m = *(char **)(s + 0x304);
            func_002A8578(s, *(int *)(m + 0x70) + (int)m, *(int *)(m + 0x74) + (int)m, 5, 0.0f, 0, 0);
        }
        m = *(char **)(s + 0x304);
        func_002A8578(s, *(int *)(m + 0x98) + (int)m, *(int *)(m + 0x9C) + (int)m, 5, 0.0f, 0, 0);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 1, 0x5F, s, 0, 0, 0, 0);
        register int k __asm__("$3") = *(unsigned char *)(s + 0x2F6);
        *(unsigned char *)(s + 0x2F6) = k + 1;
    }
    case 1:
        if (moveMotion__FP8cObjBase(s)) {
            *(unsigned char *)(s + 0x2F4) = 2;
            *(unsigned char *)(s + 0x2F5) = 1;
            *(unsigned char *)(s + 0x2F6) = 0;
            *(unsigned char *)(s + 0x2F7) = 0;
        } else {
            float one = 1.0f;
            addNullSpeed_Rotation__8cObjBasef(s, one);
            addNullSpeed__8cObjBasef(s, one);
        }
    }
}
