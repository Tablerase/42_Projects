#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}
TargetGenerator::~TargetGenerator(){
  for (std::map<std::string, ATarget *>::iterator it = field.begin();
        it != field.end(); 
        it++)
    {
      if (it->second != NULL) {
        delete it->second;
      }
    }
  field.clear();
}

void TargetGenerator::learnTargetType(ATarget * target_to_learn){
  field.insert(std::pair<std::string, ATarget *>(target_to_learn->getType(), target_to_learn->clone()));
}

void TargetGenerator::forgetTargetType(std::string const & target_to_forget){
  try {
    ATarget * result = field.at(target_to_forget);
    delete result;
    field.erase(target_to_forget);
  } catch (std::exception const & e){}
}

ATarget * TargetGenerator::createTarget(std::string const & target_to_create){
  try {
    ATarget * result = field.at(target_to_create);
    return result->clone();
  } catch (std::exception const & e) {}
  return NULL;
}