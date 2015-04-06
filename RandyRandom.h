#ifndef RANDYRANDOM_H
#define RANDYRANDOM_H

#include "Player.h"
class randyRandom : public Player {
		int vitorias = 0;
		int minhaVitoria = 0;
		int lastGuess = 0;
		std::string name() const {
			return "Randy";
		}
		int hand() {
			int cont = 4;
			cont -= minhaVitoria;
			if ( cont == 0 ) return 0;
			return rand() % cont;
		}
		int guess ( const std::vector<int>& cantadas ) {

			int cont = 0;
for ( auto x: cantadas ) {
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
            for ( auto x: cantadas ) {
					if ( guess == x ) {
						guess = rand() % cont;
						igual = true;
					}
				}
			}
			lastGuess = guess;

			return guess;
		}
		void settle_round ( const std::vector<int>& numeroDePalitos, const std::vector<int>& cantadas ) {
			int sum = 0;
            for ( auto x: numeroDePalitos ) {
				if ( x > 0 )
					sum += x;
			}
            for ( auto x: cantadas ) {
				if ( x == sum ) {
					vitorias++;
				}

			}
			if ( lastGuess == sum ) {
				minhaVitoria++;
			}
		}
		void end_round() {
			vitorias = 0;
			minhaVitoria = 0;
			lastGuess = 0;

		}

};

#endif // RANDYRANDOM_H
