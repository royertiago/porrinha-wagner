#include <iostream>

#include "human_player.h"

namespace human_player {

HumanPlayer::HumanPlayer( std::string name, int chopsticks ) :
    _name(name),
    chopsticks(chopsticks)
{}

std::string HumanPlayer::name() const {
    return _name;
}

int HumanPlayer::hand() {
    std::cout << "Human " << _name << ", type how many chopsticks"
        " you will use this round:";
    int hand;


        std::cin >> hand;

        if( !std::cin ) {
            std::cout << "Please type a number:";
            std::cin.clear();

        }
        if( hand > chopsticks ) {
            std::cout << "You have only " << chopsticks << " chopsticks.\n"
                "Type a valid number of chopsticks:";

        }
        if( hand < 0 ) {
            std::cout << "You cannot play a negative number of chopsticks!\n"
                "Type a valid number of chopsticks:";

        }

    return hand;
}

int HumanPlayer::guess( const std::vector<int>& other_guesses ) {

    for( unsigned i = 0; i < other_guesses.size(); i++ ) {
       // if( other_guesses[i] >= 0 )
            std::cout << "Player " << i << " guessed "
                      << other_guesses[i] << ".\n";
    }

    std::cout << "Human " << _name << ", type your guess for this round:";
     lastguess;
    while( true ) {
        std::cin >> lastguess;
        if( !std::cin ) {
            std::cout << "Please type a number:";
            std::cin.clear();
            continue;
        }
        if( lastguess < 0 ) {
            std::cout << "Your cannot guess a negative number of chopsticks!\n"
                "Type a valid guess.";
            continue;
        }
        break;
    }
    return lastguess;
}

void HumanPlayer::settle_round(
    const std::vector<int>& hands,
    const std::vector<int>& guesses
) {
    for( unsigned i = 0; i < guesses.size(); i++ )
        std::cout << "Player " << i << " guessed " << guesses[i]
            << " and played " << hands[i] << " choptsicks.\n";

    int sum=0;
    for ( auto x: hands ) {
		if ( x > 0 )
			sum += x;
	}
	std::cout<< "Total sticks: "<<sum<<" you guessed "<<lastguess <<std::endl;


}


} // namespace human_player
