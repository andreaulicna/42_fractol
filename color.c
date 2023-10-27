/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:36:53 by aulicna           #+#    #+#             */
/*   Updated: 2023/10/27 13:49:14 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	choose_color(int c)
{
	if (c == 0)
		return (66 << 16 | 30 << 8 | 15);  
	else if (c == 15)
		return (25 << 16 | 7 << 8 | 26);  
	else if (c == 14)
		return (9 << 16 | 1 << 8 | 47);  
	else if (c == 13)
		return (4 << 16 | 4 << 8 | 73);  
	else if (c == 12)
		return (0 << 16 | 7 << 8 | 100);  
	else if (c == 11)
		return (12 << 16 | 44 << 8 | 138);  
	else if (c == 10)
		return (24 << 16 | 82 << 8 | 177);  
	else if (c == 9)
		return (57 << 16 | 125 << 8 | 209);  
	else if (c == 8)
		return (134 << 16 | 181 << 8 | 229);  
	else if (c == 7)
		return (211 << 16 | 236 << 8 | 248);  
	else if (c == 6)
		return (241 << 16 | 233 << 8 | 191);  
	else if (c == 5)
		return (248 << 16 | 201 << 8 | 95);  
	else if (c == 4)
		return (255 << 16 | 170 << 8 | 0);  
	else if (c == 3)
		return (204 << 16 | 128 << 8 | 0);  
	else if (c == 2)
		return (153 << 16 | 87 << 8 | 0);  
	else if (c == 1)
		return (106 << 16 | 52 << 8 | 3);  
	return (c);
}
