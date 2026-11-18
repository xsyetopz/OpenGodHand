// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" int func_00276468(void *);
extern "C" void func_002A8578(void *, int, int, int, float, int, int);
extern "C" void func_002705D8(void *);
extern "C" void func_00260B30(void *);
extern "C" void func_002609A8(void *, int, int, int, int, int);
extern "C" float fRand0_1__Fv();
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void SetTgtTurn__8cGameObjRC4cVecf(void *, void *, float);
extern "C" void SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(int, int, void *, void *, float, int);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern char g_CollSolidManage[];
extern char Snd[];

#define B(o) (*(unsigned char *)(self + (o)))
#define UH(o) (*(unsigned short *)(self + (o)))
#define W(o) (*(unsigned *)(self + (o)))
#define F(o) (*(float *)(self + (o)))

// DRAFT: GAME 0x2448E0 - 8 words differ: store order and constant registers of the 0x623/0x531/0x617 stores in case 3, and the 0x564 == 0x20F test (original xori+beqz, mine addiu+beq)
#ifdef NONMATCHING
extern "C" void func_002448E0(char *self)
{
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    switch (B(0x2F6)) {
    case 0: {
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0xD70) + (int)o, *(int *)(o + 0xD74) + (int)o, 3, 0.0f, r, 0);
        B(0x2F6)++;
    }
    case 1:
        F(0x54C) = 2.0f;
        UH(0x434) |= 8;
        if (moveMotion__FP8cObjBase(self))
            B(0x2F6)++;
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    case 2:
        F(0x600) = fRand0_1__Fv() * 45.0f + 90.0f;
        W(0x4A8) |= 0x80000000;
        F(0x608) = 3.0f;
        W(0x604) = 0;
        B(0x2F6)++;
    case 3:
        B(0x623) = 1;
        B(0x531) = 0xFF;
        F(0x54C) = 2.0f;
        B(0x617) = 1;
        SetTgtTurn__8cGameObjRC4cVecf(self, self + 0x16A0, F(0x5A8) * 0.098174773f);
        UH(0x434) |= 8;
        moveMotion__FP8cObjBase(self);
        if (F(0x618) > 1.0f) {
            W(0x330) = 0;
            W(0x334) = 0;
            F(0x338) = F(0x5A8) * 0.1f;
        } else {
            W(0x330) = 0;
            W(0x334) = 0;
            W(0x338) = 0;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        F(0x600) -= F(0x5A8);
        if (F(0x600) <= 0.0f) {
            B(0x2F6) = 4;
            break;
        }
        F(0x604) -= F(0x5A8);
        if (F(0x604) <= 0.0f) {
            SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(0x58, 0x9C, 0, *(void **)(self + 0xF0), 1.0f, -1);
            F(0x604) = 6.0f;
        }
        if (W(0x474) != 1 && W(0x474) != 9)
            B(0x2F6) = 4;
        F(0x608) -= F(0x5A8);
        if (F(0x608) <= 0.0f) {
            F(0x608) = 15.0f;
            SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0xFB, self, 0, 0, 0, 0);
        }
        break;
    case 4: {
        unsigned short r = func_00276468(self);
        int a, b;
        if (*(int *)(self + 0x564) ^ 0x20F) {
            char *o = *(char **)(self + 0x304);
            a = *(int *)(o + 0xDA8) + (int)o;
            b = *(int *)(o + 0xDAC) + (int)o;
            func_002609A8(self, 0x14, 0x23, 0x37, -1, 0);
        } else {
            char *o = *(char **)(self + 0x304);
            a = *(int *)(o + 0xD78) + (int)o;
            b = *(int *)(o + 0xD7C) + (int)o;
        }
        func_002A8578(self, a, b, 3, 0.0f, r, 0);
        F(0x1744) = 300.0f;
        B(0x531) = 3;
        W(0x4A8) &= 0x7FFFFFFF;
        F(0x54C) = 5.0f;
        B(0x2F6)++;
        B(0x623) = 0;
    }
    case 5:
        if (moveMotion__FP8cObjBase(self))
            func_002705D8(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        func_00260B30(self);
        break;
    }
}
#endif
