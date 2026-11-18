extern char Snd[];
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" void setMeshColorFromLayer__7cOmBaseUifff(void *, unsigned, float, float, float);
// FUNCTION: GAME 0x1B5430
extern "C" void func_001B5430(char *self)
{
    SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 0, 10, self, 0, 0, 0, 0);
    setMeshColorFromLayer__7cOmBaseUifff(self, 0, 1.0f, 0.0f, 0.0f);
    *(short *)(self + 0x644) = 4;
    if (*(unsigned char *)(self + 0x2F4) == 0) {
        float f = *(float *)(self + 0x964) + 0.04f;
        *(float *)(self + 0x964) = f;
        if (f >= 0.3f)
            *(float *)(self + 0x964) = 0.3f;
    }
    *(unsigned *)(self + 0x600) |= 0x10;
}
