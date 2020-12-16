#!c:\python27\python
# -*- coding: UTF-8 -*-

# HTTP 头部
print "Content-Disposition: attachment; filename=\"foo.txt\"";
print
# 打开文件
fo = open("C:\\Apache24\\cgi-bin\\tmp\\python.txt", "rb")

str = fo.read();
print str

# 关闭文件
fo.close()
