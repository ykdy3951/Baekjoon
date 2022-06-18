l=list(open(0))
x=['+','-','/','*']
for y in l[1:]:
    a,b,c=y.split()
    s='Impossible'
    for i in x:
        if eval(a+i+b) == int(c) or eval(b+i+a) == int(c):
            s='P'+s[3:]
            break
    print(s)