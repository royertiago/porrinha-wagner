#ifndef RANDYRANDOM_H
#define RANDYRANDOM_H

#include "player.h"
#include "core/util.h"
class randyRandom : public Player {
		int vitorias = 0;
		int minhaVitoria = 0;
		int lastGuess = 0;
		std::string name() const {
			return "Randy";
		}
        void begin_game() {}
		int hand() {
			int cont = 4;
			cont -= minhaVitoria;
			if ( cont == 0 ) return 0;
			return rand() % cont;
		}
		int guess () {

			int cont = 0;
for ( auto x: core::guess() ) {
				cont += 3;
			}
			cont -= vitorias;
			cont++;
			if ( cont == 0 ) return 0;

			int guess = rand() % cont;
			bool igual = true;
			int loopGuard = 0;
			while ( igual && loopGuard < 10 ) {
				// loopGuard++;
				igual = false;
            for ( auto x: core::guess() ) {
					if ( guess == x ) {
						guess = rand() % cont;
						igual = true;
					}
				}
			}
			lastGuess = guess;

			return guess;
		}
		void end_round () {
			int sum = 0;
            for ( auto x: core::hand() ) {
				if ( x > 0 )
					sum += x;
			}
            for ( auto x: core::guess() ) {
				if ( x == sum ) {
					vitorias++;
				}

			}
			if ( lastGuess == sum ) {
				minhaVitoria++;
			}
		}
		void end_game() {
			vitorias = 0;
			minhaVitoria = 0;
			lastGuess = 0;

		}

};

#endif // RANDYRANDOM_H
