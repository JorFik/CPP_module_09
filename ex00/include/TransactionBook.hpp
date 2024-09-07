/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TransactionBook.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:28:46 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/07 19:25:32 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include "DataBase.hpp"
#include "BitcoinExchange.hpp"

typedef std::multimap<std::string, double> t_TransactionBook;

class TransactionBook: public DataBase<t_TransactionBook>
{
	private:
		TransactionBook()											= delete;
		TransactionBook &operator=(const TransactionBook &other)	= delete;

	public:
		TransactionBook(const std::string &filename);
		~TransactionBook() override									= default;
		TransactionBook(const TransactionBook &other);

		void	executeTransactions(const BitcoinExchange &exchange);
};