#ifndef PASSARELLA_VIDEOJOC_H
#define PASSARELLA_VIDEOJOC_H

#include <iostream>
using namespace std;

class PassarellaVideojoc{
    private:
        string nom;
        int qualificacioEdat;
        string dataLlansament;
        int minsEstimat;
        string genere;

    public:
        PassarellaVideojoc();
        PassarellaVideojoc(string nomV, int qeV, string dL, int minV, string gV);
        
        string obteNom();
        int obteQualifiacioEdat();
        string obteDataLlansament();
        int obteMinsEstimat();
        string obteGenere();

        void modifyNom(string Nom);
        void modifyQualificacioEdat(int Qe);
        void modifyDataLlansament(string Dl);
        void modifyMinsEstimat(int Me);
        void modifyGenere(string Ge);
};




#endif