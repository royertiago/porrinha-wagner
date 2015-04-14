#include "Smarty.h"
using namespace std;

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
int Smarty::hand() {

	if ( sticks == 0 ){
	    myhand=0;
        return 0;
	}
	myhand =rand() % (sticks+1);
	return myhand;
}
int Smarty::guess ( const std::vector<int>& cantadas ) {
    if(firstRound){
        for (int i=0;i<cantadas.size();i++){
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
            for(auto x: cantadas){
                if(myguess==x){
                    myguess++;
                    igual=true;
                }
            }
        }
    lastGuess=myguess;

	return myguess;
}
void Smarty::settle_round ( const std::vector<int>& numeroDePalitos, const std::vector<int>& cantadas ) {
	int sum = 0;
    for ( auto x: numeroDePalitos ) {
		if ( x > 0 )
			sum += x;
	}
    for (int i=0;i<cantadas.size();i++){
        if(cantadas[i]==sum){
            opponentSticks[i]--;
        }
        if(cantadas[i]==lastGuess){
            self=i;
        }
    }

	if ( lastGuess == sum ) {
		sticks--;
	}
}
void Smarty::end_round() {


    sticks=totalSticks;
     for(auto& x: opponentSticks){
        x=totalSticks;
    }

}
