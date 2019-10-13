/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HddModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 21:42:08 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/07 21:42:09 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HddModule.hpp"

/*==============================CONSTRUCTORS=================================*/

HddModule::HddModule(void)
{
	this->collectInfo();
}

HddModule::HddModule(HddModule const &src) { *this = src; }
HddModule::~HddModule(void) {}

/*================================OPERATORS==================================*/

HddModule & 			HddModule::operator = (HddModule const &rhs)
{
	if (this != &rhs)
	{
		this->_hddModel = rhs._hddModel;
		this->_hddCapac = rhs._hddCapac;
		this->_hddSysCap = rhs._hddSysCap;
		this->_hddSysAvail = rhs._hddSysAvail;
	}
	return (*this);
}

/*==============================GETTERS-SETTERS==============================*/

std::string			HddModule::getHddModel(void) const { return (this->_hddModel); }
std::string			HddModule::getHddCapac(void) const { return (this->_hddCapac); }
std::string			HddModule::getHddSysCap(void) const { return (this->_hddSysCap); }
std::string			HddModule::getHddSysAvail(void) const { return (this->_hddSysAvail); }

void				HddModule::collectInfo(void)
{

	this->_hddModel = getComRes("grep -A 0 'Model: APPLE'  < info/sysprof.txt");
	this->_hddModel = _hddModel.substr(17);
	this->_hddModel = _hddModel.substr(0, 25);

	this->_hddCapac = getComRes("grep -A 0 'Capacity: 1 TB'  < info/sysprof.txt");
	this->_hddCapac = _hddCapac.substr(20);
	this->_hddCapac = _hddCapac.substr(0, 5);

	std::string s =  getComRes("grep -A 2 'Mac OS'  < info/sysprof.txt");

	this->_hddSysCap = s.substr(44, 74);
	this->_hddSysCap = _hddSysCap.substr(0, 7);
	this->_hddSysAvail = s.substr(100, 131);
	this->_hddSysAvail = _hddSysAvail.substr(0, 8);

}
