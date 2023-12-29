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
        TxIniciSessio(string sU,string cU) : sobrenomU(sU), contrasenyaU(cU)
        {

        }
        ~TxIniciSessio()
        {

        }
        void executar()
        {
            CercadoraUsuari c;
            PassarellaUsuari u = c.cercaUsuari(sobrenomU);

            string contr = u.obteContrasenya();
            if (contr != contrasenyaU) {
                cout << "Joder" << endl;
            }

            Videoconsola& v = Videoconsola::getInstance();
            v.iniciaSessio(u); 
        }
};