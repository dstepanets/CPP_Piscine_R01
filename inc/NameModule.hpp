/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NameModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:08:40 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/07 16:08:42 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMEMODULE_HPP
# define NAMEMODULE_HPP

#include "includes.hpp"
#include "IMonitorModule.hpp"

class		NameModule : public IMonitorModule
{
	public:
		NameModule(void);
		NameModule(NameModule const &src);
		~NameModule(void);

		NameModule &	operator = (const NameModule &rhs);


		std::string		getHostName(void) const;
		std::string		getUserName(void) const;


		virtual void	collectInfo(void);

	private:
		std::string 	_hostName;
		std::string 	_userName;
};

#endif

