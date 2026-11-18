extern "C" int func_002F7110(void *);
extern "C" int func_002F7CD8(void *);

// FUNCTION: GAME 0x300060
extern "C" int func_00300060(void *p) { int r = (int)p; if (r) r = func_002F7110(p); return r; }
// FUNCTION: GAME 0x300088
extern "C" int func_00300088(void *p) { int r = (int)p; if (r) r = func_002F7CD8(p); return r; }
