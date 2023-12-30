#include "TxConsultaUsuari.h"
#include "Videoconsola.h"
#include "PasarellaUsuari.h"

string[] TxConsultaUsuari::obteResultat() 
{ 
    return infoUsu;
}    

PassarellaUsuari TxConsultaUsuari::obteUsuari()
{
    return usuari;
}

void executar()
{
    Videoconsola& v = Videoconsola::getInstance();
    PasarellaUsuari usu = v.obteUsuari();

    infoUsu[0] = usu.obteNom();
    infoUsu[1] = usu.obteSobrenom();
    infoUsu[2] = usu.obteCorreuElectronic();
    infoUsu[3] = usu.obteDataNaixament();

    usuari = u;
    resultat = infoUsu;
}


