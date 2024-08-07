#include "Fireball.hpp"

Fireball::~Fireball(){}
Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {};

Fireball * Fireball::clone(){
  return new Fireball();
}