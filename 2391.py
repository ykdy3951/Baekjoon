for i in range(int(input())):
    t=input()
    x,y=987654321,''
    for j in range(int(input())):
        d=0
        a=input()
        for k in range(len(t)):
            if t[k] != a[k]:
                d+=1
        if d < x:
            x,y=d,a
    print(y)
