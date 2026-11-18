// God Hand: medium switch-state units in 0x180000-0x1A8000
extern "C" void setMeshDispFromLayer__7cOmBaseUib(char *, unsigned, int);
extern "C" void func_00186038(char *, int);
extern "C" void SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(char *, int, int, char *, int, int, int, int);
extern "C" void SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, char *, int, int, unsigned);
extern char Snd[];
// FUNCTION: GAME 0x1851C0
extern "C" void func_001851C0(char *self, int k)
{
    setMeshDispFromLayer__7cOmBaseUib(self, 0, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x80, 0);
    switch (k) {
    case 0:
        setMeshDispFromLayer__7cOmBaseUib(self, 0, 1);
        break;
    case 4:
        func_00186038(self, 0x10);
        func_00186038(self, 0x11);
        func_00186038(self, 0x12);
        func_00186038(self, 0x13);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x80, 1);
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0x298, 1, self, 0, -1, 0xFFFFFFFFu);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x116, self, 0, 0, 0, 0);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 0, 2, self, 0, 0, 0, 0);
        break;
    }
}

// FUNCTION: GAME 0x185910
extern "C" void func_00185910(char *self, int k)
{
    setMeshDispFromLayer__7cOmBaseUib(self, 0x24, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x25, 0);
    switch (k) {
    case 0:
        setMeshDispFromLayer__7cOmBaseUib(self, 0x24, 1);
        break;
    case 1:
        setMeshDispFromLayer__7cOmBaseUib(self, 0x25, 1);
        break;
    case 4:
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x115, self, 0, 0, 0, 0);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x113, self, 0, 0, 0, 0);
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0x298, 5, self, 0, -1, 0xFFFFFFFFu);
        break;
    }
}
