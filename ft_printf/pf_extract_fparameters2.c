/******************************************************************************/
/*     Copyright (c) 2020 Arsene Temfack                                      */
/*                                                                            */
/*     SPDX-License-Identifier: MIT                                           */
/******************************************************************************/

#include "ft_printf.h"

static void		pf_extract_flags(char flags[5], char c)
{
	if (c == '-')
		flags[0] = c;
	else if (c == '+')
		flags[1] = c;
	else if (c == ' ')
		flags[2] = c;
	else if (c == '#')
		flags[3] = c;
	else
		flags[4] = c;
}

static void		pf_extract_value(int *value, va_list args, char **nformat)
{
	if (**nformat == '*')
	{
		*value = va_arg(args, int);
		(*nformat)++;
	}
	else
	{
		*value = ft_atoi((*nformat));
		while (ft_isdigit(**nformat))
			(*nformat)++;
	}
}

static void		pf_extract_length(t_format *fpara, char **nformat)
{
	if (**nformat == 'l')
	{
		(*nformat)++;
		fpara->length[0] = 'l';
		if (**nformat == 'l')
		{
			(*nformat)++;
			fpara->length[1] = 'l';
		}
	}
	else if (**nformat == 'h')
	{
		(*nformat)++;
		fpara->length[0] = 'h';
		if (**nformat == 'h')
		{
			(*nformat)++;
			fpara->length[1] = 'h';
		}
	}
}

int				pf_extract_fparameters2(char *nformat, va_list args,
					t_format *fpara)
{
	while (ft_strchr("-+ #0", *nformat))
		pf_extract_flags(fpara->flags, *nformat++);
	pf_extract_value(&fpara->width, args, &nformat);
	if (fpara->width < 0)
	{
		fpara->flags[0] = '-';
		fpara->width *= -1;
	}
	if (*nformat == '.' && nformat++)
	{
		fpara->dot = '.';
		pf_extract_value(&fpara->precision, args, &nformat);
	}
	if (*nformat == 'h' || *nformat == 'l')
		pf_extract_length(fpara, &nformat);
	if (ft_strchr("cspdiuxX%nf", *nformat) == NULL)
		return (-1);
	fpara->specifier = *nformat;
	return (1);
}
