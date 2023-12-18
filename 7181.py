def f(n):
    d={}
    for i in n:
        d[i]=d.get(i,0)+1
    return d
a=list(input())
x=f(a)
for i in range(int(input())):
    b=list(input())
    y=f(b)
    p,q=0,0
    for j in range(4):
        if a[j] == b[j]:
            p+=1
    for j in x:
        if j in y:
            q+=min(x[j],y[j])
    print(q, p)