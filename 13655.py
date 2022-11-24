l=list(open(0))
for i in l:
    a,b,c=map(int,i.split())
    if 144*c*c >= (144+a*a)*b*b:
        print('S')
    else:
        print('N')