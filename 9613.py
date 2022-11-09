from math import gcd

for i in range(int(input())):
    s=0
    l=list(map(int,input().split()))[1:]
    for i in range(len(l)):
        for j in range(i+1, len(l)):
            s+=gcd(l[i],l[j])
    print(s)