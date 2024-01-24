#include "PassarellaConte.h"
#include "CercadoraConte.h"

PassarellaConte::PassarellaConte()
{

}

PassarellaConte::PassarellaConte(string nomVideojoc, string nomPaquet): nomV(nomVideojoc), nomP(nomPaquet)
{

}

string PassarellaConte::obteNomVideojoc()
{
    return nomV;
}

string PassarellaConte::obteNomPaquet()
{
    return nomP;
}

void PassarellaConte::modifyNomPaq(string nompaq)
{
    nomP = nompaq;
}

void PassarellaConte::modifyNomVid(string nomvid)
{
    nomV = nomvid;
}


