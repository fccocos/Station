## 套接字选项详细说明

### `getsockopt`和`setsockopt`函数

#### 函数原型

```c
#include <sys/types.h>
#include <sys/socket.h>

int getsockopt(int s, int level, int optname, void* optval, socklen_t *optlen);
int setsockopt(int s, int level, int optname, const void* optval, socklen_t optlen);
```

#### 参数说明

- `s`
  - 需要设置或获取套接字选项的套接字
- `level`
  - 设置套接字选项等级，`SOL_SOCKET`, `IPPROTO_IP`, `IPPROTO_TCP`
- `optname`
  - 套接字选项的名字
- `optval`
  - 套接字选项的值
- `optlen`
  - 套接字选项的长度

### 套接字等级
#### 套接字等级说明
##### `SOL_SOCKET`通用套接字
用于获取或设置通用的一些参数，例如接收或发送缓冲区的大小，地址重用等
##### `IPPROTO_IP` IP选项
用于获取或设置IP层参数，如IP_HDRINCL表示在数据中包含IP头部数据、IP_TOS表示服务器类型、IP_TTL表示生存周期
##### `IPPROTO_TCP`TCP选项
用于获取或设置TCP层参数，如TCP_MAXRT对最大重传时间进行操作，TCP_MAXSEG对最大分片大小进行操作，TCP_KEEPALIVE对保持连接时间进行操作

|level|optname|含义|optval|set|get|
|-----|-------|----|------|---|---|
|SOL_SOCKET|SO_BROADCAST|设置广播|广播套接字描述符|Y|Y|
||SO_DEBUG|调试|1表示打开调试，0表示关闭调试，默认是关闭调试，通过命令来trpt查看|Y|Y|
||SO_DONTROUTE|发送的数据分组不通过路由机制,即网络数据不通过网关发送，只能发送到直接相连的主机或一个子网内的主机。|1表示打开，0表示关闭, 默认关闭|Y|Y|
||SO_ERROR|当套接字发生错误时，内核变量so_error会设置为UNIX_Exxx的错误值|1表示打开，0表示关闭, 默认关闭|N|Y|
||SO_KEEPALIVE|TCP保持连接,主要用于可能长时间无数据响应的TCP连接。当设置此选项后，如果2小时没有用数据通信时，TCP会自动发送一个活动探测数据报文，对方必须对此报文进行响应。|1表示打开，0表示关闭, 默认关闭|Y|Y|
||SO_LINGER|设置或获取套接字关闭时是否阻塞套接字关闭函数|1表示打开，0表示关闭, 默认关闭|Y|Y|
||SO_OOBINLINE|将外带数据放入正常数据流，在普通数据流中接收外带数据。这样做会增加带宽|1表示打开，0表示关闭, 默认关闭|Y|Y|
||SO_RCVBUF|设置接收缓冲区的大小
||SO_SNDBUF|
||SO_RCVLOWAT|
||SO_SNDLOWAT|
||SO_RCVTIMEO|
||SO_SNDTIMEO|
||SO_REUSEADDR|
||SO_TYPE|
||SO_BSDCOMPAT|
|IPPROTO_IP|IP_HDRINCL|
||IP_OPTIONS|
||IP_RECVDSTADDR|
||IP_RECVIF|
||IP_TOS|
||IP_TTL|
||IP_MULTICAST_IF|
||IP_MULTICAST_TTL|
||IP_MULTICAST_LOOP|
||IP_ADD_MEMBERSHIP|
||IP_DROP_MEMBERSHIP|
|IPPROTO_TCP|TCP_KEEPALIVE|
||TCP_MAXRT|
||TCP_MAXSEG|
||TCP_NODELAY|
||TCP_PSTEDURG|

#### `SOL_SOCKET`通用套接字


#### `IPPROTO_IP`IP选项

#### `IPPROTO_TCP`TCP选项



