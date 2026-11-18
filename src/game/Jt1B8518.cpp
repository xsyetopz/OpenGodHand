// Jump-table unit; this file holds no other .rodata.
extern char Snd[];
extern char CoreSave[];
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(char *, int, int);
extern "C" void *SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, char *, void *, int, unsigned);
extern "C" void SeStop__4cSnd6eSndId(char *, int);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" int getGameLevel__9cCoreSave(char *);

// FUNCTION: GAME 0x1B8518
extern "C" void clearFire__5cOmbb(char *self)
{
    KillEffect__FPC4cObji13eEspEraseMode(self, 0, 2);
    SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(1, 2, self, 0, 0, -1);
    if (*(int *)(self + 0x608) != 0)
        SeStop__4cSnd6eSndId(Snd, *(int *)(self + 0x608));
    *(int *)(self + 0x608) = 0;
    SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x16, self, 0, 0, 0, 0);
    switch (getGameLevel__9cCoreSave(CoreSave)) {
    case 1:
    default: *(float *)(self + 0x604) = 450.0f; break;
    case 2: *(float *)(self + 0x604) = 350.0f; break;
    case 3: *(float *)(self + 0x604) = 250.0f; break;
    case 4: *(float *)(self + 0x604) = 250.0f; break;
    case 5: *(float *)(self + 0x604) = 150.0f; break;
    }
    *(char *)(self + 0x2F4) = 0;
    *(char *)(self + 0x2F6) = 4;
    *(char *)(self + 0x600) = 0;
}
