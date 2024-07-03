/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:30:57 by rcutte            #+#    #+#             */
/*   Updated: 2024/07/02 02:33:46 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ================================  Header ================================= */

#include "BitcoinExchange.hpp"

/* ======================== Constructor / Destructor ======================== */

/**
 * @brief Init Struct Params
 * @throw Error in case file couldnt open, or not enought args in av
 */
void InitExchange(int ac, char** av, BitcoinExchange& core)
{
  if (ac != 2){
    std::string error = YEL;
    error += "[Usage]";
    error += RESET;
    error += " ./btc [input_file]";
    throw std::invalid_argument(error);
  }
  std::string file_name = av[1];
  core.input_file_.open(av[1]);
  if (core.input_file_.is_open() == false){
    throw std::runtime_error("can't open: " + file_name);
  };
  core.data_file_.open("data.csv");
  if (core.data_file_.is_open() == false){
    core.input_file_.close();
    throw std::runtime_error("can't open: data.csv");
  }
}

/**
 * @brief Init Coin Map
 * @param core Main structure to store values
 * @note Parse csv and store value in the map coin_map_
 * @throw In case of format (date,value) not respected
 */
void InitCoinMap(BitcoinExchange& core){
  std::string line;
  while (std::getline(core.data_file_, line))
  {
    if (line.find("date,exchange_rate") != line.npos){
      continue;
    }
    std::istringstream sstream(line);
    std::string sub_line;
    std::string key;
    float value = 0.0f;
    int i = 0;
    while (std::getline(sstream, sub_line, ','))
    {
      if (i == 0){
        key = sub_line;
      } else if (i == 1){
        std::istringstream iss(sub_line);
        if (!(iss >> value)) {
          throw std::runtime_error("Invalid argument: " + sub_line + " cannot be converted to float.");
        }
      }
      i++;
    }
    core.coin_map_[key] = value;
  }
}

/* ================================ Function ================================ */

void ParseDate(std::istringstream& sstream, std::string& parsedDate) {
  std::string year, month, day;
  if (std::getline(sstream, year, '-')
    && std::getline(sstream, month, '-')
    && std::getline(sstream, day, ' ')) {
    std::istringstream year_stream(year);
    int year_int;
    if (!(year_stream >> year_int) || !year_stream.eof() || year_int < 2009) {
      throw std::runtime_error("bad input: " + year + '-' + month + '-' + day);
    }
    std::istringstream month_stream(month);
    int month_int;
    if (!(month_stream >> month_int) || !month_stream.eof()
      || month_int < 1 || month_int > 12) {
      throw std::runtime_error("bad input: " + year + '-' + month + '-' + day);
    }
    std::istringstream day_stream(day);
    int day_int;
    if (!(day_stream >> day_int) || !day_stream.eof()
      || day_int < 1 || day_int > 31) {
      throw std::runtime_error("bad input: " + year + '-' + month + '-' + day);
    }
  } else {
    throw std::runtime_error("bad input: " + year + '-' + month + '-' + day);
  }
  parsedDate = year + '-' + month + '-' + day;
}

void ParseCoin(std::istringstream& sstream, CoinInfos& coin){
  std::string limiter, number;
  if (std::getline(sstream, limiter, ' ')
    && std::getline(sstream, number)){
    int pos = limiter.find_first_of("|");
    if (pos != 0){
      throw std::runtime_error("bad input: " + coin.date + ' ' + limiter);
    }
    std::istringstream coin_stream(number);
    float coin_value;
    if (!(coin_stream >> coin_value) || !coin_stream.eof()){
      throw std::runtime_error("bad input: " + coin.date + ' ' + limiter + ' ' + number);
    } else if (coin_value < 0){
      throw std::runtime_error("not a positive number: " + number);
    } else if (coin_value > 1000){
      throw std::runtime_error("number too large: " + number);
    } else {
      coin.amount = coin_value;
    }
  } else {
    throw std::runtime_error("bad input: " + coin.date + ' ' + limiter);
  }
}

void CalculateCoin(BitcoinExchange& core, CoinInfos& coin){
  std::map<std::string, float>::iterator it = core.coin_map_.find(coin.date);
  float change_value;
  if (it != core.coin_map_.end()) {
    // Exact date found
    change_value = it->second;
    coin.value = coin.amount * change_value;
  } else {
    // Date not found, search for the closest previous date
    std::map<std::string, float>::iterator closest_it = core.coin_map_.end();
    for (it = core.coin_map_.begin(); it != core.coin_map_.end(); ++it) {
      if (it->first <= coin.date) {
        closest_it = it; // Found a closer date
      } else {
        break; // Since map is ordered, no need to search further
      }
    }
    if (closest_it != core.coin_map_.end()) {
      // Closest date found
      change_value = closest_it->second;
      coin.value = coin.amount * change_value;
    } else {
      // No suitable date found
      throw std::runtime_error("No suitable date found for: " + coin.date);
    }
  }
}

void BitcoinDisplay(BitcoinExchange& core){
  std::string line;
  std::getline(core.input_file_, line);
  if (line.compare("date | value") != 0){
    throw std::runtime_error("invalid format: " + line);
  }
  while (std::getline(core.input_file_, line))
  {
    CoinInfos coin;
    try
    {
      std::istringstream sstream(line);
      ParseDate(sstream, coin.date);
      ParseCoin(sstream, coin);
      CalculateCoin(core, coin);
      // Display infos
      std::cout
        << WHTB << " " << coin.date << " " << RESET
        << BLUB << " " << std::setw(4) << coin.amount << " 🪙  " << RESET
        << CYNB << " " << coin.value << " 💵 " << RESET
        << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr
        << YELB << " ERROR " << RESET << " "
        << e.what() << std::endl;
    }
  }
}
