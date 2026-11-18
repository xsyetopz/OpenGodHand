// Medium helpers in 0x280000-0x2D0000.

struct cMessCommon {
    static int isPageEndCode(unsigned short c);
};

// FUNCTION: GAME 0x2AF0B8
int cMessCommon::isPageEndCode(unsigned short c)
{
    if (!(c >> 15))
        return 0;
    switch (c & 0xFF00) {
    case 0x8000: case 0x8100: case 0x8200: case 0x8300: case 0x8900: case 0x9000:
    case 0xA100: case 0xA500: case 0xA600: case 0xA700:
    case 0xD200: case 0xD900: case 0xDA00:
    case 0xE200: case 0xE400: case 0xE500: case 0xE700:
        return 1;
    }
    return 0;
}
