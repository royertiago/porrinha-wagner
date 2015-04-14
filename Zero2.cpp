#include "Zero2.h"
#include "core/util.h"
namespace wagner {
	Zero2::Zero2(std::string name):_name(name)
	{

	}

	Zero2::~Zero2()
	{

    }
	int Zero2::hand() {
		return 0;
	}
	int Zero2::guess () {
	    core::chopstick_count()/2;


	}
    std::string Zero2::name() const{

    }

}

