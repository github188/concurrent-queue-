用posix的多线程和自旋锁根据http://www.cs.rochester.edu/research/synchronization/pseudocode/queues.html#tlq算法实现了一个Two-Lock Concurrent Queue。

同时根据用C语言实现了CAS锁根据Non-Blocking Concurrent Queue Algorithm算法实现了
一个非阻塞的并发队列。

编译：
1. 如果是想测试two blocks 算法实现的concurrent queue, 直接在当前目录下
＃make 
然后
＃./test
即可运行，这里面有4个线程，两个线程竞争去入队，两个线程竞争出队伍

2. 如果想测试non blocking 算法，需要修改Makefile文件
为：
 $(CC)  -o  test $(CFLAGS) test.c twolock.c -lpthread

3.其中twolock为two locks algorith实现的头文件
       nonblock为none blocking算法，我们自己定义了CAS锁
4. 通过条件编译实现这两种锁的分别测试
