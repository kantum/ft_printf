#include "ft_printf.h"

int		ft_f(va_list ap, t_flags *f)
{
	(void)f;
	(void)ap;
	return (0);
}

int		ft_c(va_list ap, t_flags *f)
{
	(void)f;
	(void)ap;
	if (f->opts & LLONG)
		printf("l flag\n");
	return (0);
}

int		ft_s(char const *restrict format, va_list ap, t_flags *f)
{
	if (*format == 's')
		return (ft_putbuf(va_arg(ap, char *), f->fd));
	else if (*format == 'S')
		return (ft_putwstr(va_arg(ap, wchar_t *), f->fd));
	return (0);
}

char	*ft_d_precis(t_flags *f, char *fr)
{
	size_t	i;
	size_t	len;
	char	*ret;
	char	*tmp;

	i = 0;
	tmp = fr;
	len = ft_strlen(fr);
	while(tmp[i] == '0')
	{
		--len;
		++i;
	}
	ret = (char*)malloc(f->prec + 1);
	ft_bzero(ret, f->prec + 1);
	ft_memset(ret, '0', f->prec);
	len = ft_strlen(fr);
	while (i < len)
	{
		ret[f->prec - len + i] = fr[i];
		++i;
	}
	free(fr);
	return (ret);
}

char	*ft_d_width(t_flags *f, char *fr)
{
	size_t	i;
	size_t	len;
	char	*ret;

	i = 0;
	len = ft_strlen(fr);
	ret = (char*)malloc(f->min_w + 1);
	ft_bzero(ret, f->min_w + 1);
	if (f->opts & ZERO)
		ft_memset(ret, '0', f->min_w);
	else
		ft_memset(ret, ' ', f->min_w);
	while (i < len)
	{
		ret[f->min_w - len + i] = fr[i];
		++i;
	}
	free(fr);
	return (ret);
}

char	*ft_d_separ(char *fr)
{
	size_t	len;
	size_t	cp_size;
	size_t	k;
	char	*ret;

	k = 0;
	len = ft_strlen(fr);
	ret = (char*)malloc(26);
	ft_bzero(ret, 26);
	ft_memmove(ret, fr, len);
	while (++k < len)
		if (!(k % 3))
		{
			cp_size = ft_strlen(&ret[len - k]);
			ft_memmove(&ret[len - k + 1], &ret[len - k], cp_size);
			ret[len - k] = *localeconv()->thousands_sep;
		}
	free(fr);
	return (ret);
}

int		ft_d(va_list ap, t_flags *f)
{
	char	*fr;
	int		size;

	if (f->opts & LONG)
		fr = ft_ltoa(va_arg(ap, long int));
	else
		fr = ft_itoa(va_arg(ap, int));
	if (f->opts & PRECIS)
		fr = ft_d_precis(f, fr);
	if (f->opts & WIDTH)
		fr = ft_d_width(f, fr);
	if (f->opts & SEPAR)
		fr = ft_d_separ(fr);
	ft_putbuf(fr, f->fd);
	size = ft_strlen(fr);
	free(fr);
	return (size);
}

int		ft_x(va_list ap, t_flags *f, int down)
{
	char	*tmp;
	int		i;

	i = 0;
	if (down)
	{
		tmp = ft_itoa_base(va_arg(ap, int), 16);
		while (tmp[i])
		{
			tmp[i] = ft_tolower(tmp[i]);
			++i;
		}
		return (ft_putbuf(tmp, f->fd));
	}
	return (ft_putbuf(ft_itoa_base(va_arg(ap, int), 16), f->fd));
}

int		ft_ident(const char *restrict format, va_list ap, t_flags *f)
{
	if (*format == 'd')
		ft_d(ap, f);
	else if (*format == 's' || *format == 'S')
		ft_s(format, ap, f);
	else if (*format == 'c')
		ft_c(ap, f);
	else if (*format == '%')
		ft_putbuf("%", f->fd);
	else if (*format == 'x')
		ft_x(ap, f, 1);
	else if (*format == 'X')
		ft_x(ap, f, 0);
	return (1);
}
