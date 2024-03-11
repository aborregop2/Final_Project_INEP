#include "TxIniciSessio.h"
#include "CercadoraUsuari.h"
#include "Videoconsola.h"

TxIniciSessio::TxIniciSessio(string sU,string cU) : sobrenomU(sU), contrasenyaU(cU)
{

}

void TxIniciSessio::executar() 
{
    CercadoraUsuari c;
    vector<PassarellaUsuari> vu = c.cercaUsuari(sobrenomU);

    string contr = vu[0].obteContrasenya();
    if (contr != contrasenyaU) {
        cerr << "Contrasenya Incorrecta" << endl;
    }

    Videoconsola& v = Videoconsola::getInstance();
    v.iniciaSessio(vu[0]);
}