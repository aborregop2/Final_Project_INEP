#include <iostream>
using namespace std;

class PassarellaUsuari{
    private:
        string nom;
        string sobrenom;
        string contrasenya;
        string correuElectronic;
        string dataNaixement;
        
        void insereixp();
    public:

    PassarellaUsuari(string nU,string sU,string cU,string ceU,string dnU);
    void insereix();
};