# include "Warlock.hpp"

Warlock::Warlock(){};
Warlock::~Warlock(){
      std::cout << name << ": My job here is done!" << std::endl;
    };

Warlock::Warlock(std::string const & input_name, std::string const & input_title):
      name(input_name), title(input_title) { 
        std::cout << name << ": This looks like another boring day." << std::endl;
      };

std::string const & Warlock::getName() const {
      return this->name;
    }

std::string const & Warlock::getTitle() const {
      return this->title;
    }

void Warlock::setTitle(std::string const & input){
      title = input;
    }

void Warlock::introduce() const {
      std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
    }

void Warlock::learnSpell(ASpell * spell){
  book.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spell_to_forget){
  book.forgetSpell(spell_to_forget);
}

void Warlock::launchSpell(std::string spell_to_launch, ATarget const & target){
  ASpell * result = book.createSpell(spell_to_launch);
  if (result != NULL) {
    result->launch(target);
    delete result;
  }
}