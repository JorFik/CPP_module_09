/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TransactionBook.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:22:40 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/14 17:11:09 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TransactionBook.hpp"

TransactionBook::TransactionBook(const std::string &filename) : DataBase(filename)
{
}

TransactionBook::TransactionBook(const TransactionBook &other) : DataBase(other)
{
}

void	TransactionBook::executeTransactions(const BitcoinExchange &exchange)
{
	double	total = 0;
	for (const auto &transaction : _dataBase)
	{
		try
		{
			if (transaction.second > 1000)
				throw std::runtime_error("Transaction too large.");
			double	price = exchange.priceAtDate(transaction.first);
			total += transaction.second * price;
			std::cout << "Exchange date: " << transaction.first << std::endl;
			std::cout << "\tExchange rate: " << price << std::endl;
			std::cout << "\tAmount: " << transaction.second << std::endl;
			std::cout << "\tTotal: " << transaction.second * price << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << "Exchange denied: ";
			std::cerr << transaction.first + " for ";
			std::cerr << transaction.second << ": ";
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Final total: " << total << std::endl;
}
