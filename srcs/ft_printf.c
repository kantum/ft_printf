#include "ft_printf.h"
#include "libft.h"
//
//int		ft_f(va_list ap, t_flags *f)
//{
//	(void)f;
//	return (ft_ftoa(va_arg(ap, char *), 1));
//}
//
int		ft_s(va_list ap, t_flags *f)
{
	(void)f;
	return (ft_putbuf(va_arg(ap, char *), 1));
}

int		ft_d(va_list ap, t_flags *f)
{
	if (f->opts & LONG) //TODO don't forget to free
		ft_putbuf(ft_ltoa(va_arg(ap, long int)), 1);
	else
		ft_putbuf(ft_itoa(va_arg(ap, int)), 1);
	return (4);
}

int		ft_ident(const char *restrict format, va_list ap, t_flags *f)
{
	if (*format == 'd')
		ft_d(ap, f);
	if (*format == 's')
		ft_s(ap, f);
	//if (*format == 'f')
	//	ft_f(ap, f);
	return (1);
}

int		ft_printf(const char *restrict format, ...)
{
	int		ret;
	va_list	arg;

	va_start(arg, format);
	ret = ft_vfprintf(stdout, format, arg);
	va_end(arg);
	return (ret);
}
