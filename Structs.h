#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <vector>

using namespace std;

struct InfoVid{
    string nomVid;
    string descVid;
    string preuVid;
    string dataVid;
};

struct InfoPaq{
    string nomPaq;
    string descPaq;
    string preuPaq;
    string dataPaq;
    float estalvi;
    vector<InfoVid> res;
};




#endif