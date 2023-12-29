#include <iostream>
#include "Videoconsola.h"
#include "CercadoraUsuari.h"
#include "PassarellaUsuari.h"
using namespace std;

class TxIniciSessio{
    private:
        string sobrenomU;
        string contrasenyaU;

    public:
        TxIniciSessio(string sU,string cU);
        ~TxIniciSessio();
        void executar();
};