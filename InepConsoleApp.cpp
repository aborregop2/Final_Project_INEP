#include <iostream>
#include <chrono>
#include <ctime>
#include <pqxx/pqxx>
#include "TxRegistraUsuari.h"
#include "TxIniciSessio.h"
#include "TxTancaSessio.h"
#include "TxConsultaUsuari.h"
#include "TxInfoCompres.h"
#include "CtrlModificaUsuari.h"
#include "TxEsborraUsuari.h"
#include "TxConsultaVideojoc.h"
#include "TxComprarVideojoc.h"



using namespace std;
using namespace pqxx;

int main() {

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
					TxConsultaUsuari txCU;
					txCU.executar();
					string* infoUsuari = txCU.obteResultat();

					TxInfoCompres txIC;
					txIC.executar();
					string* infoCompres = txIC.obteResultat();


					cout << "** Consulta usuari **" << endl;
					cout << "Nom complet: " << infoUsuari[0] << endl;
					cout << "Sobrenom: " << infoUsuari[1] << endl;
					cout << "Correu electronic: " << infoUsuari[2] << endl; 
					cout << "Data naixement (DD/MM/AAAA): " << infoUsuari[3] << endl << endl; 
						
					cout << infoCompres[1] <<" videojocs comprats" << endl; 
					cout << infoCompres[0] <<" paquet de videojocs comprats" << endl; 
					cout << infoCompres[2] <<" euros gastats en total" << endl; 
						


				}
				else if (opt == 2){
					string nomU, contraU, correuU, neixU;
					CtrlModificaUsuari cmU;
					string* infoU = cmU.consultaUsuari();

					cout << "** Consulta usuari **" << endl;
					cout << "Nom complet: " << infoU[0] << endl;
					cout << "Sobrenom: " << infoU[1] << endl;
					cout << "Correu electronic: " << infoU[2] << endl; 
					cout << "Data naixement (DD/MM/AAAA): " << infoU[3] << endl << endl; 

					//cin >> c; //Intro

					cout << "Omplir la informacio que es vol modificar ..." << endl;
					cout << "Nom complet: ";
					cin >> nomU;	//Getline()
					cout << "Contrasenya: ";
					cin >> contraU;
					cout << "Correu electronic: ";
					cin >> correuU;
					cout << "Data naixement (DD/MM/AAAA): ";
					cin >> neixU;

					cmU.modificaUsuari(nomU, contraU, correuU, neixU);
					
					//Pasan cosas char c
					//cin >> c; //Intro
					
					string *infoUs = cmU.consultaUsuari();
					cout << "** Dades usuari modificades **" << endl;
					cout << "Nom complet: " << infoUs[0] << endl;
					cout << "Sobrenom: " << infoUs[1] << endl;
					cout << "Correu electronic: " << infoUs[2] << endl; 
					cout << "Data naixement (DD/MM/AAAA): " << infoUs[3] << endl << endl;
				}
				else if (opt == 3){
					string contraU;
					cout << "** Esborra usuari **" << endl;
					cout << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya ..." << endl;
					cout << "Contrasenya: ";
					cin >> contraU;
					
					TxEsborraUsuari txEU(contraU);
					txEU.executar();
					//Error -> "La contrasenya no es correcta l'usuari, no s'ha esborrrat"
					
					cout << endl << "L'usuari s'ha esborrat correctament!" << endl;
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
					string nomV, c;

					cout << "** Compra videojoc **" << endl;
					cout << "Nom videojoc: ";
					cin >> nomV;
			
					TxConsultaVideojoc txCV(nomV);
					txCV.executar();
					string* infoVideojoc = txCV.obteResultat();
					

					cout << endl << "Informacio videojoc ..." << endl;
					cout << "Nom videojoc: " << infoVideojoc[0] << endl;
					cout << "Descripcio: " << infoVideojoc[1] <<endl;
					cout << "Qualificacio edat: " << infoVideojoc[2] << endl;
					cout << "Genere: " << infoVideojoc[5] << endl;
					cout << "Data llansament: " << infoVideojoc[3] << endl;
					cout << "Preu: " << infoVideojoc[6] << endl;
					cout << "Vols continuar amb la compra (S/N):" << endl;
					
					cin >> c;

					if (c == "S") {
					
						// Obtener el reloj actual del sistema
						auto ahora = std::chrono::system_clock::now();

						// Convertir el tiempo en un formato legible
						std::time_t tiempoActual = std::chrono::system_clock::to_time_t(ahora);

						// Obtener la estructura de tiempo local de manera segura con ctime_s
						std::tm tiempoLocal{};


						// Imprimir la fecha y hora actual
					
						TxComprarVideojoc txCV(nomV);
						txCV.executar();

						
							// Imprimir día, mes y año actual
						std::cout << "Compra Registrada: " << tiempoLocal.tm_mday << "/" << tiempoLocal.tm_mon + 1 << "/" << tiempoLocal.tm_year + 1900 << std::endl;
						
						//cout << "Compra registrada: " << local_tm.tm_mday <<'/' << (local_tm.tm_mon + 1) << '/' << (local_tm.tm_year + 1900) << endl;
						cout << "Jocs relacionats:" << endl;
						vector<InfoRel> res = txCV.obteResultat();
						for(unsigned int i = 0; i < res.size(); ++i){
							cout << "- " << res[i].nomVid << "; " << res[i].descVid << "; " << res[i].preu << endl;
						}
						cout << endl;

					}
				}
				else if (opt == 2){
					string nomV, c;
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
				string c;
				cout << "** Tancar sessio **" << endl;
				cout << "Vols tancar sessio (S/N)";
				cin >> c;

				if (c == "S") {
					TxTancaSessio txTS;
					txTS.executar();
					cout << "Sessio tancada correctament" << endl;

					goto inici;
				}
				else goto menuPrincipal;
				
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
	
