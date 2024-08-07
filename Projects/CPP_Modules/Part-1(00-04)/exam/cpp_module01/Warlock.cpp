# include "Warlock.hpp"

Warlock::Warlock(){};
Warlock::~Warlock(){
      std::cout << name << ": My job here is done!" << std::endl;
      for (std::map<std::string, ASpell *>::iterator it = spell_store.begin();
        it != spell_store.end(); 
        it++)
        {
          if (it->second != NULL) {
            delete it->second;
          }
        }
      spell_store.clear();
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
  spell_store.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void Warlock::forgetSpell(std::string spell_to_forget){
  try {
    ASpell * result = spell_store.at(spell_to_forget);
    delete result;
    spell_store.erase(spell_to_forget);
  } catch (std::exception const & e){}
}

void Warlock::launchSpell(std::string spell_to_launch, ATarget const & target){
  try {
    ASpell * result = spell_store.at(spell_to_launch);
    result->launch(target);
  } catch (std::exception const & e){}
}