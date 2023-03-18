a,b=map(int,input().split())

b %= a*2

if b > a/2 and b < a/2*3:
    print('down')
else:
    print('up')