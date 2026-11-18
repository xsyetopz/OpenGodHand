extern float D_0041E898[];
extern short D_003BD70C;
extern "C" void func_00145410(void *);
extern "C" void func_00145460(void *);
extern "C" void func_00145810(void *);
extern "C" void func_00145FC8(void *);
extern "C" void func_00146190(void *);
extern "C" void move__7cIDBase(char *);
extern "C" char *getIDWork__7cIDBasei(char *, int);
#ifdef NONMATCHING
// DRAFT: GAME 0x145238 (DIVNOP: 1; 9 words off: self/a/b callee-saved registers s0/s2 swapped)
extern "C" void func_00145238(char *self) {
  unsigned short i;
  switch (*(short *)(self + 0x41E)) {
  case 0: func_00145410(self); break;
  case 1: func_00145460(self); break;
  case 2: func_00145810(self); break;
  case 3: func_00145FC8(self); break;
  case 4: func_00146190(self); break;
  }
  for (i = 0; i < 5; i++) move__7cIDBase(self + 0x100 + i * 0x50);
  if (*(short *)(self + 0x41E) == 2) {
    short *t = (short *)(self + 0x4D0);
    (*t)--;
    if (*t < 0) *t = 0;
    char *a = self + 0x430;
    char *b = self + 0x480;
    float *d = D_0041E898;
    char *w = getIDWork__7cIDBasei(a, 0);
    float x = d[0];
    *(float *)(w + 0x38) = x;
    char *w2 = getIDWork__7cIDBasei(a, 0);
    float y = d[1];
    *(float *)(w2 + 0x3C) = y;
    *(float *)(getIDWork__7cIDBasei(a, 1) + 0x48) = (float)*t * 6.28f / (float)D_003BD70C;
    *(short *)(getIDWork__7cIDBasei(a, 2) + 0x90) = 0x30F2;
    *(float *)(getIDWork__7cIDBasei(b, 0) + 0x38) = x;
    *(float *)(getIDWork__7cIDBasei(b, 0) + 0x3C) = y;
    move__7cIDBase(a);
    move__7cIDBase(b);
  }
}
#endif
