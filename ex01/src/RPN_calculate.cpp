/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_calculate.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:32:00 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/11 20:46:05 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::string	RPN::_doOperation(int operand_1, int operand_2,
	std::string const &operation)
{
	if (operation == "+")
		return (std::to_string(operand_1 + operand_2));
	if (operation == "-")
		return (std::to_string(operand_1 - operand_2));
	if (operation == "*")
		return (std::to_string(operand_1 * operand_2));
	if (operation == "/")
	{
		if (operand_2 == 0)
			throw RPN::InvalidFormula("Division by zero");
		return (std::to_string(operand_1 / operand_2));
	}
	throw RPN::InvalidFormula("If you see this message, the RPN is broken");
}

bool	RPN::_isNumber(std::string const &token)
{
	return (token.find_first_of("0123456789") != std::string::npos);
}

static bool	hasAllPieces(std::string const &operation,
	long const &operand_1, long const &operand_2)
{
	if (operation.empty()
		|| operand_1 == UNSET_OPERAND
		|| operand_2 == UNSET_OPERAND)
		return (false);
	return (true);
}

void	RPN::calculate()
{
	static int	operations_done = 0;
	long		operand_1 = UNSET_OPERAND;
	long		operand_2 = UNSET_OPERAND;
	std::string	operation;

	if (_formula.size() == 1)
		return (std::cout << _formula.top() << std::endl, void());
	while (hasAllPieces(operation, operand_1, operand_2) == false)
	{
		if (_isNumber(_formula.top()) == false && operation.empty())
		{
			operation = _formula.top(), _formula.pop();
			continue ;
		}
		else if (_isNumber(_formula.top()) == false)
			calculate();
		if (operand_2 == UNSET_OPERAND)
			operand_2 = std::stoi(_formula.top()), _formula.pop();
		else
			operand_1 = std::stoi(_formula.top()), _formula.pop();
	}
	_formula.push(_doOperation(operand_1, operand_2, operation));
	if (++operations_done == _operatorCount)
		std::cout << _formula.top() << std::endl;
}
