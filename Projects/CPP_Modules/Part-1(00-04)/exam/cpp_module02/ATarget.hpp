#pragma once

# include <iostream>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
  private:
    std::string type;
    ATarget();
    ATarget &operator=(ATarget const & rhs);
    ATarget (ATarget const & other);
  
  public:
    virtual ~ATarget();
    ATarget(std::string input_type);
    std::string const & getType() const;

    void getHitBySpell(ASpell const & spell) const;

    virtual ATarget * clone() = 0;
};