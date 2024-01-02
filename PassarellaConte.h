#ifndef PASSARELLA_CONTE_H
#define PASSARELLA_CONTE_H

using namespace std;
class PassarellaConte{
    private:
        string nomV;
        string nomP;

    public:
        PassarellaConte(string nomVideojoc, string nomPaquet);
        string obteNomVideojoc();
        string obteNomPaquet();
};


#endif
