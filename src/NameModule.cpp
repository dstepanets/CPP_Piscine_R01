/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NameModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:08:25 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/07 16:08:30 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/NameModule.hpp"

/*==============================CONSTRUCTORS=================================*/

NameModule::NameModule(void)
{
	this->collectInfo();
}

NameModule::NameModule(NameModule const &src) { *this = src; }
NameModule::~NameModule(void) {}

/*================================OPERATORS==================================*/

NameModule & 			NameModule::operator = (NameModule const &rhs)
{
	if (this != &rhs)
	{
		this->_hostName = rhs._hostName;
		this->_userName = rhs._userName;
	}
	return (*this);
}

/*==============================GETTERS-SETTERS==============================*/

std::string			NameModule::getHostName(void) const { return (this->_hostName); }
std::string			NameModule::getUserName(void) const { return (this->_userName); }

void				NameModule::collectInfo(void)
{
	char 	buf[120];
	size_t 	bufSize = 120;

	sysctlbyname("kern.hostname", &buf, &bufSize, NULL, 0);
	this->_hostName = buf;

	struct passwd	*pass;
	pass = getpwuid(geteuid());
	this->_userName = pass->pw_name;

}


/*===========================FUNCTIONS=======================================*/



/*===========================EXCEPTIONS======================================*/


