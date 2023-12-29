#include <iostream>
#include <pqxx/pqxx>
#include "txRegistraUsuari.h"
#include "txIniciSessio.h"
//#include "txTancaSessio.h"
//#include "txConsultaUsuari.h"
//#include "txInfoCompres.h"
//#include "CtrlModificaUsuari.h"
//#include "txEsborraUsuari.h"


using namespace std;
using namespace pqxx;

int main() {

			string nc;
			string c;

		while(true){

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
				string sU, cU;

				cout << "** Inici sessio **" << endl;
				cout << "Sobrenom: ";
				cin >> sU;

				cout << "Contrasenya: ";
				cin >> cU;
				cout << endl; 

				TxIniciSessio txIS(sU, cU);
				txIS.executar();
				//sI UsuariNoExisteix o ErrorContrasenya
				// -> "Hi ha hagut error amb el sobrenom o la contrasenya"
				cout << "Sessio iniciada correctament!" << endl << endl;
				
			}
			else if(opt == 2){ 
				string nU, sU, cU, ceU, dnU;

				cout << "** Registrar Usuari **" << endl;
				cout << "Omplir la informacio que es demana ..." << endl;
				cout << "Nom complet: ";
				cin >> nU;

				cout << "Sobrenom: ";
				cin >> sU;

				cout << "Contrasenya: ";
				cin >> cU;

				cout << "Correu electronic: ";
				cin >> ceU;

				cout << "Data naixement (DD/MM/AAAA): ";
				cin >> dnU;
				cout << endl;

				TxRegistraUsuari txRU(nU, sU, cU, ceU, dnU);
				txRU.executar();
				// Si el sobrenom o correu electronic ja es troba a la base dades 
				// sobrenom -> "Ja exiteix un usuari amb aquest sobrenom"
				// correu -> "Ja exiteix un usuari amb aquest correu electronic"
				cout << "Usuari registrat amb exit" << endl << endl;

			}
			else if (opt == 3){
				break;
			}
			else{
				cout << "** Opcio no valida **" << endl;
				cin >> opt;
			} 


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
					cout << "** Consulta usuari **" << endl;
					cout << "Nom complet: " << endl; //Hay que poner
					cout << "Sobrenom: " << endl; //Hay que poner
					cout << "Correu electronic: " << endl; //Hay que poner
					cout << "Data naixement (DD/MM/AAAA): " << endl << endl; //Hay que poner
						
					cout << " videojocs comprats" << endl; //Hay que poner num de videojocs
					cout << " paquet de videojocs comprats" << endl; //Hay que poner num de paquets
					cout << " euros gastats en total" << endl; //Hay que poner num de paquets				
				}
				else if (opt == 2){
					string sob, cont, cE;
					cout << "** Consulta usuari **" << endl;
					cout << "Nom complet: " << endl; //Hay que poner
					cout << "Sobrenom: " << endl; //Hay que poner
					cout << "Correu electronic: " << endl; //Hay que poner
					cout << "Data naixement (DD/MM/AAAA): " << endl << endl; //Hay que poner

					
					//cin >> c; //Intro

					cout << "Omplir la informacio que es vol modificar ..." << endl;
					cout << "Nom complet: ";
					cin >> nc >> nc;	//Getline()
					cout << "Sobrenom: ";
					cin >> sob;
					cout << "Contrasenya: ";
					cin >> cont;
					cout << "Correu electronic: ";
					cin >> cE;
					cout << "Data naixement (DD/MM/AAAA): ";
						
					//Pasan cosas char c
					//cin >> c; //Intro

					cout << "** Dades usuari modificades **" << endl;
					cout << "Nom complet: " << endl; //Hay que poner
					cout << "Sobrenom: " << endl; //Hay que poner
					cout << "Correu electronic: " << endl; //Hay que poner
					cout << "Data naixement (DD/MM/AAAA): " << endl << endl; //Hay que poner
				}
				else if (opt == 3){
					string cont;
					cout << "** Esborra usuari **" << endl;
					cout << "Per confirmar l'esborrat, s'ha d'entrar la contraasenya ..." << endl;
					cout << "Contrasenya: ";
					cin >> cont;
					//Pasan cosas
					cout << endl << "Usuari esborrat correctament!" << endl;
				}
				else if (opt == 4){
					break;
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
					string nV;

					cout << "** Compra videojoc **" << endl;
					cout << "Nom videojoc: ";
					cin >> nV;
					cout << endl << "Informacio videojoc ..." << endl;
					cout << "Nom videojoc: (nom videojoc)" << endl;
					cout << "Descripcio: (descripcio)" << endl;
					cout << "Qualificacio edat: (edat)" << endl;
					cout << "Genere: (genere)" << endl;
					cout << "Data llansament: (data)" << endl;
					cout << "Preu: (preu)" << endl;
					cout << "Vols continuar amb la compra (S/N):" << endl;
					
					cin >> c;

					if (c == "S") {
						cout << "Compra registrada: " << "(avui)" << endl;
						cout << "Jocs relacionats:" << endl;
						//Pasan cosas
					}
				}
				else if (opt == 2){
					string nomV;
					cout << "** Compra paquet **" << endl;
					cout << "Nom paquet: ";
					cin >> nomV;
					cout << endl << "Informacio paquet ..." << endl;
					cout << "Nom paquet: (nom paquet)" << endl;
					cout << "Descripcio: (descripcio)" << endl;
					cout << "Preu: (preu)" << endl << endl;
					cout << "Jocs inclosos:" << endl;
					//Pasan cosas

					cout << "Vols continuar amb la compra (S/N):" << endl;

					cin >> c;
					if (c == "S") {
						cout << "Compra registrada: " << "(avui)" << endl;
					}
				}
				else if (opt == 3){
					cout << "** Compra compres **" << endl;
					//Pasan cosas
					cout << "Total: (total) euros" << endl;
				}
				else if (opt == 4){
					break;
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
				break;
			}
			else if (opt == 4){
				break;
			}
			else if (opt == 5){
				exit(0);
			}
			else{
				cout << "Opcio no valida" << endl;
				cin >> opt;
			} 	
		}
		
		return 0;

}
	
