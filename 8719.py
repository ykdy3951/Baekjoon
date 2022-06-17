for i in list(open(0))[1:]:
    a,b=map(int,i.split())
    j=0
    while(True):
        if a >= b:
            print(j)
            break
        a*=2
        j+=1