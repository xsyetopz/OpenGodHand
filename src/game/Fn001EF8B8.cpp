// Fn001EF8B8: count live enemies in the list.
extern "C" int checkDeadFlag__7cEmBase(void *);
struct Node { void *pad; Node *next; char *em; };
extern Node *D_005869F0;

#ifdef NONMATCHING
// DRAFT: GAME 0x001EF8B8
// 37 words differ: original branches (slti/bnez, daddu 0) for the range flags, ours emits movz and 24 bytes less; tried inline helper, if-form, && and & forms (34-37)
extern "C" int func_001EF8B8(void) {
    Node *n = D_005869F0;
    int c = 0;
    if (n) {
        do {
            char *e = n->em;
            if (e) {
                int s = *(unsigned short *)(e + 0x2FE);
                unsigned char a = 0;
                if (s >= 0x200) a = s < 0x300;
                if (a) {
                    unsigned char b = 0;
                    if (s >= 0x2A0) b = s < 0x300;
                    if (!b && checkDeadFlag__7cEmBase(e) != 1)
                        c += *(short *)(e + 0x54A) > 0;
                }
            }
            n = n->next;
        } while (n);
    }
    return c;
}
#endif
