/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_split.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:48:40 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/14 15:29:18 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "PmergeMe.hpp"
#include <vector>

template <typename IntContainer>
static inline int	insert_and_pop_front(IntContainer &container,
	IntContainer &sorted)
{
	const int	ret = *container.begin();
	const auto	pos = binary_search_position(sorted, *container.begin());

	container.pop_front();
	sorted.insert(pos, ret);
	return (ret);
}

static inline int	insert_and_pop_front(std::vector<int> &container,
	std::vector<int> &sorted)
{
	const int	ret = *container.begin();
	const auto	pos = binary_search_position(sorted, *container.begin());

	container.erase(container.begin());
	sorted.insert(pos, ret);
	return (ret);
}

template <typename IntContainer>
static int	insert_and_pop_bigger(IntContainer &container,
	IntContainer &container2, IntContainer &sorted)
{
	int	ret;

	if (*container2.begin() > *container.begin())
		ret = insert_and_pop_front(container2, sorted);
	else
		ret = insert_and_pop_front(container, sorted);
	return (ret);
}

template <typename IntContainer>
static int	initial_split(IntContainer &container, IntContainer &container2,
	IntContainer &sorted);

template <typename IntContainer>
static void	divide_in_half(IntContainer &container, IntContainer &sorted)
{
	int				to_be_deleted;

	if (container.size() % 2)
	{
		IntContainer	tmp(std::next(container.begin()), container.end());
		to_be_deleted = insert_and_pop_bigger(container, tmp, sorted);
		auto it = std::find(container.begin(), container.end(), to_be_deleted);
		container.erase(it);
	}
	auto			middle = container.begin();
	std::advance(middle, container.size() / 2);
	IntContainer	half_1(container.begin(), middle);
	IntContainer	half_2(middle, container.end());

	to_be_deleted = initial_split(half_1, half_2, sorted);
	auto it = std::find(container.begin(), container.end(), to_be_deleted);
	if (it != container.end())
		container.erase(it);
}

template <typename IntContainer>
static int	initial_split(IntContainer &container, IntContainer &container2,
	IntContainer &sorted)
{
	int		ret = -1;
	size_t	size = container.size() + container2.size();

	if (container.size() > 1)
		divide_in_half(container, sorted);
	if (container2.size() > 1)
		divide_in_half(container2, sorted);
	if (size == 2)
		ret = insert_and_pop_bigger(container, container2, sorted);
	return (ret);
}

template <typename IntContainer>
static void	handle_single_element(IntContainer &container, IntContainer &sorted)
{
	sorted.push_back(*container.begin());
	container.pop_front();
}

static inline void	handle_single_element(std::vector<int> &container,
	std::vector<int> &sorted)
{
	sorted.push_back(*container.begin());
	container.erase(container.begin());
}

template <typename IntContainer>
IntContainer	initial_split(IntContainer &container)
{
	auto			start = container.begin();
	auto			end = container.end();
	size_t			goal_size = container.size() / 2;
	auto			middle = start;
	std::advance(middle, goal_size);
	IntContainer	sorted;

	if (container.size() == 1)
	{
		handle_single_element(container, sorted);
		return (sorted);
	}
	IntContainer half_1(start, middle);
	IntContainer half_2(middle, end);

	initial_split(half_1, half_2, sorted);
	delete_if_already_sorted(container, sorted);
	return (sorted);
}

template <typename IntContainer>
void	delete_if_already_sorted(IntContainer &container, IntContainer &sorted)
{
	for (int i : sorted)
	{
		auto it = std::find(container.begin(), container.end(), i);
		if (it != container.end())
			container.erase(it);
	}
}
