/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:39:14 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/08 17:23:35 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main ()
{
    char    *a = "Prueba para strcmp\n";
    char    *b = "Prueba para strcmp\n";
    char    *c = "Hola";
    char    *d = "";
    char    buf;
	char	cad[50];
	char	cad2[50];
	ssize_t len;
	int		fd;
	int		count;

	buf = 0;
	len = 0;	
	fd = 0;
	count = 0;
	cad[0] = 0;

    printf ("-----ft_strlen------\n");
    printf("Original: %lu\n", strlen(a));
	printf("ft_strlen: %lu\n", ft_strlen(a));
    printf ("-----b------\n");
    printf("Original: %lu\n", strlen(b));
	printf("ft_strlen: %lu\n", ft_strlen(b));
    printf ("-----c------\n");
    printf("Original: %lu\n", strlen(c));
	printf("ft_strlen: %lu\n", ft_strlen(c));
    printf ("-----d------\n");
    printf("Original: %lu\n", strlen(d));
	printf("ft_strlen: %lu\n", ft_strlen(d));

    printf ("------ft_strcmp ab------\n");
    printf("Original: %d\n",strcmp(a, b));
	printf("ft_strlen: %d\n",ft_strcmp(a, b));
    printf ("------ft_strcmp bc------\n");
    printf("Original: %d\n",strcmp(b, c));
	printf("ft_strlen: %d\n",ft_strcmp(b, c));
    printf ("------ft_strcmp cd------\n");
    printf("Original: %d\n",strcmp(c, d));
	printf("ft_strlen: %d\n",ft_strcmp(c, d));
    printf ("------ft_strcmp da------\n");
    printf("Original: %d\n",strcmp(d, a));
	printf("ft_strlen: %d\n",ft_strcmp(d, a));

    printf ("-------ft_strcpy------\n");
    d = "Esto deberia ser copiado";
    strcpy(cad, a);
	printf("Original: %s\n", cad);
	ft_strcpy(cad2, a);
	printf("ft_strcpy: %s\n", cad2);
    printf ("-------ft_strcpy back------\n");
	d = "";
    strcpy(cad, c);
	printf("Original: %s\n", cad);
	d = "";
	ft_strcpy(cad2, c);
	printf("ft_strcpy: %s\n", cad2);

    printf ("------ft_read-------");
    if ((fd = open ("test1.txt", O_RDONLY)) < 0)
    {
        printf("error al leer el archivo");
        return (0);
    }
    else
    {
        printf("\nRead Original:");
        while ((count = read(fd, &buf, 1)) != 0)
            printf("%c", buf);
        close(fd);
        printf("\nRead ft_read:");
        fd = open("test1.txt", O_RDONLY);
        while ((count = read(fd, &buf, 1)) != 0)
            printf("%c", buf);
        close(fd);
    }
    printf("\n\nPrueba stdin\n");
    ft_read(0, cad, 50);
	printf("Has introducido: %s", cad);
    read(0, cad, 50);
	printf("Has introducido: %s", cad);

    printf ("------ft_write------\n");
    c = "Original: Esto es una prueba de la funcion write\n";
	d = "ft_write: Esto es una prueba de la funcion write\n";
	write(1, a, strlen(a));
	ft_write(1, d, strlen(d));
	c = "Original: Esto es una prueba mas larga y completa de la funcion write asdasdasasdadfdfsdfsdffsdfsdfsdfsdfsdssajkbdnsabjndjksahdjksahdjksahdjksahdjsajdhjksaddhsajkdhsajkdh\n";
	d = "ft_write: Esto es una prueba mas larga y completa de la funcion write asdasdasasdadfdfsdfsdffsdfsdfsdfsdfsdssajkbdnsabjndjksahdjksahdjksahdjksahdjsajdhjksaddhsajkdhsajkdh\n";
	write(1, a, strlen(a));
	ft_write(1, d, strlen(d));
	c = "Original:\n";
	d = "Mft_write:\n";
	write(1, a, strlen(a));
	ft_write(1, d, strlen(d));
	write(1, NULL, 10);
	ft_write(1, NULL, 10);
	c = "Esto es una prueba de ft_write en archivo\n";
	len = ft_strlen(a);
	if ((fd = open("test_write.txt", O_WRONLY | O_APPEND)) < 0)
		printf("No se ha podido abrir el archivo test_write.");
	if (ft_write(fd,a, strlen(a)) != len)
		printf("Hubo un error a a hora de escribir el archivo");
	else
		printf("Se pudo escribir con exito en el archivo test_write.txt\n");

    printf ("------ft_strdup------\n");
	char *src = "tendria que copiar esto";
	char *s1;
	char *s2;
	
	s1 = strdup(src);
	s2 = ft_strdup(src);
	printf("Originall: %s\n", s1);
	printf("ft_strdup: %s\n", s2);
	free(s1);
	free(s2);
	s1 = strdup(b);
	s2 = ft_strdup(b);
	printf("Original: %s\n", s1);
	printf("ft_strdup: %s\n", s2);
	free(s1);
	free(s2);
	

    return (0);
}