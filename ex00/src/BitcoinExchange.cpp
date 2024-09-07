/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:34:43 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/07 19:36:33 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange(const std::string &filename): DataBase(filename)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : DataBase(other)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_dataBase = other._dataBase;
	return (*this);
}

double BitcoinExchange::priceAtDate(const std::string &Date) const
{
	auto it = _dataBase.lower_bound(Date);
	if (it == _dataBase.begin() && it->first != Date)
		throw std::runtime_error("No data available before " + it->first);
	if (it->first != Date)
		--it;
	return (it->second);
}
