#include "TipoJogador.h"
#include <stdlib.h>

class zero2 : public TipoJogador{
    std::string nome(){
        return "zeroDois";
    }
     int pegarMao(){
         return 2;
    }
    unsigned int pegarCantada ( std::vector<int> cantadas ){
        return 2;
    }
        void informarRodada ( std::vector<int> numeroDePalitos, std::vector<int> cantadas ){

    }
};
class randyRandom : public TipoJogador{
    std::string nome(){
        return "Randy";
    }
     int pegarMao(){
         return rand()%3;
    }
    unsigned int pegarCantada ( std::vector<int> cantadas ){
        int cont=0;
        for(auto x: cantadas){
             cont+=3;
        }
        if(cont==0)return 0;
        return rand()%cont;

    }
    void informarRodada ( std::vector<int> numeroDePalitos, std::vector<int> cantadas ){

    }

};
