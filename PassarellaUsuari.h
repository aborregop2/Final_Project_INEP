#ifndef PASARELLA_USUARI_H
#define PASARELLA_USUARI_H

#include <iostream>
using namespace std;
#include <pqxx/pqxx>

class PassarellaUsuari{
    private:
        string nom;
        string sobrenom;
        string contrasenya;
        string correuElectronic;
        string dataNaixement;
        
    public:
        PassarellaUsuari(string nU,string sU,string cU,string ceU,string dnU);

        ~PassarellaUsuari();
        string obteContrasenya();
        void insereix();
        PassarellaUsuari& operator=(const PassarellaUsuari &p);
};

#endif