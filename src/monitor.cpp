/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 22:18:24 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/06 22:18:26 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/monitor.hpp"

/*==============================CONSTRUCTORS=================================*/

Monitor::Monitor(void)
{
	this->initMonitors();
}
Monitor::Monitor(Monitor const &src) { *this = src; }
Monitor::~Monitor(void)
{
	delete _name;
	delete _time;
	delete _cpu;
}

/*================================OPERATORS==================================*/

Monitor & 		Monitor::operator = (Monitor const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_time = rhs._time;
		this->_cpu = rhs._cpu;
	}
	return (*this);
}

/*===========================FUNCTIONS=======================================*/

void			Monitor::initMonitors(void)
{
	
	this->_name = new NameModule;
	this->_time = new TimeModule;
	this->_os = new OsModule;
	this->_hdd = new HddModule;
	this->_cpu = new CpuModule;
	this->_ram = new RAMModule;
	this->_net = new NetModule;
}

void			Monitor::NcursesLoop(Monitor *m)
{
	NcursesDisplay	*nc	= new NcursesDisplay;

	nc->logoDisplay();
	nc->nameDisplay(m->_name);

	nc->osDisplay(m->_os);
	nc->hddDisplay(m->_hdd);

	nc->ramDisplay(m->_ram);
	// nc->networkDisplay(m->_net);

	int	key = -1;

	while (key != ESC)
	{
		std::time_t t = std::time(nullptr);

		nc->timeDisplay(m->_time);
		nc->cpuDisplay(m->_cpu);
		nc->osDisplay(m->_os);

		if ((key = getch()) != ERR)
			nc->key_events(key);
		while (t == std::time(nullptr))
			;

	}
	delete nc;

}


/*===========================EXCEPTIONS======================================*/
