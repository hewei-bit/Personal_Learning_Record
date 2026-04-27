pizzas = ['乐凯撒','千樽','尊宝','比格','好伦哥','新出炉','米斯特','必胜客','萨克斯','米斯特']
for pizza in pizzas:
    print('我喜欢'+pizza+'披萨！！！')
print('但是我最喜欢'+pizzas[0]+'披萨！！！')
friend_pizzas = pizzas[:]
pizzas.append('盗版必胜客')
friend_pizzas.append('还是盗版必胜客')
print('我喜欢'+pizzas[-1]+'披萨！！！')
print('我的朋友喜欢'+friend_pizzas[-1]+'披萨！！！')
