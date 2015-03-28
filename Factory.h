#ifndef FACTORY_H
#define FACTORY_H
#include <vector>

    class Player;

    class Factory
    {
        public:
            Factory();
            virtual ~Factory();
           static  std::vector<Player*> criarJogadores();
        protected:
        private:
    };

#endif // FACTORY_H
