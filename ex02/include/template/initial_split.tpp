/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_split.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:48:40 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/13 21:16:15 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "PmergeMe.hpp"

template <typename IntContainer>
static int	insert_bigger(IntContainer &container,
	IntContainer &container2, IntContainer &sorted)
{
	typename IntContainer::iterator	pos;
	int	ret;

	if (*container2.begin() > *container.begin())
	{
		pos = binary_search_position(sorted, *container2.begin());
		ret = *container2.begin();
		container2.pop_front();
	}
	else
	{
		pos = binary_search_position(sorted, *container.begin());
		ret = *container.begin();
		container.pop_front();
	}
	sorted.insert(pos, ret);
	return (ret);
}

template <typename IntContainer>
static int	initial_split(IntContainer &container, IntContainer &container2,
	IntContainer &sorted, size_t goal_size);

template <typename IntContainer>
static void	divide_in_half(IntContainer &container, IntContainer &sorted,
	size_t goal_size)
{
	auto	start = container.begin();
	auto	end = container.end();
	auto	middle = start + container.size() / 2;
	int		to_be_deleted;

	if (container.size() % 2)
	{
		IntContainer tmp(start + 1, end);
		insert_bigger(container, tmp, sorted);
	}
	IntContainer half_1(start, middle);
	IntContainer half_2(middle, end);

	to_be_deleted = initial_split(half_1, half_2, sorted, goal_size);
	auto it = std::find(container.begin(), container.end(), to_be_deleted);
	if (it != container.end())
		container.erase(it);
}

template <>
void	divide_in_half<std::list<int>>(std::list<int> &container, std::list<int> &sorted,
	size_t goal_size)
{
	auto	start = container.begin();
	auto	end = container.end();
	auto	middle = start;
	std::advance(middle, container.size() / 2);
	int		to_be_deleted;

	if (container.size() % 2)
	{
		std::list<int> tmp(std::next(start), end);
		if (sorted.size() == goal_size)
			return ;
		insert_bigger<std::list<int>>(container, tmp, sorted);
	}
	std::list<int> half_1(start, middle);
	std::list<int> half_2(middle, end);

	to_be_deleted = initial_split(half_1, half_2, sorted, goal_size);
	container.remove(to_be_deleted);
}

template <typename IntContainer>
static int	initial_split(IntContainer &container, IntContainer &container2,
	IntContainer &sorted, size_t goal_size)
{
	int		ret = -1;
	size_t	size = container.size() + container2.size();
	if (sorted.size() == goal_size)
		return (ret);
	if (container.size() > 1)
		divide_in_half(container, sorted, goal_size);
	if (container2.size() > 1)
		divide_in_half(container2, sorted, goal_size);
	if (sorted.size() == goal_size)
		return (ret);
	if (size == 2)
		ret = insert_bigger(container, container2, sorted);
	return (ret);
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
	for (int i : sorted)
	{
		auto it = std::find(container.begin(), container.end(), i);
		if (it != container.end())
			container.erase(it);
	}
	return (sorted);
}
