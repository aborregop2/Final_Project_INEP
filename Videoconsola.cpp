#include "Videoconsola.h"

Videoconsola::Videoconsola()
{

}

Videoconsola& Videoconsola::getInstance() {
    static Videoconsola instance;
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

void Videoconsola::modifyUsuari(string nom, string contrasenya, string correu, string data)
{
    if(!nom.empty()) usuari.value().modifyNom(nom);
    if(!contrasenya.empty()) usuari.value().modifyContrasenya(contrasenya);
    if(!correu.empty()) usuari.value().modifyCorreuElectronic(correu);
    if(!data.empty()) usuari.value().modifyDataNaixement(data);
}