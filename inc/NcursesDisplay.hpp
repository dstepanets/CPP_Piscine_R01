/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:55:07 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/06 17:55:09 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSESDISPLAY_HPP
# define NCURSESDISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include "monitor.hpp"

#define WINH	60
#define WINW	240

#define	MODH (WINH / 3)
#define	MODW (WINW / 4)

class		NcursesDisplay : public IMonitorDisplay
{
	public:
		NcursesDisplay(void);
		NcursesDisplay(NcursesDisplay const &src);
		~NcursesDisplay(void);

		NcursesDisplay &	operator = (const NcursesDisplay &rhs);


		// WINDOW*		getWin(void) const;

		void		init_colors(void);
		void		key_events(int key);
		void		makeModuleWindows(void);

		void		printBorder(WINDOW *modw, std::string title);

		void		logoDisplay();

		void		nameDisplay(NameModule *name);
		void		timeDisplay(TimeModule *time);
		void		osDisplay(OsModule *os);
		void		hddDisplay(HddModule *hdd);
		void		cpuDisplay(CpuModule *cpu);
		void		ramDisplay(RAMModule *ram);
		void		networkDisplay(NetModule *net);

	private:
		WINDOW 			*_logoWin;
		WINDOW 			*_nameWin;
		WINDOW 			*_timeWin;
		WINDOW 			*_osWin;
		WINDOW 			*_hddWin;
		WINDOW 			*_cpuWin;
		WINDOW 			*_ramWin;
		WINDOW 			*_networkWin;

};


#endif

		// class	Exception : public std::exception
		// {
		// public:
		// 	Exception(void);
		// 	Exception(const Exception &src);
		// 	~Exception(void) throw();
		// 	Exception& operator = (const Exception &rhs);
		// 	virtual const char* what() const throw();
		// };