for _ in range(int(input())):
    d={}
    for i in input():
        if i not in d:
            d[i]=0
        d[i]+=1
    for j in range(int(input())):
        x={}
        for k in input():
            if k not in x:
                x[k]=0
            x[k]+=1
        f=True
        for k in x.keys():
            if k not in d or x[k] > d[k]:
                f=False
                break
        print('YES' if f else 'NO')