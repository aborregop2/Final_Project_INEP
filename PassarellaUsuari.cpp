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

PassarellaUsuari::PassarellaUsuari(){
  
}




string PassarellaUsuari::obteContrasenya() 
{
    return contrasenya;
}

void PassarellaUsuari::insereix()
{
      pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
      pqxx::work txn(conn);
      txn.exec("INSERT INTO public.usuari(nom, sobrenom, contrasenya, correuelectronic, datanaixement) VALUES('"+nom+"','"+sobrenom+"' , '"+contrasenya+"', '"+correuElectronic+"', '"+dataNaixement+"')");
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
    try{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        txn.exec("UPDATE public.usuari SET nom= '"+nomU+"' WHERE sobrenom = '" + sobrenom + "'");
        txn.commit();
    }
    catch(const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
  }
}


void PassarellaUsuari::posaContrasenya(string contraU)
{
  if(contraU != ""){
    try{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        txn.exec("UPDATE public.usuari SET contrasenya= '"+contraU+"' WHERE sobrenom = '" + sobrenom + "'");
        txn.commit();
    }
    catch(const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
  }
}


void PassarellaUsuari::posaCorreuElectronic(string correuU)
{
  if(correuU != ""){
    try{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        txn.exec("UPDATE public.usuari SET correuelectronic= '"+correuU+"' WHERE sobrenom = '" + sobrenom + "'");
        txn.commit();
    }
    catch(const exception &e){
        //Captura excepcio de UNIQUE del correuElectronic
        std::cerr << "Error: " << e.what() << std::endl;
    }
  }
}

void PassarellaUsuari::posaDataNaixement(string neixU)
{
  if(neixU != ""){
    try{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        txn.exec("UPDATE public.usuari SET datanaixement= '"+neixU+"' WHERE sobrenom = '" + sobrenom + "'");
        txn.commit();
    }
    catch(const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
  }
}