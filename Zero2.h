#ifndef ZERO2_H
#define ZERO2_H

#include "player.h"
namespace wagner{

    class Zero2 : public Player {
        public:
            Zero2(std::string name = "Zero2");

            std::string name() const override;
            int hand() override;
            int guess() override;
            void end_round(){}
            void begin_game(){}
            void end_game(){}
        protected:
           std::string _name;
        private:
    };
}

#endif // ZERO2_H
