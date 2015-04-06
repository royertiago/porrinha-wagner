#ifndef SAOBARBETA_H
#define SAOBARBETA_H
#include "Player.h"
#include <iostream>
#include <vector>
class Saobarbeta : public Player
{
	public:
		Saobarbeta ( std::string name = "Barbeta", int palitos = 3 );




		virtual std::string name() const override;

		virtual int hand() override;
		virtual int guess ( const std::vector<int>& other_guesses ) override;
		virtual void settle_round (
		    const std::vector<int>& hands,
		    const std::vector<int>& guesses
		) override;
		virtual void end_round();

		virtual ~Saobarbeta();
	protected:
        std::string _name;
        int myhand=0;
        int sticks;
        int totalSticks;
        int lastGuess;

        bool firstRound=true;

        std::vector<int> opponentSticks;
        int self=0;

	private:
};

#endif // SAOBARBETA_H
