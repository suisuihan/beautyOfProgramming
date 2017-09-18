# 1.1 让 CPU 占用率曲线听你指挥

## 问题

控制占有率曲线，即让 CPU 在"忙/闲"中按不同比例来回切换。那么有几个问题：

1. 多核怎么办？
2. “忙/闲” 精度多少？
3. CPU 不是只跑这一个程序，怎么计算自己该跑多久？

__吐个槽，书里代码错误真多啊。。。__

## 解决思路
* 多核问题：将进程/线程绑定在某个 CPU 上，可以在一定程度上控制单个CPU的使用率。我简单的绑定到 CPU2 上了（mask 为 0x04）

* “忙/闲”精度：跑多长时间，休息多长时间？
    1. “忙”可以让 cpu 跑个 while 循环，
	2. “忙”多久呢？可以用 GetTickCount() 来计算；“闲”可以用Sleep(idleTime)执行；
	3. CPU又不是你自己用，怎么实时计算呢？可以用PerformanceCounter 来获取。

### 代码说明

* [solution2.cpp](https://github.com/suisuihan/beautyOfProgramming/blob/master/1.1%E8%AE%A9CPU%E5%8D%A0%E7%94%A8%E7%8E%87%E6%9B%B2%E7%BA%BF%E5%90%AC%E4%BD%A0%E6%8C%87%E6%8C%A5/solution2.cpp) 简单的跑 10ms sleep 10ms，效果如下：    
![solution2 的CPU曲线效果](https://github.com/suisuihan/beautyOfProgramming/blob/master/1.1%E8%AE%A9CPU%E5%8D%A0%E7%94%A8%E7%8E%87%E6%9B%B2%E7%BA%BF%E5%90%AC%E4%BD%A0%E6%8C%87%E6%8C%A5/solution2.png)

* [solution3.py](https://github.com/suisuihan/beautyOfProgramming/blob/master/1.1%E8%AE%A9CPU%E5%8D%A0%E7%94%A8%E7%8E%87%E6%9B%B2%E7%BA%BF%E5%90%AC%E4%BD%A0%E6%8C%87%E6%8C%A5/solution3.py) __可以指定cpu（单核）使用率比例的代码。__原理就是绑定自己在某个CPU上，然后不断获取当前核的CPU使用率，高则sleep。测试过程中发现sleep(0.01)的话会导致cpu使用率上不去，猜测为当代cpu更牛逼，频率更高，进程/线程调度时间消耗更小。很惭愧没有用c++实现，CLI实在是太难搞明白了……    
![solution3 的 CPU 曲线效果](https://github.com/suisuihan/beautyOfProgramming/blob/master/1.1%E8%AE%A9CPU%E5%8D%A0%E7%94%A8%E7%8E%87%E6%9B%B2%E7%BA%BF%E5%90%AC%E4%BD%A0%E6%8C%87%E6%8C%A5/solution3.PNG)

* [solution4.cpp](https://github.com/suisuihan/beautyOfProgramming/blob/master/1.1%E8%AE%A9CPU%E5%8D%A0%E7%94%A8%E7%8E%87%E6%9B%B2%E7%BA%BF%E5%90%AC%E4%BD%A0%E6%8C%87%E6%8C%A5/solution4.cpp) 正弦曲线。正弦曲线求值公式已经忘了……基本套路就是将一条正弦曲线0-2π平均分配为200份，每份时间片为300。每个时间片内如何分配“忙/闲”比例呢？这就是第一个for循环要做的事情：计算每个时间片内工作的时间，时间片长度*振幅。第二个for循环执行。注意：绑定单核。    
![solution4效果](https://github.com/suisuihan/beautyOfProgramming/blob/master/1.1%E8%AE%A9CPU%E5%8D%A0%E7%94%A8%E7%8E%87%E6%9B%B2%E7%BA%BF%E5%90%AC%E4%BD%A0%E6%8C%87%E6%8C%A5/solution4.PNG)