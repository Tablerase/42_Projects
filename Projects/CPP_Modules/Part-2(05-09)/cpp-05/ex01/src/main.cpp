/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:50:49 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/13 13:28:08 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

#define SEPARATOR_LENGHT 60

void SeparatorLine(){
  std::cout
    << BLU
    << std::setw(SEPARATOR_LENGHT) << std::setfill('-')
    << RESET << "\n";
}

void SeparatorMsg(std::string msg){
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

void  testForm(){
  SeparatorMsg("Form");
  {
    Form paper;
    std::cout << paper;
  }
  SeparatorLine();
  {
    Bureaucrat agent_1 = Bureaucrat("Master Agent", 1);
    Bureaucrat agent_150 = Bureaucrat("Intern Agent", 150);
    Bureaucrat agent_75 = Bureaucrat("Standard Agent", 75);
    Form paper_to_fill = Form("Master form", 10, 10);
    std::cout
      << paper_to_fill
      << agent_75
      << agent_1;
    agent_75.signForm(paper_to_fill);
    agent_1.signForm(paper_to_fill);
  }
  SeparatorLine();
  {
    Bureaucrat agent_src = Bureaucrat("Agent Source", 10);
    Bureaucrat *agent_ptr = new Bureaucrat(agent_src);
    Form paper_src = Form("Source paper", 15, 15);
    Form *paper_ptr = new Form(paper_src);
    agent_ptr->signForm(*paper_ptr);
    std::cout << *paper_ptr;
    delete paper_ptr;
    delete agent_ptr;
  }
}

int main(){
  SeparatorMsg("Highest: 1 | Lowest: 150");
  testForm();
}