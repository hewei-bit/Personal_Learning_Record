users = ['admin','Eric','david','lily','drink']
yourname = input('please input your name:\n')
if yourname in users:
    if yourname == 'admin':
        print('Hello admin,would you like to see status report!')
    else:
        print('Hello '+yourname+',thank you for logging again!')
else:
    print('We need other users!!!')
    
