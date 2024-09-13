/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_position.tpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:03:34 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/13 21:01:06 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "PmergeMe.hpp"

template <typename IntContainer>
static typename IntContainer::iterator	binary_search_position(IntContainer &container,
	int number,
	typename IntContainer::iterator position,
	typename IntContainer::iterator end)
{
	size_t	size = std::distance(position, end);
	typename IntContainer::iterator	middle = position;
	std::advance(middle, size / 2);

	if (size == 1)
	{
		if (number < *position)
			return (position);
		else if (position == container.end())
			return (container.end());
		return (std::next(position));
	}
	if (number > *middle)
		return (binary_search_position<IntContainer>(container, number, middle, end));
	return (binary_search_position<IntContainer>(container, number, position, middle));
}

template <typename IntContainer>
typename IntContainer::iterator	binary_search_position(IntContainer &container,
	int number)
{
	if (container.empty())
		return (container.end());
	return (binary_search_position<IntContainer>(container, number,
		container.begin(), container.end()));
}
