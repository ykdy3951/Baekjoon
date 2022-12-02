l=list(map(int,input().split()))
x=[]
for i in range(len(l)):
    if l[i] != 0:
        x.append(i)
a,d=0,0
if (l[x[1]]-l[x[0]]) % (x[1]-x[0]):
    print(-1)
else:
    d=(l[x[1]]-l[x[0]]) // (x[1]-x[0])
    a=l[x[0]]-x[0]*d
    for i in range(len(l)):
        print(a+i*d,end=' ')