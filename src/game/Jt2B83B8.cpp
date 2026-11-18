// Body-part mesh visibility by model id; sole switch of 0x2B83B8.
extern const char D_0044B430[], D_0044B438[], D_0044B440[], D_0044B448[], D_0044B458[], D_0044B468[];
extern const char D_0044B470[], D_0044B478[], D_0044B480[], D_0044B488[], D_0044B490[], D_0044B498[];
extern "C" int setMeshDisplay__6cModelPCcb(void *, const char *, int);

// FUNCTION: GAME 0x2B83B8
extern "C" void SetOneBodyFlag__10cObjSimpleb(char *self, int flag)
{
    self[0x4D8] = flag;
    if (!flag)
        return;
    setMeshDisplay__6cModelPCcb(self, D_0044B430, 0);
    unsigned short *hp = (unsigned short *)(self + 0x2FE);
    int t = *hp - 0x201;
    switch (t) {
    case 3:
    case 42:
        setMeshDisplay__6cModelPCcb(self, D_0044B438, 0);
        break;
    case 73:
        setMeshDisplay__6cModelPCcb(self, D_0044B440, 0);
        setMeshDisplay__6cModelPCcb(self, D_0044B448, 0);
    case 63:
        setMeshDisplay__6cModelPCcb(self, D_0044B458, 0);
        break;
    case 0:
    case 39:
        setMeshDisplay__6cModelPCcb(self, D_0044B468, 0);
        break;
    case 65:
        setMeshDisplay__6cModelPCcb(self, D_0044B470, 0);
        setMeshDisplay__6cModelPCcb(self, D_0044B478, 0);
    case 66:
    case 67:
        setMeshDisplay__6cModelPCcb(self, D_0044B480, 0);
        break;
    case 80:
        setMeshDisplay__6cModelPCcb(self, D_0044B488, 0);
        break;
    default:
        break;
    }
    setMeshDisplay__6cModelPCcb(self, D_0044B490, 0);
    setMeshDisplay__6cModelPCcb(self, D_0044B498, 0);
}
