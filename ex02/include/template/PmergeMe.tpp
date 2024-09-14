/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:25:03 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/14 15:42:07 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "PmergeMe.hpp"

template <typename IntContainer>
PmergeMe<IntContainer>::PmergeMe(char **argv): _elapsed(-1)
{
	int	number;
	_start = std::chrono::high_resolution_clock::now();

	try {
		for (int i = 1; argv[i]; i++)
		{
			number = std::stoi(std::string(argv[i]));
			if (number < 0)
				throw std::invalid_argument("Negative number");
			if (std::find(_ints.begin(), _ints.end(), number) != _ints.end())
				throw std::invalid_argument("Duplicate number");
			_ints.push_back(number);
		}
	}
	catch (std::exception const &e) {
		std::cerr << "Invalid argument: " << e.what() << std::endl;
		exit(1);
	}
}

template <typename IntContainer>
void	print_container(IntContainer const &container)
{
	for (int i : container)
		std::cout << i << ", ";
	std::cout << "\b\b  " << std::endl;
}

template <typename IntContainer>
void	PmergeMe<IntContainer>::benchmark(void (*sort)(IntContainer &))
{
	std::cout << "Before:\t" << std::flush;
	print_container(_ints);

	sort(_ints);
	auto _end = std::chrono::high_resolution_clock::now();
	std::cout << "After:\t" << std::flush;
	print_container(_ints);
	if (_elapsed == -1)
		_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(_end - _start).count();
	std::cout << "Elapsed time: " << _elapsed << " µs" << std::endl;
}
