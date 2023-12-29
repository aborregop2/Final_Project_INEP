#include <iostream>
#include "PassarellaUsuari.h"
#include <optional>

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