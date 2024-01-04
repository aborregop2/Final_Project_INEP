#include "Videoconsola.h"

Videoconsola::Videoconsola()
{

}

typename Videoconsola::Videoconsola* Videoconsola::getInstance()
{
    if (instance == nullptr){
        instance = new Videoconsola();
    }
    return instance;
}

optional<PassarellaUsuari> Videoconsola::obteUsuari()
{
    return usuari;
}


void Videoconsola::iniciaSessio(PassarellaUsuari u)
{
    usuari = u;
}

void Videoconsola::tancaSessio()
{
    usuari = nullopt;
}