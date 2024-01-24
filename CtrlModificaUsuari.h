#ifndef CTRL_MODIFICA_USUARI_H
#define CTRL_MODIFICA_USUARI_H

#include "PassarellaUsuari.h"
#include <iostream>
#include <vector>
using namespace std;

class CtrlModificaUsuari{
    private:
        PassarellaUsuari usuari;
    public:
        CtrlModificaUsuari();
        vector<string> consultaUsuari();
        void modificaUsuari(string nomU, string sorbU, string contraU, string correuU, string neixU);
};

#endif