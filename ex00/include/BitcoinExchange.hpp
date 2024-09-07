/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:08:31 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/07 19:09:29 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include "DataBase.hpp"
#ifndef DATABASE_FILE
	# define DATABASE_FILE "data.csv"
#endif

typedef std::map<std::string, double> t_DataBase;

class BitcoinExchange : public DataBase<t_DataBase>
{
	public:
		BitcoinExchange()											= default;
		~BitcoinExchange() override									= default;
		BitcoinExchange(const std::string &filename);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		BitcoinExchange(const BitcoinExchange &other);

		double priceAtDate(const std::string &Date) const;
};
