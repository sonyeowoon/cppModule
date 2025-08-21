/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:22:55 by sangseo           #+#    #+#             */
/*   Updated: 2025/08/13 22:22:17 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int i = 1;
	while (av[i])
	{
		int j = 0;
		while (av[i][j])
		{
			av[i][j] = toupper(av[i][j]);
			j++;
		}
		std::cout << av[i];
		i++;
	}
	std::cout << std::endl;
}
