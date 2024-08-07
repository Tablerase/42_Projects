#pragma once

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
  private:
    std::string name;
    std::string effects;
    ASpell();
    ASpell &operator=(ASpell const & rhs);
    ASpell (ASpell const & other);
  
  public:
    virtual ~ASpell();
    ASpell(std::string input_name, std::string input_effects);

    std::string getName() const;
    std::string getEffects() const;

    void launch(ATarget const & target);

    virtual ASpell * clone() = 0;
};
