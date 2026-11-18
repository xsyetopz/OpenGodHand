extern char Snd[];
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(void *, int, int);
extern "C" int SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, void *, void *, int, unsigned);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
// FUNCTION: GAME 0x1B8480
extern "C" void setFire__5cOmbb(char *self)
{
    if (*(unsigned char *)(self + 0x600) == 0) {
        *(unsigned char *)(self + 0x2F4) = 0;
        *(unsigned char *)(self + 0x2F6) = 2;
        KillEffect__FPC4cObji13eEspEraseMode(self, 0, 2);
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(1, 1, self, 0, 0, 0xFFFFFFFFu);
        *(int *)(self + 0x608) = SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x15, self, 0, 0, 0, 0);
        *(unsigned char *)(self + 0x600) = 1;
    }
}
