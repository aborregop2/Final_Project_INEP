#include "TxConsultaNovetatsVideojocs.h"
#include "CercadoraVideojoc.h"
#include "PassarellaVideojoc.h"



TxConsultaNovetatsVideojocs::TxConsultaNovetatsVideojocs(string d) : data(d)
{
    
}

void TxConsultaNovetatsVideojocs::executar()
{
    CercadoraVideojoc cVI;
    vector<PassarellaVideojoc> pv = cVI.cercaVideojocsNovetat(data);
    for (unsigned int i = 0; i < pv.size(); i++) {
        resultat.push_back(pv[i].obteNom());
    }
}
        
        
vector<string> TxConsultaNovetatsVideojocs::obteResultat()
{
    return resultat;
}
