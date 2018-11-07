#include <stdio.h>
#include <locale.h>
#include "ft_printf.h"
#include "libft.h"
#include "libft.h"

int	ft_printf(const char *restrict format, ...);

int		main(void)
{
	//printf("setlocale : %s\n", setlocale(LC_ALL, "fr_FR.UTF-8"));
	printf("setlocale : %s\n", setlocale(LC_ALL, "en_US.UTF-8"));
	//printf("MB_CUR_MAX = %d\n", MB_CUR_MAX);

	int ret;

	ft_printf("ft_printf\t: ");
	ret = ft_printf("%% hello %s yolo\n", "you");
	ft_printf("ret = %d\n", ret);
	printf("real printf\t: ");
	ret = printf("%% hello %s yolo\n", "you");
	printf("ret = %d\n", ret);
	printf("\n\n");

	ft_putstr("\nft_printf\t: ");
	ret = ft_printf("hello %X\n", 42);
	ft_printf("ret = %d\n", ret);
	printf("real printf\t: ");
	ret = printf("hello %X\n", 42);
	printf("ret = %d\n", ret);
	printf("\n\n");

	ft_putstr("\nft_printf\t: ");
	ret = ft_printf("precise %.40ld\n", 9223372036854775807);
	ft_printf("ret = %d\n", ret);
	printf("real printf\t: ");
	ret = printf("precise %.40ld\n", 9223372036854775807);
	printf("ret = %d\n", ret);
	//printf("oups %.5d\n", 23432357);
	printf("\n\n");

	ft_putstr("\nft_printf\t: ");
	ret = ft_printf("precise *  %.*ld\n", 35, 9223372036854775807);
	ft_printf("ret = %d\n", ret);
	printf("real printf\t: ");
	ret = printf("precise *  %.*ld\n", 35, 9223372036854775807);
	printf("ret = %d\n", ret);
	//printf("oups %.5d\n", 23432357);
	printf("\n\n");

	ft_putstr("\nft_printf\t: ");
	ret = ft_printf("hello %0.30d\n", 775807);
	ft_printf("ret = %d\n", ret);
	printf("real printf\t: ");
	ret = printf("hello %0.30d\n", 775807);
	printf("ret = %d\n", ret);
	//printf("oups %.5d\n", 23432357);
	printf("\n\n");


	ft_putstr("\nft_printf\t: ");
	ret = ft_printf("hello %'ld\n", 9223372036854775807);
	ft_printf("ret = %d\n", ret);
	printf("real printf\t: ");
	ret = printf("hello %'ld\n", 9223372036854775807);
	printf("ret = %d\n", ret);
	//printf("oups %.5d\n", 23432357);
	printf("\n\n");

	ft_printf("ft_printf\t: ");
	ret = ft_printf("long %.10ld\n", 1234567890);
	ft_printf("ret = %d\n", ret);
	printf("real printf\t: ");
	ret = printf("long %.10ld\n", 1234567890);
	printf("ret = %d\n", ret);
	printf("\n\n");

	ft_printf("ft_printf\t: ");
	ret = ft_printf("hello %s yolo\n", "👾");
	ft_printf("ret = %d\n", ret);
	printf("real printf\t: ");
	ret = printf("hello %s yolo\n", "👾");
	printf("ret = %d\n", ret);
	printf("\n\n");

	ft_printf("ft_printf\t: ");
	ret = ft_printf("hello %S yolo\n", L"👾");
	ft_printf("ret = %d\n", ret);
	printf("real printf\t: ");
	ret = printf("hello %S yolo\n", L"👾");
	printf("ret = %d\n", ret);
	printf("\n\n");

	printf("real printf\t: ");
	printf("hello %f", 21474.86480);
	printf("\nft_printf\t: ");
	ft_printf("hello %f", 21474.86480);
	printf("\n\n");

	printf("real printf\t: ");
	printf("hello %#12.3F", 21474.8648098989);
	printf("\nft_printf\t: ");
	ft_printf("hello %#12.3jF", 21474.8648098989);
	printf("\n\n");

}
