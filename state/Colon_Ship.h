// Generated by dia2code
#ifndef STATE__COLON_SHIP__H
#define STATE__COLON_SHIP__H


namespace state {
  class Planet;
  class Ship;
}

#include "Planet.h"
#include "Ship.h"

namespace state {

  /// class Colon_Ship - 
  class Colon_Ship : public state::Ship {
    // Operations
  public:
    void colonize (Planet planet);
    // Setters and Getters
  };

};

#endif