// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAMModule.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/07/07 19:41:02 by vdzhanaz          #+#    #+#             //
//   Updated: 2019/07/07 19:41:04 by vdzhanaz         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../inc/RAMModule.hpp"

/*==============================CONSTRUCTORS=================================*/

RAMModule::RAMModule(void)
{
	this->collectInfo();
}

RAMModule::RAMModule(RAMModule const &src) { *this = src; }
RAMModule::~RAMModule(void) {}

/*================================OPERATORS==================================*/

RAMModule & 			RAMModule::operator = (RAMModule const &rhs)
{
	if (this != &rhs) {
		this->_ramSize = rhs._ramSize;
		this->_ramType = rhs._ramType;
		this->_ramSlot = rhs._ramSlot;
		this->_ramSlotSpeed = rhs._ramSlotSpeed;
	}
	return (*this);
}

/*==============================GETTERS-SETTERS==============================*/

std::string			RAMModule::getRAMSize(void) const { return (this->_ramSize); }
std::string			RAMModule::getRAMType(void) const { return (this->_ramType); }
std::string			RAMModule::getRAMSlot(void) const { return (this->_ramSlot); }
std::string			RAMModule::getRAMSlotSpeed(void) const { return (this->_ramSlotSpeed); }


/*===========================FUNCTIONS=======================================*/

void				RAMModule::collectInfo(void)
{
	this->_ramSize = getComRes("cat info/sysprof.txt | grep 'Memory: \\d* ' | sed -e 's/^ *//'");
	this->_ramSlotSpeed = getComRes("cat info/sysprof.txt | grep -A 40 'Upgradeable Memory:' | awk '/Speed:/  {printf \"%s \", $2$3;}'");
	this->_ramSlot = getComRes("cat info/sysprof.txt | grep -A 40 'Upgradeable Memory:' | awk '/Size:/  {printf \"%s \", $2$3;}'");
	this->_ramType = getComRes("cat info/sysprof.txt | grep -A 40 'Upgradeable Memory:' | awk '/Type:/  {printf \"%s \", $2;}'");
}

/*===========================EXCEPTIONS======================================*/
