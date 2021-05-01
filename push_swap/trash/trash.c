long* ft_convert_arg (int size, char *arg, long *cad)
{
	int			i;
	int 		j;
	long int	*k;

	i = 0;
	j = 0;
	cad[0] = 0;
	if (!(k = malloc(size * sizeof(long int))))
		cad[0] = -1;
	while ((j + 1) < size)
	{
		if ((i == 0 || arg[i] == ' ') && j++)
			k[size - j] = ft_atoiswap(&arg[i]);
		if (k[size - j] > 2147483648)
			cad[0] = 1;
		i++;
	}
	k[0] = -1;
	if (cad[0] == 0)
		return (ft_compare (k, size));
	else
		return (cad);
}

