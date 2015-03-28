#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "player.h"

namespace human_player {

    class HumanPlayer : public Player {
        std::string _name;
        int chopsticks;
    public:
        HumanPlayer( std::string name, int chopsticks );

        /* Overriden methods */
        std::string name() const override;
        int hand() override;
        int guess( const std::vector<int>& other_guesses ) override;
        void settle_round(
            const std::vector<int>& hands,
            const std::vector<int>& guesses
        ) override;
    };

} // namespace human_player

#endif // HUMAN_PLAYER_H
