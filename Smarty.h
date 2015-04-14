#ifndef SMARTY_H
#define SMARTY_H
#include "Player.h"
#include <iostream>
#include <vector>
class Smarty : public Player
{
	public:
		Smarty ( std::string name = "Smarty", int palitos = 3 );




		virtual std::string name() const override;

		virtual int hand() override;
		virtual int guess ( const std::vector<int>& other_guesses ) override;
		virtual void settle_round (
		    const std::vector<int>& hands,
		    const std::vector<int>& guesses
		) override;
		virtual void end_round();

		virtual ~Smarty();
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

#endif // SMARTY_H
