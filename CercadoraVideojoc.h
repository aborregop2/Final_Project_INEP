#ifndef CERCADORA_VIDEOJOC_H
#define CERCADORA_VIDEOJOC_H

#include <iostream>
#include <vector>
#include "PassarellaVideojoc.h"

using namespace std;

class CercadoraVideojoc {
    public:
        CercadoraVideojoc();
        vector<PassarellaVideojoc> cercaVideojoc(string nomV);
        vector<PassarellaVideojoc> cercaTotsVideojocs();
        vector<PassarellaVideojoc> cercaVideojocsEdat(int edatV);
        vector<PassarellaVideojoc> cercaVideojocsNovetat(string dataV);

};



#endif