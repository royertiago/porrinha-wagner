#include <iostream>
#include <windows.h>
#include <string>
#include "Factory.h"
#include "Player.h"
#include "Jogo.h"
using namespace std;
void gotoxy (int x, int y){
        COORD point;
        point.X = x; point.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
int main(int argc, char *argv[]=0)
{
    vector<Player*> jogadores=Factory::criarJogadores();
    int jogos=5;

    if(argc>1){
        string temp=argv[0];
        std::cout<< temp <<std::endl;
       // jogos=std::stoi (temp);
    }
    Jogo jogo= Jogo(jogadores);

    jogo.comecar();




    return 0;
}
