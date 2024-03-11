#include "TxConsultaVideojoc.h"
#include "CercadoraVideojoc.h"
#include "PassarellaVideojoc.h"
#include "PassarellaElemCompra.h"
#include "CercadoraElemCompra.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std; 

TxConsultaVideojoc::TxConsultaVideojoc(string nomV) : nom(nomV)
{

}
        
string* TxConsultaVideojoc::obteResultat()
{
    return resultat;
}


void TxConsultaVideojoc::executar()
{
    CercadoraVideojoc cv;
    vector<PassarellaVideojoc> v = cv.cercaVideojoc(nom);
    CercadoraElemCompra cec;
    vector<PassarellaElemCompra> vv = cec.cercaElement(nom);

    resultat[0] = v[0].obteNom();
    resultat[1] = vv[0].obteDescripcio();
    resultat[2] = to_string(v[0].obteQualifiacioEdat());
    resultat[3] = v[0].obteDataLlansament();
    resultat[4] = to_string(v[0].obteMinsEstimat());
    resultat[5] = v[0].obteGenere();
    resultat[6] = vv[0].obtePreu();
}