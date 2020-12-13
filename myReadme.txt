1、下载后得到zip压缩包.

2、解压到自己想要安装到的目录，本人解压到的是D:\Environment\mysql-5.7.19

3、添加环境变量：我的电脑->属性->高级->环境变量

选择PATH,在其后面添加: 你的mysql 安装文件下面的bin文件夹
4、新建并编辑 my.ini 文件 ,注意替换路径位置

[mysqld]
basedir=D:\Program Files\mysql-5.7\
datadir=D:\Program Files\mysql-5.7\data\
port=3306
skip-grant-tables

注意:为了保险起见,先启动管理员模式下的CMD,然后输入 sc delete mysql ,删除mysql服务
5、启动管理员模式下的CMD，并将路径切换至mysql下的bin目录，然后输入mysqld –install (安装mysql)

6、再输入 mysqld --initialize-insecure --user=mysql 初始化数据文件
7、然后再次启动mysql 然后用命令 mysql –u root –p 进入mysql管理界面（密码可为空）

8、进入界面后更改root密码

update mysql.user set authentication_string=password('123456') where user='root' and Host = 'localhost';

9、刷新权限

flush privileges

10、修改 my.ini文件删除最后一句skip-grant-tables

11、重启mysql即可正常使用

net stop mysql --关闭数据库
net start mysql --开启数据库