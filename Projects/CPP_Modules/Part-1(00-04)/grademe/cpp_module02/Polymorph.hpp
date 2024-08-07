#pragma once

# include "ASpell.hpp"

class Polymorph : public ASpell
{
  private:
    Polymorph &operator=(Polymorph const & rhs);
    Polymorph (Polymorph const & other);
  
  public:
    Polymorph();
    ~Polymorph();

    Polymorph * clone();
};