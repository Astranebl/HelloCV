1.在一个合适的地方创建一个空目录

比如mkdir gitlearning,创建一个gitlearning文件夹

然后cd gitlearning,进入文件夹

输入git init,把这个目录变成Git可管理的仓库.

用ls -ah命令就能看到目录里多了个.git目录

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759914502912-f012b649-4849-49af-af81-97cf04c29d7a.png)

2.对readme.txt进行编辑

输入vi readme.txt进入文本,输入I或i后出现insert标识就说明可以进行编辑

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759931774092-b1f563e7-3fb1-483d-9ba0-278f745c1258.png)

编辑完毕后用ESC退出编辑,但是还没有完,还需要输入:wq表示保存并退出

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759931898526-78a5387e-b0e3-4025-9e61-79dc5bdc532d.png)

如果出现这条信息说明此文本被设置为只读模式,那么在原指令后加!强制一下就好了.

如果要添加权限,只需要退出后输入chmod <u/g/o> +w readme.txt就行了

3.把刚编写好的readme.txt添加到仓库

输入git add readme.txt,如果没有任何显示则说明没问题

接着输入git commit -m "wrote a readme file"(-m后面输入的是本次提交的说明，可以是任何内容)

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759932788977-b30ff909-3350-4d22-bf6b-ab6e32de7e3e.png)

git commit成功后,1 file changed说明有一个文件被改动;1 insertion说明插入了一行内容

注:添加文件分为add和commit两步，是因为commit可以一次性提交多个文件,所以可以多次add.









SSH密钥

1.输入cd回到主用户的目录

输入ssh-keygen -t rsa -C "你的邮箱"来创建SSH Key

如果不需要值,那就一路回车

输入ls -ah查看是否有.ssh目录

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759972940436-dd033abc-bb29-4f89-90ba-c77b11a5913d.png)

.ssh目录下应有两个文件,分别为![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759972968451-1fa6d7eb-5e83-4a5f-aa50-26bb2511cae7.png)

这两个就是SSH Key的密钥对id_rsa是私钥;id_rsa.pub是公钥

2.登录GitHub

来到如下界面

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759973065286-7f9e9012-2db5-4304-9258-8070bd0439c5.png)

点击New SSH Key

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1759973101886-b3b1346e-4124-4c5b-ae88-670534a7919a.png)

在Key中复制id_rsa.pub文件的内容,就可以添加密钥了

