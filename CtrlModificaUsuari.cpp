#include "TxConsultaUsuari.h"
#include "CtrlModificaUsuari.h"
#include "PasarellaUsuari.h"


string[] CtrlModificaUsuari::consultaUsuari()
{
    TxConsultaUsuari txCU;
    txCU.executar();
    string infoUsu[4] = txCU.obteResultat();
    PassarellaUsuari usu = txCU.obteUsuari();
    usuari = usu;

    return infoUsu;
}

void TxConsultaUsuari::modificaUsuari(string nomU, string contraU, string correuU, string neixU)
{
    PassarellaUsuari usuari(nomU, contraU, correuU, neixU);
    usuari.posaNom(nomU);
    usuari.posaContrasenya(contraU);
    usuari.posaCorreuElectronic(correuU);
    usuari.posaDataNaixement(neixU);
}