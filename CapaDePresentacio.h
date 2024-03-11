#ifndef CAPA_DE_PRESENTACIO_H
#define CAPA_DE_PRESENTACIO_H

#include <iostream>
#include "TxRegistraUsuari.h"
#include "TxIniciSessio.h"
#include "TxTancaSessio.h"
#include "TxConsultaUsuari.h"
#include "TxInfoCompres.h"
#include "CtrlModificaUsuari.h"
#include "TxEsborraUsuari.h"
#include "TxConsultaVideojoc.h"
#include "TxComprarVideojoc.h"
#include "TxComprarPaquet.h"
#include "TxConsultaCompres.h"
#include "CercadoraConte.h"
#include "PassarellaConte.h"
#include "TxConsultaVideojocs.h"
#include "PassarellaVideojoc.h"
#include "TxConsultaNovetatsVideojocs.h"
#include "TxConsultarVideojocsPerEdat.h"
#include "TxConsultarPaquet.h"
#include "TxConsultarPaquets.h"
#include "Structs.h"




using namespace std;

class CapaDePresentacio {
    private:
        //static CapaDePresentacio* instance;
        CapaDePresentacio();

    public:
        //static CapaDePresentacio* getInstance();
        /*Implementaci� de inst�ncia com en El fitxer de provaOO*/

        //////////////////////////////////

        static CapaDePresentacio& getInstance() {
            static CapaDePresentacio instance;
            return instance; 
        }

        /////////////////////////////////
        
        /** - USER CASES - **/
        void iniciSessio();
        void tancaSessio();
        void registrarUsuari();
        void consultaUsuari();
        void modificaUsuari();
        void esborraUsuari();
        void comprarVideojoc();
        
        /** - VIDEOGAME CASES - **/
        void comprarPaquetVideojocs();
        void consultaCompres();
        void consultarVideojoc();
        void consultarVideojocs();
        void consultarVideojocsPerEdat();
        void consultarNovetatsVideojocs();
        void consultarPaquetVideojocs();
        void consultarPaquetsVideojocs();
    
};

#endif