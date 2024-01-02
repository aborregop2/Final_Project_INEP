#include "PassarellaVideojoc.h"

PassarellaVideojoc::PassarellaVideojoc(string nomV, int qeV, string dL, int minV, string gV): nom(nomV), qualificacioEdat(qeV), dataLlansament(dL), minsEstimat(minV), genere(gV) {
    
}

string PassarellaVideojoc::obteNom()
{
    return nom; 
}
int PassarellaVideojoc::obteQualifiacioEdat()
{
    return qualificacioEdat;
}
string PassarellaVideojoc::obteDataLlansament()
{
    return dataLlansament;
}
int PassarellaVideojoc::obteMinsEstimat()
{
    return minsEstimat;
}
string PassarellaVideojoc::obteGenere()
{
    return genere;
}
