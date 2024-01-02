#ifndef PASSARELLA_USUARI_H
#define PASSARELLA_USUARI_H

#include <iostream>
using namespace std;

class PassarellaUsuari{
    private:
        string nom;
        string sobrenom;
        string contrasenya;
        string correuElectronic;
        string dataNaixement;
        
    public:
        PassarellaUsuari(string nU,string sU,string cU,string ceU,string dnU);
        PassarellaUsuari(string nU,string cU,string ceU,string dnU);

        PassarellaUsuari();
        string obteContrasenya();
        void insereix();
        void esborra();

        PassarellaUsuari& operator=(const PassarellaUsuari &p);
        
        //Getters
        string obteNom();
        string obteSobrenom();
        string obteCorreuElectronic();
        string obteDataNaixament();
        
        //Setters
        void posaNom(string nomU);
        void posaContrasenya(string contraU);
        void posaCorreuElectronic(string correuU);
        void posaDataNaixement(string neixU);
};

#endif