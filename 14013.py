q=list(open(0))
l=list(map(float,q[0].split()))
for p in q[2:]:
    a,b=p.split();a=float(a)
    i=ord(b)-65
    j=(i+1)%2
    print(l[j]*a/l[i])