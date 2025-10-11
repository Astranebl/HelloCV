# HelloCV

此项目结构一共有两个branch,分别为main和master

README在main下

OpenCV安装,Git配置,VS Code开发环境配置,Linux相关,ROS2安装均在master下


环境配置

1.在Github中新建仓库,取名为HelloCV

2.在本地配置Git详细可参考Git配置文件

3.SSH连接Github

1)输入cd回到主用户的目录

输入ssh-keygen -t rsa -C "你的邮箱"来创建SSH Key

如果不需要值,那就一路回车

输入ls -ah查看是否有.ssh目录

.ssh目录下应有两个文件,分别为

这两个就是SSH Key的密钥对id_rsa是私钥;id_rsa.pub是公钥

2)登录GitHub

来到New SSH Key界面

在Key中复制id_rsa.pub文件的内容,就可以添加密钥了

3)在终端中输入

git add remote origin git@github.com:github用户名/仓库名.git

git push -u origin master

即可把本地库所有内容推送到远程库上

使用方式

在完成上诉操作后,我们后续就可以接着git push origin master来上传后续文件
