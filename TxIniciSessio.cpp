#include "TxIniciSessio.h"
#include "CercadoraUsuari.h"
#include "Videoconsola.h"

TxIniciSessio::TxIniciSessio(string sU,string cU) : sobrenomU(sU), contrasenyaU(cU)
{

}

void TxIniciSessio::executar() 
{
    CercadoraUsuari c;
    PassarellaUsuari u = c.cercaUsuari(sobrenomU);

    string contr = u.obteContrasenya();
    if (contr != contrasenyaU) {
        //Error 
    }

    Videoconsola& v = Videoconsola::getInstance();
    v.iniciaSessio(u);
}