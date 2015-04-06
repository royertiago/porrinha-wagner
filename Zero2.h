#ifndef ZERO2_H
#define ZERO2_H

#include "Player.h"
namespace zero2{

    class Zero2 : public Player {
        public:

            Zero2(std::string name="Zero2");
            virtual ~Zero2();

            std::string name() const override;

            int hand() override;

            int guess( const std::vector<int>& other_guesses ) override;

            void settle_round(
                const std::vector<int>& hands,
                const std::vector<int>& guesses
            ) override;
            void end_round(){}


        protected:
           std::string _name;
        private:
    };
}

#endif // ZERO2_H
