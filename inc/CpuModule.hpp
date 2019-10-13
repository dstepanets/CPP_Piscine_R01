/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:57:12 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/06 21:57:13 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

#include "includes.hpp"
#include "IMonitorModule.hpp"

class		CpuModule : public IMonitorModule
{
	public:
		CpuModule(void);
		CpuModule(CpuModule const &src);
		~CpuModule(void);
		CpuModule &	operator = (const CpuModule &rhs);

		std::string		getCpuName(void) const;
		std::string		getCpuModel(void) const;
		std::string		getCpuArch(void) const;
		unsigned int	getCpuCoreNum(void) const;
		float			getCPUUsageUsr(void) const;
		float			getCpuUsageSys(void) const;
		float			getCpuUsageIdle(void) const;

		virtual void	collectInfo(void);
		virtual void	collectDynamicInfo(void);

	private:
		std::string 	_cpuName;
		std::string		_cpuModel;
		std::string		_cpuArch;
		unsigned int	_cpuCoreNum;
		float			_cpuUsageUser;
		float			_cpuUsageSys;
		float			_cpuUsageIdle;
};

#endif
