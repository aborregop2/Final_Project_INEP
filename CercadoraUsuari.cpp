#include "CercadoraUsuari.h"
#include "PassarellaUsuari.h"
#include <pqxx/pqxx>

CercadoraUsuari::CercadoraUsuari()
{

}

vector<PassarellaUsuari> CercadoraUsuari::cercaUsuari(string sobrenomU) 
{
    pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
    pqxx::work txn(conn);
    pqxx::result r = txn.exec("SELECT nom, sobrenom, contrasenya, correu_electronic, data_naixement FROM public.usuari WHERE sobrenom = '"+sobrenomU+"'; ");
    pqxx::row row = r[0];
    vector<PassarellaUsuari> pu;
    PassarellaUsuari res;
    pu.push_back(res);
    for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
        PassarellaUsuari u(row["nom"].as<string>(), row["sobrenom"].as<string>(), row["contrasenya"].as<string>(), row["correu_electronic"].as<string>(), row["data_naixement"].as<string>());
        pu[0] = u;
    }

    txn.commit();
    return pu;
}