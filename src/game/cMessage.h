#ifndef CMESSAGE_H
#define CMESSAGE_H

struct cMessageNode {
    unsigned short m_workId;
    char _pad2[6];
    cMessageNode *m_next;
};

class cMessage {
public:
    char *getMessageAddr(unsigned short no) const;
    cMessageNode *searchWorkId(unsigned short id) const;
    void closeAll();
    void deleteAll();
    bool ckMessage(unsigned short no);

    char *m_table[4];
    cMessageNode *m_list;
};

extern "C" cMessageNode *func_002AED40(cMessage *, unsigned short);
extern "C" void func_002B2400(cMessageNode *);
extern "C" cMessageNode *func_002AEF10(cMessage *, cMessageNode *);

#endif
