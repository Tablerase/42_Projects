#pragma once

# include <iostream>
# include <string>
# include <map>

# include "ATarget.hpp"
# include "ASpell.hpp"

class SpellBook
{
  private:
    std::map<std::string, ASpell *> spell_store;
    SpellBook(SpellBook const & other);
    SpellBook &operator=(SpellBook const & rhs);
  
  public:
    SpellBook();
    ~SpellBook();
    void learnSpell(ASpell * spell);
    void forgetSpell(std::string const & spell_to_forget);
    ASpell * createSpell(std::string const & spell_to_create);
};