/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:30:51 by rcutte            #+#    #+#             */
/*   Updated: 2024/07/02 00:48:02 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H_
# define BITCOINEXCHANGE_H_

# include <iostream>
# include <iomanip>
# include <string>

# include <map>
# include <exception>
# include <algorithm>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include "color.h"

/**
 * @note std::map - allow to compare and find easyly precise values
 * according to a key.
 * https://cplusplus.com/reference/map/map/
*/

struct CoinInfos
{
  std::string date;
  float       amount;
  float       value;
};

struct BitcoinExchange
{
  std::ifstream                 input_file_;
  std::ifstream                 data_file_;
  std::map<std::string, float>  coin_map_;
};

// Initialization

void InitExchange(int ac, char** av, BitcoinExchange& core);
void InitCoinMap(BitcoinExchange& core);

// Read Input File

void BitcoinDisplay(BitcoinExchange& core);

#endif