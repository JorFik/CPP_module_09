/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:27:18 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/14 15:03:53 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>

static	int	jacobstahl_number_generator(bool first_time = false)
{
	static int	jacobstahl_number_1 = 1;
	static int	jacobstahl_number_2 = 0;
	int			jacobstahl_number;

	if (first_time)
	{
		jacobstahl_number_1 = 1;
		jacobstahl_number_2 = 0;
	}
	jacobstahl_number = (2 * jacobstahl_number_2) + jacobstahl_number_1;
	jacobstahl_number_2 = jacobstahl_number_1;
	jacobstahl_number_1 = jacobstahl_number;
	return (jacobstahl_number);
}

void	ford_johnson_deque(std::deque<int> &container)
{
	int	odd_number = -1;

	if (container.size() % 2)
		odd_number = container.back(), container.pop_back();
	std::deque<int>	sorted = initial_split(container);
	if (odd_number != -1)
	{
		auto pos = binary_search_position(sorted, odd_number);
		sorted.insert(pos, odd_number);
	}
	int	jacobstahl = jacobstahl_number_generator(true);
	while (!container.empty())
	{
		if (static_cast<size_t>(jacobstahl) > container.size())
			break ;
		auto pos = binary_search_position(sorted, container[jacobstahl]);
		sorted.insert(pos, container[jacobstahl]);
		jacobstahl = jacobstahl_number_generator();
	}
	delete_if_already_sorted(container, sorted);
	for (auto it = container.begin(); it != container.end(); it++)
	{
		auto pos = binary_search_position(sorted, *it);
		sorted.insert(pos, *it);
	}
	container = sorted;
}

void	ford_johnson_list(std::list<int> &container)
{
	int	odd_number = -1;

	if (container.size() % 2)
		odd_number = container.back(), container.pop_back();
	std::list<int>	sorted = initial_split(container);
	if (odd_number != -1)
	{
		auto pos = binary_search_position(sorted, odd_number);
		sorted.insert(pos, odd_number);
	}
	int	jacobstahl = jacobstahl_number_generator(true);
	int	iteration = 0;
	while (!container.empty())
	{
		if (static_cast<size_t>(jacobstahl - iteration) > container.size())
			break ;
		auto jacobstahl_it = container.begin();
		std::advance(jacobstahl_it, jacobstahl - iteration);
		auto pos = binary_search_position(sorted, *jacobstahl_it);
		sorted.insert(pos, *jacobstahl_it);
		container.erase(jacobstahl_it);
		jacobstahl = jacobstahl_number_generator();
		iteration++;
	}
	for (auto it = container.begin(); it != container.end(); it++)
	{
		auto pos = binary_search_position(sorted, *it);
		sorted.insert(pos, *it);
	}
	container = sorted;
}

void	ford_johnson_vector(std::vector<int> &container)
{
	int	odd_number = -1;

	if (container.size() % 2)
		odd_number = container.back(), container.pop_back();
	std::vector<int>	sorted = initial_split<std::vector<int>>(container);
	if (odd_number != -1)
	{
		auto pos = binary_search_position(sorted, odd_number);
		sorted.insert(pos, odd_number);
	}
	int	jacobstahl = jacobstahl_number_generator(true);
	int	iteration = 0;
	while (!container.empty())
	{
		if (static_cast<size_t>(jacobstahl - iteration) > container.size())
			break ;
		auto jacobstahl_it = container.begin();
		std::advance(jacobstahl_it, jacobstahl - iteration);
		auto pos = binary_search_position(sorted, *jacobstahl_it);
		sorted.insert(pos, *jacobstahl_it);
		container.erase(jacobstahl_it);
		jacobstahl = jacobstahl_number_generator();
		iteration++;
	}
	for (auto it = container.begin(); it != container.end(); it++)
	{
		auto pos = binary_search_position(sorted, *it);
		sorted.insert(pos, *it);
	}
	container = sorted;
}
