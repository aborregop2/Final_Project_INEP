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
        
vector<string> TxConsultaVideojoc::obteResultat()
{
    return resultat;
}


void TxConsultaVideojoc::executar()
{
    CercadoraVideojoc cv;
    vector<PassarellaVideojoc> v = cv.cercaVideojoc(nom);
    string Errorvid = "ERROR: No s'ha trobat el videojoc que buscaves\n";
    if (v.empty()) throw(Errorvid);
    CercadoraElemCompra cec;
    vector<PassarellaElemCompra> vv = cec.cercaElement(nom);

    resultat.push_back(v[0].obteNom());
    resultat.push_back(vv[0].obteDescripcio());
    resultat.push_back(to_string(v[0].obteQualifiacioEdat()));
    resultat.push_back(v[0].obteDataLlansament());
    resultat.push_back(to_string(v[0].obteMinsEstimat()));
    resultat.push_back(v[0].obteGenere());
    resultat.push_back(vv[0].obtePreu());
}