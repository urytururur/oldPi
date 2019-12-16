from ftplib import FTP

#domain name or server ip:
ftp = FTP('155.4.151.137')
ftp.login(user='ftpAdmin', passwd = 'urytururur')

ftp.cwd('/whyfix/')