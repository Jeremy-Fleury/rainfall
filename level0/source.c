/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 08:23:30 by jfleury           #+#    #+#             */
/*   Updated: 2021/04/19 20:58:57 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define _GNU_SOURCE

int main(int ac, char **av)
{
    if (atoi(av[1]) == 423)
    {
        char *arg[2];

        arg[0] = strdup("/bin/sh");
        arg[1] = 0;
        gid_t gid = getegid();
        uid_t uid = geteuid();
        setresgid(gid, gid, gid);
        setresuid(uid, uid, uid);
        execv("/bin/sh", arg);
    }
    else
    {
        fwrite("No !\n", 1, 5, 2);
    }
    return (0);
}