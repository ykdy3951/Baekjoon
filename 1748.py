n=int(input());s=0;i=1;j=9
while n:
    t=min(j,n)
    s+=i*t
    j*=10
    i+=1
    n-=t
print(s)