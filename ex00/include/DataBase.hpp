/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:51:39 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/07 18:51:49 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class DataBase
{
	private:

	protected:
		T	_dataBase;

		DataBase()									= default;
		DataBase &operator=(const DataBase &other);
		DataBase(const std::string &filename);
		DataBase(const DataBase &other);

	public:
		virtual ~DataBase()							= default;
};

#include "template/DataBase.tpp"