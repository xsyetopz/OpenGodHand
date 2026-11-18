struct V3 { float x, y, z, w; V3 &operator=(const V3 &o) { if (this != &o) { x = o.x; y = o.y; z = o.z; } return *this; } };
struct Mt { float m[16]; };
extern "C" void MtxInitCoord__FR7cMatrixRC4cVecN21Uc(Mt *, void *, V3 *, V3 *, unsigned char);
extern "C" void MtxInverse__FR7cMatrixRC7cMatrix(Mt *, Mt *);
extern "C" void sceVu0MulMatrix(Mt *, Mt *, Mt *);
extern "C" void func_00156D70(float, void *, void *, void *);
extern "C" void func_001501D0(void *, unsigned);
struct Bone { char _p0[0x40]; Mt l40; Mt l80; char _p1[0x144 - 0xC0]; Bone *next; Bone *a148; char _p2[0x154 - 0x14C]; int fl154; };
struct Mdl {
  char _p0[0x80]; Mt w80; char _p1[0xF0 - 0xC0]; void *pF0; char _p2[0x100 - 0xF4]; V3 v100, v110, v120;
  char _p3[0x140 - 0x130]; unsigned char b140; char _p4[3]; Bone *b144; char _p5[0x250 - 0x148]; unsigned f250;
  char _p6[0x27C - 0x254]; float f27C; char _p7[0x2B4 - 0x280]; unsigned char n2B4;
};
// FUNCTION: GAME 0x14A038
extern "C" void calcWorldParts__6cModel(Mdl *self) {
  if (self->f250 & 0x20) {
    if (!(self->f250 & 0x800)) {
      MtxInitCoord__FR7cMatrixRC4cVecN21Uc(&self->w80, self->pF0, &self->v100, &self->v110, self->b140);
      self->v120 = self->v110;
    }
    Bone *b = self->b144;
    for (int i = 0; i < self->n2B4; i++, b = b->next) {
      unsigned long f = b->fl154;
      if (((f >> 4) & 1) != 1) {
        if (self->f27C > 0.0f && !(f & 0x100000)) {
          Mt t;
          MtxInverse__FR7cMatrixRC7cMatrix(&t, (Mt *)((char *)b->a148 + 0x80));
          sceVu0MulMatrix(&t, &t, &b->l80);
          func_00156D70(self->f27C, b, b, &b->l40);
        }
        func_001501D0(b, self->f250);
      }
    }
  }
}
