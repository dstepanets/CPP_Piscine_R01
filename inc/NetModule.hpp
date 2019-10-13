// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NetModule.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/07/07 20:31:21 by vdzhanaz          #+#    #+#             //
//   Updated: 2019/07/07 20:31:22 by vdzhanaz         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NETMODULE_HPP
# define NETMODULE_HPP

# include "includes.hpp"
# include "IMonitorModule.hpp"
# include <vector>
# include <list>

class		NetModule : public IMonitorModule
{
	public:
		NetModule(void);
		NetModule(NetModule const &src);
		~NetModule(void);
		NetModule &	operator = (const NetModule &rhs);

		std::list<std::string> 	getNetInt(void) const;
		std::list<std::string> 	getNetTp(void) const;
		std::list<std::string> 	getNetBd(void) const;
		long int 					getITot(void) const;
		long int 					getOTot(void) const;

		virtual void				collectInfo(void);
		// virtual void				collectDynInfo(void);

	private:
		std::list<std::string> 	_netInt;
		std::list<std::string> 	_netTp;
		std::list<std::string> 	_netBd;
		// // long int 				_iTot;
		// long int 				_oTot;
};

#endif