#include "ft_printf.h"

void	init(t_flags *f)
{
	f->opts = 0;
	f->prec = 0;
	f->min_w = 0;
}

int		ft_vfprintf(FILE *restrict stream,
		const char *restrict format, va_list ap)
{
	int		ret;
	int		i;
	char	tmp[BUFFSIZE];
	t_flags	f;

	ret = 0;
#ifdef __ANDROID__
	f.fd = stream->_file;
#elif defined(__gnu_linux__)
	f.fd = stream->_fileno;
#elif defined(__APPLE__)
	f.fd = stream->_file;
#endif
	ft_bzero(tmp, BUFFSIZE);
	while (*format)
	{
		i = -1;
		while (*format && *format != '%')
			tmp[++i] = (char)*format++;
		ft_putbuf(tmp, f.fd);
		ft_bzero(tmp, BUFFSIZE);
		if (*format == '%')
		{
			init(&f);
			++format;
			format += ft_flags(format, &f);
			format += ft_fwidth(format, ap, &f);
			format += ft_precis(format, ap, &f);
			format += ft_length(format, &f);
			format += ft_ident(format, ap, &f);
		}
	}
	return (ret = ft_putbuf(NULL, f.fd));
}
