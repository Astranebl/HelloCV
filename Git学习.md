三大区域分别为工作区，暂缓区，仓库

工作区存放我们当前能直接看到和编辑的文件

暂存区是一个中间区域，临时存放我们打算下次提交的改动

仓库存放所有已提交的版本记录



git clone是将远程仓库完整下载到本地，并自动设置远程地址origin

输入git clone git@github.com:用户名/my-project.git后，

当前目录下会生成一个 'my-awesome-project' 文件夹



想同步最新的代码就输入

git pull origin main



想同步最新的代码

git pull origin main

注意：如果是第一次推送的话,

需要使用 -u 参数建立追踪

git push -u origin main



git add与git commit在"Git配置中"有介绍



git status能查看当前状态

比如我的库目前是![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1760447895299-1a32589c-3d47-4d91-8b2c-ec05ce248c3e.png)



git log能够查看历史

![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1760447936630-43a4855b-fe43-4ad7-b742-4e7fb1a16873.png)



git diff能查看工作区和暂存区的差异（尚未 git add 的改动）

git  diff --staged能查看暂存区和最新一次提交的差异（已经 git add 的改动）



git branch能查看所有本地分支（当前分支前有 * 号）

git branch feature-login创建一个新分支 feature-login

              （-d）可以删除分支

        （-D）可以强制删除分支

切换到 feature-login 分支

git checkout feature-login



查看远程仓库地址（通常名为 origin）

git remote -v



软回退 - 只回退提交记录，保留工作区和暂存区的改动

git reset --soft HEAD~1



混合回退（默认） - 回退提交和暂存区，但保留工作区改动

git reset HEAD~1

git reset --mixed HEAD~1



硬回退（危险） - 彻底回退，丢弃提交、暂存区和工作区的所有改动

git reset --hard HEAD~1



撤销指定的某次提交（例如输入为 123）

git revert 123

这会打开编辑器让我们输入新的提交信息，然后创建一个抵消 abc123 改动的提交



把当前的修改暂存起来

git stash



获取 origin 远程的所有最新分支和提交

git fetch origin



与git pull 的区别：

git pull = git fetch + git merge

git fetch 更安全，让你可以先看看别人做了什么再决定是否合并



查看详细的操作历史

git reflog![](https://cdn.nlark.com/yuque/0/2025/png/61411083/1760448293047-97f431c8-9ef1-475b-81bd-ebd1683dc8ef.png)



