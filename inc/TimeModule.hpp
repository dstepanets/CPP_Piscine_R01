/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:40:17 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/07 13:40:19 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

#include "includes.hpp"
#include "IMonitorModule.hpp"

class		TimeModule : public IMonitorModule
{
	public:
		TimeModule(void);
		TimeModule(TimeModule const &src);
		~TimeModule(void);

		TimeModule &	operator = (const TimeModule &rhs);


		std::string		getDate(void) const;
		std::string		getTime(void) const;


		virtual void	collectInfo(void);

	private:
		std::string 	_date;
		std::string 	_time;

};

#endif
