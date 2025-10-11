1.Linux安装



本文档实现wsl安装linux虚拟机

1.打开控制面板，选择程序和功能，打开启用或关闭Windows功能，勾选适用于Linux的Windows子系统.![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759906627585-2ab5cbd5-18cf-455a-9d7c-27eec67e0894.png)

然后重新启动Windows.

2.重启后打开power shell

输入wsl --set-default-version 2

再输入wsl --update

再输入wsl --shutdown

3.接着,在微软应用商店搜索Unbuntu22.04,下载.

下载完毕后,打开Ubuntu22.04,根据所给提示输入用户名和密码（注意：输入密码时不会显示出来，所以需要自己记住）

4.完成后,在power shell输入wsl -l -v,如果显示了对应版本的Ubuntu，则说明安装成功

5.进行分盘,输入wsl --export Ubuntu-22.04 "D:\WSL\Ubuntu-22.04\backup.tar"

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759907174333-75ebd26b-89de-4235-90e8-cab54d5d2d7d.png)

6.注销当前分发版,输入wsl --unregister Ubuntu-22.04

再重新下载Ubuntu到新的目录,输入wsl --import Ubuntu-22.04 "D:\WSL\Ubuntu" "D:\WSL\Ubuntu-22.04\backup.tar" --version 2

