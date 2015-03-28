#ifndef TIPOJOGADOR_H
#define TIPOJOGADOR_H

#include <vector>
#include <string>

/**Interface para jogadores e Inteligências artificiais do para o jogo Porrinha*/
class TipoJogador
{
	public:
        /**Retorna o nome de sua inteligencia artificial, usado em placares e tal */
        virtual std::string nome() =0;


		/** Metodo chamado pelo jogo no início do round que pedira quantos
		**  palitos o jogador deseja esconder em sua mão.
		**  Conforme as regras do jogo, somente valores 0-3
		**  São valores validos.
		*/
		virtual int pegarMao() = 0;

		/** Metodo chamado pelo jogo quando for sua vez de jogar
		**  O vetor cantada contem as cantadas feitas por jogadores que jogaram anteriormente.
		**  Jogadores que não jogaram ainda estaram marcado como -1.
		**  Jogadores fora do jogo, estaram marcados como -2.
		** o retorno da função sera o valor de sua cantada;
		*/
		virtual unsigned int pegarCantada ( std::vector<int> cantadas ) = 0;


		/** Metodo chamado pelo jogo no final da rodada depois de chamar o metodo pegarCantada
		**  de todos os jogadores. O vetor numeroDePalitos contem a quantidade total de palitos de cada
		**  jogador até o final de rodada. Sendo a soma dela a resposta correta da rodada.
		**  O vetor cantadas contém as cantadas de todos os jogadores nesta rodada
		*/
		virtual void informarRodada ( std::vector<int> numeroDePalitos, std::vector<int> cantadas ) = 0;


		virtual ~TipoJogador() {}
	protected:
	private:
};

#endif // TIPOJOGADOR_H
