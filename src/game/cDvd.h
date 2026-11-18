#ifndef CDVD_H
#define CDVD_H

enum eDvdId {
    eDvdId_0 = 0
};

class cDvd {
public:
    bool FileExist(const char *);
    int Check(eDvdId);
    void CheckWait(eDvdId);
};

#endif
