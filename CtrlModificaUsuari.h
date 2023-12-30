#ifndef PASSARELLA_USUARI_H
#define PASSARELLA_USUARI_H

#include "PassarellaUsuari.h"
#include <iostream>
using namespace std;

class CtrlModificaUsuari{
    private:
        PassarellaUsuari usuari;
    public:
        string[] consultaUsuari();
        void modificaUsuari(string nomU, string contraU, string correuU, string neixU);
};

#endif