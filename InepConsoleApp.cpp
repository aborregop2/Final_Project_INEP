#include "CapaDePresentacio.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

int main() {
		//CapaDePresentacio* cdp = CapaDePresentacio::getInstance();
		CapaDePresentacio& cdp = CapaDePresentacio::getInstance();
		string nc;

		while(true){
			inici:

			cout << "******************" << endl;
			cout << "  Menu Principal  " << endl;
			cout << "******************" << endl;
			cout << "1. Iniciar sessio" << endl;
			cout << "2. Registrar usuari" << endl;
			cout << "3. Sortir" << endl;
			cout << "Opcio: ";

			int opt;
			cin >> opt;
			
			if (opt == 1){
				cout << "Entro" << endl;
				cdp.iniciSessio();
			}
			else if(opt == 2){ 
				try {
					cdp.registrarUsuari();
				}
				catch (const exception& e) {
					std::cerr << "Error: " << e.what() << std::endl;
					return 1;
				}
				
			}
			else if (opt == 3){
				break;
			}
			else{
				cout << "** Opcio no valida **" << endl;
				cin >> opt;
			} 

			menuPrincipal:
			cout << "******************" << endl;
			cout << "  Menu Principal  " << endl;
			cout << "******************" << endl;
			cout << "1. Gestionar usuari" << endl;
			cout << "2. Gestionar compres" << endl;
			cout << "3. Consultar" << endl;
			cout << "4. Tancar sessio" << endl;
			cout << "5. Sortir" << endl; 
			cout << "Opcio: " ;
			
			cin >> opt;
			cout << endl;
			
			if (opt == 1){
				
				cout << "--------------------" << endl;
				cout << "  Gestionar usuari  " << endl;
				cout << "--------------------" << endl;
				cout << "1. Consultar usuari" << endl;
				cout << "2. Modificar usuari" << endl;
				cout << "3. Esborrar usuari" << endl;
				cout << "4. Tornar" << endl;
				cout << "Opcio: ";
				cin >> opt;
				
				if (opt == 1){
					cdp.consultaUsuari();
				}
				else if (opt == 2){
					cdp.modificaUsuari();
				}
				else if (opt == 3){
					cdp.esborraUsuari();
				}
				else if (opt == 4){
					goto menuPrincipal;
				}
				else{
					cout << "Opcio no valida" << endl;
					cin >> opt;
				} 
			}	
			else if (opt == 2){
				
				cout << "-----------------------------" << endl;
				cout << "      Gestionar compres      " << endl;
				cout << "-----------------------------" << endl;
				cout << "1. Comprar videojoc" << endl;
				cout << "2. Comprar paquet videojocs" << endl;
				cout << "3. Consultar compres" << endl;
				cout << "4. Tornar" << endl;
				cout << "Opcio: ";
				
				cin >> opt;
				cout << endl;
				
				if (opt == 1){
					cdp.comprarVideojoc();
				}
				else if (opt == 2){
					cdp.comprarPaquetVideojocs();
				}
				else if (opt == 3){
					cdp.consultaCompres();
				}
				else if (opt == 4){
					goto menuPrincipal;
				}
				else{
					cout << "Opcio no valida" << endl;
					cin >> opt;
				} 
			}
			else if (opt == 3){
				cout << "-------------------------------" << endl;
				cout << "      Consultes Videojocs      " << endl;
				cout << "-------------------------------" << endl;
				cout << "1. Consultar videojoc" << endl;
				cout << "2. Consultar videojocs" << endl;
				cout << "3. Consultar videojocs per edat" << endl;
				cout << "4. Consultar novetats videojocs" << endl;
				cout << "5. Consultar paquet videojocs" << endl;
				cout << "6. Consultar paquets videojocs" << endl;
				cout << "7. Tornar" << endl;
				cout << "Opcio: ";

				int consult;
				cin >> consult;
				if(consult == 1){
					cdp.consultarVideojoc();
				}
				else if(consult == 2){
					cdp.consultarVideojocs();
				}
				else if(consult == 3){
					cdp.consultarVideojocsPerEdat();
				}
				else if(consult == 4){
					cdp.consultarNovetatsVideojocs();
				}
				else if(consult == 5){
					cdp.consultarPaquetVideojocs();	
				}
				else if(consult == 6){
					cdp.consultarPaquetsVideojocs();
				}
				else if(consult == 7){
					goto menuPrincipal;
				}
				else {
					cout <<"Opcio no valida" << endl;
					cin >> consult;
				}
			}
			else if (opt == 4){
				string c;
				cout << "** Tancar sessio **" << endl;
				cout << "Vols tancar sessio (S/N)";
				cin >> c;

				if (c == "S") {
					cdp.tancaSessio();

					goto inici;
				}
			
			}
			else if (opt == 5){
				break;	
			}
			else{
				cout << "Opcio no valida" << endl;
				cin >> opt;
			} 	
		}
		
		return 0;

}
	
