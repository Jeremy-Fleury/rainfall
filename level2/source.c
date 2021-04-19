/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:21:37 by jfleury           #+#    #+#             */
/*   Updated: 2021/04/19 20:58:00 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void p(void)
{
	char *str;
	void *addr;

	fflush(stdout);
	gets(str);
	if (((unsigned int)addr & 0xb0000000) == 0xb0000000)
	{
		printf("(%p)\n", addr);
		exit(1);
	}
	puts(str);
	strdup(str);
}

int main(void)
{
	p();
	return 0;
}