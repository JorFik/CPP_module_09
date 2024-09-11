/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:25:01 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/11 17:34:15 by JFikents         ###   ########.fr       */
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
			throw std::invalid_argument("Formula ends with operand");
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
		throw std::invalid_argument("Invalid formula: Unexpected symbol");
	if (operators_count = count_operators(formula), operators_count == 0)
		throw std::invalid_argument("Invalid formula: missing operator");
	if (operands_count = count_operands(formula), operands_count == 0)
		throw std::invalid_argument("Invalid formula: missing operand");
	if (operators_count + 1 < operands_count)
		throw std::invalid_argument("Invalid formula: too many operands");
	if (operators_count + 1 > operands_count)
		throw std::invalid_argument("Invalid formula: too many operators");
}

RPN::RPN(std::string const &formula)
{
	check_validity(formula);
}

void RPN::calculate()
{
	std::cout << "Result: " << 42 << std::endl;
}
