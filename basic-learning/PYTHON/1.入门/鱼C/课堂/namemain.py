def CToF(cel):
    fah = cel * 1.8 + 32
    return fah

def FToC(fah):
    cel = (fah - 32) / 1.8
    return cel

def test():
    print("32℃是%.2f℉" % CToF(32))
    print("85℉是%.2f℃" % FToC(85))

if __name__ == '__main__':
    test()