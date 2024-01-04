#include "CapaDePresentacio.h"
#include <chrono>
#include <string>

CapaDePresentacio::CapaDePresentacio()
{
    
}

typename CapaDePresentacio::CapaDePresentacio* CapaDePresentacio::getInstance()
{
    if (instance == nullptr) {
        instance = new CapaDePresentacio();
    }
    return instance;
}


void CapaDePresentacio::iniciSessio()
{
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

void CapaDePresentacio::tancaSessio()
{

}

void CapaDePresentacio::registrarUsuari()
{
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

void CapaDePresentacio::consultaUsuari()
{
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

void CapaDePresentacio::modificaUsuari()
{
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

void CapaDePresentacio::esborraUsuari()
{
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

void CapaDePresentacio::comprarVideojoc()
{
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

void CapaDePresentacio::comprarPaquetVideojocs()
{

     auto now = std::chrono::system_clock::now();
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);
	std::tm local_tm = *std::localtime(&now_time);
    std::string dataavui = to_string(local_tm.tm_mday) + '/' + to_string((local_tm.tm_mon + 1)) + '/' + to_string((local_tm.tm_year + 1900));
    std::string hora_minuts = std::to_string(local_tm.tm_hour) + ':' + std::to_string(local_tm.tm_min);

    string nomP, c;
    cout << "** Compra paquet **" << endl;
    cout << "Nom paquet: ";
    cin >> nomP;

    TxComprarPaquet tCP(nomP);
    tCP.executar();

    InfoPaq inf;
    cout << endl << "Informacio paquet ..." << endl;
    cout << "Nom paquet: " << inf.nomPaq << endl;
    cout << "Descripcio: " << inf.descPaq << endl;
    cout << "Preu: " << inf.preuPaq << endl << endl;

    for (unsigned int i = 0; i < inf.res.size(); ++i){
        cout << "- " << inf.res[i].nomVid << "; " << inf.res[i].descVid << "; " << inf.res[i].preuVid << endl;
    }

    cout << "Vols continuar amb la compra (S/N):" << endl;
    cin >> c;
    if (c == "S") {
        tCP.executar2();
        cout << "Compra registrada: " << dataavui << " " << hora_minuts << endl;
    }
}

void CapaDePresentacio::consultaCompres()
{
    cout << "** Consulta compres **" << endl;
    TxConsultaCompres tXCC;
    tXCC.executar();
    pair<vector<InfoPaq> , vector<InfoVid> > res = tXCC.obteResultat();
    int preuT = 0;
    for(unsigned int i = 0; i < res.first.size(); ++i){
        preuT += stoi(res.first[i].preuPaq);
        cout << res.first[i].dataPaq << ": paquet " << res.first[i].nomPaq << "; " << res.first[i].descPaq << "; " << res.first[i].preuPaq << endl; 
        cout << "   Videojocs:" << endl;
        for(unsigned int j = 0; res.first[i].res.size(); ++j){
            cout <<"    " << res.first[i].res[j].nomVid << "; " << res.first[i].res[j].descVid << endl; 
        }
    }

    for(unsigned i = 0; i < res.second.size(); i++){
        preuT += stoi(res.second[i].preuVid);
        cout << res.second[i].dataVid << ": videojoc " << res.second[i].nomVid << " " << res.second[i].descVid << "; " << res.second[i].preuVid << endl;
    }
    cout << "Total: " << preuT << "euros" << endl;
}

void CapaDePresentacio::consultarVideojoc()
{   
    cout << "** Consulta videojoc **" << endl;
    cout << "Nom videojoc: "; 
    string nomV;
    cin >> nomV;
    cout << "Informacio videojoc ..." << endl;
    
    TxConsultaVideojoc txCV(nomV);
    txCV.executar();
    string* resultat = txCV.obteResultat();

    CercadoraConte CCon;
    vector<PassarellaConte> vpc = CCon.cercaConteV(nomV);

    cout << "Nom videojoc: " << resultat[0] << endl; 
    cout << "Descripcio: " << resultat[1] << endl; 
    cout << "Qualificacio edat: " << resultat[2] << endl; 
    cout << "Genere: " << resultat[5] << endl; 
    cout << "Data llansament: " << resultat[3] << endl;
    cout << "Preu: " << resultat[6] << endl; 
    cout << "Paquets on esta inclos: ";
    for(unsigned int i = 0; i < vpc.size(); ++i){
        cout << vpc[i].obteNomPaquet() << " ";
    }
    cout << endl; 
}

void CapaDePresentacio::consultarVideojocs()
{
    cout << "** Consulta videojocs **" << endl; 
    TxConsultaVideojocs txCVs;
    txCVs.executar();
    vector<string> resultatnom = txCVs.obteResultat();
    for(unsigned int i = 0; i < resultatnom.size(); ++i){
        TxConsultaVideojoc txCv(resultatnom[i]);
        txCv.executar();
        string* resultat = txCv.obteResultat();
        CercadoraConte CCon;
        vector<PassarellaConte> vpc = CCon.cercaConteV(resultat[i]);

        cout << resultat[0] << "; " << resultat[1] << "; " << resultat[6] << " euros "<< "; " << resultat[2] << " PEGI " <<  "; "; 
        cout << resultat[5] << "; " << resultat[3] << "; ";
        if(resultat[4] != "") cout << "estimacio temps joc: " << resultat[4] << "minuts" << "; "; 
        
        cout << "Paquets: ";
        for(unsigned int i = 0; i < vpc.size(); ++i){
            cout << vpc[i].obteNomPaquet() << " ";
        }
        cout << endl;
    }

}

void CapaDePresentacio::consultarVideojocsPerEdat()
{   
    int edat;
    cin >> edat;   

    cout << "** Consulta videojocs per edat **" << endl;
    cout << "Edat maxima (anys): " << edat;

    TxConsultarVideojocsPerEdat txCvpe(edat);
    txCvpe.executar();
    vector<string> resultatjocsedat = txCvpe.obteResultat();

    cout << "** Consulta videojocs fins a " << edat << "anys **" << endl;

    for(unsigned int i = 0; i< resultatjocsedat.size(); ++i){
        TxConsultaVideojoc txCv(resultatjocsedat[i]);
        txCv.executar();
        string* resultat = txCv.obteResultat();
        CercadoraConte CCon;
        vector<PassarellaConte> vpc = CCon.cercaConteV(resultat[i]);
         cout << resultat[0] << "; " << resultat[1] << "; " << resultat[6] << " euros "<< "; " << resultat[2] << " PEGI " <<  "; "; 
        cout << resultat[5] << "; " << resultat[3] << "; ";
        if(resultat[4] != "") cout << "estimacio temps joc: " << resultat[4] << "minuts" << "; "; 
        
        cout << "Paquets: ";
        for(unsigned int i = 0; i < vpc.size(); ++i){
            cout << vpc[i].obteNomPaquet() << " ";
        }
        cout << endl;
    }

}

void CapaDePresentacio::consultarNovetatsVideojocs()
{
    cout << "** Consulta novetats **" <<endl;
    cout << "Data (DD/MM/AAAA): " ;
    string datalimit;
    cin >> datalimit;

    TxConsultaNovetatsVideojocs txCnv(datalimit);
    txCnv.executar();
    vector<string> resultatnovetatvideojocs = txCnv.obteResultat();
    for(unsigned int i = 0; i < resultatnovetatvideojocs.size(); ++i){
        TxConsultaVideojoc txCv(resultatnovetatvideojocs[i]);
        txCv.executar();
        string* resultat = txCv.obteResultat();
        CercadoraConte CCon;
        vector<PassarellaConte> vpc = CCon.cercaConteV(resultat[i]);
         cout << resultat[0] << "; " << resultat[1] << "; " << resultat[6] << " euros "<< "; " << resultat[2] << " PEGI " <<  "; "; 
        cout << resultat[5] << "; " << resultat[3] << "; ";
        if(resultat[4] != "") cout << "estimacio temps joc: " << resultat[4] << "minuts" << "; "; 
        
        cout << "Paquets: ";
        for(unsigned int i = 0; i < vpc.size(); ++i){
            cout << vpc[i].obteNomPaquet() << " ";
        }
        cout << endl;
    }
}

void CapaDePresentacio::consultarPaquetVideojocs()
{
    cout <<"** Consulta paquet **" << endl;
    cout <<"Nom paquet: " << endl;
    string nomP;
    cin >> nomP;
    TxConsultarPaquet txCp(nomP);
    txCp.executar();
    InfoPaq resultatpaq = txCp.obteResultat();
    
    cout << "Informacio paquet ..."<< endl;
    cout << "Nom paquet: " << nomP << endl;
    cout << "Descripcio: " << resultatpaq.descPaq << endl;
    cout << "Preu: " << resultatpaq.preuPaq << " euros (estalvi de " << resultatpaq.estalvi << " euros)" << endl << endl;

    cout <<"Jocs inclosos:" << endl;
    for(unsigned int i = 0; resultatpaq.res.size(); ++i){
        cout << "- " << resultatpaq.res[i].nomVid << "; " << resultatpaq.res[i].descVid << "; ";
        cout << resultatpaq.res[i].preuVid << " euros" <<endl;
    }

    cout << endl; 
}

void CapaDePresentacio::consultarPaquetsVideojocs()
{
    TxConsultarPaquets txcp;
    txcp.executar();
    vector<InfoPaq> resultatpaquets = txcp.obteResultat();

    cout << "** Consulta paquets **" <<endl;
    for(unsigned int i = 0; i < resultatpaquets.size(); ++i){
        cout << resultatpaquets[i].nomPaq << "; " << resultatpaquets[i].descPaq << "; ";
        cout << resultatpaquets[i].preuPaq << " euros (estalvi de " << resultatpaquets[i].estalvi << " euros)" << endl; 
    }
}