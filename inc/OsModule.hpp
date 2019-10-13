/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsModule.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:14:59 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/07 17:15:00 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSMODULE_HPP
# define OSMODULE_HPP

#include "includes.hpp"
#include "IMonitorModule.hpp"

class		OsModule : public IMonitorModule
{
	public:
		OsModule(void);
		OsModule(OsModule const &src);
		~OsModule(void);

		OsModule &	operator = (const OsModule &rhs);

		std::string		getSysVer(void) const;
		std::string		getKerName(void) const;
		std::string		getKerVer(void) const;
		std::string		getKerTimeStamp(void) const;
		std::string		getSysArch(void) const;

		virtual void	collectInfo(void);

	private:
		std::string 	_sysVer;
		std::string 	_kerName;
		std::string 	_kerVer;

		std::string 	_kerTime;
		std::string 	_architecture;
};

#endif


