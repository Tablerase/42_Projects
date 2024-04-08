/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:46:26 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/05 23:03:26 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _CONTACT_HPP
  #define _CONTACT_HPP 

#include <string>

class Contact
{
  private:
    std::string first_name_;
    std::string last_name_;
    std::string nick_name_;
    std::string phone_num_;
    std::string darkest_secret_;
  public:
    Contact(); // Default Constructor
    Contact( // Param Constructor
      std::string input_first_name_,
      std::string input_last_name_,
      std::string input_nick_name_,
      std::string input_phone_num_,
      std::string input_darkest_secret_);
    ~Contact( void );

    void  printContact() const;

    std::string getFirstName() const { return first_name_; }
    std::string getLastName() const { return last_name_; }
    std::string getNickName() const { return nick_name_; }
    std::string getPhoneNum() const { return phone_num_; }
    std::string getDarkestSecret() const { return darkest_secret_; }
    
    void setFirstName(const std::string& firstName) { first_name_ = firstName; }
    void setLastName(const std::string& lastName) { last_name_ = lastName; }
    void setNickName(const std::string& nickName) { nick_name_ = nickName; }
    void setPhoneNum(const std::string& phoneNum) { phone_num_ = phoneNum; }
    void setDarkestSecret(const std::string& darkestSecret) { darkest_secret_ = darkestSecret; }
};

#endif