// Jump-table unit; this file holds no other .rodata.
extern char Snd[];
extern "C" void setMeshDispFromLayer__7cOmBaseUib(char *, unsigned, int);
extern "C" void *SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, char *, void *, int, unsigned);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" void func_00186038(char *, int);

// FUNCTION: GAME 0x185690
extern "C" void func_00185690(char *self, unsigned state)
{
    setMeshDispFromLayer__7cOmBaseUib(self, 0x15, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x16, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x17, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x18, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x1A, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x1B, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x1C, 0);
    switch (state) {
    case 0:
        setMeshDispFromLayer__7cOmBaseUib(self, 0x15, 1);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x1A, 1);
        break;
    case 1:
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x111, self, 0, 0, 0, 0);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x16, 1);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x1B, 1);
        break;
    case 2:
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x111, self, 0, 0, 0, 0);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x17, 1);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x1C, 1);
        break;
    case 3:
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0x298, 9, self, 0, -1, -1);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x112, self, 0, 0, 0, 0);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x18, 1);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x1C, 1);
        func_00186038(self, 7);
        break;
    case 4:
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0x298, 10, self, 0, -1, -1);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x112, self, 0, 0, 0, 0);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x18, 1);
        setMeshDispFromLayer__7cOmBaseUib(self, 0x1C, 1);
        func_00186038(self, 8);
        func_00186038(self, 9);
        func_00186038(self, 10);
        func_00186038(self, 11);
        break;
    }
}
