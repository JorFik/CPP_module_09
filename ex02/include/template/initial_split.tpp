/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_split.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:48:40 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/13 20:22:58 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "PmergeMe.hpp"

template <typename IntContainer>
static void	insert_bigger(IntContainer &container,
	IntContainer &container2, IntContainer &sorted)
{
	typename IntContainer::iterator pos;

	if (*container2.begin() > *container.begin())
	{
		pos = binary_search_position(sorted, *container2.begin());
		sorted.insert(pos, *container2.begin());
		container2.pop_front();
		return ;
	}
	pos = binary_search_position(sorted, *container.begin());
	sorted.insert(pos, *container.begin());
	container.pop_front();
}

template <typename IntContainer>
static void	initial_split(IntContainer &container, IntContainer &container2,
	IntContainer &sorted, size_t goal_size)
{
	auto	start = container.begin();
	auto	end = container.end();
	auto	middle = start + container.size() / 2;

	if (sorted.size() == goal_size)
		return ;
	if (container.size() > 1)
	{
		if (container.size() % 2)
		{
			IntContainer tmp(start + 1, end);
			insert_bigger(container, tmp, sorted);
		}
		IntContainer half_1(start, middle);
		IntContainer half_2(middle, end);

		initial_split(half_1, half_2, sorted, goal_size);
		for (int i : sorted)
		{
			auto same_number = std::find(container.begin(), container.end(), i);
			if (same_number != container.end())
				container.erase(same_number);
		}
	}
	if (container2.size() > 1)
	{
		if (container2.size() % 2)
		{
			IntContainer tmp(container2.begin() + 1, container2.end());
			insert_bigger(container2, tmp, sorted);
		}
		IntContainer half_1(container2.begin(), container2.begin() + container2.size() / 2);
		IntContainer half_2(container2.begin() + container2.size() / 2, container2.end());

		initial_split(half_1, half_2, sorted, goal_size);
		for (int i : sorted)
		{
			auto same_number = std::find(container.begin(), container.end(), i);
			if (same_number != container.end())
				container.erase(same_number);
		}
	}
	insert_bigger(container, container2, sorted);
	for (int i : sorted)
	{
		auto same_number = std::find(container.begin(), container.end(), i);
		if (same_number != container.end())
			container.erase(same_number);
	}
}

template <typename IntContainer>
IntContainer	initial_split(IntContainer &container)
{
	auto			start = container.begin();
	auto			end = container.end();
	size_t			goal_size = container.size() / 2;
	auto			middle = start + goal_size;
	IntContainer	sorted;

	if (container.size() == 1)
	{
		sorted.push_back(*start);
		container.pop_front();
		return (sorted);
	}
	IntContainer half_1(start, middle);
	IntContainer half_2(middle, end);

	initial_split(half_1, half_2, sorted, goal_size);
	return (sorted);
}
