alien_0={'color':'green','point':5}
#键：值
print(alien_0['color'])
print(alien_0['point'])

new_points = alien_0['point']
print('you just earned ' + str(new_points) + ' points!')

print(alien_0)
alien_0['x_position'] = 0
alien_0['y_position'] = 25
print(alien_0)

#del alien_0['point']
#point(alien_0)

message = {'first_name':'何','last_name':'蔚','age':23,'city':'广州'}

favorite_number = {'David':1,
                   'Rashford':10,
                   'Lukaku':9
                   ,'Hewei':9}
for k,v in favorite_number.items():
    print('\nname:' + k)
    print('number:' + str(v))
print('\n')
for k in favorite_number.keys():
    print(k)
print('\n')
for k in sorted(favorite_number.keys()):
    print(k)
print('\n')
for v in set(favorite_number.values()):
    print(v)
print('\n')


alien0 = {'color':'green','points':5}
alien1 = {'color':'yellow','points':15}
alien2 = {'color':'red','points':10}
aliens = []
for an in  range(30):
    new_alien = {'color':'green','points':5,'speed':'slow'}
    aliens.append(new_alien)

for alien in aliens[0:3]:
    if alien['color'] == 'green':
        alien['color']= 'yellow'
        alien['speed'] = 'medium'
        alien['points'] = 10
        
for alien in aliens[:5]:
    print(alien)
print(...)

pizza = {'crust':'thick',
         'toppings':['mushrooms','extra cheese'],}
print ('You ordered a '+pizza['crust']+'-crust pizza'+'with the following toppings:')
for topping in pizza['toppings']:
    print('\t'+topping)

favorite_places = {
    'mata':['guangzhou','shanghai','beijing'],
    'uzi':['zhangzhou','quanzhou','xiamen']
    }
for a,b in favorite_places.items():
    print('\nName:'+a.title())
    print('\nHis favorite places are:')
    for c in b:
        print('\t'+c.title())
        
