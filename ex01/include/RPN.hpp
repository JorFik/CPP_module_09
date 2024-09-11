/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:05:23 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/11 16:25:28 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>

class RPN
{
private:
	std::stack<std::string> _formula;
public:
	RPN() 								= delete;
	RPN(RPN const &other)				= delete;
	RPN &operator=(RPN const &other)	= delete;
	~RPN() 								= default;

	RPN(std::string const &formula);
	void calculate();
};
