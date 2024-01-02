#include "PassarellaVideojoc.h"

PassarellaVideojoc::PassarellaVideojoc(string nomV, int qeV, string dL, int minV, string gV): nom(nomV), qualificacioEdat(qeV), dataLlansament(dL), minsEstimat(minV), genere(gV) {
    
}

string PassarellaVideojoc::getNom()
{
    return nom; 
}
int PassarellaVideojoc::getQualifiacioEdat()
{
    return qualificacioEdat;
}
string PassarellaVideojoc::getDataLlansament()
{
    return dataLlansament;
}
int PassarellaVideojoc::getMinsEstimat()
{
    return minsEstimat;
}
string PassarellaVideojoc::getGenere()
{
    return genere;
}
