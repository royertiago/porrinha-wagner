#include "Factory.h"
#include "AI.h"
#include "Player.h"

Factory::Factory(){

}
Factory::~Factory(){ }
 std::vector<Player*> Factory::criarJogadores(){
    std::vector<Player*> jogadores= std::vector<Player*>();
    jogadores.push_back(new randyRandom());
    jogadores.push_back(new zero2());
    return jogadores;

}
