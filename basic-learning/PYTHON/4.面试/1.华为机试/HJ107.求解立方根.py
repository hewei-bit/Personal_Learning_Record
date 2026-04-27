def fun(guess: float, x: float):
    if abs(guess * guess * guess - x) < 0.0000001:
        return guess
    else:
        return fun((x / guess / guess + 2 * guess) / 3, x)


if __name__ == '__main__':
    n = int(input())
    guess = 1.0
    print("%.1f" % fun(guess, n))
