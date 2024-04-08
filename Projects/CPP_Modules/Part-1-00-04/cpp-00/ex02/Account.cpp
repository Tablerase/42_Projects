/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:48:51 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/05 22:33:09 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Account.hpp"

Account::Account( void ){}

Account::~Account( void ){
  Account::_displayTimestamp();
  std::cout 
    << "index:" << this->_accountIndex << ";"
    << "amount:" << this->_amount << ";"
    << "closed" << "\n";
}

Account::Account( int initial_deposit ){
  _accountIndex = _nbAccounts++;
  _amount = initial_deposit;
  _totalAmount = _totalAmount + initial_deposit;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  Account::_displayTimestamp();
  std::cout 
    << "index:" << this->_accountIndex << ";"
    << "amount:" << this->_amount << ";"
    << "created" << "\n";
}

void Account::displayStatus( void ) const {
  Account::_displayTimestamp();
  std::cout
    << "index:" << this->_accountIndex << ";"
    << "amount:" << this->_amount << ";"
    << "deposits:" << this->_nbDeposits << ";"
    << "withdrawals:" << this->_nbWithdrawals << ";"
    << "\n";
}

void Account::_displayTimestamp( void ){
  std::time_t t = std::time(nullptr); // get current time
  std::tm* timePtr = std::localtime(&t); // convert to local time

  std::cout 
    << "[" << std::put_time(timePtr, "%Y%m%d_%H%M%S") << "] ";
}

void Account::makeDeposit( int deposit ){
  Account::_displayTimestamp();
  int p_amount = this->_amount;
  this->_amount += deposit;
  _totalAmount += deposit;
  this->_nbDeposits++;
  _totalNbDeposits++;
  std::cout
    << "index:" << this->_accountIndex << ";"
    << "p_amount:" << p_amount << ";"
    << "deposit:" << deposit << ";"
    << "amount:" << this->_amount << ";"
    << "nb_deposits:" << this->_nbDeposits << ";"
    << "\n";
}

int Account::checkAmount(void) const {
  return this->_amount;
}

bool Account::makeWithdrawal( int withdrawal ){
  Account::_displayTimestamp();
  int p_amount = this->_amount;
  if (withdrawal < checkAmount())
  {
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout
      << "index:" << this->_accountIndex << ";"
      << "p_amount:" << p_amount << ";"
      << "withdrawal:" << withdrawal << ";"
      << "amount:" << this->_amount << ";"
      << "nb_withdrawals:" << this->_nbWithdrawals << ";"
      << "\n";
    return true; 
  }
  else
  {
    std::cout
      << "index:" << this->_accountIndex << ";"
      << "p_amount:" << p_amount << ";"
      << "withdrawal: refused"
      << "\n";
    return false;
  }
}

// Init non member var

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Define non member function

int Account::getNbAccounts( void ){
  int result = _nbAccounts;
  return result;
}

int Account::getTotalAmount( void ){
  int result = _totalAmount;
  return result;
}

int Account::getNbDeposits( void ){
  int result = _totalNbDeposits;
  return result;
}

int Account::getNbWithdrawals( void ){
  int result = _totalNbWithdrawals;
  return result;
}

void Account::displayAccountsInfos( void ){
  Account::_displayTimestamp();
  std::cout
    << "accounts:" << getNbAccounts() << ";"
    << "total:" << getTotalAmount() << ";"
    << "deposits:" << getNbDeposits() << ";"
    << "withdrawals:" << getNbWithdrawals() << ";"
    << "\n";
}