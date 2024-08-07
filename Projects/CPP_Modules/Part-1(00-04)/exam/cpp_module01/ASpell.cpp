#include "ASpell.hpp"

ASpell::~ASpell(){}
ASpell::ASpell(std::string input_name, std::string input_effects) :
  name(input_name), effects(input_effects){ }

std::string ASpell::getName() const {
  return name;
}
std::string ASpell::getEffects() const {
  return effects;
}

void ASpell::launch(ATarget const & target){
  target.getHitBySpell(*this);
}
