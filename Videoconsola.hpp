#include <iostream>
#include "PassarellaUsuari.hpp"
#include <optional>

using namespace std;

class Videoconsola {
    private:
        optional<PassarellaUsuari> usuari;
        Videoconsola();

    public:
        
        optional<PassarellaUsuari> obteUsuari();
        static Videoconsola& getInstance();
        void iniciaSessio(PassarellaUsuari u);
};