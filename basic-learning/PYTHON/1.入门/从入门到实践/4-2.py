for num in range(1,20):
    print(num,end = ' ')

digits_0 = list(range(1,101))
print(digits_0)
print(min(digits_0))
print(max(digits_0))
print(sum(digits_0))

digits_1 = list(range(1,21,2))
print(digits_1)

digits_3 = list(range(3,31))
for digit in digits_3:
    if digit%3 == 0:
        print(digit,end = ' ')

cubes = []
digits_4 = list(range(1,11))
for n in digits_4:
    cube = n ** 3
    cubes.append(cube)
print('\n',cubes)

print('The first three items in the list are:')
for n in cubes[:4]:
    print('\t',n,end = ' ')
print('\n')   
for n in cubes[4:7]:
    print('\t',n,end = ' ')
print('\n')  
for n in cubes[-3:]:
    print('\t',n,end = ' ')
