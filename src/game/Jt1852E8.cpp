// Jump-table unit; this file holds no other .rodata.
extern char Snd[];
extern "C" void setMeshDispFromLayer__7cOmBaseUib(char *, unsigned, int);
extern "C" void *SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, char *, void *, int, unsigned);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" void func_00186038(char *, int);

// FUNCTION: GAME 0x1852E8
extern "C" void func_001852E8(char *self, unsigned state)
{
    setMeshDispFromLayer__7cOmBaseUib(self, 1, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 2, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 3, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 4, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 6, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 7, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 8, 0);
    switch (state) {
    case 0:
        setMeshDispFromLayer__7cOmBaseUib(self, 1, 1);
        setMeshDispFromLayer__7cOmBaseUib(self, 6, 1);
        break;
    case 1:
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x111, self, 0, 0, 0, 0);
        setMeshDispFromLayer__7cOmBaseUib(self, 2, 1);
        setMeshDispFromLayer__7cOmBaseUib(self, 7, 1);
        break;
    case 2:
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x111, self, 0, 0, 0, 0);
        setMeshDispFromLayer__7cOmBaseUib(self, 3, 1);
        setMeshDispFromLayer__7cOmBaseUib(self, 8, 1);
        break;
    case 3:
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0x298, 7, self, 0, -1, -1);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x112, self, 0, 0, 0, 0);
        setMeshDispFromLayer__7cOmBaseUib(self, 4, 1);
        setMeshDispFromLayer__7cOmBaseUib(self, 8, 1);
        func_00186038(self, 0);
        func_00186038(self, 1);
        func_00186038(self, 2);
        break;
    case 4:
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0x298, 8, self, 0, -1, -1);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x112, self, 0, 0, 0, 0);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x114, self, 0, 0, 0, 0);
        setMeshDispFromLayer__7cOmBaseUib(self, 4, 1);
        setMeshDispFromLayer__7cOmBaseUib(self, 8, 1);
        func_00186038(self, 3);
        func_00186038(self, 4);
        func_00186038(self, 5);
        func_00186038(self, 6);
        break;
    }
}
