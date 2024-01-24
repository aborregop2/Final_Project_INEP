#include "TxEsborraUsuari.h"
#include "PassarellaUsuari.h"
#include "Videoconsola.h"

TxEsborraUsuari::TxEsborraUsuari(string contraU) : contrasenyaU(contraU)
{

}

void TxEsborraUsuari::executar()
{
    Videoconsola& v = Videoconsola::getInstance();
    PassarellaUsuari usu = v.obteUsuari().value();

    string c = usu.obteContrasenya();
    if (c != contrasenyaU) {
        cout << "La contrasenya no es correcta l'usuari, no s'ha esborrrat" << endl;
        return;
    }

    usu.esborra();
}