#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	res;

	i = 8;
	res = 0;
	while (i--)
	{
		// res = res | (octet >> i & 1) << (7 - i);
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}

void	print_bits(unsigned char octet)
{
	int		i;
	char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int	main(void)
{
	print_bits(8);
	write(1, "\n", 1);
	print_bits(reverse_bits(8));
}