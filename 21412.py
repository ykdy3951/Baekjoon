from math import gcd
n=int(input())
for i in range(n//2,0,-1):
    if gcd((n-i),i) == 1:
        print(i,n-i)
        break