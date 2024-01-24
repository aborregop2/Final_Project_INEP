#include "PassarellaElemCompra.h"

string PassarellaElemCompra::obteNom()
{
    return nom;
}

string PassarellaElemCompra::obteDescripcio()
{
    return descripcio;
}

string PassarellaElemCompra::obtePreu()
{
    return preu;
}

string PassarellaElemCompra::obteTipus()
{
    return tipus;
}

void PassarellaElemCompra::modifyNom(string nomEc)
{
    nom = nomEc;
}
void PassarellaElemCompra::modifyDesc(string descEc)
{
    descripcio = descEc;
}
void PassarellaElemCompra::modifyPreu(string preuEc)
{
    preu = preuEc;
}
void PassarellaElemCompra::modifyTipus(string tipusEc)
{
    tipus = tipusEc;
}