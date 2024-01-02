#include "PassarellaConte.h"
#include "CercadoraConte.h"

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


