#pragma once

# include "ATarget.hpp"

class Dummy : public ATarget
{
  private:
    Dummy &operator=(Dummy const & rhs);
    Dummy (Dummy const & other);
  
  public:
    Dummy();
    ~Dummy();
    
    Dummy * clone();
};