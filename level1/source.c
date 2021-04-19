/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:16:37 by jfleury           #+#    #+#             */
/*   Updated: 2021/02/24 21:28:10 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void run(void)
{
	fwrite("Good... Wait what?\n", 1, 19, stdout);
	system("/bin/sh");
}

int main(void)
{
	char str[76];

	gets(str);
	return 0;
}