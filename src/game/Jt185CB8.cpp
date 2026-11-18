// Jump-table unit; this file holds no other .rodata.
extern char Snd[];
extern "C" void setMeshDispFromLayer__7cOmBaseUib(char *, unsigned, int);
extern "C" void *SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, char *, void *, int, unsigned);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" void func_00186038(char *, int);

// FUNCTION: GAME 0x185CB8
extern "C" void func_00185CB8(char *self, unsigned state)
{
    setMeshDispFromLayer__7cOmBaseUib(self, 0x10, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x10 + 1, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x10 + 2, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x10 + 3, 0);
    switch (state) {
    case 0:
        setMeshDispFromLayer__7cOmBaseUib(self, 0x10, 1);
        break;
    case 1:
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x111, self, 0, 0, 0, 0);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x10 + 1, 1);
        break;
    case 2:
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x111, self, 0, 0, 0, 0);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x10 + 2, 1);
        break;
    case 3:
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x111, self, 0, 0, 0, 0);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x10 + 3, 1);
        break;
    case 4:
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0x298, 0xB, self, 0, -1, -1);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x112, self, 0, 0, 0, 0);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x10 + 3, 1);
        func_00186038(self, 0xE);
        func_00186038(self, 0xF);
        break;
    }
}
