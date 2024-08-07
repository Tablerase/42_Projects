#include "ATarget.hpp"

ATarget::ATarget(std::string input_type): type(input_type){}
ATarget::~ATarget(){}

std::string const & ATarget::getType() const {
  return type;
}

void ATarget::getHitBySpell(ASpell const & spell) const {
  std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}