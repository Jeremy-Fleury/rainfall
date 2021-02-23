# Rainfall level0

After disassembling the ./level0 binary. We have seen that by executing the binary with the password 423, we can access a shell

> $./level0 423<br/>

> $ whoami
>> level1

> $ ls -la /home/user/level1
>> dr-xr-x---+ 1 level1 level1   80 Mar  6  2016 .<br/>
>> dr-x--x--x  1 root   root    340 Sep 23  2015 ..<br/>
>> -rw-r--r--  1 level1 level1  220 Apr  3  2012 .bash_logout<br/>
>> -rw-r--r--  1 level1 level1 3530 Sep 23  2015 .bashrc<br/>
>> -rwsr-s---+ 1 level2 users  5138 Mar  6  2016 level1<br/>
>> -rw-r--r--+ 1 level1 level1   65 Sep 23  2015 .pass<br/>
>> -rw-r--r--  1 level1 level1  675 Apr  3  2012 .profile<br/>

> $ cat /home/user/level1/.pass
>> 1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a