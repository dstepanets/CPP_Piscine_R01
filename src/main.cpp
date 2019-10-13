/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:52:07 by dstepane          #+#    #+#             */
/*   Updated: 2019/07/06 15:52:09 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/monitor.hpp"

std::list<std::string>		split(const std::string& s, const char& c) {
	size_t i = 0;
	std::string				buf = "";
	std::list<std::string>	res;

	while(s[i]) {
		if(s[i] != c)
			buf+=s[i];
		else
			if(s[i] == c && buf != "") { 
				res.push_back(buf);
				buf = "";
				}
		i++;
	}
	return (res);
}

std::string		getComRes(const char *com)
{
	char		buff[100];
	FILE*		pip = popen(com, "r");
	std::string	res = "";

	if (!pip)
		perror ("Error:");
	try {
		while (!feof(pip)) {
			if(fgets(buff, 100, pip))
				res = res + buff;
		}
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
		pclose(pip);
	}
	pclose(pip);
	return (res);
}

int				main(void)
{
	// pid_t	child;
	// if ((child = fork()) == 0)
	// {
	PUTLN("Gathering data...");	
	system("system_profiler -detailLevel basic > info/sysprof.txt");
	// 	return (0);
	// }

	Monitor			*m	= new Monitor;

	m->NcursesLoop(m);

	delete m;

	return(0);
}




/*

>> system_profiler
>> top
>> sysctl
>> sysctlbyname


 exec("grep -A 20 'Processor Name:' < info/sysprof.txt");
("grep -A 20 'Network:' < info.txt")

uname -- Print operating system name



void OSModule::setOSinfo(void)
{
    char buffer[100] = {0};
    size_t bufLen = 100;
	std::string result;

    sysctlbyname("kern.ostype", &buffer, &bufLen, NULL, 0);
	result = buffer;
	memset(buffer, 0, bufLen);
	sysctlbyname("kern.osrelease", &buffer, &bufLen, NULL, 0);
	result.append(" ");
	result.append(buffer);
	
	this->_moduleMap["OS info"] = result;
}



*/