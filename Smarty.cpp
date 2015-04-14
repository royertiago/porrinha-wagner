#include "Smarty.h"
using namespace std;

namespace wagner {

Smarty::Smarty( std::string name, int palitos ) :
	_name ( name ), totalSticks ( palitos )
{
    opponentSticks= std::vector<int>();
    end_round();

}

Smarty::~Smarty()
{
	//dtor
}
std::string Smarty::name() const {
	return _name;
}
void Smarty::begin_game() {
}
int Smarty::hand() {

	if ( sticks == 0 ){
	    myhand=0;
        return 0;
	}
	myhand =rand() % (sticks+1);
	return myhand;
}
int Smarty::guess () {
    if(firstRound){
        for (int i=0;i<core::guess().size();i++){
            opponentSticks.push_back(totalSticks);
        }
        firstRound=false;
    }
    int sum=0;

    for (int i=0;i<opponentSticks.size();i++){
        if(i!=self && opponentSticks[i] >0){

            sum+= rand()%(opponentSticks[i]+1);
        }
    }
    sum+=myhand;


   int myguess= sum ;


    bool igual=true;
    while(igual){
            igual=false;
            for(auto x: core::guess()){
                if(myguess==x){
                    myguess++;
                    igual=true;
                }
            }
        }
    lastGuess=myguess;

	return myguess;
}
void Smarty::end_round () {
	int sum = 0;
    for ( auto x: core::hand() ) {
		if ( x > 0 )
			sum += x;
	}
    for (int i=0;i<core::guess().size();i++){
        if(core::guess(i)==sum){
            opponentSticks[i]--;
        }
        if(core::guess(i)==lastGuess){
            self=i;
        }
    }

	if ( lastGuess == sum ) {
		sticks--;
	}
}
void Smarty::end_game() {


    sticks=totalSticks;
     for(auto& x: opponentSticks){
        x=totalSticks;
    }

}

} // namespace wagner
