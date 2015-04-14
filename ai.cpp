#include "ai.h"
#include "Zero2.h"
#include "RandyRandom.h"
#include "Smarty.h"

namespace wagner {
    Player * generateZero2( int players, int chopsticks ){
        return new Zero2();
    }
    Player * generateRandyRandom( int, int ) {
        return new randyRandom();
    }
    Player * generateSmarty( int, int chopsticks ) {
        return new Smarty( "Smarty", chopsticks );
    }
} // namespace wagner
