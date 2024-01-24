#include "TxIniciSessio.h"
#include "CercadoraUsuari.h"
#include "Videoconsola.h"

TxIniciSessio::TxIniciSessio(string sU,string cU) : sobrenomU(sU), contrasenyaU(cU)
{

}

void TxIniciSessio::executar() 
{
    CercadoraUsuari c;
    vector<PassarellaUsuari> vu = c.cercaUsuari(sobrenomU); // Error aqui
    string contr = vu[0].obteContrasenya();
    string sobr = vu[0].obteSobrenom();
    if (contr != contrasenyaU or sobr == "") {
        throw exception();
        return;
    }
    else {
        Videoconsola& v = Videoconsola::getInstance();
        v.iniciaSessio(vu[0]);
    }

    
}