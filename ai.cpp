#include "player.h"
#include "ai.h"
#include "Zero2.h"
#include "RandyRandom.h"
#include "Smarty.h"
#include "core/util.h"

namespace wagner {
    Player * generateZero2( cmdline::args&& ){
        return new Zero2();
    }
    Player * generateRandyRandom( cmdline::args&& ) {
        return new randyRandom();
    }
    Player * generateSmarty( cmdline::args&& ) {
        return new Smarty();
    }
} // namespace wagner
