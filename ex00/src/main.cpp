/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:05:08 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/07 20:02:29 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"
#include "TransactionBook.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange	exchange;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <file_name>" << std::endl;
		return (1);
	}
	try{
		BitcoinExchange	new_database(DATABASE_FILE);
		exchange = new_database;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << DATABASE_FILE << ": " << e.what() << std::endl;
		return (1);
	}
	try{
		TransactionBook	requested_conversions(argv[1]);

		requested_conversions.executeTransactions(exchange);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << argv[1] << ": " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
