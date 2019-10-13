// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NetModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/07/07 20:42:32 by vdzhanaz          #+#    #+#             //
//   Updated: 2019/07/07 20:42:33 by vdzhanaz         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../inc/NetModule.hpp"

/*==============================CONSTRUCTORS=================================*/

NetModule::NetModule(void)
{
	this->collectInfo();
	// this->collectDynInfo();
}

NetModule::NetModule(NetModule const &src) { *this = src; }
NetModule::~NetModule(void) {}

/*================================OPERATORS==================================*/

NetModule & 			NetModule::operator = (NetModule const &rhs)
{
	if (this != &rhs) 
	{
		this->_netInt = rhs._netInt;
		this->_netTp = rhs._netTp;
		this->_netBd = rhs._netBd;
		// this->_iTot = rhs._iTot;
		// this->_oTot = rhs._oTot;
	}
	return (*this);
}

/*==============================GETTERS-SETTERS==============================*/

std::list<std::string>		NetModule::getNetInt(void) const { return (this->_netInt); }
std::list<std::string>		NetModule::getNetTp(void) const { return (this->_netTp); }
std::list<std::string>		NetModule::getNetBd(void) const { return (this->_netBd); }
// long int 					NetModule::getITot(void) const { return (this->_iTot); }
// long int 					NetModule::getOTot(void) const { return (this->_oTot); }

/*===========================FUNCTIONS=======================================*/

void				NetModule::collectInfo(void)
{
	std::string		tmpIntf = getComRes("cat info/sysprof.txt | grep -A 29 'Network:' | grep '\\w:$' | awk '{gsub(\"Network:\", \"\", $1); printf \"%s %s \", $1, $2}'");
	std::string		tmpTp = getComRes("cat info/sysprof.txt | grep -A 29 'Network:' | grep 'Type: '");
	std::string		tmpBs = getComRes("cat info/sysprof.txt | grep -A 29 'Network:' | grep 'BSD' | awk '{print $4}'");
	
	this->_netInt = split(tmpIntf, ':');
	this->_netTp = split(tmpTp, '\n');
	this->_netBd = split(tmpBs, '\n');
}

// void				NetModule::collectDynInfo(void) {
// 	std::list<std::string>	temp = split(getComRes("netstat -i -I en0 -b | awk '{print $5, $7, $8, $10}'"), '\n');
// 	char *ed;
// 	static long int 	lastItot = 0;
// 	static long int 	lastOtot = 0;

// 	std::list<std::string>::iterator it = temp.begin();
// 	it++;
// 	this->_iTot = strtol(it, &ed, 10);
// 	this->_iTot = strtol(ed, &ed, 10);
// 	this->_oTot = strtol(ed, &ed, 10);
// 	this->_oTot = strtol(ed, NULL, 10);

// 	this->_iTot = this->_iTot - lastItot;
// 	this->_oTot = this->_oTot - lastOtot;

// 	lastItot = this->_iTot + lastItot;
// 	lastItot = this->_iTot + lastItot;
// } 

/*===========================EXCEPTIONS======================================*/
 