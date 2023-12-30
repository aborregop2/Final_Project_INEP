#include "CtrlModificaUsuari.h"
#include "TxConsultaUsuari.h"
#include "PasarellaUsuari.h"

CtrlModificaUsuari::CtrlModificaUsuari()
{

}

string[] CtrlModificaUsuari::consultaUsuari()
{
    TxConsultaUsuari txCU;
    txCU.executar();
    string infoUsu[4] = txCU.obteResultat();
    PassarellaUsuari usu = txCU.obteUsuari();
    usuari = usu;

    return infoUsu;
}

void CtrlModificaUsuari::modificaUsuari(string nomU, string contraU, string correuU, string neixU)
{
    PassarellaUsuari usuari(nomU, contraU, correuU, neixU);
    usuari.posaNom(nomU);
    usuari.posaContrasenya(contraU);
    usuari.posaCorreuElectronic(correuU);
    usuari.posaDataNaixement(neixU);
}