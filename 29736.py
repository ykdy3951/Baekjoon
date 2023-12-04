a,b=map(int,input().split())
k,x=map(int,input().split())
t=min(b,k+x)-max(a,k-x)+1
print(t if t>0 else 'IMPOSSIBLE')