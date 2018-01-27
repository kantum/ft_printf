#include "libft.h"

char		*ft_ltoa(long n)
{
	size_t	i;
	char	*ret;
	int		sign;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * 20)))
		return (0);
	if (n == 0)
		return (ft_strdup("0"));
	sign = (n < 0) ? 1 : 0;
	while (n != 0)
	{
		ret[i++] = (sign) ? (-1 * (n % 10)) + '0' : (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		ret[i++] = '-';
	ret[i] = '\0';
	return (ft_strrev(ret));
}
