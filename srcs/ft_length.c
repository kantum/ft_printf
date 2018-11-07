#include "ft_printf.h"

int		ft_ll(const char *restrict format, t_flags *f)
{
	int		i;

	i = 0;
	++format;
	++i;
	if (*format == 'l')
	{
		++format;
		++i;
		f->opts ^= LLONG;
	}
	else
		f->opts ^= LONG;
	return (i);
}

int		ft_lh(const char *restrict format, t_flags *f)
{
	int		i;

	i = 0;
	++format;
	++i;
	if (*format == 'h')
	{
		++format;
		++i;
		f->opts ^= MOD_HH;
	}
	else
		f->opts ^= MOD_H;
	return (i);
}

int		ft_length(const char *restrict format, t_flags *f)
{
	int		i;

	(void)f;
	i = 0;
	if (*format == 'h')
		i = ft_lh(format, f);
	else if (*format == 'l')
		i = ft_ll(format, f);
	else if (*format == 'j')
	{
		++format;
		++i;
	}
	else
		return (0);
	return (i);
}
