#include "Factory.h"
#include "AI.h"
#include "TipoJogador.h"

Factory::Factory(){

}
Factory::~Factory(){ }
 std::vector<TipoJogador*> Factory::criarJogadores(){
    std::vector<TipoJogador*> jogadores= std::vector<TipoJogador*>();
    jogadores.push_back(new randyRandom());
    jogadores.push_back(new zero2());
    return jogadores;

}
