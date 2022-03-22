import yagmail
import pandas as pd

class send_mail:
    #目前适用于163邮箱
    def __init__(self,user='********@163.com',passwd='*********'):
        self.yag = None
        self.mail_user = user
        #密码(部分邮箱为授权码)
        self.mail_pass = passwd
        #初始化用户名字和密码
        self.yag = yagmail.SMTP(user=self.mail_user, password=self.mail_pass, host='smtp.163.com')
    def messsage(self,body,file=None,who='2948561911@qq.com',title="你好"):
        subject = title
        body = body
        h1 = '<h1>HELLO,WORLD</h1>'  ##利用HTML可以实现文字格式的变化
        self.yag.send(to=who,subject=subject, contents=[body, h1, a_link])




message="XXX,sdgsdfhgfhfdhdfghdfghdfghd"
new_msg=message.replace("XXX",'xxx')
print(new_msg)  #这块是替换名字的那一部分


sd=send_mail()
fpath=r''
pv=pd.read_excel(fpath)

email=list[pv.get('邮箱')]
for i in pv.get('邮箱'):
    if(pd.isnull(i)== False):
        sd.messsage(body="hello,world")





# fpath=r'baoming.xlsx'
# pv=pd.read_excel(fpath)
#
# email=list[pv.get('邮箱')]
# for i in pv.get('邮箱'):
#     if(pd.isnull(i)== False):
#         print(i)         这块完成的是pandas提取excel中的数据
