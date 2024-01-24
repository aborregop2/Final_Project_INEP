#ifndef PASSARELLA_CONTE_H
#define PASSARELLA_CONTE_H
#include <iostream>
using namespace std;

class PassarellaConte{
    private:
        string nomV;
        string nomP;

    public:
        PassarellaConte();
        PassarellaConte(string nomVideojoc, string nomPaquet);
        string obteNomVideojoc();
        string obteNomPaquet();
        void modifyNomPaq(string nompaq);
        void modifyNomVid(string nomvid);
};


#endif
