for i in list(open(0)):
    s=bin(int(i))[2:]
    a=s.count('0');b=s.count('1')
    print('left' if a > b else ['straight', 'right'][a<b])