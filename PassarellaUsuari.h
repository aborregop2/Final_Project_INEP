#include <iostream>
#include <pqxx/pqxx>
using namespace std;

class PassarellaUsuari{
    private:
        string nom;
        string sobrenom;
        string contrasenya;
        string correuElectronic;
        string dataNaixement;
        
    public:
        PassarellaUsuari(string nU,string sU,string cU,string ceU,string dnU) : nom(nU), sobrenom(sU),
                                        contrasenya(cU), correuElectronic(ceU), dataNaixement(dnU)
        {

        }

        ~PassarellaUsuari()
        {

        }
        string obteContrasenya()
        {
            return contrasenya;
        }

        void insereix()
        {
            try{
                pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
                pqxx::work txn(conn);
                txn.exec("INSERT INTO public.usuari(nom, sobrenom, contrasenya, correuelectronic, datanaixement) VALUES('"+nom+"','"+sobrenom+"' , '"+contrasenya+"', '"+correuElectronic+"', '"+dataNaixement+"')");
                txn.commit();
            }
            catch(const exception &e){
                std::cerr << "Error: " << e.what() << std::endl;
            } 
        }

        PassarellaUsuari& operator=(const PassarellaUsuari &p)
        {
           if (this != &p) {
                nom = p.nom;
                sobrenom = p.sobrenom;
                contrasenya = p.contrasenya;
                correuElectronic = p.correuElectronic;
                dataNaixement = p.dataNaixement;
            }

            return *this; 
        }
};