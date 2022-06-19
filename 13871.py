n,c,s=map(int,input().split())
l=list(map(int,input().split()))
a=0;w=0
if a == s-1:
    w+=1
for i in l:
    if i == 1:
        a=(a+1)%n
    else:
        a-=1
        if a < 0:
            a+=n
    if a == s-1:
        w+=1
print(w)