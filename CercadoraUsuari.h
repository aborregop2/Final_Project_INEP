#ifndef CERCADORA_USUARI_H
#define CERCADORA_USUARI_H

#include <iostream>
#include <vector>
#include "PassarellaUsuari.h"

using namespace std;

class CercadoraUsuari {
    public:
        CercadoraUsuari();
        vector<PassarellaUsuari> cercaUsuari(string sobrenomU);

};

#endif