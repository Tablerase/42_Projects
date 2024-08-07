#include "Polymorph.hpp"

Polymorph::~Polymorph(){}
Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {};

Polymorph * Polymorph::clone(){
  return new Polymorph();
}