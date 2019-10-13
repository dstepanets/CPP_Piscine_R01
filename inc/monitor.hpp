/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:33:40 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/06 16:33:42 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_HPP
# define MONITOR_HPP

#include "includes.hpp"

#include "TimeModule.hpp"
#include "NameModule.hpp"
#include "OsModule.hpp"
#include "HddModule.hpp"
#include "CpuModule.hpp"
#include "RAMModule.hpp"
#include "NetModule.hpp"

#include "NcursesDisplay.hpp"

class					Monitor
{
	public:
		Monitor(void);
		Monitor(Monitor const &src);
		~Monitor(void);
		Monitor &	operator = (const Monitor &rhs);

		void			initMonitors(void);

		void			NcursesLoop(Monitor *m);

	private:
		NameModule		*_name;
		TimeModule		*_time;
		OsModule		*_os;
		HddModule		*_hdd;
		CpuModule		*_cpu;
		RAMModule		*_ram;
		NetModule		*_net;

};



#endif