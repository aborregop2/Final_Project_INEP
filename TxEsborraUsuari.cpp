#include "TxEsborraUsuari.h"
#include "PasarellaUsuari.h"
#include "Videoconsola.h"

TxEsborraUsuari::TxEsborraUsuari(string contraU) : contrasenyaU(contraU)
{

}

void TxEsborraUsuari::executar()
{
    Videoconsola& v = Videoconsola::getInstance();
    PasarellaUsuari usu = v.obteUsuari();

    string c = usu.obteContrasenya();
    if (c != contrasenyaU) {
        cout << "La contrasenya no es correcta l'usuari, no s'ha esborrrat" << endl;
        return;
    }

    usu.esborra();
}