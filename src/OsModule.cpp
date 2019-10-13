/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsModule.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:14:44 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/07 17:14:46 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/OsModule.hpp"

/*==============================CONSTRUCTORS=================================*/

OsModule::OsModule(void)
{
	this->collectInfo();
}

OsModule::OsModule(OsModule const &src) { *this = src; }
OsModule::~OsModule(void) {}

/*================================OPERATORS==================================*/

OsModule & 			OsModule::operator = (OsModule const &rhs)
{
	if (this != &rhs)
	{
		this->_kerName = rhs._kerName;
		this->_kerVer = rhs._kerVer;
	}
	return (*this);
}

/*==============================GETTERS-SETTERS==============================*/

std::string			OsModule::getSysVer(void) const { return (this->_sysVer); }
std::string			OsModule::getKerName(void) const { return (this->_kerName); }
std::string			OsModule::getKerVer(void) const { return (this->_kerVer); }
std::string			OsModule::getKerTimeStamp(void) const { return (this->_kerTime); }
std::string			OsModule::getSysArch(void) const { return (this->_architecture); }

void				OsModule::collectInfo(void)
{
	struct utsname 		os;
	uname(&os);

	this->_sysVer = getComRes("grep -A 0 'System Version:'  < info/sysprof.txt");
	this->_sysVer = _sysVer.substr(22);
	this->_kerName = os.sysname;
	this->_kerVer = os.release;
	this->_kerTime = os.version;
	this->_kerTime = _kerTime.substr (30,28);
	this->_architecture = os.machine;
    //   System Version: macOS 10.13.3 (17D47)

	
// 	char 			buf[100];
// 	std::string 	name;

// 	FILE*	pipe = popen("sysctl -n machdep.cpu.brand_string", "r");
// 	fgets(buf, 40, pipe);


//  exec("grep -A 20 'Processor Name:' < info/sysprof.txt");
// ("grep -A 20 'Network:' < info.txt")

}

/*
	Kernel name: Darwin
	Kernel version: 17.4.0
	Product name: High Sierra
	Platform: x86_64
	Product name: Mac OS X
	Product version: 10.13.3
	Build version: 17D47

*/

/*===========================FUNCTIONS=======================================*/



/*===========================EXCEPTIONS======================================*/

