#ifndef SMARTY_H
#define SMARTY_H
#include "player.h"
#include "core/util.h"
#include <iostream>
#include <vector>

namespace wagner {

class Smarty : public Player
{
	public:
		Smarty ( std::string name = "Smarty", int palitos = 3 );




		virtual std::string name() const override;

        virtual void begin_game() override;
		virtual int hand() override;
		virtual int guess () override;
		virtual void end_round () override;
		virtual void end_game();

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

} // namespace wagner

#endif // SMARTY_H
