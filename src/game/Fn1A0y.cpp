// FUNCTION: GAME 0x1B7A78
extern "C" int canItemDrop__7cOmBase(char *self)
{
    long f = (unsigned)*(int *)(self + 0x5B0);
    long hit = (f >> 1) & 1;
    if (hit == 1) return 0;
    int k = *(int *)(self + 0x560);
    if (k == 0x9C3) return 0;
    if (k != 0xFFFF) return 1;
    switch (*(unsigned short *)(self + 0x2FE)) {
    case 0x301: case 0x302:
    case 0x309: case 0x30A: case 0x30B: case 0x30C:
    case 0x325:
    case 0x32A: case 0x32B: case 0x32C:
    case 0x32E: case 0x32F:
    case 0x332:
    case 0x33D:
    case 0x33F: case 0x340: case 0x341: case 0x342: case 0x343: case 0x344: case 0x345:
    case 0x347: case 0x348:
    case 0x400: case 0x401: case 0x402:
    case 0x410: case 0x411:
    case 0x418: case 0x419: case 0x41A:
    case 0x41F:
    case 0x42E:
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x1AAC90
extern char g_CollSolidManage[];
extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(void *, int, int);
extern "C" void setMeshDispFromLayer__7cOmBaseUib(void *, unsigned, int);
extern "C" void func_001AAC90(char *self)
{
    if (*(void **)(self + 0x608)) SetDamageCollActive__11cDamageUnitb(*(void **)(self + 0x608), 0);
    if (*(void **)(self + 0x604)) SetDamageCollActive__11cDamageUnitb(*(void **)(self + 0x604), 0);
    int *p;
    p = *(int **)(self + 0x60C);
    if (p) p[2] &= ~1;
    p = *(int **)(self + 0x610);
    if (p) p[2] &= ~1;
    p = *(int **)(self + 0x614);
    if (p) p[2] &= ~1;
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    *(unsigned *)(self + 0x9D0) |= 0x80000000;
    KillEffect__FPC4cObji13eEspEraseMode(self, 3, 2);
    KillEffect__FPC4cObji13eEspEraseMode(self, 0xB, 2);
    setMeshDispFromLayer__7cOmBaseUib(self, 1, 0);
    *(unsigned char *)(self + 0x2F4) = 0;
    *(unsigned char *)(self + 0x2F5) = 0;
    *(unsigned char *)(self + 0x2F6) = 2;
    *(unsigned char *)(self + 0x2F7) = 0;
}
