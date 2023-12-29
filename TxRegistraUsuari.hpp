#include <iostream>
using namespace std;

class TxRegistraUsuari{
    private:
        string nomU;
        string sobrenomU;
        string contrasenyaU;
        string correuElectronicU;
        string dataNaixementU;
        
        void executarp();

    public:
        TxRegistraUsuari(string nU,string sU,string cU,string ceU,string dnU);
        void executar();
};