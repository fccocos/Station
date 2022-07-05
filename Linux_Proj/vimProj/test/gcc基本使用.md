# gcc的基本使用

## gcc的编译过成

1. 预编译
   预编译期间，将头文件以及各种宏进行展开和替换，其中宏包括，编译宏指令、函数宏指令、普通宏，在gcc中加`-E`来生成.i文件
   ```shell
    $gcc -o string.i -E string.h
   ```

2. 编译和优化
   编译期间，对预处理过后的.i文件编译生成.o目标文件
   ```shell
    $gcc -o string.c
   ```  

3. 汇编
  
4. 链接

```shell
gcc -o string.i -E string.h 
gcc -c string.c # 生成.o文件
gcc -S string.c # 生成.ash汇编文件
ar -rcs libstr.a string.o # 生成static library
# 链接static library
gcc -o test main.c string.h libstr.a # 方式一，只用使用libstr.a
gcc -o test main.c string.h -lstr -L./ # 方式二，通过-l和-L来指定库文件，-l为库的名字，-L为库的路径
gcc -shared -Wl,-soname,libstr.so -o libstr.so.1.0.0 string.c #  动态库的链接是通过动态库的符号链接名来链接的，不会使用真正的动态库，-soname选项就是告诉编译器要为该动态库创建一个符号链接，如果没有用-soname选项，在编译完成后，可以使用ln -s 命令来为动态库取别名
gcc -o main.c string.h -lstr -L./  # 链接动态库
```
## 动态库的加载

1. 首先在Linux系统中，编译默认先从/lib,/usr/lib, /usr/local/lib中查找动态库
2. 其在才会在-L指定的目录中查找动态库

## 如何让编译器加载自定义的动态库

第一种：设置编译的动态库路径环境变量 `LD_PATH=your\custom\so\name\path; $LD_PATH` `export $LD_PATH`# 使用source 命令更新/etc/profile或/etc/bashrc或~/.brahrc
第二种：将动态库的路径名加入到\etc\ld.so.conf中, 使用该种方法时需要注意的是，编译加载动态库不是使用该配置做的，而是系统会为所有的动态库路径生成一个缓存ld.conf.cache,编译器只会在这个缓存中寻找动态库的路径。因此我们需要一个命令来更新这个缓存，从而将写入到ld.conf.d中的动态库路径加载到缓存中，这个命令就是ldconfig。因此在配置完后，需要执行一下ldconfig命令。
第三种：在使用编译指令时，加-l和-L选项
第四种：将动态库直接加入到编译的默认加载路径中，此种方法与第二种方法类似，也需要执行ldconfig命令




