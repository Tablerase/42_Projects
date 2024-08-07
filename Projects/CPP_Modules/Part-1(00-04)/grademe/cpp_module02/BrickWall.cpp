#include "BrickWall.hpp"

BrickWall::~BrickWall(){}
BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}
BrickWall * BrickWall::clone(){
  return new BrickWall();
}