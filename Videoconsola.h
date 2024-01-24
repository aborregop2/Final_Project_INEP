#ifndef VIDEOCONSOLA_H
#define VIDEOCONSOLA_H

#include <iostream>
#include <optional>
#include "PassarellaUsuari.h"

using namespace std;

class Videoconsola {
    private:
        optional<PassarellaUsuari> usuari;
        //static Videoconsola* instance;
        Videoconsola();

    public:
        static Videoconsola& getInstance();
        optional<PassarellaUsuari> obteUsuari();
        //static Videoconsola* getInstance();

        void iniciaSessio(PassarellaUsuari u);
        void tancaSessio();

        void modifyUsuari(string nom, string contrasenya, string correu, string data);
};

#endif