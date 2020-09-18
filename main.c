/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:34:54 by fulldemo          #+#    #+#             */
/*   Updated: 2020/02/02 15:45:20 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "libasm.h"


void		test_ft_strdup()
{
	printf("ft_strdup :\n");
	printf("	[1]''\n");
	printf("		<string.h>  %s\n", strdup(""));
	printf("		<libasm.a>  %s\n", ft_strdup(""));
	printf("	[2]'toto'\n");
	printf("		<string.h>  %s\n", strdup("toto"));
	printf("		<libasm.a>  %s\n", ft_strdup("toto"));
	printf("	[3]'0123456789'\n");
	printf("		<string.h>  %s\n", strdup("0123456789"));
	printf("		<libasm.a>  %s\n", ft_strdup("0123456789"));
	char	*a = "bonjour";
	char	*b = "bonjour";
	char	*a1 = strdup(a);
	char	*b1 = ft_strdup(b);
	printf("	[4]free\n");
	printf("		<string.h>  %s\n", a1);
	printf("		<libasm.a>  %s\n", b1);
	free(a1);
	free(b1);
}

void		test_ft_read()
{
	int			fd;
	char		buffer[100];
	char		show[100];
	ssize_t		ret;

	printf("ft_read:\n");
	printf("	[1]'open(\"main.c\", O_RDONLY)' '' '0'\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		<unistd.h>  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		<libasm.a>  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	printf("	[2]'open(\"Makefile\", O_RDONLY)' '' '50'\n");
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buffer, 50);
	printf("		<unistd.h>  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buffer, 50);
	printf("		<libasm.a>  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	printf("	[3]'open(\"dontexist\", O_RDONLY)' '' '10'\n");
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		<unistd.h>  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		<libasm.a>  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	printf("	[4]'open(\"main.c\", O_RDONLY)' 'NULL' '10'\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("		<unistd.h>  %zd\n", ret);
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("		<libasm.a>  %zd\n", ret);
	close(fd);
	printf("	[5]'42' '' '10'\n");
	ret = read(42, buffer, 10);
	printf("		<unistd.h>  %zd - %s\n", ret, strncpy(show, buffer, 10));
	ret = read(42, buffer, 10);
	printf("		<libasm.a>  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("empty_file", O_RDONLY | O_TRUNC | O_CREAT, 0777);
	printf("	[6]'open(\"empty_file\", O_RDONLY | O_TRUNC | O_CREAT, 0777)' '' '10'\n");
	ret = read(fd, buffer, 10);
	printf("		<unistd.h>  %zd - %s\n", ret, strncpy(show, buffer, 10));
	ret = read(fd, buffer, 10);
	printf("		<libasm.a>  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	remove("empty_file");
}

void		test_ft_write()
{
	int			fd;
	char		buffer[100];

	printf("\nft_write :\n");
	printf("	[1]'1' '' '0'\n");
	printf("		<unistd.h>  %zd\n", write(1, "", 0));
	printf("		<libasm.a>  %zd\n", ft_write(1, "", 0));
	printf("	[2]'1' 'toto' '4'\n");
	printf("		<unistd.h>  %zd\n", write(1, "toto", 4));
	printf("		<libasm.a>  %zd\n", ft_write(1, "toto", 4));
	printf("	[3]'1' 'toto' '2'\n");
	printf("		<unistd.h>  %zd\n", write(1, "toto", 2));
	printf("		<libasm.a>  %zd\n", ft_write(1, "toto", 2));
	printf("	[4]'1' 'toto' '40'\n");
	printf("		<unistd.h>  %zd\n", write(1, "toto", 40));
	printf("		<libasm.a>  %zd\n", ft_write(1, "toto", 40));
	printf("	[5]'1' 'NULL' '6'\n");
	printf("		<unistd.h>  %zd\n", write(1, NULL, 6));
	printf("		<libasm.a>  %zd\n", ft_write(1, NULL, 6));
	printf("	[6]'0' 'toto' '4'\n");
	printf("		<unistd.h>  %zd\n", write(0, "toto", 4));
	printf("		<libasm.a>  %zd\n", ft_write(0, "toto", 4));
	printf("	[7]'42' 'toto' '4'\n");
	printf("		<unistd.h>  %zd\n", write(42, "toto", 4));
	printf("		<libasm.a>  %zd\n", ft_write(42, "toto", 4));
	printf("	[8]'-1' 'toto' '4'\n");
	printf("		<unistd.h>  %zd\n", write(-1, "toto", 4));
	printf("		<libasm.a>  %zd\n", ft_write(-1, "toto", 4));
	fd = open("ft_write_test", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	printf("	[9]'open(\"ft_write_test\", O_WRONLY | O_TRUNC | O_CREAT)' '<whichlib.h> toto' '15'\n");
	write(fd, "<unistd.h> toto", 15);
	ft_write(fd, "<libasm.a> toto", 15);
	close(fd);
	fd = open("ft_write_test", O_RDONLY);
	read(fd, buffer, 15);
	printf("		<unistd.h>  %s\n", buffer);
	read(fd, buffer, 15);
	printf("		<libasm.a>  %s\n", buffer);
	close(fd);
	remove("ft_write_test");
}

void		test_ft_strcmp()
{
	printf("\nft_strcmp :\n");
	printf("	[1]'' ''\n");
	printf("		<string.h>  %d\n", strcmp("", ""));
	printf("		<libasm.a>  %d\n", ft_strcmp("", ""));
	printf("	[2]'toto' 'toto'\n");
	printf("		<string.h>  %d\n", strcmp("toto", "toto"));
	printf("		<libasm.a>  %d\n", ft_strcmp("toto", "toto"));
	printf("	[3]'toto' ''\n");
	printf("		<string.h>  %d\n", strcmp("toto", ""));
	printf("		<libasm.a>  %d\n", ft_strcmp("toto", ""));
	printf("	[4]'' 'toto'\n");
	printf("		<string.h> %d\n", strcmp("", "toto"));
	printf("		<libasm.a> %d\n", ft_strcmp("", "toto"));
	printf("	[5]'tototest' 'toto'\n");
	printf("		<string.h>  %d\n", strcmp("tototest", "toto"));
	printf("		<libasm.a>  %d\n", ft_strcmp("tototest", "toto"));
	printf("	[6]'bbbonjour' 'bbonjour'\n");
	printf("		<string.h> %d\n", strcmp("bbbonjour", "bbonjour"));
	printf("		<libasm.a> %d\n", ft_strcmp("bbbonjour", "bbonjour"));
/*	printf("	[7]'NULL' 'bbonjour'\n");
	printf("		<string.h> %s\n", "SEGMENTATION FAULT");
	printf("		<libasm.a> %d\n", ft_strcmp(NULL, "bbonjour"));
	printf("	[8]'NULL' 'NULL'\n");
	printf("		<string.h> %s\n", "SEGMENTATION FAULT");
	printf("		<libasm.a> %d\n", ft_strcmp(NULL, NULL));
	printf("	[9]'' 'NULL'\n");
	printf("		<string.h> %s\n", "SEGMENTATION FAULT");
	printf("		<libasm.a> %d\n", ft_strcmp("", NULL));
*/
	printf("	[10]'bonjour' 'bonjourr'\n");
	printf("		<string.h> %d\n", strcmp("bonjour", "bonjourr"));
	printf("		<libasm.a> %d\n", ft_strcmp("bonjour", "bonjourr"));
}

void		test_ft_strcpy()
{
	char	dst[100];

	printf("\nft_strcpy :\n");
	printf("	[1]\n");
	printf("		<string.h>  %s\n", strcpy(dst, ""));
	printf("		<libasm.a>  %s\n", ft_strcpy(dst, ""));
	printf("	[2]\n");
	printf("		<string.h>  %s\n", strcpy(dst, "[toto]"));
	printf("		<libasm.a>  %s\n", ft_strcpy(dst, "[toto]"));
	printf("	[3]\n");
	printf("		<string.h>  %s\n", strcpy(dst, "[0123456789]"));
	printf("		<libasm.a>  %s\n", ft_strcpy(dst, "[0123456789]"));
	printf("	[4]\n");
	printf("		<string.h>  %s\n", strcpy(dst, "[0123\n4567\0 89]"));
	printf("		<libasm.a>  %s\n", ft_strcpy(dst, "[0123\n4567\0 89]"));
}

void		test_ft_strlen()
{
	printf("ft_strlen :\n");
	printf("	[1]\n");
	printf("		<string.h>  %lu\n", strlen(""));
	printf("		<libasm.a>  %lu\n", ft_strlen(""));
	printf("	[2]\n");
	printf("		<string.h>  %lu\n", strlen("    "));
	printf("		<libasm.a>  %lu\n", ft_strlen("    "));
	printf("	[3]\n");
	printf("		<string.h>  %lu\n", strlen("0123456789"));
	printf("		<libasm.a>  %lu\n", ft_strlen("0123456789"));
	printf("	[4]\n");
	printf("		<string.h>  %lu\n", strlen("toto\n42"));
	printf("		<libasm.a>  %lu\n", ft_strlen("toto\n42"));
	printf("	[5]\n");
	printf("		<string.h>  %lu\n", strlen("toto\0 42"));
	printf("		<libasm.a>  %lu\n", ft_strlen("toto\0 42"));
}

int			main(int argc, char *argv[])
{
	if (argc == 2 && !strcmp(argv[1], "ft_strlen"))
		test_ft_strlen();
	else if (argc == 2 && !strcmp(argv[1], "ft_strcpy"))
		test_ft_strcpy();
	else if (argc == 2 && !strcmp(argv[1], "ft_strcmp"))
		test_ft_strcmp();
	else if (argc == 2 && !strcmp(argv[1], "ft_write"))
		test_ft_write();
	else if (argc == 2 && !strcmp(argv[1], "ft_read"))
		test_ft_read();
	else if (argc == 2 && !strcmp(argv[1], "ft_strdup"))
		test_ft_strdup();
	else
	{
		test_ft_strlen();
		test_ft_strcpy();
		test_ft_strcmp();
		test_ft_write();
		test_ft_read();
		test_ft_strdup();
	}/*
	write(1, "\n\nLeaks:\n", 9);
	system("leaks test");*/
	return (0);
}