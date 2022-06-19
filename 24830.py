l=list(open(0));t=1
for i in l[1:]:
    a,o,b=i.split()
    a=int(a);b=int(b)
    if o == '*':
        t=(a*b)**2
    elif o == '/':
        t=(a+1)//2
    elif o == '+':
        t=a+b-t
    else:
        t=(a-b)*t
    print(t)