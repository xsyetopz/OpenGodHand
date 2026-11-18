#ifndef COMITEM_H
#define COMITEM_H

#include "game/cOmBase.h"

class cOmItem : public cOmBase {
public:
    void setGetRangeLong(bool on);
    void setScrCheck(bool on);

    char _pad5B8[0x676 - 0x5B8];
    unsigned char m_itemFlags;
};

#endif
