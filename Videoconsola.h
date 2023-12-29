#ifndef VIDEOCONSOLA_H
#define VIDEOCONSOLA_H

#include <iostream>
#include <optional>
#include "PassarellaUsuari.h"


using namespace std;

class Videoconsola {
    private:
        optional<PassarellaUsuari> usuari;
        Videoconsola();

    public:
        
        optional<PassarellaUsuari> obteUsuari();
        ~Videoconsola();

        static Videoconsola& getInstance();

        void iniciaSessio(PassarellaUsuari u);
};

#endif