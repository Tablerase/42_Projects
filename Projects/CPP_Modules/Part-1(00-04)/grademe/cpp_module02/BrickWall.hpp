#pragma once

# include "ATarget.hpp"

class BrickWall : public ATarget
{
  private:
    BrickWall &operator=(BrickWall const & rhs);
    BrickWall (BrickWall const & other);
  
  public:
    BrickWall();
    ~BrickWall();
    
    BrickWall * clone();
};