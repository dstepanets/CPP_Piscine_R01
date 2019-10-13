/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 22:46:18 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/06 22:46:20 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_HPP
# define INCLUDES_HPP

#include <ncurses.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <pwd.h>
#include <sys/utsname.h>

#define PUTLN(l) std::cout << (l) << std::endl;

#define ESC	27

std::string		getComRes(const char *com);
std::list<std::string>		split(const std::string& s, const char& c);

#endif