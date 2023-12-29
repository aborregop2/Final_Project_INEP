#include "PassarellaUsuari.h"
#include <iostream>
#include <string>
using namespace std;

class TxRegistraUsuari{
    private:
        string nomU;
        string sobrenomU;
        string contrasenyaU;
        string correuElectronicU;
        string dataNaixementU;

    public:
        TxRegistraUsuari(string nU,string sU,string cU,string ceU,string dnU);
        ~TxRegistraUsuari();
        void executar();
        
};
