n,k,x,y=map(int,input().split());a=0
for _ in range(n):
    i,j=map(int,input().split())
    if abs(x-i)**2+abs(y-j)**2 > k*k:
        a+=1
print(a)