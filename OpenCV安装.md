1.首先进行必要的更新工作

输入sudo apt-get update

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759966796317-4d163969-dd6a-4e06-ac70-64b355cd38c9.png)

2.接着,安装opencv

输入sudo apt-get install libopencv-dev

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759966886835-8dc7d290-4cd9-4554-aff0-96638a96755e.png)

(因为我已经安装过了，所以显示这个)

3.输入code进入vsc

写好所要用的头文件，

我要实现图片转灰度图，

用如下代码

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759968934295-4d53693f-332b-40f4-ae28-b4e2a5456056.png)

要运行代码,需要在task.json中配置opencv,配置默认生成任务后,在终端输入

g++ -o test (文件名) `pkg-config --cflags --libs opencv4`

如果头文件没有标红,则说明配置成功了

接着在终端输入./test 图片文件名,

即可运行代码

如：

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759968819497-08403386-1976-4305-86c8-279164ed1112.png)

