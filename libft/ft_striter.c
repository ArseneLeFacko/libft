/******************************************************************************/
/*     Copyright (c) 2020 Arsene Temfack                                      */
/*                                                                            */
/*     SPDX-License-Identifier: MIT                                           */
/******************************************************************************/

void	ft_striter(char *s, void (*f)(char *))
{
	if (!(s) || !(f))
		return ;
	while (*s)
	{
		f(s);
		s++;
	}
}
