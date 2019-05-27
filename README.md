# keyStrikeHook
This program uses a compromising approach to solve mechanical keyboards' continuous strike problem on windows.
## Usage
Download the main file and compile it using g++ or create a vs-project for the code and build it.

## Note
- Remember to close the anti-virus software or add the `.exe` file to its white-list, or there may be problems. 
- The code will hide automatically when running, you can check it in Taskmanager. 

## Run automatically 
There are many ways to set a routing runs at start-up. One approach on Windows7 is 
1. win+R
2. enter `regedit`
3. find `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run`
4. right click, choose `New--String`
5. rename it whatever you like and set the value as the program path.


# keyStrikHook
用软件解决机械键盘连击的问题，有一定的瑕疵，如长按退格键删除大段文字时光标移动略慢。

## 使用方法
下载 .cpp 文件，用g++或者visual studio编译即可使用。

## 注意事项
- 记得要关闭杀毒软件，否则软件可能会出莫名奇妙的问题。
- 腾讯游戏等软件会对钩子函数进行检测并且屏蔽，所以有的时候该程序会失效。
- 程序在main函数里自动隐藏了console窗口，可以在任务管理器里面查看。

## 添加开机启动
有很多方法可以设置开机启动，这里介绍一种。
1. 开始-运行-输入regedit
2. 找到 `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run`
3. 右键，新建字符串值，随意设置一个名字，值为程序的路径
