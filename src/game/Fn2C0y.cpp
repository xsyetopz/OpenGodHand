// Small units from 0x2C0000-0x2E0000.
struct Spr100 { char pad[0x10]; float m_w; float m_h; };
extern "C" void drawTex__14cScrSpriteDrawUiffffffffUi(Spr100 *, unsigned, float, float, float, float, float, float, float, float, unsigned);

// FUNCTION: GAME 0x2C6550
extern "C" void func_002C6550(Spr100 *self, unsigned a1, float x, float y, float sx, float sy, float f4, float f5, float f6, float f7, unsigned a2)
{
    drawTex__14cScrSpriteDrawUiffffffffUi(self, a1, x - sx * self->m_w * 0.5f, y - sy * self->m_h * 0.5f, sx, sy, f4, f5, f6, f7, a2);
}
