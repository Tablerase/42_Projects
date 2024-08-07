#include "Fwoosh.hpp"

Fwoosh::~Fwoosh(){}
Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {};

Fwoosh * Fwoosh::clone(){
  return new Fwoosh();
}