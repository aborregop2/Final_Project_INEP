#include <iostream>
using namespace std;

class PassarellaCompra{
    private:
        string usuari;
        string element;
        string data;

    public:

        string obteUsuari();
        string obteElementCompra();
        string obteData();
};