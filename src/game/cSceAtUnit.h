#ifndef CSCEATUNIT_H
#define CSCEATUNIT_H

enum eActType { ACT_0 };

enum eSceAt_id { SCEAT_0 };
enum eAreaHitType { AHT_0 };
enum eAreaTrgType { ATT_0 };
enum eScehitType { SHT_0 };

class cSceAtUnit {
public:
    void AtInit(eSceAt_id id, eAreaHitType hit, eAreaTrgType trg, eActType act);
    void ActTypeSet(eActType actType, eActType actType2);
    void SetEnable(unsigned char);
    void SetDisable(unsigned char);

    char _pad0[0x34];
    unsigned char m_flags;
    unsigned char m_type;
    unsigned short m_unk36;
    char _pad38[0x3A - 0x38];
    unsigned char m_unk3A;
    unsigned char m_unk3B;
    unsigned int m_unk3C;
    char _pad40[4];
    unsigned char m_unk44;
    char _pad45[0x4E - 0x45];
    unsigned char m_unk4E;
    char _pad4F[0x54 - 0x4F];
    unsigned char m_unk54;
    char _pad55[0x70 - 0x55];
    void *m_unk70;
    void *m_unk74;
    char _pad78[0x9C - 0x78];
};

extern "C" void *memset(void *, int, unsigned int);
extern "C" void func_002C0E20(cSceAtUnit *);
extern "C" void func_002C0E60(cSceAtUnit *);

#endif
