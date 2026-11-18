// Free units in 0x140000-0x150000.
extern float D_0041E880[];
extern float D_0041E884;
struct Part { char _q[0x40]; float s40, s44; char _r[4]; unsigned c4C; };
struct Ent { Part *a; Part *d; Part *b; Part *c; int p10; };
struct W {
  char _p0[0x90]; unsigned f90; Ent e[5];
  char _p1[0x338 - 0xF8]; float f338; char _p2[0x364 - 0x33C]; unsigned c364, c368;
  char _p3[0x41E - 0x36C]; short s41E; short s420;
};
// FUNCTION: GAME 0x146190
extern "C" void func_00146190(W *self) {
  unsigned short i;
  switch (self->s420) {
  case 0:
    self->s420++;
    self->f338 = 1.0f;
    break;
  case 1:
    self->f338 = self->f338 * 0.3f;
    for (i = 0; i < 5; i++) {
      self->e[i].d->s44 = self->f338;
      self->e[i].d->s40 = self->f338;
    }
    if (self->f338 < 0.01f) self->s420++;
    break;
  case 2:
    for (i = 0; i < 4; i++) {
      float k = D_0041E880[i] / 3.0f;
      self->e[i].a->s40 -= k;
      self->e[i].a->s44 -= k;
      if (self->e[i].a->s40 < 0.001f) {
        self->s420 = 0;
        self->s41E = 0;
        self->f90 &= 0xBFFFFFFF;
        self->f90 &= 0xDFFFFFFF;
      }
    }
    break;
  }
}
