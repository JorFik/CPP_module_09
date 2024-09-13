/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:18:10 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/13 20:29:31 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <algorithm>
#include <list>
#include <chrono>

typedef std::chrono::steady_clock::time_point	t_time_point;

template <typename IntContainer>
class	PmergeMe
{
	private:
		IntContainer	_ints;
		t_time_point	_start;
		long long		_elapsed;

	public:
		PmergeMe()								= delete;
		PmergeMe(PmergeMe const &)				= delete;
		PmergeMe &operator=(PmergeMe const &)	= delete;
		~PmergeMe()								= default;
		PmergeMe(char **argv);

		void	benchmark(void (*sort)(IntContainer &));
};

void	ford_johnson_deque(std::deque<int> &container);
void	ford_johnson_list(std::list<int> &container);
void	ford_johnson_vector(std::vector<int> &container);

template <typename IntContainer>
typename IntContainer::iterator	binary_search_position(IntContainer &container,
	int number);

template <typename IntContainer>
void	print_container(IntContainer const &container);

template <typename IntContainer>
IntContainer	initial_split(IntContainer &container);

#include "template/PmergeMe.tpp"
#include "template/binary_search_position.tpp"
#include "template/initial_split.tpp"
