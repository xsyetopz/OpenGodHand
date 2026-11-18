// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" void setTexChange__7cOmBaseUi(char *, unsigned);

static inline void sel(char *self, unsigned n)
{
    *(unsigned short *)(self + 0x604) = n;
    switch ((unsigned short)n) {
    case 0: setTexChange__7cOmBaseUi(self, 0); break;
    case 1: setTexChange__7cOmBaseUi(self, 1); break;
    case 2: setTexChange__7cOmBaseUi(self, 2); break;
    case 3: setTexChange__7cOmBaseUi(self, 3); break;
    case 4: break;
    }
}

// FUNCTION: GAME 0x1B2118
extern "C" void SetTexColor__5cOm71Us(char *self, unsigned short n)
{
    if (n < 5)
        sel(self, n);
}
