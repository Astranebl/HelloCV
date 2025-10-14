apt:

sudo apt update可以更新软件包列表![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1760448762277-2da02dfe-87b3-4c4d-8730-93c469556a76.png)

~install git就可以安装git软件

~remove git就可以卸载git软件

apt search git就可以搜索git软件



snap:

sudo snap install code --classic可以安装snap软件(如VSCode)

snap list可以查看已安装的snap软件



ls -la可以列出文件和目录（包括隐藏目录）![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1760448911759-9bfb6c45-e928-47bf-896f-7a749661c336.png)

touch example.txt可以创建名为example的文本

mkdir newdir可以创建新目录newdir

cp file1.txt file2.txt复制文件file1到file2

cp -r dir1/ dir2/递归复制目录dir1到dir2

mv file1.txt file2.txt重命名file1为file2

mv file.txt /目标目录   可将file移动到目标目录

rm file.txt删除file

rm -r dir/递归删除dir目录





权限:

ls -l file.txt可查看file的权限![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1760449200113-9f9e4bda-69af-4c38-8b02-5a214c3d01cf.png)

修改权限(数字方式)

如chmod 755 readme.txt可以让所有者可读写执行，其他人可读执行

（符号方式）

chmod u+x readme.txt可以给所有者添加执行权限

chmod go-w readme.txt可以一处组和其他人的写权限

(4为读，2为写，1为执行)





进程控制命令:

ps aux可查看当前用户进程![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1760449410787-d5975e2c-7ea4-465a-b1fd-71f1913de301.png)

pstree可查看所有进程(树状结构)

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1760449434910-e7576706-8cb1-41f0-bf24-67162f2a98ca.png)

top可实时查看系统进程

kill 1234可正常结束进程ID 1234

kill -9 1234则为强制结束进程

sudo systemctl start nginx为启动系统服务

                         stop              停止

                         restart           重启

                         status            查看服务状态

导航命令则为cd

后面可以加绝对路径，相对路径

加..则为回到上级目录

~为返回家目录

pwd可查看当前目录





vim readme.txt可启动vim编辑器对readme.txt进行编辑

内部命令:

i:进入插入模式

ESC:返回普通模式

:w:保存文件

:q:退出Vim

:wq:保存并退出  
:q!:强制退出不保存

dd:删除当前行

yy:复制当前行

p:粘贴

u:撤销

/text:搜索"text"



grep "something" readme.txt可在文件中搜索内容

grep -r "st" src/可递归搜索目录

grep -i "st" readme.txt忽略大小写搜索



awk

ls -l | awk '{print $9}' 可打印文件名列



sed 's/old/new/g' file.txt 可替换所有old为new

sed -i 's/12/123/g' script.sh可直接修改文件

