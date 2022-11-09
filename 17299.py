n=int(input())
l=list(map(int,input().split()))
x=[-1]*n
s=[]
d=[0]*1000001
for i in l:
    d[i]+=1
for i in range(n):
    while(len(s) and d[l[s[-1]]] < d[l[i]]):
        x[s[-1]]=l[i]
        s.pop()
    s.append(i)
print(*x)