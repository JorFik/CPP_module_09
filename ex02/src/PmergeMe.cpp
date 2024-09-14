/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:27:18 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/14 16:25:00 by JFikents         ###   ########.fr       */
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

template <typename IntContainer>
static void	insert_sorted(IntContainer &sorted, int number)
{
	auto pos = binary_search_position(sorted, number);
	sorted.insert(pos, number);
}

void	ford_johnson_deque(std::deque<int> &container)
{
	std::deque<int>	sorted = initial_split(container);
	int	jacobstahl = jacobstahl_number_generator(true);

	for (int iteration = 0;
		static_cast<size_t>(jacobstahl - iteration) > container.size();
		++iteration)
	{
		auto jacobstahl_it = container.begin();
		jacobstahl_it += jacobstahl - iteration;
		insert_sorted(sorted, *jacobstahl_it);
		container.erase(jacobstahl_it);
		jacobstahl = jacobstahl_number_generator();
	}
	for (auto it = container.begin(); it != container.end(); it++)
		insert_sorted(sorted, *it);
	container = sorted;
}

void	ford_johnson_list(std::list<int> &container)
{
	std::list<int>	sorted = initial_split(container);
	int	jacobstahl = jacobstahl_number_generator(true);

	for (int iteration = 0;
		static_cast<size_t>(jacobstahl - iteration) > container.size();
		++iteration)
	{
		auto jacobstahl_it = container.begin();
		std::advance(jacobstahl_it, jacobstahl - iteration);
		insert_sorted(sorted, *jacobstahl_it);
		container.erase(jacobstahl_it);
		jacobstahl = jacobstahl_number_generator();
	}
	for (auto it = container.begin(); it != container.end(); it++)
		insert_sorted(sorted, *it);
	container = sorted;
}

void	ford_johnson_vector(std::vector<int> &container)
{
	std::vector<int>	sorted = initial_split<std::vector<int>>(container);
	int	jacobstahl = jacobstahl_number_generator(true);

	for (int iteration = 0;
		static_cast<size_t>(jacobstahl - iteration) > container.size();
		++iteration)
	{
		auto jacobstahl_it = container.begin();
		jacobstahl_it += jacobstahl - iteration;
		insert_sorted(sorted, *jacobstahl_it);
		container.erase(jacobstahl_it);
		jacobstahl = jacobstahl_number_generator();
	}
	for (auto it = container.begin(); it != container.end(); it++)
		insert_sorted(sorted, *it);
	container = sorted;
}
