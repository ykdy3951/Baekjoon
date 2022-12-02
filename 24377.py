x=[1]*4
l=list(map(int,input().split()))
for i in l:
    if i != 0:
        x[i-1]=0
if l.count(0) == 1:
    print(l.index(0)+1, x.index(1)+1)
elif l.count(0) == 2:
    t=[]
    for i in range(4):
        if x[i]:
            t.append(i+1)
    print(*t)
else:
    print(l[0],l[1])