n,k=map(int,input().split())
l=[i+1 for i in range(n)]
s=0
while True:
    if k <= 0: 
        k=0
        break
    if n-s-1 >= k:
        l=l[:s]+l[s+k:s+k+1]+l[s:s+k]+l[s+k+1:]
        break
    else:
        l=l[:s]+l[n-1:n]+l[s:n-1]
        k-=n-s-1
    s+=1
print(*l)