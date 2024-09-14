/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:53:36 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/14 17:11:59 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

#include "../DataBase.hpp"

template <typename T>
DataBase<T>::DataBase(const DataBase &other)
{
	_dataBase = other._dataBase;
}

template <typename T>
DataBase<T> &DataBase<T>::operator=(const DataBase &other)
{
	if (this != &other)
		_dataBase = other._dataBase;
	return (*this);
}

static inline std::string	find_delimiter(std::ifstream &file)
{
	std::string	delimiter;
	std::string	line;

	std::getline(file, line);
	if (!std::isalpha(line[0]))
		throw std::runtime_error("Could not find format line");
	auto start_delimeter = std::find_if(line.begin(), line.end(),
		[] (char c) {
			return (!std::isalpha(c));
			});
	auto end_delimeter = std::find_if(start_delimeter, line.end(),
		[] (char c) {
			return (std::isalpha(c));
			});
	delimiter = std::string(start_delimeter, end_delimeter);
	if (delimiter.empty())
		throw std::runtime_error("Could not find a valid delimiter");
	return (delimiter);
}

static bool	is_day_valid(int month, int day)
{
	if (day < 1)
		return (false);
	if (month == 2 && day > 29)
		return (false);
	if ((month % 7) % 2 == 1 || month == 7)
	{
		if (day > 31)
			return (false);
	}
	else if (day > 30)
		return (false);
	return (true);
}

static inline void	validate_date(const std::string &date)
{
	if (date.size() != 10)
		throw std::runtime_error("Invalid date size");
	if (date[4] != '-' || date[7] != '-')
		throw std::runtime_error("Expected '-' as separator");
	if (std::count(date.begin(), date.end(), '-') != 2)
		throw std::runtime_error("Unexpected extra '-'");

	std::string	s_year = date.substr(0, 4);
	std::string	s_month = date.substr(5, 2);
	std::string	s_day = date.substr(8, 2);
	
	if (std::all_of(s_year.begin(), s_year.end(), isdigit) == false
		|| std::all_of(s_month.begin(), s_month.end(), isdigit) == false
		|| std::all_of(s_day.begin(), s_day.end(), isdigit) == false)
		throw std::runtime_error("Unexpected non-digit character in date");

	int	year = std::stoi(s_year);
	int	month = std::stoi(s_month);
	int	day = std::stoi(s_day);

	if (year < 0
		|| month < 1 || month > 12
		|| is_day_valid(month, day) == false)
		throw std::runtime_error(date + " is not a valid date");
}

template <typename T>
DataBase<T>::DataBase(const std::string &filename)
{
	std::ifstream	file(filename);
	std::string		delimiter;
	std::string		date;
	double			value;
	std::string		line;
	size_t			delimiter_pos;

	if (!file.is_open())
		throw std::runtime_error("Could not open file");
	delimiter = find_delimiter(file);
	while (std::getline(file, line))
	{
		try {
			delimiter_pos = line.find(delimiter);
			if (delimiter_pos == std::string::npos
				|| delimiter_pos == 0
				|| delimiter_pos == line.size() - delimiter.size())
				throw std::runtime_error("Invalid line format");
			date = line.substr(0, delimiter_pos);
			validate_date(date);
			value = std::stod(line.substr(delimiter_pos + delimiter.size()));
			if (value < 0)
				throw std::runtime_error("Invalid value");
		} catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
			std::cerr << "Skipping line: " << line << std::endl;
			std::cerr << "*********************************" << std::endl;
			continue ;
		}
		_dataBase.insert(std::make_pair(date, value));
	}
}
