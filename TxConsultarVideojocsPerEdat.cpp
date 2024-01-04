#include "TxConsultarVideojocsPerEdat.h"
#include "CercadoraVideojoc.h"
#include "PassarellaVideojoc.h"

TxConsultarVideojocsPerEdat::TxConsultarVideojocsPerEdat(int edatU) : edat(edatU)
{

}

void TxConsultarVideojocsPerEdat::executar()
{
    CercadoraVideojoc cVI;
    vector<PassarellaVideojoc> pv = cVI.cercaVideojocsEdat(edat);
    for (unsigned int i = 0; i < pv.size(); i++) {
        resultat.push_back(pv[i].obteNom());
    }
}

vector<string> TxConsultarVideojocsPerEdat::obteResultat()
{
    return resultat;
}