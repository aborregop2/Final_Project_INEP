#include "CtrlModificaUsuari.h"
#include "TxConsultaUsuari.h"
#include "PassarellaUsuari.h"
#include "Videoconsola.h"

CtrlModificaUsuari::CtrlModificaUsuari()
{

}

vector<string> CtrlModificaUsuari::consultaUsuari()
{
    TxConsultaUsuari txCU;
    txCU.executar();
    vector<string> infoUsu = txCU.obteResultat();
    PassarellaUsuari usu = txCU.obteUsuari();
    usuari = usu;

    return infoUsu;
}

void CtrlModificaUsuari::modificaUsuari(string nomU, string sobrU, string contraU, string correuU, string neixU)
{
    PassarellaUsuari usuari(nomU, sobrU, contraU, correuU, neixU);
    usuari.posaNom(nomU);
    usuari.posaContrasenya(contraU);
    usuari.posaCorreuElectronic(correuU);
    usuari.posaDataNaixement(neixU);
    Videoconsola& v = Videoconsola::getInstance();
    v.modifyUsuari(nomU, contraU, correuU, neixU);
}