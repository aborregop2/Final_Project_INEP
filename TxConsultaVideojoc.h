#ifndef TX_CONSULTA_VIDEOJOC_H
#define TX_CONSULTA_VIDEOJOC_H

class TxConsultaVideojoc{
    private:
        string nom;
        string resultat[5];
        
    public:
        TxConsultaVideojoc(string nom);
        string[] obteResultat();
        void executa();
     
};



#endif