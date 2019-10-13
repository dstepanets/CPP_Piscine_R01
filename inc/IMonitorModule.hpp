/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:34:49 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/06 17:34:51 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP


class		IMonitorModule
{
	public:
		virtual ~IMonitorModule() {};

		virtual void	collectInfo(void) = 0;

};

#endif


