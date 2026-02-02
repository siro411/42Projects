unsigned char	swap_bits(unsigned char octet)
{
	return (octet << 4 | octet >> 4);
}

#include <unistd.h>

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
	print_bits(swap_bits(8));
}