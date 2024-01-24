#ifndef CERCADORA_CONTE_H
#define CERCADORA_CONTE_H
#include "PassarellaConte.h"
#include <iostream>
#include <vector>

using namespace std;

class CercadoraConte{
    public:
        CercadoraConte();
        vector<PassarellaConte> cercaConteV(string nomV);
        vector<PassarellaConte> cercaConteP(string nomP);
};


#endif