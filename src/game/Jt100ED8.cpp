// pl01::SetParent: sole switch and jump table of 0x100ED8.
extern char CoreSave[];
extern "C" int getCostumeNo__9cCoreSave(char *);

static inline int IsSet(const int &v) { return v != 0; }
static inline char *Slot0(char *o)
{
    if (IsSet(*(unsigned char *)(o + 0x2B4)))
        return **(char ***)(o + 0x278);
    return 0;
}
static inline int InRange(const int &n, int i) { return i >= 0 && i < n; }
static inline char *SlotN(char *o, int i)
{
    if ((unsigned char)InRange(*(unsigned char *)(o + 0x2B4), i))
        return ((char **)*(char ***)(o + 0x278))[i];
    return 0;
}

// FUNCTION: GAME 0x100ED8
extern "C" void SetParent__4pl01P4cObjUi(char *self, char *par, int idx)
{
    if (par) {
        char *a = Slot0(self);
        if (a) {
            char *c = SlotN(par, idx);
            if (c) {
                int v;
                *(char **)(a + 0x148) = c;
                *(int *)(self + 0x20D4) = idx;
                *(char **)(self + 0x20D0) = par;
                *(char **)(self + 0x20A8) = par;
                switch (getCostumeNo__9cCoreSave(CoreSave)) {
                case 2:
                case 3:
                    v = 0xB;
                    break;
                case 4:
                case 5:
                    v = 7;
                    break;
                case 0:
                case 1:
                case 6:
                case 7:
                default:
                    v = 0xC;
                    break;
                }
                *(int *)(self + 0x2088) = v;
            }
        }
    }
}
