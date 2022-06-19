s,a,b=map(int,input().split());f=1
for i in range(s//a,-1,-1):
    if (s-i*a) % b == 0:
        print(i, (s-i*a) // b)
        f=0
        break
if f:
    print('Impossible')