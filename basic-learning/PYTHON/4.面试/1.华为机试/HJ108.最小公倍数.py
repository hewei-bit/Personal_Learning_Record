


def gcd(a:int ,b:int):
    return a if b ==0 else gcd(b,a%b)

def lcd(a:int,b:int):
    return a*b/gcd(a,b)

if __name__ == '__main__':
    a ,b = map(int,input().strip().split())
    print(lcd(a,b))
