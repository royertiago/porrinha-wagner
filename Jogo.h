#ifndef JOGO_H
#define JOGO_H
#include <vector>
class TipoJogador;

class Jogo
{

    public:

        Jogo(std::vector<TipoJogador*> jogadores, int numeroRodadas = 5, int numeroPalitos = 3 );
        void comecar();
        virtual ~Jogo();

        struct Jogador{
            int mao,cantada,palitos;
            bool estaJogando=true;
            TipoJogador* ai;

        };


    protected:

        virtual void placarRodada();
        virtual void placarTotal();
        virtual void partida();
        virtual void fimDeRodada();
        virtual int pegarPerdedor();

        virtual void pegarCantada(Jogador&);
        virtual void pegarMao(Jogador&);
        virtual void ganhou(Jogador&);

        void proximoJogador();



        std::vector<Jogador> _jogadores;
        std::vector<Jogador> _placar;
        unsigned int _jogadorAtual;
        unsigned int _jogadorInicial;
        unsigned int _partidaAtual;
        int _numeroJogadores;


    private:

        const unsigned int _numeroPalitos;
        const unsigned int _numeroPartidas;
};

#endif // JOGO_H
