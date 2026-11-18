// Game functions at 0x318000-0x31C000, matched byte-identically.
extern "C" {
void calcParts__6cModel(void *);
void calcWorldParts__6cModel(void *);
void InverseKinematics__2IKP8cObjBase(void *, void *);
}

// FUNCTION: GAME 0x318468
extern "C" void func_00318468(char *self)
{
    if (!(*(int *)(self + 0x250) & 2)) {
        calcParts__6cModel(self);
        if (*(int *)(self + 0x258) >= 0) {
            InverseKinematics__2IKP8cObjBase(self + 0x448, self);
            calcWorldParts__6cModel(self);
        }
    }
}
