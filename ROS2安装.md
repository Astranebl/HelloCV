**<font style="color:#DF2A3F;">1  </font>****<u><font style="color:#DF2A3F;">思路</font></u>**

1）由于ROS2本身<u>不是一个操作系统，而是可以安装在现在已有的操作系统（Linux、Windows、Mac）上的软件库和工具集</u>，结合我们的需求，我选择使用**在Linux虚拟机安装ROS2**.

2）ROS2可以通过**手动安装**和**安装工具安装**两种方式来安装，考虑到我们是初学者，所以我选择**使用安装工具安装**.

3）使用安装工具安装可以分为三步：

1、更新，即 sudo apt update

2、调用安装工具，即 wget http://fishros.com/install -O fishros && bash fishros

3、测试命令（要记得打开新终端，在上下文才能生效）：ros2



**<font style="color:#DF2A3F;">2  </font>****<u><font style="color:#DF2A3F;">实现步骤</font></u>**

1）打开虚拟机，进入终端

2）输入 sudo apt update

3）输入wget http://fishros.com/install -O fishros && bash fishros调用工具

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759803381780-e597ac4a-48d4-4b54-98dc-3749011b6f31.png)

选择[1]



![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759803465043-13f75b26-e5d6-4b97-9203-d73818f907fa.png)

选择[2]![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759805317846-89d824bd-59c6-4311-a8fd-58987c38e11a.png)

选择完版本后就可以等待安装了.

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759806109951-ac7dba57-378f-4a5e-8aa9-6f5222cf396f.png)

4)检测是否安装成功

输入ros2，若出现

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759806354172-fb13f72c-e1ca-4e66-8ae2-85ace1808fcf.png)

则说明安装成功

查看一下ros2的路径

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759806455819-bc00a152-5eb8-4659-adf4-ca3103154e34.png)

至此，ros2安装完成

