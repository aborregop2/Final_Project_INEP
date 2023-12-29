#ifndef CERCADORA_USUARI_H
#define CERCADORA_USUARI_H

#include <iostream>
#include "PassarellaUsuari.h"

using namespace std;

class CercadoraUsuari {
    public:
        PassarellaUsuari cercaUsuari(string sobrenomU);
};

#endif