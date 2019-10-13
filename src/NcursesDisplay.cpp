/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:06:35 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/06 20:06:37 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/NcursesDisplay.hpp"
#include "../inc/monitor.hpp"

/*==============================CONSTRUCTORS=================================*/

NcursesDisplay::NcursesDisplay(void)
{
	initscr();			// Initialize the window
	cbreak();			// Line buffering disabled, Pass on everty thing to me
	noecho(); 			// Don't echo any keypresses
	curs_set(FALSE); 	// Don't display a cursor
	start_color();
	clear();
	refresh();

	keypad(stdscr, 1);
	nodelay(stdscr, TRUE);

	this->init_colors();
	this->makeModuleWindows();

}

NcursesDisplay::NcursesDisplay(NcursesDisplay const &src) { *this = src; }

NcursesDisplay::~NcursesDisplay(void)
{
	erase();
	delwin(stdscr);
	endwin();	// restore the terminal settings before exit;
}

/*================================OPERATORS==================================*/

NcursesDisplay & 		NcursesDisplay::operator = (NcursesDisplay const &rhs)
{
	if (this != &rhs)
	{
		
		this->_nameWin = rhs._nameWin;
		this->_timeWin = rhs._timeWin;
		this->_cpuWin = rhs._cpuWin;
	}
	return (*this);
}

/*==============================GETTERS-SETTERS==============================*/

// WINDOW*		NcursesDisplay::getWin(void) const { return (this->_win); }


/*===========================FUNCTIONS=======================================*/

void		NcursesDisplay::init_colors(void)
{
	start_color();							//for using colors

	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);	// logo subtitle
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_MAGENTA, COLOR_BLACK);	// logo

	init_pair(10, COLOR_BLACK, COLOR_BLUE); 	// module border
	init_pair(11, COLOR_BLUE, COLOR_YELLOW);	// module title
	init_pair(12, COLOR_BLACK, COLOR_YELLOW);	// logo border
}

void		NcursesDisplay::key_events(int key)
{
	switch(key)
	{
		case ESC:
			NcursesDisplay::~NcursesDisplay();
			break;

	}
}

void		NcursesDisplay::makeModuleWindows(void)
{
	this->_logoWin = newwin((MODH / 2), MODW, 1, MODW * 2 + 1);
	wrefresh(_logoWin);
	
	this->_nameWin = newwin((MODH / 2), MODW, 1, 1);
	wrefresh(_nameWin);
	this->_timeWin = newwin((MODH / 2), MODW, 1 + (MODH / 2), 1);
	wrefresh(_timeWin);
	this->_osWin = newwin(MODH, MODW, (1 + MODH), 1);
	wrefresh(_osWin);
	this->_hddWin = newwin(MODH, MODW, (1 + (MODH * 2)), 1);
	wrefresh(_hddWin);

	this->_cpuWin = newwin(MODH, MODW, 1, MODW + 1);
	wrefresh(_cpuWin);
	this->_ramWin = newwin(MODH, MODW, (1 + MODH), MODW + 1);
	wrefresh(_ramWin);
	this->_networkWin = newwin(MODH, MODW, (1 + MODH * 2), MODW + 1);
	wrefresh(_networkWin);
}


void		NcursesDisplay::logoDisplay()
{
	wattron(_logoWin, COLOR_PAIR(12));
		box(_logoWin, 0, 0);
	wattroff(_logoWin, COLOR_PAIR(12));

	int		y = 2;
	int 	x = (MODW / 2) - 20;
	wattron(_logoWin, A_BOLD);
	wattron(_logoWin, COLOR_PAIR(8));
		mvwprintw(_logoWin, y++, x, "   ___ _      ______________  __  _______");
		mvwprintw(_logoWin, y++, x, "  / _ | | /| / / __/ __/ __ \\/  |/  / __/");
		mvwprintw(_logoWin, y++, x, " / __ | |/ |/ / _/_\\ \\/ /_/ / /|_/ / _/  ");
		mvwprintw(_logoWin, y++, x, "/_/ |_|__/|__/___/___/\\____/_/  /_/___/ ");
	wattroff(_logoWin, COLOR_PAIR(8));

	wattron(_logoWin, COLOR_PAIR(6));
		x = (MODW / 2) - 7;
		mvwprintw(_logoWin, (y++ + 1), x, "SYSTEM MONITOR");
	wattroff(_logoWin, A_BOLD);
	wattroff(_logoWin, COLOR_PAIR(6));

	wrefresh(_logoWin);
}

void		NcursesDisplay::printBorder(WINDOW *modw, std::string title)
{
	wattron(modw, COLOR_PAIR(10));
		box(modw, 0, 0);
	wattroff(modw, COLOR_PAIR(10));

	wattron(modw, A_BOLD);
	wattron(modw, COLOR_PAIR(11));
		mvwprintw(modw, 1, ( (MODW / 2) - (static_cast<int>(title.length() / 2) )), "%s", title.c_str());
	wattroff(modw, A_BOLD);
	wattroff(modw, COLOR_PAIR(11));
}


void		NcursesDisplay::nameDisplay(NameModule *name)
{
	printBorder(_nameWin, "* Username / Hostname *");

	int		x = (MODW / 2) - (static_cast<int>(name->getUserName().length() / 2));
	mvwprintw(_nameWin, 3, x, "%s", name->getUserName().c_str());
	x = (MODW / 2) - (static_cast<int>(name->getHostName().length() / 2));
	mvwprintw(_nameWin, 5, x, "%s", name->getHostName().c_str());

	wrefresh(_nameWin);
}

void		NcursesDisplay::timeDisplay(TimeModule *time)
{
	time->collectInfo();
	werase(_timeWin);

	printBorder(_timeWin, "* Date / Time *");

	int		x = (MODW / 2) - (static_cast<int>(time->getDate().length() / 2));
	mvwprintw(_timeWin, 3, x, "%s", time->getDate().c_str());
	x = (MODW / 2) - (static_cast<int>(time->getTime().length() / 2));
	mvwprintw(_timeWin, 5, x, "%s", time->getTime().c_str());

	wrefresh(_timeWin);
}

void		NcursesDisplay::osDisplay(OsModule *os)
{
	printBorder(_osWin, "* O S *");

	mvwprintw(_osWin, 3, 2, "System version:\t%s", os->getSysVer().c_str());
	mvwprintw(_osWin, 4, 2, "Kernel name:\t\t%s", os->getKerName().c_str());
	mvwprintw(_osWin, 5, 2, "Kernel version:\t%s", os->getKerVer().c_str());
	mvwprintw(_osWin, 6, 2, "Kernel timestamp:\t%s", os->getKerTimeStamp().c_str());
	mvwprintw(_osWin, 7, 2, "Architecture:\t\t%s", os->getSysArch().c_str());
	wrefresh(_osWin);
}

void		NcursesDisplay::hddDisplay(HddModule *hdd)
{
	printBorder(_hddWin, "* H D D *");

	mvwprintw(_hddWin, 3, 2, "HDD Model:\t\t\t%s", hdd->getHddModel().c_str());
	mvwprintw(_hddWin, 4, 2, "HDD Capacity:\t\t\t%s", hdd->getHddCapac().c_str());
	mvwprintw(_hddWin, 5, 2, "System Drive:\t\t\t%s", hdd->getHddSysCap().c_str());
	mvwprintw(_hddWin, 6, 2, "System Drive Available:\t%s", hdd->getHddSysAvail().c_str());

	wrefresh(_hddWin);
}

void		NcursesDisplay::cpuDisplay(CpuModule *cpu)
{
	cpu->collectDynamicInfo();
	werase(_timeWin);

	printBorder(_cpuWin, "* C P U *");

	mvwprintw(_cpuWin, 3, 2, "Name:\t\t%s", cpu->getCpuName().c_str());
	mvwprintw(_cpuWin, 4, 2, "Model:\t%s", cpu->getCpuModel().c_str());
	mvwprintw(_cpuWin, 5, 2, "Arch:\t\t%s", cpu->getCpuArch().c_str());
	mvwprintw(_cpuWin, 6, 2, "Cores:\t%u", cpu->getCpuCoreNum());
	
	mvwprintw(_cpuWin, 8, 2, "User Usage:\t%.2f", cpu->getCPUUsageUsr());
	mvwprintw(_cpuWin, 9, 2, "System Usage:\t%.2f", cpu->getCpuUsageSys());
	mvwprintw(_cpuWin, 10, 2, "Idle:\t\t%.2f", cpu->getCpuUsageIdle());

	wrefresh(_cpuWin);
}

void		NcursesDisplay::ramDisplay(RAMModule *ram)
{
	printBorder(_ramWin, "* R A M *");

	mvwprintw(_ramWin, 3, 2, "RAM Size:\t\t%s", ram->getRAMSize().c_str());
	mvwprintw(_ramWin, 4, 2, "RAM Type:\t\t%s", ram->getRAMType().c_str());
	mvwprintw(_ramWin, 5, 2, "RAM Slots:\t\t%s", ram->getRAMSlot().c_str());
	mvwprintw(_ramWin, 6, 2, "RAM Slots Speed:\t%s", ram->getRAMSlotSpeed().c_str());

	wrefresh(_ramWin);
}

// void		NcursesDisplay::networkDisplay(NetModule *net)
// {
// 	printBorder(_networkWin, "* NETWORK *");

// 	mvwprintw(_networkWin, 3, 2, "RAM Size:\t\t%s", net->getRAMSize().c_str());
// 	mvwprintw(_networkWin, 4, 2, "RAM Type:\t\t%s", net->getRAMType().c_str());
// 	mvwprintw(_networkWin, 5, 2, "RAM Slots:\t\t%s", net->getRAMSlot().c_str());
// 	net->getITot();
// 	wrefresh(_networkWin);
// }






/*===========================EXCEPTIONS======================================*/

// NcursesDisplay::Exception::Exception(void) {}
// NcursesDisplay::Exception::Exception(Exception const &src) {*this = src;}
// NcursesDisplay::Exception::~Exception(void) throw() {}
// NcursesDisplay::Exception &NcursesDisplay::Exception::operator = (NcursesDisplay::Exception const &rhs) 
// 	{std::exception::operator=(rhs); return *this;}
// const char *		NcursesDisplay::Exception::what(void) const throw()
// 	{return ("NcursesDisplay error.");}


