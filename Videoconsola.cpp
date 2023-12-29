#include "Videoconsola.h"

optional<PassarellaUsuari> Videoconsola::obteUsuari()
{
    return usuari;
}

Videoconsola::~Videoconsola()
{

}



Videoconsola& Videoconsola::getInstance()
{
    static Videoconsola instance;
    return instance;
}

void Videoconsola::iniciaSessio(PassarellaUsuari u)
{
    usuari = u;
}