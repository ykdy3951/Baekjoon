from math import sqrt
while(True):
    a,b=map(int,input().split())
    if [a,b] == [0,0]:
        break
    l=[]
    for i in range(a//2+1):
        l.append(abs(sqrt(i**2+(a-i)**2)-b))
    print(min(l))