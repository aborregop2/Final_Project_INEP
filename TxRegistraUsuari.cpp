#include "TxRegistraUsuari.h"
#include "PassarellaUsuari.h"

TxRegistraUsuari::TxRegistraUsuari(string nU,string sU,string cU,string ceU,string dnU) 
    : nomU(nU), sobrenomU(sU),contrasenyaU(cU), correuElectronicU(ceU), dataNaixementU(dnU)
{

}

void TxRegistraUsuari::executar()
{
    PassarellaUsuari u(nomU, sobrenomU, contrasenyaU, correuElectronicU, dataNaixementU);
    u.insereix();
}
