说明下列代码中每次执行write()后，输出文件的内容是什么?为什么?
```c
/* fd1 的值为3, 理由：最小未使用原则，即open默认使用值最小且未使用的文件描述符*/
fd1 = open(file, 0_RDWR|0_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);

/* fd2 的值为4, 理由同上*/
fd2=dup(fd1);

/* fd3 的值为0, 理由：由于file文件已经创建并打开，所以open调用打开已经打开的文件会返回0*/
fd3=open(file,0_RDWR);

/*file中的内容为: Hello*/
write(fd1,"Hello,",6);

/*file中的内容为: Helloworld, 理由：由于fd1和fd2共享同一个打开文件句柄中的偏移量，所以会在上一次写入后的当前位置开始写入*/
write(fd2,"world",6);

/*file中的文件位置指针指向文件的开头，即fd2和fd1所指向文件中的文件位置指针也指向文件的开头，理由同上*/
1seek(fd2,0,SEEK_SET);

/*file中的内容为: HELLO,. 理由：由于上一行代码的设置，所以调用write系统调用的时候，内核会用"HELLO,"来覆盖以前的内容*/
write(fd1,"HELLO,",6);

/*会在终端输入"Gidday", 理由：由于fd3=0,而0指向标准输入终端，所以字符串"Gidday"会写入到标准输入终端上*/
write(fd3,"Gidday",6)
```