from math import pi
for i in range(int(input())):
    r,a,b=map(int,input().split())
    l=[r]
    while(True):
        if len(l) % 2:
            l.append(l[-1]*a)
        else:
            l.append(l[-1]//b)
        if l[-1] == 0:
            break
    s=0
    for j in l:
        s+=j*j
    print('Case #%d:'%(i+1), s*pi)