[io多路复用](https://www.cnblogs.com/aspirant/p/9166944.html)
```
A. epoll 和 select 都是 I/O 多路复用的技术，都可以实现同时监听多个 I/O 事件的状态。

B. epoll 相比 select 效率更高，主要是基于其操作系统支持的I/O事件通知机制，而 select 是基于轮询机制。

C. epoll 支持水平触发和边沿触发两种模式。

D. select 能并行支持 I/O 比较小，且无法修改。

出题人：阿里巴巴出题专家：寈峰／阿里技术专家
参考答案：A，B，C
【延伸】那在高并发的访问下，epoll使用那一种触发方式要高效些？当使用边缘触发的时候要注意些什么东西？
```