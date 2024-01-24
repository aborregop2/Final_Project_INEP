#include "PassarellaVideojoc.h"


PassarellaVideojoc::PassarellaVideojoc() : qualificacioEdat(0), minsEstimat(0)
{

}

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

void PassarellaVideojoc::modifyNom(string Nom)
{
    nom = Nom;
}
void PassarellaVideojoc::modifyQualificacioEdat(int Qe)
{
    qualificacioEdat = Qe;
}
void PassarellaVideojoc::modifyDataLlansament(string Dl)
{
    dataLlansament = Dl;
}
void PassarellaVideojoc::modifyMinsEstimat(int Me)
{
    minsEstimat = Me;
}

void PassarellaVideojoc::modifyGenere(string Ge)
{
    genere = Ge;
}