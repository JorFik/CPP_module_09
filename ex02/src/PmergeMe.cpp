/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:27:18 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/13 20:24:45 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>

void	ford_johnson_deque(std::deque<int> &container)
{
	int	odd_number = -1;
	if (container.size() % 2)
	{
		odd_number = container.back();
		container.pop_back();
	}
	// std::deque<int>	sorted = initial_split(container);
	// print_container(sorted);
	std::sort(container.begin(), container.end());
}

void	ford_johnson_list(std::list<int> &container)
{
	container.sort();
}

void	ford_johnson_vector(std::vector<int> &container)
{
	std::sort(container.begin(), container.end());
}
