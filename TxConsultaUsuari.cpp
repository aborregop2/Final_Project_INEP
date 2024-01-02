#include "TxConsultaUsuari.h"
#include "Videoconsola.h"
#include "PassarellaUsuari.h"

TxConsultaUsuari::TxConsultaUsuari()
{
    
}
string* TxConsultaUsuari::obteResultat() 
{ 
    return resultat;
}    

PassarellaUsuari TxConsultaUsuari::obteUsuari()
{
    return usuari;
}

void TxConsultaUsuari::executar()
{
    Videoconsola& v = Videoconsola::getInstance();
    PassarellaUsuari usu = v.obteUsuari().value();

    string infoUsu[4];
    infoUsu[0] = usu.obteNom();
    infoUsu[1] = usu.obteSobrenom();
    infoUsu[2] = usu.obteCorreuElectronic();
    infoUsu[3] = usu.obteDataNaixament();

    usuari = usu;
    resultat = infoUsu;
}


