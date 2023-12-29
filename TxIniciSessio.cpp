#include "TxIniciSessio.hpp"
#include "CercadoraUsuari.hpp"
#include "Videoconsola.hpp"

TxIniciSessio::TxIniciSessio(string sU,string cU) : sobrenomU(sU), contrasenyaU(cU)
{}

void TxIniciSessio::executar() 
{
    CercadoraUsuari c;
    PasarellaUsuari u = c.cercaUsuari(sobrenomU);

    string contr = u.obteContrasenya();
    if (contr != contrasenyaU) {
        //Activar ErrorContrasenya
    }

    Videoconsola& v = Videoconsola::getInstance();
    v.iniciaSessio(u);
}