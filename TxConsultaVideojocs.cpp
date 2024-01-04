#include "TxConsultaViodeojocs.h"
 
TxConsultaVideojocs:: TxConsultaVideojocs()
{

}
 
vector<string> TxConsultaVideojocs::obteResultat()
{
    return resultat;
}

void TxConsultaVideojocs::executar()
{
    CercadoraVideojoc cVI;
    vector<PassarellaVideojoc> pv = cVI.cercaTotsVideojocs();

    for (unsigned int i = 0; i < pv.size(); i++) {
        resultat.push_back(pv[i].obteNom());
    }
}