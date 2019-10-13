/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:57:23 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/06 21:57:24 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/CpuModule.hpp"

/*==============================CONSTRUCTORS=================================*/

CpuModule::CpuModule(void)
{
	this->collectInfo();
	this->collectDynamicInfo();
}

CpuModule::CpuModule(CpuModule const &src) { *this = src; }
CpuModule::~CpuModule(void) {}

/*================================OPERATORS==================================*/

CpuModule & 			CpuModule::operator = (CpuModule const &rhs)
{
	if (this != &rhs) {
		this->_cpuName = rhs._cpuName;
		this->_cpuModel = rhs._cpuModel;
		this->_cpuArch = rhs._cpuArch;
		this->_cpuCoreNum = rhs._cpuCoreNum;
		this->_cpuUsageUser = rhs._cpuUsageUser;
		this->_cpuUsageSys = rhs._cpuUsageSys;
		this->_cpuUsageIdle = rhs._cpuUsageIdle;
	}
	return (*this);
}

/*==============================GETTERS-SETTERS==============================*/

std::string			CpuModule::getCpuName(void) const { return (this->_cpuName); }
std::string			CpuModule::getCpuModel(void) const { return (this->_cpuModel); }
std::string			CpuModule::getCpuArch(void) const { return (this->_cpuArch); }
unsigned int		CpuModule::getCpuCoreNum(void) const { return (this->_cpuCoreNum); }
float				CpuModule::getCPUUsageUsr(void) const { return (this->_cpuUsageUser); }
float				CpuModule::getCpuUsageSys(void) const { return (this->_cpuUsageSys); }
float				CpuModule::getCpuUsageIdle(void) const { return (this->_cpuUsageIdle); }

// void				CpuModule::collectInfo(void)
// {
// 	char 			buf[100];
// 	std::string 	name;

// 	FILE*	pipe = popen("sysctl -n machdep.cpu.brand_string", "r");
// 	fgets(buf, 40, pipe);

// 	name = static_cast<std::string>(buf);
// 	this->_cpuName = name;
// 		pclose(pipe);
	// PUTLN(_cpuName);
// }


/*===========================FUNCTIONS=======================================*/

void				CpuModule::collectInfo(void) {
	std::string		name = getComRes("sysctl -n machdep.cpu.brand_string");

	this->_cpuArch = getComRes("uname -p");
	this->_cpuCoreNum = static_cast<unsigned int>(std::stoi(getComRes("sysctl hw.ncpu | sed 's/.*: //'")));
	this->_cpuName = name.substr(0, name.find("(TM) ") + 5);
	this->_cpuModel = name.substr(name.find("(TM) ") + 5);
}

void				CpuModule::collectDynamicInfo(void) {
	this->_cpuUsageUser = std::stof(getComRes("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $3;}'"));
	this->_cpuUsageSys = std::stof(getComRes("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $5;}'"));
	this->_cpuUsageIdle = std::stof(getComRes("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $7;}'"));
}

/*===========================EXCEPTIONS======================================*/

