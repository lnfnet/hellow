#!C:\Users\lnf\AppData\Local\Programs\Python\Python37\python3
# -*- coding: UTF-8 -*-

import os

print ("Content-type: text/html")
print ()
print ("<meta charset=\"gb2312\">")
print ("<b>环境变量</b><br>")
print ("<ul>")
for key in os.environ.keys():
    print ("<li><span style='color:green'>%30s </span> : %s </li>" % (key,os.environ[key]))
print ("</ul>")
