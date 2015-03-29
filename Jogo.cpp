#include <stdlib.h>
#include "Jogo.h"
#include "Player.h"
#include <iostream>
#include <algorithm>

#define NAO_JOGOU -1
#define FORA_DE_JOGO -2
#define SEM_VENCENDOR -1
#define SEM_PERDEDOR -1

using namespace std;

Jogo::Jogo ( std::vector<Player*> jogadores, int numeroPartidas , int numeroPalitos  ) :
	_numeroPartidas ( numeroPartidas ),
	_numeroPalitos ( numeroPalitos ),
	_partidaAtual(0)
{
	 _numeroJogadores = jogadores.size();
	_jogadores = std::vector<Jogador> ( _numeroJogadores );

	for ( int i = 0; i < _numeroJogadores ; i++ ) {
		_jogadores[i].ai = jogadores[i];
	}
}
Jogo::~Jogo()
{
	//dtor
}
static std::vector<int> vetorCantadas ( std::vector<Jogo::Jogador> &jogadores ) {
	std::vector<int> cantadas = std::vector<int>();
	//cria o vetor de cantadas de outro jogadores
	for ( auto &atual: jogadores ) {
		cantadas.push_back ( atual.cantada );
	}
	return cantadas;
}
static std::vector<int> vetorMaos ( std::vector<Jogo::Jogador> &jogadores ) {
	std::vector<int> maos = std::vector<int>();
	//cria o vetor de maos de outro jogadores
	for ( auto &atual: jogadores ) {
		maos.push_back ( atual.mao );
	}
	return maos;
}

void Jogo::comecar() {
	while ( _partidaAtual < _numeroPartidas ) {
		//reset nos jogadores
    for ( auto &jogador: _jogadores ) {
			jogador.mao = NAO_JOGOU;
			jogador.cantada = NAO_JOGOU;
			jogador.palitos = _numeroPalitos;
			jogador.estaJogando = true;
		}
		partida();
		for(auto x: _jogadores){
			x.ai->end_round();
		}
		placarRodada();
		_placar.clear();
		_partidaAtual++;
	}
	placarTotal();
}

void Jogo::partida() {
	_jogadorAtual = rand() % _numeroJogadores;

	while ( pegarPerdedor() == SEM_VENCENDOR ) {

		int maoTotal = 0;
		int jogadoresJogando=0;

		///Conta quantos jogadores estão em jogo
		for(auto jogador: _jogadores ){
		    if(jogador.estaJogando)
                jogadoresJogando++;
		}

		/**inicio da rodada. Todos jogadores escondem os palitos na mão*/
		for ( int i = 0; i < jogadoresJogando; i++ ) {
			Jogador* atual = &_jogadores[_jogadorAtual];

			atual->cantada = NAO_JOGOU;
			pegarMao ( *atual );
			maoTotal += atual->mao;
			proximoJogador();
		}

		/**Palpites de cada jogador*/
		for ( int i = 0; i < jogadoresJogando; i++ ) {
			Jogador* atual = &_jogadores[_jogadorAtual];
			pegarCantada ( *atual );
			proximoJogador();
		}
		fimDeRodada();

		/**verifica algum ganhador e atualiza o proximo a iniciar*/
		bool houveGanhador=false;
		for ( int i = 0; i < _jogadores.size(); i++ ) {
			Jogador* atual = &_jogadores[i];
			if ( atual->cantada == maoTotal ) {
				atual->palitos --;
				_jogadorAtual = i;
				houveGanhador = true;
				if ( atual->palitos <= 0 ) {
					proximoJogador();
					ganhou ( *atual );
				}
			}
		}
		if(!houveGanhador){
		    proximoJogador();
		}
		/** reseta jogadores para proxima rodada*/
        for ( auto &atual: _jogadores ) {
			if ( atual.estaJogando ) {
				atual.mao = NAO_JOGOU;
				atual.cantada = NAO_JOGOU;
			} else {
				atual.mao = FORA_DE_JOGO;
				atual.cantada = FORA_DE_JOGO;
			}
		}
	}
	_placar.push_back ( &_jogadores[ pegarPerdedor() ] );
}

int Jogo::pegarPerdedor() {
	int cont = 0;
	int jogador = -1;
	for ( int i = 0; i < _numeroJogadores; i++ ) {
		if ( _jogadores[i].estaJogando ) {
			cont++;
			jogador = i;
		}
	}
	if ( cont == 1 ) return jogador;
	return SEM_PERDEDOR;
}
void Jogo::fimDeRodada() {
	std::vector<int> cantadas = vetorCantadas ( _jogadores );
	std::vector<int> maos = vetorMaos ( _jogadores );
for ( auto &atual: _jogadores ) {
		atual.ai->settle_round ( maos, cantadas );
	}

}

void Jogo::proximoJogador() {
	_jogadorAtual = ( _jogadorAtual + 1 ) % _numeroJogadores;

	if ( !_jogadores[_jogadorAtual].estaJogando ) {
		proximoJogador();
	}

}

void Jogo::ganhou ( Jogador& j ) {
	j.estaJogando = false;
	_placar.push_back ( &j );
}

void Jogo::pegarCantada ( Jogador& jogador ) {
	std::vector<int> cantadas = vetorCantadas ( _jogadores );

	int cantada = jogador.ai->guess ( cantadas );
	//verifica se é uma cantada repetida
    for ( auto &atual: _jogadores ) {
		if ( atual.cantada == cantada ) {
			cantada = NAO_JOGOU;
			std::cout << "Jogador " << (jogador.ai->name()) << " cantada invalida" <<std::endl;

		}
	}
	jogador.cantada = cantada;
}
void Jogo::pegarMao ( Jogador& jogador ) {
	int mao = jogador.ai->hand();
	if ( mao < 0 || mao > jogador.palitos ) {
		mao = 0;
		std::cout << "Jogador " << jogador.ai->name() << " mao invalida" <<std::endl;
	}
	jogador.mao = mao;



}
void Jogo::placarRodada() {
	int cont = 1;
	cout << "partida " << _partidaAtual << endl;
    for ( auto jogador: _placar ) {
		cout << cont << ": " << jogador->ai->name() << endl;

		switch (cont)
		{
		    case 1: {jogador->pontos+=5;
		        break;}
            case 2:{ jogador->pontos+=2; break;}
            case 3: {jogador->pontos+=1; break;}
		    default:
		        break;
		}

		cont++;
	}
	std::cout << "" << std::endl;

}
static bool sortJ(Jogo::Jogador a, Jogo::Jogador b){
    return a<b;
}
void Jogo::placarTotal() {
    std::sort(_jogadores.begin(),_jogadores.end(),sortJ );
    std::reverse(_jogadores.begin(),_jogadores.end());

    for(auto &jogador: _jogadores ){
        std::cout<< "Jogador: " <<jogador.ai->name()<<" fez "<<jogador.pontos<<"  pontos"<< std::endl;

    }

}

