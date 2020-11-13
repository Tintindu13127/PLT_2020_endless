// Generated by dia2code
#ifndef STATE__PLANET__H
#define STATE__PLANET__H


#include "Type_planetID.h"
#include "SizeID.h"
#include "StatutID.h"

namespace state {

  /// class Planet - 
  class Planet {
    // Associations
    // Attributes
  private:
    Type_planetID type;
    SizeID size_p;
    StatutID statut;
    int planetID;
    // Operations
  public:
    SizeID const get_size_p ();
    void colonize ();
    Type_planetID const get_type ();
    StatutID const get_statut ();
    int get_planetID ();
    // Setters and Getters
  };

};

#endif