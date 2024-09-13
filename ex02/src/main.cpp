/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:35:11 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/13 17:24:28 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		if (argc == 2)
			std::cerr << "No benchmarking is possible with only one argument.";
		else
			std::cerr << "Usage: " << *argv << " [int1] [int2] [int3] ...";
		std::cerr << std::endl;
		return (1);
	}
	std::cout << "Benchmarking deque:" << std::endl;
	PmergeMe<std::deque<int>>	deque(argv);
	deque.benchmark(ford_johnson_deque);
	std::cout << std::endl;
	std::cout << "Benchmarking list:" << std::endl;
	PmergeMe<std::list<int>>	list(argv);
	list.benchmark(ford_johnson_list);
	std::cout << std::endl;
	std::cout << "Benchmarking vector:" << std::endl;
	PmergeMe<std::vector<int>>	vector(argv);
	vector.benchmark(ford_johnson_vector);
	std::cout << std::endl;
	return (0);
}
