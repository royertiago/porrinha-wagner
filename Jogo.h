#ifndef JOGO_H
#define JOGO_H
#include <vector>
class Player;

///Pontuacao: 5 pontos para primeiro lugar, 2 pontos para segundo lugar, 1 ponto para terceiro lugar

class Jogo
{

	public:

		Jogo ( std::vector<Player*> jogadores, int numeroRodadas = 5, int numeroPalitos = 3 );


		void comecar();
		virtual ~Jogo();
		struct Jogador {
			int mao, cantada, palitos, pontos=0;
			bool estaJogando = true;
			Player* ai;
			bool operator<(const Jogador e){
                return this->pontos < e.pontos;
			}

		};


	protected:

		virtual void placarRodada();
		virtual void placarTotal();
		virtual void partida();
		virtual void fimDeRodada();
		virtual int pegarPerdedor();

		virtual void pegarCantada ( Jogador& );
		virtual void pegarMao ( Jogador& );
		virtual void ganhou ( Jogador& );

		void proximoJogador();

		std::vector<Jogador> _jogadores;
		std::vector<Jogador*> _placar;
		unsigned int _jogadorAtual;
		unsigned int _jogadorInicial;
		unsigned int _partidaAtual;
		int _numeroJogadores;


	private:

		const unsigned int _numeroPalitos;
		const unsigned int _numeroPartidas;
};

#endif // JOGO_H
