#pragma once

# include "ASpell.hpp"

class Fwoosh : public ASpell
{
  private:
    Fwoosh &operator=(Fwoosh const & rhs);
    Fwoosh (Fwoosh const & other);
  
  public:
    Fwoosh();
    ~Fwoosh();

    Fwoosh * clone();
};