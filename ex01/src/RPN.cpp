/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:25:01 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/11 18:01:54 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static int	count_operators(std::string const &formula)
{
	size_t	pos = -1;
	int		operators = 0;

	while (pos = formula.find_first_of("+-*/", ++pos), pos != std::string::npos)
	{
		if ((formula[pos] == '*' || formula[pos] == '/')
			|| formula[pos + 1] == ' ' || pos + 1 == formula.size())
			operators++;
	}
	return (operators);
}

static int	count_operands(std::string const &formula)
{
	size_t	pos = -1;
	int		operands = 0;

	while (pos = formula.find_first_of("0123456789", ++pos), pos != std::string::npos)
	{
		if (formula[pos + 1] == ' ')
			operands++;
		if (pos + 1 == formula.size())
			throw RPN::InvalidFormula("Expected operator after operand");
		if (std::string("+-*/").find(formula[pos + 1]) != std::string::npos)
			throw RPN::InvalidFormula("Unexpected symbol in operand");
	}
	return (operands);
}

static void check_validity(std::string const &formula)
{
	int	operators_count;
	int	operands_count;

	if (formula.empty())
		throw std::invalid_argument("Empty formula");
	if (formula.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw RPN::InvalidFormula("Unexpected symbol");
	if (operators_count = count_operators(formula), operators_count == 0)
		throw RPN::InvalidFormula("missing operator");
	if (operands_count = count_operands(formula), operands_count == 0
		|| operands_count < operators_count + 1)
		throw RPN::InvalidFormula("missing operand");
	if (operators_count + 1 < operands_count)
		throw RPN::InvalidFormula("too many operands");
}

RPN::RPN(std::string const &formula)
{
	check_validity(formula);
}

void RPN::calculate()
{
	std::cout << "Result: " << 42 << std::endl;
}

RPN::InvalidFormula::InvalidFormula(std::string const &message)
	: _message(message)
{}

const char *RPN::InvalidFormula::what() const noexcept
{
	std::string const &message = "Invalid formula: " + _message;
	return (message.c_str());
}
