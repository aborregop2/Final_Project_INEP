#include "TxTancaSessio.h"
#include "Videoconsola.h"

TxTancaSessio::TxTancaSessio() 
{

}

void TxTancaSessio::executar()
{
    Videoconsola& v = Videoconsola::getInstance();
    v.tancaSessio();
}