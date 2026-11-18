// Small unnamed functions in 0x1E0000-0x1FFFFF.
#define EMPTY(a) extern "C" void func_##a(void) {}

// FUNCTION: GAME 0x1F15B8
EMPTY(001F15B8)
// FUNCTION: GAME 0x1F1B18
EMPTY(001F1B18)
// FUNCTION: GAME 0x1F1C48
EMPTY(001F1C48)
// FUNCTION: GAME 0x1F1ED8
EMPTY(001F1ED8)
// FUNCTION: GAME 0x1F20F0
EMPTY(001F20F0)
// FUNCTION: GAME 0x1F2420
EMPTY(001F2420)
// FUNCTION: GAME 0x1F2538
EMPTY(001F2538)
// FUNCTION: GAME 0x1F2648
EMPTY(001F2648)

struct Timer {
    char _pad[0xB6C];
    int m_frames;
    char _pad2[0xB98 - 0xB70];
    float m_secs;
};

// FUNCTION: GAME 0x1EFD50
extern "C" void func_001EFD50(Timer *self)
{
    self->m_secs = (float)(self->m_frames * 30);
}

class cBoundingBox {
public:
    int m_v[6];
    cBoundingBox();
};

// FUNCTION: GAME 0x1F8A40
cBoundingBox::cBoundingBox()
{
    m_v[0] = 0;
    m_v[1] = 0;
    m_v[2] = 0;
    m_v[3] = 0;
    m_v[4] = 0;
    m_v[5] = 0;
}
