#ifndef CMODEL_H
#define CMODEL_H

class cModel {
public:
    unsigned char getMeshNum() const;

    char _pad0[0x2B1];
    unsigned char m_meshNum;
};

#endif
