#pragma once

# include <iostream>
# include <string>
# include <map>

# include "ATarget.hpp"
# include "ASpell.hpp"
# include "SpellBook.hpp"

class Warlock
{
  private:
    std::string name;
    std::string title;
    SpellBook book;

    Warlock();
    Warlock &operator=(Warlock const &rhs){ if (this != &rhs){ }; return *this; }
    Warlock(Warlock const &other){ *this = other; }

  public:
    Warlock(std::string const & input_name, std::string const & input_title);
    ~Warlock();

    std::string const & getName() const ;
    std::string const & getTitle() const ;

    void setTitle(std::string const & input);

    void introduce() const;

    void learnSpell(ASpell * spell);
    void forgetSpell(std::string spell_to_forget);
    void launchSpell(std::string spell_to_launch, ATarget const & target);
};