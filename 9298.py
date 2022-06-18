l=list(open(0))
i=1
for w in range(int(l[0])):
    a,b,x,y=1000.0,-1000.0,1000.0,-1000.0
    i+=1;j=i+int(l[i-1])
    for k in range(i,j):
        q,e=map(float,l[k].split())
        a=min(a,q)
        b=max(b,q)
        x=min(x,e)
        y=max(y,e)
    i=j
    print('Case %d: Area %f, Perimeter %f' %(w+1, (b-a)*(y-x), 2*(b+y-a-x)))