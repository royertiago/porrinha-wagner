#include "Zero2.h"
#include "core/util.h"
namespace wagner {
	Zero2::Zero2( std::string name ) :
        _name(name)
	{}
	int Zero2::hand() {
		return 0;
	}
	int Zero2::guess () {
	    int guess = core::chopstick_count()/2;
        while( !core::valid_guess(guess) )
            guess = (guess + 1) % core::chopstick_count();
        return guess;
	}
    std::string Zero2::name() const{
        return "zero2";
    }
}
