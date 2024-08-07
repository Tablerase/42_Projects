#include "Dummy.hpp"

Dummy::~Dummy(){}
Dummy::Dummy() : ATarget("Target Practice Dummy") {}
Dummy * Dummy::clone(){
  return new Dummy();
}