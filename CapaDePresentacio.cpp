#define _CRT_SECURE_NO_WARNINGS
#include "CapaDePresentacio.h"
#include <chrono>
#include <string>
#include <limits>


CapaDePresentacio::CapaDePresentacio()
{

}


/*
typename CapaDePresentacio::CapaDePresentacio* CapaDePresentacio::getInstance()
{
    if (instance == nullptr) {
        instance = new CapaDePresentacio();
    }
    return instance;
}

*/

/** - COMMENTED TO SOLVE PROBLEMS - **/

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
}

void CapaDePresentacio::tancaSessio()
{
    TxTancaSessio txTS;
    txTS.executar();

    cout << "Sessio tancada correctament" << endl;
}


void CapaDePresentacio::consultaUsuari()
{
    TxConsultaUsuari txCU;
    txCU.executar();
    vector<string> infoUsuari = txCU.obteResultat();
    cout << "\n";
    cout << "** Consulta usuari **" << endl;
    cout << "Nom complet: " << infoUsuari[0] << endl;
    cout << "Sobrenom: " << infoUsuari[1] << endl;
    cout << "Correu electronic: " << infoUsuari[2] << endl;
    cout << "Data naixement (DD/MM/AAAA): " << infoUsuari[3] << endl << endl;
    TxInfoCompres txIC;
    txIC.executar();     
    vector<string> infoCompres = txIC.obteResultat();


   

    cout << infoCompres[1] <<" videojocs comprats" << endl;
    cout << infoCompres[0] <<" paquet de videojocs comprats" << endl;
    cout << infoCompres[2] << " euros gastats en total" << endl << endl;;

}

void CapaDePresentacio::modificaUsuari()
{
    string nomU, contraU, correuU, neixU;
    CtrlModificaUsuari cmU;
    vector<string> infoU = cmU.consultaUsuari();
    cout << "\n";
    cout << "** Consulta usuari **" << endl;
    cout << "Nom complet: " << infoU[0] << endl;
    cout << "Sobrenom: " << infoU[1] << endl;
    cout << "Correu electronic: " << infoU[2] << endl;
    cout << "Data naixement (DD/MM/AAAA): " << infoU[3] << endl << endl;


    cout << "Omplir la informacio que es vol modificar ..." << endl;
    cout << "Nom complet: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nomU);
    cout << "Contrasenya: ";
    getline(cin, contraU);
    cout << "Correu electronic: ";
    getline(cin, correuU);
    cout << "Data naixement (DD/MM/AAAA): ";
    getline(cin, neixU);

    cmU.modificaUsuari(nomU, infoU[1], contraU, correuU, neixU);

    CtrlModificaUsuari cmUs;
    vector<string> infoUs = cmUs.consultaUsuari();
    cout << "\n";
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nomV);

    TxConsultaVideojoc txCV(nomV);
    try {
     txCV.executar();
    }
    catch (string& e) {
        throw(e);
    }
    vector<string> infoVideojoc = txCV.obteResultat();


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


        TxComprarVideojoc txCV(nomV, infoVideojoc[6]);
        try {
            txCV.executar();
        }
        catch (string& e) {
            throw(e);
        }

        time_t tiempoActual = time(nullptr);
        tm* FechaHora = localtime(&tiempoActual);
        string dataavui;
        string horamin;
        dataavui += to_string(FechaHora->tm_mday);
        dataavui += '/';
        dataavui += to_string(FechaHora->tm_mon + 1);
        dataavui += '/';
        dataavui += to_string(FechaHora->tm_year + 1900);
        horamin += to_string(FechaHora->tm_hour);
        horamin += ':';
        horamin += to_string(FechaHora->tm_min);
        cout << "Compra registrada: " << dataavui << " " << horamin << endl;
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
    /*
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm local_tm = *std::localtime(&now_time);
    std::string dataavui = to_string(local_tm.tm_mday) + '/' + to_string((local_tm.tm_mon + 1)) + '/' + to_string((local_tm.tm_year + 1900));
    std::string hora_minuts = std::to_string(local_tm.tm_hour) + ':' + std::to_string(local_tm.tm_min);
    */
     

    string nomP, c;
    cout << "** Compra paquet **" << endl;
    cout << "Nom paquet: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nomP);

    TxComprarPaquet tCP(nomP);
    try {
       tCP.executar();
    }
    catch (string& err) {
        throw(err);
    }

    InfoPaq inf = tCP.obteResultat();
    cout << endl << "Informacio paquet ..." << endl;
    cout << "Nom paquet: " << inf.nomPaq << endl;
    cout << "Descripcio: " << inf.descPaq<< endl;
    cout << "Preu: " << inf.preuPaq << endl << endl;

    for (unsigned int i = 0; i < inf.res.size(); ++i){
        cout << "- " << inf.res[i].nomVid << "; " << inf.res[i].descVid << "; " << inf.res[i].preuVid << endl;
    }

    cout << "Vols continuar amb la compra (S/N):" << endl;
    cin >> c;
    if (c == "S") {
        tCP.executar2();
        time_t tiempoActual = time(nullptr);
        tm* FechaHora = localtime(&tiempoActual);
        string dataavui;
        string horamin;
        dataavui += to_string(FechaHora->tm_mday);
        dataavui += '/';
        dataavui += to_string(FechaHora->tm_mon + 1);
        dataavui += '/';
        dataavui += to_string(FechaHora->tm_year + 1900);
        horamin += to_string(FechaHora->tm_hour);
        horamin += ':';
        horamin += to_string(FechaHora->tm_min);
        cout << "Compra registrada: " << dataavui << " " << horamin << endl;
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
    vector<string> resultat = txCV.obteResultat();

    CercadoraConte CCon;
    vector<PassarellaConte> vpc = CCon.cercaConteV(nomV);

    cout << "Nom videojoc: " << resultat[0] << endl;
    cout << "Descripcio: " << resultat[1] << endl;
    cout << "Qualificacio edat: " << resultat[2] << endl;
    cout << "Genere: " << resultat[5] << endl;
    cout << "Data llansament: " << resultat[3] << endl;
    cout << "Preu: " << resultat[6] << " euros" << endl;
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
        vector<string> resultat = txCv.obteResultat();
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
    cout << "** Consulta videojocs per edat **" << endl;
    int edat;
    cin >> edat;
    cout << "Edat maxima (anys): " << edat << endl;


    TxConsultarVideojocsPerEdat txCvpe(edat);
    txCvpe.executar();
    vector<string> resultatjocsedat = txCvpe.obteResultat();

    cout << "** Consulta videojocs fins a " << edat << " anys **" << endl;

    for(unsigned int i = 0; i< resultatjocsedat.size(); ++i){
        TxConsultaVideojoc txCv(resultatjocsedat[i]);
        txCv.executar();
        vector<string> resultat = txCv.obteResultat();
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
        vector<string> resultat = txCv.obteResultat();
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
    cout <<"Nom paquet: ";
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
    for(unsigned int i = 0; i < resultatpaq.res.size(); ++i){
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




void CapaDePresentacio::registrarUsuari()
{
    string nU, sU, cU, ceU, dnU;

    cout << "** Registrar Usuari **" << endl;
    cout << "Omplir la informacio que es demana ..." << endl;
    cout << "Nom complet: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nU);

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

}
