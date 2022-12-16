for _ in range(int(input())):
    l=[]
    for i in range(int(input())):
        d=[]
        c=0
        x=input()
        for j in x:
            if j >= 'A' and j <= 'Z':
                if j not in d:
                    d.append(j)
                    c+=1
        l.append([-c, x])
    print('Case #%d:' %(_+1), sorted(l)[0][1])
