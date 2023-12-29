#include <iostream>
#include "PassarellaUsuari.hpp"
#include <optional>

using namespace std;

class Videoconsola {
    private:
        optional<PasarellaUsuari> usuari;

    public:
        Videoconsola() = delete;
        static optinal<PassarellaUsuari> obteUsuari();
};