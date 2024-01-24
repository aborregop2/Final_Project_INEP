#include "TxConsultaUsuari.h"
#include "Videoconsola.h"
#include "PassarellaUsuari.h"

TxConsultaUsuari::TxConsultaUsuari()
{
    
}
vector<string> TxConsultaUsuari::obteResultat() 
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
   
    resultat.push_back(usu.obteNom());
    resultat.push_back(usu.obteSobrenom());
    resultat.push_back(usu.obteCorreuElectronic());
    resultat.push_back(usu.obteDataNaixament());
  
}


