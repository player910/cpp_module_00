/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksahinoz <ksahinoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:21:15 by ksahinoz          #+#    #+#             */
/*   Updated: 2026/07/14 15:21:18 by ksahinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int i = 1;
	int j = 0;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			std::cout << (char)(toupper(argv[i][j]));
			j++;
		}	
		i++;
	}
	std::cout << std::endl;
	return (0);
}
