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
    int estalvi;
    vector<InfoVid> res;
};