l=list(open(0))
s=0
for i in l[2:]:
    a,b=map(int,i.split())
    s+=a*b
print(s//int(l[0]))