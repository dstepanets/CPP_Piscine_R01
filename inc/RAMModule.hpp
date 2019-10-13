// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAMModule.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/07/07 19:26:25 by vdzhanaz          #+#    #+#             //
//   Updated: 2019/07/07 19:26:27 by vdzhanaz         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

#include "includes.hpp"
#include "IMonitorModule.hpp"

class		RAMModule : public IMonitorModule
{
	public:
		RAMModule(void);
		RAMModule(RAMModule const &src);
		~RAMModule(void);
		RAMModule &	operator = (const RAMModule &rhs);

		std::string		getRAMSize(void) const;
		std::string		getRAMType(void) const;
		std::string		getRAMSlot(void) const;
		std::string		getRAMSlotSpeed(void) const;

		virtual void	collectInfo(void);

	private:
		std::string 	_ramSize;
		std::string		_ramType;
		std::string		_ramSlot;
		std::string		_ramSlotSpeed;
};

#endif