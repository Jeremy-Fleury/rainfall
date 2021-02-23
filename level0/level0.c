/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 08:23:30 by jfleury           #+#    #+#             */
/*   Updated: 2021/02/22 21:11:00 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define _GNU_SOURCE

int main(int ac, char **av)
{
    /*
    **  0x08048ed4 <+20>:   call    0x8049710 <atoi>
    **  0x08048ed9 <+25>:   cmp     $0x1a7,%eax --> 0x1a7: 423
    **  0x08048ede <+30>:   jne     0x8048f58 <main+152>
    */
    if (atoi(av[1]) == 423)
    {
        /*
        **  0x08048ee0 <+32>:   movl    $0x80c5348,(%esp) --> 0x80c5348: "/bin/sh"
        **  0x08048ee7 <+39>:   call    0x8050bf0 <strdup>
        **  0x08048eec <+44>:   mov     %eax,0x10(%esp)
        **  0x08048ef0 <+48>:	movl    $0x0,0x14(%esp)
        */
        char *arg[2];
        arg[0] = strdup("/bin/sh");
        arg[1] = 0;
        /*
        **  0x08048ef8 <+56>:   call    0x8054680 <getegid>
        **  0x08048efd <+61>:   mov     %eax,0x1c(%esp)
        */
        gid_t gid = getegid();
        /*
        **  0x08048f01 <+65>:   call    0x8054670 <geteuid>
        **  0x08048f06 <+70>:   mov     %eax,0x18(%esp)
        */
        uid_t uid = geteuid();
        /*
        **  0x08048f0a <+74>:   mov     0x1c(%esp),%eax
        **  0x08048f0e <+78>:   mov     %eax,0x8(%esp)
        **  0x08048f12 <+82>:   mov     0x1c(%esp),%eax
        **  0x08048f16 <+86>:   mov     %eax,0x4(%esp)
        **  0x08048f1a <+90>:   mov     0x1c(%esp),%eax
        **  0x08048f1e <+94>:   mov     %eax,(%esp)
        **  0x08048f21 <+97>:   call    0x8054700 <setresgid>
        */
        setresgid(gid, gid, gid);
        /*
        **  0x08048f26 <+102>:  mov     0x18(%esp),%eax
        **  0x08048f2a <+106>:  mov     %eax,0x8(%esp)
        **  0x08048f2e <+110>:  mov     0x18(%esp),%eax
        **  0x08048f32 <+114>:  mov     %eax,0x4(%esp)
        **  0x08048f36 <+118>:  mov     0x18(%esp),%eax
        **  0x08048f3a <+122>:  mov     %eax,(%esp)
        **  0x08048f3d <+125>:  call    0x8054690 <setresuid>
        */
        setresuid(uid, uid, uid);
        /*
        **  0x08048f42 <+130>:	lea     0x10(%esp),%eax
        **  0x08048f46 <+134>:	mov     %eax,0x4(%esp)
        **  0x08048f4a <+138>:	movl    $0x80c5348,(%esp) --> 0x80c5348: "/bin/sh"
        **  0x08048f51 <+145>:	call    0x8054640 <execv>
        */
        execv("/bin/sh", arg);
        /*
        **  0x08048f56 <+150>:  jmp     0x8048f80 <main+192>
        */
    }
    else
    {
        /*
        **  0x08048f58 <+152>:  mov     0x80ee170,%eax
        **  0x08048f5d <+157>:	mov     %eax,%edx
        **  0x08048f5f <+159>:	mov     $0x80c5350,%eax --> 0x80c5350: "No !\n"
        **  0x08048f64 <+164>:	mov     %edx,0xc(%esp)q
        **  0x08048f68 <+168>:	movl    $0x5,0x8(%esp)
        **  0x08048f70 <+176>:	movl    $0x1,0x4(%esp)
        **  0x08048f78 <+184>:	mov     %eax,(%esp)
        **  0x08048f7b <+187>:	call    0x804a230 <fwrite>
        */
        fwrite("No !\n", 1, 5, 2);
    }
    /*
    **  0x08048f80 <+192>:  mov     $0x0,%eax
    */
    return (0);
    /*
    **  0x08048f85 <+197>:  leave
    **  0x08048f86 <+198>:  ret
    */
}