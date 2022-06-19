t,d,m=map(int,input().split())
i=0;s=0
for _ in range(m):
    j=int(input())
    s=max(s,j-i)
    i=j
s=max(d-i,s)
print('Y' if s >= t else 'N')