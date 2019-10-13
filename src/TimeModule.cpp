/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:40:06 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/07 13:40:08 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/TimeModule.hpp"

/*==============================CONSTRUCTORS=================================*/

TimeModule::TimeModule(void)
{
	this->collectInfo();
}

TimeModule::TimeModule(TimeModule const &src) { *this = src; }
TimeModule::~TimeModule(void) {}

/*================================OPERATORS==================================*/

TimeModule & 			TimeModule::operator = (TimeModule const &rhs)
{
	if (this != &rhs)
		this->_time = rhs._time;
	return (*this);
}

/*==============================GETTERS-SETTERS==============================*/

std::string			TimeModule::getDate(void) const { return (this->_date); }
std::string			TimeModule::getTime(void) const { return (this->_time); }


void				TimeModule::collectInfo(void)
{
	std::time_t t = std::time(nullptr);
	std::tm 	tl = *std::localtime(&t);

	char 	buf[30];

	strftime (buf, 30, "%A, %B %d %G", &tl);
	this->_date = buf;
	bzero(buf, 30);
	strftime (buf, 30, "%T", &tl);
	this->_time = buf;

	// char  *ptr = strchr(buf, ':');
	// ptr -= 3;
	// std::string str = buf;
	// size_t i = str.find(":");
	// i -= 3;

	// this->_date = str.substr(0, i);
	// this->_time = str.substr(i, 9);
	// PUTLN(_date);
	// PUTLN(_time);
// Sun Jul  7 14:02:09 2019
	// std::cout << "[" << std::put_time(&tm, "%Y%m%d_%H%M%S") << "] ";




}







/*===========================FUNCTIONS=======================================*/



/*===========================EXCEPTIONS======================================*/


