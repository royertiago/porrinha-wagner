#include "Player.h"
#include <stdlib.h>

class zero2 : public Player{
    std::string name() const{
        return "zeroDois";
    }
     int hand(){
         return 2;
    }
     int guess ( const std::vector<int>& cantadas ){
        return 2;
    }
        void settle_round ( const std::vector<int>& numeroDePalitos, const std::vector<int>& cantadas ){

    }
};
class randyRandom : public Player{
    std::string name() const{
        return "Randy";
    }
     int hand(){
         return rand()%3;
    }
     int guess ( const std::vector<int>& cantadas ){
        int cont=0;
        for(auto x: cantadas){
             cont+=3;
        }
        if(cont==0)return 0;
        return rand()%cont;

    }
    void settle_round ( const std::vector<int>& numeroDePalitos, const std::vector<int>& cantadas ){

    }

};
