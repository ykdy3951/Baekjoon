n=int(input())
l=list(map(int,input().split()))
x=[-1]*n
s=[]
for i in range(n):
    while (len(s) and l[s[-1]] < l[i]):
        x[s[-1]]=l[i]
        s.pop()
    s.append(i)
print(*x)