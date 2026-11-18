extern char Snd[];
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" unsigned irand__Fv();

// FUNCTION: GAME 0x26F120
extern "C" int func_0026F120(char *self)
{
    if (*(int *)(self + 0x5B4) < 200)
        return 0;
    *(int *)(self + 0x5B4) = 0;
    *(float *)(self + 0x17CC) = 150.0f;
    SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 0, 0x8C, self, 0, 0, 0, 0);
    *(unsigned char *)(self + 0x621) = 0;
    switch (*(int *)(self + 0x564)) {
    case 0x227: case 0x228: case 0x229: case 0x22A: case 0x22B:
    case 0x23A: case 0x243: case 0x24A: case 0x24B:
        if (irand__Fv() & 1)
            *(unsigned char *)(self + 0x621) = 1;
        break;
    case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x230: case 0x231:
    case 0x232: case 0x233: case 0x234: case 0x235: case 0x236: case 0x237:
    case 0x238: case 0x239: case 0x23B: case 0x23C: case 0x23D: case 0x23E:
    case 0x23F: case 0x240: case 0x241: case 0x242: case 0x244: case 0x245:
    case 0x246: case 0x247: case 0x248: case 0x249:
        break;
    }
    return 1;
}
