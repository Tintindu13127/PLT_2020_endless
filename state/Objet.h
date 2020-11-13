// Generated by dia2code
#ifndef STATE__OBJET__H
#define STATE__OBJET__H

#include <string>

namespace state {
  class Position;
  class StellarWay;
}

#include "Position.h"
#include "StellarWay.h"

namespace state {

  /// class Objet - 
  class Objet {
    // Associations
    // Attributes
  protected:
    std::string name;
    Position position ;
    // Setters and Getters
    const std::string& getName() const;
    void setName(const std::string& name);
    const Position& getPosition () const;
    void setPosition (const Position& position );
  };

};

#endif