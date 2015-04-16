#include "Zero2.h"
#include "core/util.h"
#include "stdlib.h"
namespace wagner {
    Zero2::Zero2( std::string name ) :
        _name(name)
    {}

	int Zero2::hand() {
        if(rand()%100<5){
            return rand()%core::chopsticks(core::index(this))+1;
        }
		return 0;
	}
	int Zero2::guess () {
       int half=core::chopstick_count()/2;
	   int guess= core::chopstick_count()/2;

       while(!core::valid_guess(guess)){
            guess++;
            if(guess>  core::chopstick_count())break;
       }
       guess=half;
       while(!core::valid_guess(guess)){
            guess--;
       }
       return guess;


	}
    std::string Zero2::name() const{
        return "zero2";
    }
}
