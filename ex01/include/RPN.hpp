/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:05:23 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/11 20:04:54 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>

#define UNSET_OPERAND INT_MAX + 1l

class RPN
{
private:
	std::stack<std::string> _formula;
	int						_operatorCount;

	bool		_isNumber(std::string const &token);
	std::string	_doOperation(int operand_1, int operand_2,
		std::string const &operation);

public:
	RPN()								= delete;
	RPN(RPN const &other)				= delete;
	RPN &operator=(RPN const &other)	= delete;
	~RPN()								= default;

	RPN(std::string const &formula);
	void		calculate();

	class InvalidFormula : public std::exception
	{
		private:
			std::string	_message;

		public:
			InvalidFormula()			= delete;
			virtual ~InvalidFormula()	= default;
			InvalidFormula(std::string const &message);
			virtual const char *what() const noexcept override;
	};
};
