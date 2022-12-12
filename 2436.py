from math import sqrt, gcd
a,b=map(int,input().split());x,y=0,0
c=b//a
for i in range(int(sqrt(c)), 0, -1):
    if c % i == 0:
        if gcd(i,c//i) == 1:
            x=i
            y=c//i
            break
print(x*a, y*a)