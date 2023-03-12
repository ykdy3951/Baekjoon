from math import *
def distance(x, y):
    return sqrt((x[0]-y[0])**2+(x[1]-y[1])**2)

for _ in range(int(input())):
    n=int(input())
    s=[]
    p=[]
    l=[]
    for i in range(n):
        l.append(input())
        for j in range(n):
            if l[i][j] == 's':
                s.append(i)
                s.append(j)
            elif l[i][j] == 'p':
                p.append([i,j])
    dis=-1;x=[]
    for i in p:
        t=distance(s, i)
        if dis == -1:
            dis=t
            x=i
        else:
            if dis > t:
                dis=t
                x=i
    print('(%d,%d):(%d,%d):%.2f' %(s[0],s[1],x[0],x[1],round(dis,2)))