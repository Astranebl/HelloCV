1.安装完VS Code后，在扩展中下载WSL,C++,Chinese

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759907574330-563cb049-06a3-4306-a733-69f346557742.png)

2.在终端上输入

sudo apt update

sudo apt install build-essential gdb

然后再输入gcc --version

如果出现版本号则说明安装成功

3.创建一个项目文件,然后在终端选项中选择配置默认生成任务,再选择运行生成任务,就能发现.vscode的文件夹,里面有task.json 

然后在终端栏输入./（文件名）就能执行代码了



