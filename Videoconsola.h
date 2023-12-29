#include <iostream>
#include "PassarellaUsuari.h"
#include <optional>

using namespace std;

class Videoconsola {
    private:
        optional<PassarellaUsuari> usuari;
        Videoconsola()
        {
            
        }

    public:
        
        optional<PassarellaUsuari> obteUsuari()
        {
            return usuari;
        }
        ~Videoconsola()
        {

        }

        static Videoconsola& getInstance()
        {
            static Videoconsola instance;
            return instance;
        }

        void iniciaSessio(PassarellaUsuari u)
        {
            usuari = u;
        }
};