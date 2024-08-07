#pragma once

# include "ASpell.hpp"

class Fireball : public ASpell
{
  private:
    Fireball &operator=(Fireball const & rhs);
    Fireball (Fireball const & other);
  
  public:
    Fireball();
    ~Fireball();

    Fireball * clone();
};