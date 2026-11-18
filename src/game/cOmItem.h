#ifndef COMITEM_H
#define COMITEM_H

#include "game/cOmBase.h"

class cOmItem : public cOmBase {
public:
    void setGetRangeLong(bool on);
    void setScrCheck(bool on);
    void setBlockObj(const char *name);

    char _pad5B8[0x668 - 0x5B8];
    unsigned long m_blockObj;
    char _pad670[0x676 - 0x670];
    unsigned char m_itemFlags;
};

#endif
