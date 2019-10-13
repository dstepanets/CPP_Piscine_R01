/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HddModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 21:42:24 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/07 21:42:25 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HDDMODULE_HPP
# define HDDMODULE_HPP

#include "includes.hpp"
#include "IMonitorModule.hpp"

class		HddModule : public IMonitorModule
{
	public:
		HddModule(void);
		HddModule(HddModule const &src);
		~HddModule(void);

		HddModule &	operator = (const HddModule &rhs);

		std::string		getHddModel(void) const;
		std::string		getHddCapac(void) const;
		std::string		getHddSysCap(void) const;
		std::string		getHddSysAvail(void) const;

		virtual void	collectInfo(void);

	private:
		std::string 	_hddModel;
		std::string 	_hddCapac;
		std::string 	_hddSysCap;
		std::string 	_hddSysAvail;

};

#endif


