#pragma once

# include <iostream>
# include <string>

class Warlock
{
  private:
    std::string name;
    std::string title;
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
};