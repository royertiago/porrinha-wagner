#ifndef FACTORY_H
#define FACTORY_H
#include <vector>

    class TipoJogador;

    class Factory
    {
        public:
            Factory();
            virtual ~Factory();
           static  std::vector<TipoJogador*> criarJogadores();
        protected:
        private:
    };

#endif // FACTORY_H
