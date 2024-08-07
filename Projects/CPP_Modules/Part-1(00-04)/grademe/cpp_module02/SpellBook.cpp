#include "SpellBook.hpp"

SpellBook::SpellBook(){}
SpellBook::~SpellBook(){
  for (std::map<std::string, ASpell *>::iterator it = spell_store.begin();
        it != spell_store.end(); 
        it++)
    {
      if (it->second != NULL) {
        delete it->second;
      }
    }
  spell_store.clear();
}

void SpellBook::learnSpell(ASpell * spell){
  spell_store.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(std::string const & spell_to_forget){
  try {
    ASpell * result = spell_store.at(spell_to_forget);
    delete result;
    spell_store.erase(spell_to_forget);
  } catch (std::exception const & e){}
}

ASpell * SpellBook::createSpell(std::string const & spell_to_create){
  try {
    ASpell * result = spell_store.at(spell_to_create);
    return result->clone();
  } catch (std::exception const & e) {}
  return NULL;
}