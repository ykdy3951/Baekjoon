n,m=map(int,input().split())
l=[];a,b=0,0
for i in range(n):
    l.append(input())
    if 'X' not in l[i]:
        a+=1
for i in range(m):
    f=True
    for j in range(n):
        if l[j][i] == 'X':
            f=False
            break
    if f:
        b+=1
print(max(a,b))