#include "PassarellaUsuari.h"
#include <pqxx/pqxx>

PassarellaUsuari::PassarellaUsuari(string nU,string sU,string cU,string ceU,string dnU): nom(nU), sobrenom(sU),
                                        contrasenya(cU), correuElectronic(ceU), dataNaixement(dnU)
{

}

PassarellaUsuari::PassarellaUsuari(string nU,string cU,string ceU,string dnU): nom(nU),
                                  contrasenya(cU), correuElectronic(ceU), dataNaixement(dnU)
{

}

PassarellaUsuari::PassarellaUsuari(): sobrenom("") {
  
}




string PassarellaUsuari::obteContrasenya() 
{
    return contrasenya;
}

void PassarellaUsuari::insereix()
{
      pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
      pqxx::work txn(conn);
      txn.exec("INSERT INTO public.usuari(nom, sobrenom, contrasenya, correu_electronic, data_naixement) VALUES('"+nom+"','"+sobrenom+"' , '"+contrasenya+"', '"+correuElectronic+"', '"+dataNaixement+"')");
      txn.commit();
   
}

void PassarellaUsuari::esborra() 
{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        txn.exec("DELETE FROM public.usuari WHERE sobrenom = '" + sobrenom + "'");
        txn.commit();   
}

PassarellaUsuari& PassarellaUsuari::operator=(const PassarellaUsuari& p) {
  if (this != &p) {
    nom = p.nom;
    sobrenom = p.sobrenom;
    contrasenya = p.contrasenya;
    correuElectronic = p.correuElectronic;
    dataNaixement = p.dataNaixement;
  }

  return *this;
}

string PassarellaUsuari::obteNom()
{
  return nom;
}
string PassarellaUsuari::obteSobrenom()
{
  return sobrenom;
}
string PassarellaUsuari::obteCorreuElectronic()
{
  return correuElectronic;
}

string PassarellaUsuari::obteDataNaixament()
{
  return dataNaixement;
}

void PassarellaUsuari::posaNom(string nomU)
{
  if(nomU != ""){
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        txn.exec("UPDATE public.usuari SET nom= '"+nomU+"' WHERE sobrenom = '" + sobrenom + "'");
        txn.commit();
  }
}


void PassarellaUsuari::posaContrasenya(string contraU)
{
  if(contraU != ""){
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        txn.exec("UPDATE public.usuari SET contrasenya= '"+contraU+"' WHERE sobrenom = '" + sobrenom + "'");
        txn.commit();
  }
}


void PassarellaUsuari::posaCorreuElectronic(string correuU)
{
  if(correuU != ""){
   
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        txn.exec("UPDATE public.usuari SET correu_electronic= '"+correuU+"' WHERE sobrenom = '" + sobrenom + "'");
        txn.commit();
        //Captura excepcio de UNIQUE del correuElectronic
        //std::cerr << "Error: " << e.what() << std::endl;
  }
}

void PassarellaUsuari::posaDataNaixement(string neixU)
{
  if(neixU != ""){
    try{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        txn.exec("UPDATE public.usuari SET data_naixement= '"+neixU+"' WHERE sobrenom = '" + sobrenom + "'");
        txn.commit();
    }
    catch(const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
  }
}

void PassarellaUsuari::modifyNom(string Nom)
{
    nom = Nom;
}
void PassarellaUsuari::modifySobreom(string Snom)
{
    sobrenom = Snom;
}

void PassarellaUsuari::modifyContrasenya(string Cont)
{
    contrasenya = Cont;
}
void PassarellaUsuari::modifyCorreuElectronic(string Ce)
{
    correuElectronic = Ce;
}
void PassarellaUsuari::modifyDataNaixement(string Dnaix)
{
    dataNaixement = Dnaix;
}