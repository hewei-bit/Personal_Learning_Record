'''
dayfactor = eval(input("输入你的力量"))
up = pow(1+dayfactor,365)
down = pow(1-dayfactor,365)
print("一年后up={:.2f}，down={:.2f}". format(up,down))
'''

'''
dayup = 1.0
dayfactor = eval(input("输入你的力量"))
for i in range(365):
    if i % 7 in [6,0]:
        dayup = dayup*(1 - dayfactor)
    else:
        dayup = dayup*(1 + dayfactor)
print("一年后up={:.2f}". format(dayup))   
'''

def dayUP(df):
    dayup = 1
    for i in range(365):
        if i % 7 in [6,0]:
            dayup = dayup*(1 - 0.01)
        else:
            dayup = dayup*(1 + df)
    return dayup
dayfactor = 0.01
while dayUP(dayfactor) < 37.78:
    dayfactor += 0.001
print("工作日需要努力的参数{:.3f}". format(dayfactor))

















        
