#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
  private:
    std::map<std::string, ATarget *>field;

    TargetGenerator(TargetGenerator const & other);
    TargetGenerator &operator=(TargetGenerator const & rhs);
  
  public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget * target_to_learn);
    void forgetTargetType(std::string const & target_to_forget);
    ATarget * createTarget(std::string const & target_to_create);
};