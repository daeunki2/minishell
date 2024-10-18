/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:18:51 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:19:59 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	signe;

	i = 0;
	nbr = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - 48;
		i++;
	}
	return (signe * nbr);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void) // Veuilez rentrer une chaine de character 
								//a tranformer apres le nom de l'executable
{
	printf("%d : %d\n", ft_atoi("2147483647"), atoi("2147483647"));
	printf("%d : %d\n", ft_atoi("0"), atoi("0"));
	printf("%d : %d\n", ft_atoi("-85"), atoi("-85"));
	printf("%d : %d\n", ft_atoi("15236"), atoi("15236"));
	printf("%d : %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
	printf("%d : %d\n", ft_atoi("--  458"), atoi("--  458"));
}
*/
