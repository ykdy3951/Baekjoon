from math import sqrt
l=list(open(0))
x,y=map(int,l[1].split())
for i in l[2:]:
    d,s=i.split();s=float(s)
    if len(d) != 1:
        s/=sqrt(2)
    for t in d:
        if t == 'N':
            y+=s
        if t == 'S':
            y-=s
        if t == 'E':
            x+=s
        if t == 'W':
            x-=s
print(x,y)