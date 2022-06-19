l=list(open(0))[1:]
a=[]
for i in l:
    x,y=map(int,i.split())
    a.append(y//x)
print(min(a))