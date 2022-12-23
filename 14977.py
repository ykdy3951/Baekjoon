l=list(open(0))
for i in range(len(l)//2):
    n=int(l[2*i])
    x=list(map(int,l[i*2+1].split()))
    d=[];f=1
    for i in range(1,n):
        d.append(x[i]-x[i-1])
    for i in range(n-3,-1,-1):
        if d[i] != d[i+1]:
            print(i+2)
            f=0
            break
    if f:
        print(1)