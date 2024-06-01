/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:41:49 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/26 17:22:34 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

/* ======================== Constructor / Destructor ======================== */

Span::Span() : max_entity_(10)
{
  #ifdef LOG
  std::cout << BLUB << "🧬 Constructor Span by default" << RESET << "\n";
  #endif
}

Span::~Span()
{
  #ifdef LOG
  std::cout << BLKB << "🧬‍ Destructor Span by default" << RESET << "\n";
  #endif
}

Span::Span(unsigned int const N)
  : max_entity_(N)
{
  #ifdef LOG
  std::cout << BLUB << "🧬 Constructor Span by param" << RESET << "\n";
  #endif
}

Span::Span(Span const &other)
{
  *this = other;
  #ifdef LOG
  std::cout << BLUB << "🧬 Constructor Span by copy" << RESET << "\n";
  #endif
}

Span &Span::operator=(Span const &rhs)
{
  if (this != &rhs){
    max_entity_ = rhs.get_max_entity();
    list_.clear();
    std::list<int> temp_list = rhs.get_list();
    list_.merge(temp_list);
  }
  #ifdef LOG
  std::cout << BLUB << "🧬 Constructor Span by assign" << RESET << "\n";
  #endif
  return *this;
}

/* ================================= Getter ================================= */

std::list<int> Span::get_list() const {
  return this->list_;
}

unsigned int Span::get_max_entity() const {
  return this->max_entity_;
}

/* ================================= Setter ================================= */

/* =============================== Functions ================================ */  

void Span::addNumber(int const &value){
  if (list_.size() + 1 <= max_entity_ ){
    list_.push_back(value);
  } else {
    throw SpanIsFull();
  }
}

void Span::addNumbers(int const &amount_of_elements, int const &value){
  if (list_.size() + amount_of_elements <= max_entity_){
    list_.resize(list_.size() + amount_of_elements, value);
  } else {
    throw SpanIsFull();
  }
}

void Span::addNumbers(int const &start_value,
    int const &end_value,
    int const &increment){
  unsigned int size = list_.size();
  unsigned int count = 0;
  for (int i = start_value; i < end_value; i += increment){
    count++;
    if (size + count > max_entity_){ throw SpanIsFull() ;}
    list_.push_back(i);
  }
}

unsigned int Span::shortestSpan(void) const {
  if (list_.size() < 2){
    throw SpanTooSmall();
  }

  std::list<int> sorted_list(list_);
  sorted_list.sort();

  std::list<int>::const_iterator it = sorted_list.begin();
  std::list<int>::const_iterator next = it;
  next++;
  
  unsigned int shortest_span = std::numeric_limits<unsigned int>::max();
  unsigned int span = 0;
  for (; next != sorted_list.end(); it++, next++){
    span = *next - *it;
    if (span < shortest_span){
      shortest_span = span;
    }
  }
  return shortest_span;
}

unsigned int Span::longestSpan() const {
  if(list_.size() < 2) {
      throw SpanTooSmall();
  }

  int minElement = *std::min_element(list_.begin(), list_.end());
  int maxElement = *std::max_element(list_.begin(), list_.end());

  return maxElement - minElement;
}

/* =============================== Exceptions =============================== */

const char* Span::SpanIsFull::what() const throw(){
  return "Span doesnt have enought available space to perform this operation";
}

const char* Span::SpanTooSmall::what() const throw(){
  return "Span is too small to perform this operation";
}

/* ================================= Output ================================= */

#define SEPARATOR_LENGHT 60

void SeparatorLine(){
  std::cout
    << BLU
    << std::setw(SEPARATOR_LENGHT) << std::setfill('-')
    << RESET << "\n";
}

void SeparatorMsg(std::string const &msg){
  int msg_len = msg.length();
  int inter_space = (SEPARATOR_LENGHT - msg_len) / 2;
  std::cout
    << std::setw(SEPARATOR_LENGHT) << std::setfill('=') << "\n"
    << "|" << std::setw(inter_space + 1) << std::setfill(' ') << RESET
    << msg ;
  if (msg_len % 2 == 1)
    std::cout << " ";
  std::cout
    << std::setw(inter_space + 1) << "|" << "\n"
    << std::setw(SEPARATOR_LENGHT) << std::setfill('=') << "\n";
}

std::ostream &operator<<(std::ostream &os, const Span &obj){
  os
    << MAGB << " 🧬 Span " << RESET << " " << "Max Entity: "
    << BMAG << obj.get_max_entity() << RESET << " Size: " 
    << BMAG << obj.get_list().size() << RESET << "\n"
    << BMAG << "-------------------- Contents -----------------------"
    << RESET << "\n";

  if (obj.get_list().size() == 0)
    return os;
  std::list<int> temp_list = obj.get_list();
  std::list<int>::const_iterator it;
  for(it = temp_list.begin(); it != temp_list.end(); it++) {
    os << *it << " ";
  }
  os << "\n";

  return os;
}
